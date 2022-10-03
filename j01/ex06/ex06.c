#include <unistd.h>
#include <stdio.h>
#include <string.h>

void main(){

	char result[500];
	char *input = "Quel est votre nom ? : > ";
	char *output = "\n Salut ";

	write(1,input,strlen(input));
	scanf("%s",&result);
	write(1,output,strlen(output));
	write(1,&result,strlen(&result));
	write(1,"\n",strlen("\n"));

}
