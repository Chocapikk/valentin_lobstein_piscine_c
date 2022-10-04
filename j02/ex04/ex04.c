#include <unistd.h>




void o_print_string(char *str){
    int i;
    i = 0;
    while (str && str[i] != '\0'){
        write(1,&str[i],1);
        i++;
    }

}

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

void o_reverse_int_table(int *arr,int size){
    int tmp[size];

    for (int i = 0; i < size; i++){
        tmp[size - 1 - i] = arr[i];
    }
    for (int i = 0; i < size; i++){
        arr[i] = tmp[i];
    }

}

void o_print_int_table(int *arr,int size){
    char *separator = ",";

    for (int i = 0; i < size; i++) { 
        o_print_number(arr[i]);
        if (i != size - 1)
            o_print_string(separator); 
    }
}


void main(){

    int array[11] = {0,1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(array) / sizeof(int);

    o_print_string("\n");

    o_print_string("Array before calling o_reverse_int_table() : \n");

    o_print_int_table(array,n);

    o_print_string("\n");

    o_reverse_int_table(array,n);

    o_print_string("Array after calling o_reverse_int_table() : \n");

    o_print_int_table(array,n);

    o_print_string("\n\n");

}