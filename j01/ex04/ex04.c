#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int o_charpos(char *str,char c){
	int len_char = strlen(str);

	for(int i=0; i <= len_char; i++){

		if(str[i] == c){

			return i;
	
		}

	}

return -1;

}




void main(){

	char c = 'a';
	char *string = "jesaispas";
	char result = o_charpos(string,c);
	/*printf("%d\n",result+1);*/

}
