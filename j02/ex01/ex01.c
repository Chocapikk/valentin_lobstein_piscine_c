#include <unistd.h>


void o_print_string(char *str){
    int i;
    i = 0;
    while (str && str[i] != '\0'){
        write(1,&str[i],1);
        i++;
    }

}

void main(){

char *test_string = "Salut ça va ?\n";

o_print_string(test_string);

}