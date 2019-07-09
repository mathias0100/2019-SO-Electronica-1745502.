#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int r = fork();

    if (r == 0)
    {
        printf("========== Momento de ejecutar el proceso hijo ==========\n");
        char * const argv[] = {"ls", NULL};
        char * const envp[] = {NULL};

        //ATENCIÓN:
       //Quitar "//" un punto a la vez//

        //execl("/bin/ls", "ls", NULL);
        //execlp("ls", "ls", NULL);
        //execle("/bin/ls", "ls", NULL, envp);
        //execv("/bin/ls", argv);
        //execvp("ls", argv);
        //execvpe("ls", argv, envp);
    }
    else if (r > 0)
    {
        wait(NULL);
    }
    else
    {
        fprintf(stderr, "Error occurred during fork()");
    }
}
