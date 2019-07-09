#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    struct stat sb;
    int archivo = open("Punto_2.txt", O_CREAT | O_RDWR, S_IRWXU);
    int r = fork();

    if (r == 0)
    {
        const char * child_msg = "Yo soy el proceso hijo\n";
        printf("************ Actúa el proceso hijo *************\n");
        write(archivo, child_msg , strlen(child_msg));
        exit(0);
    }
    else if (r > 0)
    {
//        wait(NULL);
        const char * parent_msg = "Yo soy tu padre\n";
        printf("************ Actúa el proceso padre ************\n");
        write(archivo, parent_msg, strlen(parent_msg));
    }
    sync();
    fstat(archivo, &sb);
    lseek(archivo, 0, SEEK_SET);
    char * buffer = malloc(sb.st_size);
    read(archivo, buffer, sb.st_size);

    printf("El nuevo contenido del archivo es: \n%s", buffer);
    close(archivo);
    return 0;
}
