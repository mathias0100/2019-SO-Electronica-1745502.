#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	FILE *text;
	long e;
	char read;
	text = fopen("texto.txt", "r");
	if(text==NULL){
		printf("El archivo no es valido");
	}
	fseek(text,0,SEEK_END);
	e=ftell(text);
	for (e-=1; e>=0; --e){
		fseek(text,e,SEEK_SET);
		read = fgetc(text);
		printf("%c", read);
	}
	printf("\n");
	return 0;

}
