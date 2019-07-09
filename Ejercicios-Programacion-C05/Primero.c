#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Start PID %d\n", (int) getpid());
    int x = 500;
    int r = fork();
    if (r < 0) {
        printf("Error: Fallo la llamada al fork().\n");
        exit(1);
    } else if (r == 0) {
        printf("Hijo (pid %d) antes de intentar cambiar x, x = %d\n",
               (int) getpid(), x);
        x = 1;
        printf("Hijo (pid %d) despues de intentar cambiar x, x = %d\n",
               (int) getpid(), x);
    } else {
        sleep(1);
        printf("Padre (pid %d) antes de intentar cambiar x, x = %d\n",
               (int) getpid(), x);
        x = 2;
        printf("Padre (pid %d) despues de intentar cambiar x, x = %d\n",
               (int) getpid(), x);
    }
    return 0;
}
