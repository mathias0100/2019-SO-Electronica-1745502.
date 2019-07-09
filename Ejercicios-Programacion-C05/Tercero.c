#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void manual(int s) {
    printf("Adiós\n");
    exit(0);
}

int main (int argc, char const *argv[]) {
    int parent_pid = getpid();
    int r = fork();
    if (r == 0) //hijo
    {
        printf("Hola\n");
        kill(parent_pid, SIGCONT);
        exit(0);
    }
    else if (r > 0) // padre
    {
        signal(SIGCONT, manual); // instalar operador
        pause();
    }
}
