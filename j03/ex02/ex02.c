#include <stdlib.h>
#include <unistd.h>

void o_print_string(char * str) {
  int i;
  i = 0;
  while (str && str[i] != '\0') {
    write(1, & str[i], 1);
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


int o_digit(int n){
	int count;

	do{
    	n /= 10;
    	++count;
  	}while (n != 0);
	return n;
}


void o_free_matrix(int *matrix){

	int size = sizeof(*matrix) / sizeof(matrix[0]);

	for(int i = 0; i < size; i++){
		free(matrix);

	}
}

int *o_matrix(int row, int col){
	int space;

	int** mat = (int** )malloc(row * sizeof(int*));

	for(int index = 0; index < row; ++index ){
    	mat[index] = (int*) malloc(col * sizeof(int));
	}
	

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			
			if(j > i)
				mat[i][j] = j;
			else
				mat[i][j] = i;
			
			o_print_number(mat[i][j]);
			
		}

		o_print_string("\n");
	}
	return *mat ;

}






void main(){

	int *mat1 = o_matrix(3,4);
	o_print_string("\n");
	int *mat2 = o_matrix(5,9);
	o_free_matrix(mat1);
	o_free_matrix(mat2);



}
