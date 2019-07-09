#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int r = fork();

    if (r == 0)
    {
        int m = wait(NULL);
        printf("Hola!, soy el proceso hijo\n");
        printf("El codigo proveniente de wait() es %d\n", m);
    }
    else if (r > 0)
    {
        printf("Hola!, soy el proceso padre\n");
    }
}
