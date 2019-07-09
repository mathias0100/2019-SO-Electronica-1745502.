#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int r = fork();

    if (r == 0)
    {
        close(STDOUT_FILENO);
        printf("Hola!, soy el proceso hijo... y tu, puedes verme? \n");
    }
    else if (r > 0)
    {
        wait(NULL);
        printf("Hola!, soy el proceso padre \n");
    }
}
