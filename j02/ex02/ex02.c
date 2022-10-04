#include <unistd.h>


void o_print_string(char *str){
    int i;
    i = 0;
    while (str && str[i] != '\0'){
        write(1,&str[i],1);
        i++;
    }

}


char o_strcpy(char *string1, const char *string2){
    size_t i = 0;
    while(string2[i] != '\0'){
        string1[i] = string2[i];
        i++;
    }
    
    string1[i] = '\0';
    return *string1; 
}


char o_strncpy(char* out,const char* str, int length){
    
    if(out == NULL && out == str)
        return ' ';

    while(*str && length--){

        *out = *str;
        out++;
        str++;
    }

    *out += '\0';
    return *out;
}

void main(){
    char str_cpyd[50];

    char *test_string = "Allo à l'huile\n";
    
    o_strcpy(str_cpyd, test_string);

    o_print_string(str_cpyd);



}