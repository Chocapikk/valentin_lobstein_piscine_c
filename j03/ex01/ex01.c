#include <unistd.h>
#include <stdlib.h>

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


int * o_interval(int a, int b){

	size_t length;
	size_t min;

	if (a > b){
		min = b;
		length  =  a - min;
	}
	else{	
		min = a;
		length = b - min + 1;
	}

	
	int *array = (int *) malloc(length * sizeof(int));

	for(int i = min; i <= length; i++){
		
		array[i] = i;
		o_print_number(array[i]);

		if (i != length){
			o_print_string(", ");
		}
		else{
			o_print_string("\n");
		}

	}

	return array;
}





void main(){

	int a,b,c,d;
	a = 10;
	b = 2;
	c = 1;
	d = 400;
	
	o_print_string("Test numéro 1\n");
	int *result1 = o_interval(a, b);
	free(result1);
	o_print_string("Test  numéro 2\n");
	int *result2 =  o_interval(c, d);
	free(result2);


}
