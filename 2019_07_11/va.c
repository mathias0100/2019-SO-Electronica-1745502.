#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	printf("locacion del codigo : %p\n", main);
	printf("locacion del monton : %p\n", malloc(100e6));
	int x = 3;
	printf("locacion de la pila: %p\n", &x);
	return x;
}

