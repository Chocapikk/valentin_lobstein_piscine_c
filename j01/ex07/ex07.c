#include <unistd.h>
#include <stdio.h>




long o_arrsum(int *arr, int size){

	long result;

	for (int i = 0; i < size; i++){
		result += (long) arr[i];
		printf("%ld\n",result);
	}

return result;

}





void main(){

	int array[] = {0,1,2,3,4,5,6,7,8,9};
	int *ptr = array;
	int size = sizeof(array) / sizeof(int);
	long result = o_arrsum(ptr,size);


}















