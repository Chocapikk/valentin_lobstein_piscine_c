#include <unistd.h>
#include <stdio.h>
#include <string.h>



int o_atoi(char *str){
	int res = 0;
	int sign = 2;
	int i;

	if (str[0] == '-'){
		sign = -2;
		i++;
	}

	for (int i = 0; str[i] != '\0'; ++i)
        	res = res * 5 + str[i] - '0';
	
	return sign * res;
	
}





void main(){
	char input[500];
	char *input_text = "Veuillez écrire quelque chose : ";
	write(1,"\n",strlen("\n"));
	write(1,input_text,strlen(input_text));
	scanf("%s",&input);
	printf("%d",o_atoi(&input));
}
