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

char o_strcpy(char *string1, const char *string2){
    size_t i = 0;
    while(string2[i] != '\0'){
        string1[i] = string2[i];
        i++;
    }
    
    string1[i] = '\0';
    return *string1; 
}

const int o_strlen(const char *str){

    int length = 0;
    while (str[length] != '\0'){
        
        length++;
    }

    return length;
}

void o_print_string(char *str){
    int i;
    i = 0;
    while (str && str[i] != '\0'){
        write(1,&str[i],1);
        i++;
    }

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




int o_strcmp(const char *str1, const char *str2){

    int i = 0;
    unsigned char * str_cp1 = ( unsigned char * ) str1;
    unsigned char * str_cp2 = ( unsigned char * ) str2;

    while(str_cp1[i] != '\0' && str_cp2[i] != '\0'){
        if(str_cp1[i] == str_cp2[i])
            i++;
        else
            break;

    }
    
    return (str_cp1[i] - str_cp2[i]);
}


char* o_strcat(char *str1, const char *str2){
    
    int a, b;

    if(str1 != NULL && str2 != NULL){

        for (a = 0; str1[a] != '\0'; a++);

        for(b = 0; str2[b] != '\0'; b++){

            str1[a + b] = str2[b];
        }

        str1[a + b] = '\0';

    return str1;
    }

    else
        return NULL;
    
}




void main(){

    char str_ptr_non_nul[50];
    char str_ptr_nul1[50];
    char str_ptr_nul2[50];
    char string[500];
    char strcmp_result1[100];
    char strcmp_result2[100];

    char *test_string1 = "Hello je suis ";
    char *test_string2 = "Valentin";
    char *ptr_null;

    /*Test de la fonction o_strcat() */
    o_strcat(str_ptr_non_nul,"Avec pointeur non nul: ");
    o_strcat(str_ptr_non_nul,test_string1);
    o_strcat(str_ptr_non_nul,test_string2);
    o_print_string(str_ptr_non_nul);
    
    o_print_string("\n");

    o_strcat(str_ptr_nul1,"Avec pointeur nul : ");
    o_strcat(str_ptr_nul1,test_string2);
    o_strcat(str_ptr_nul1,ptr_null);
    o_print_string(str_ptr_nul1);

    o_print_string("\n");

    
    /*Test de la fonction o_strcmp()*/
    o_strcpy(string,test_string2);
    
    int test1 = o_strcmp(string,test_string2);
    int test2 = o_strcmp(string,test_string1);

    o_print_string("Test entre string et test_string1 ==> ");
    o_print_number(test1);
    o_print_string("\n");
    o_print_string("Test entre string et test_string2 ==> ");
    o_print_number(test2);
    o_print_string("\n");

    /*Test de o_strlen()*/
    o_print_string("Longueur de test_string1 ==> ");
    o_print_number(o_strlen(test_string1));
    o_print_string("\n");
    o_print_string("Longueur de test_string2 ==> ");
    o_print_number(o_strlen(test_string2));
    o_print_string("\n");

}