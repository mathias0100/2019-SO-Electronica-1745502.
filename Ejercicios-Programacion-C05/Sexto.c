#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int r = fork();

    if (r == 0)
    {
        printf("Hola!, Soy el proceso hijo y mi PID es: %d\n", getpid());
        exit(0);
    }
    else if (r > 0)
    {
        int m;
        waitpid(r, &m, 0);
        printf("Hola!, Soy el proceso padre y mi PID es: %d\n", getpid());
    }

}
