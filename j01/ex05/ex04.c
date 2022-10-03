#include <unistd.h>
#include <string.h>
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
	char string_result;
	char c = 'a';
	char *string = "jesaispas";
	char result = o_charpos(string,c);

	/*printf("Result : %d\n",result + 1);*/


}
