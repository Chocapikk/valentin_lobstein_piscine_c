#include <unistd.h>

int o_intlen(int nb){

    int out;
    out = 1;

    while(nb / 10 != 0){
        nb /= 10;
        out *= 10;
    }

    return out;
}

char o_print_number(int number){
    int length = o_intlen(number);
    char output;

    while(length != 0){
        char out = number / length + '0';
        char *output = &out;
        write(1,&out,1);
        number %= length;
        length /= 10;
    }
    return output;
}

void o_print_string(char *str){
    int i;
    i = 0;
    while (str && str[i] != '\0'){
        write(1,&str[i],1);
        i++;
    }
}


void main(int argc,char* argv[]){
    int count;
    for (int i = 0; i < argc; i++) {
        
        o_print_string("ARGV ");
        o_print_number(i);
        o_print_string(": ");
        o_print_string(argv[i]);
        o_print_string("\n");
    }

}