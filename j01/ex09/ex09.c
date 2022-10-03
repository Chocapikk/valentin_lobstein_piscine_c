#include <unistd.h>
#include <stdio.h>
#include <string.h>



int o_atoi(char *str){
	int res = 0;

	for (int i = 0; str[i] != '\0'; ++i)
        	res = res * 10 + str[i] - '0';
	
	return res;
	
}





void main(){
	char input[500];
	char *input_text = "Veuillez écrire quelque chose : ";
	write(1,"\n",strlen("\n"));
	write(1,input_text,strlen(input_text));
	scanf("%s",&input);
}
