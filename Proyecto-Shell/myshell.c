#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void PantallaInicio(){
        printf("\n\t----------------------------------\n");
        printf("\t          My Shell V1.0\n");
        printf("\t----------------------------------\n");
        printf("\t Mathias Castillo - Brallan Rubio \n");
        printf("\t----------------------------------\n");
        printf("\n");
}

int cd(char **args);
int path(char **args);
int lsh_quit(char **args);
int limpiar(char **argv);
int directory(char **argv);
int env(char **argv);
int ec(char **argv);
int ayuda(char **argv);
int pausa(char **argv);


char *builtin_str[] = {
    "cd",
    "path",
    "quit",
    "clr",
    "dir",
    "environ",
    "echo",
    "help",
    "pause"
};

int (*builtin_func[]) (char **) = {
    &cd,
    &path,
    &lsh_quit,
    &limpiar,
    &directory,
    &env,
    &ec,
    &ayuda,
    &pausa
};

int num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

int cd(char **args)
{
    char buff[1024];    
    getcwd(buff, 1024);
    if (args[1] == NULL) {
        fprintf(stderr, "El directorio actual es %s\n", buff);
    } else {
        if (chdir(args[1]) != 0) {
            perror("lsh");
        }
    }
    return 1;
}

int path(char **args)
{
  char path[1024];
  getcwd(path, sizeof(path));
  printf("PATH: %s", path);
  return *path;
}

int lsh_quit(char **args)
{
    return 0;
}

int limpiar(char **args)
{
    system("clear");
    return 1;
}


int directory(char **args)
{
    printf("Se han encontrado los siguientes archivos en el directorio:\n");
    char command[50];
    strcpy( command, "dir" );
    system(command);
    return 1;
}

int env(char **args)
{
    system("env");
    return 1;
}


int ec(char **args)
{
        if(args[1] == NULL){
		    return 1;
        }
	for(int i = 1; args[i] != NULL ; i++){
	 	printf("%s ", args[i]);
        }
	printf("\n");
    return 1;
}


int ayuda(char **args)
{
    printf("Hola, Bienvenido a MyShell v1.0, los siguientes comandos estan disponibles para ser ejecutados:\n");
    printf(" - cd <directorio>: Cambiar el directorio""\n - clr: Limpiar la pantalla""\n - dir <directorio>: Muestra el contenido del directorio""\n - environ: Muestra todas las cadenas""\n - echo <comentario>: Muestra el comentario en pantalla""\n - help: Despliega este manual de usuario""\n - pause: Deterner la ejecución  hasta que se presiona enter""\n - quit: Salir de MYSHELL\n");
    return 1;

}


int pausa(char **args)
{
    do {
        printf("Presione ENTER para continuar:......");
    }while (getchar() != '\n');

    return 1;
}





int launch(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // proceso hijo
    if (execvp(args[0], args) == -1) {
      perror("lsh");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
      perror("lsh");
  } else {
      // Proceso padre
      do {
        wpid = waitpid(pid, &status, WUNTRACED);
      } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}



int execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    return 1;
  }

  for (i = 0; i < num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return launch(args);
}

#define RL_BUFSIZE 1024
char *read_line(void)
{
  int bufsize = RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "lsh: error :(\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    c = getchar();

    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;
  }
}

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
char **split_line(char *line)
{
  int bufsize = TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  token = strtok(line, TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "lsh: error :(\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

void loop(void)
{
  char *line;
  char **args;
  int status;

  do {
    printf("\nMyShell-> ");
    line = read_line();
    args = split_line(line);
    status = execute(args);

    free(line);
    free(args);
  } while (status);
}


int main(int argc, char **argv)
{
    PantallaInicio();
    loop();

    return 0;
}

