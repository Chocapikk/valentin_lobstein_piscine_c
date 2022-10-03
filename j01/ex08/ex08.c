#include <stdbool.h>
#include <stdio.h>


bool o_pow3(int n){
	
	while (n % 3 == 0){ 
		n /= 3; 
	} 

	if(n == 1)
		return true;
	else
		return false;
}







void main(){

bool result = o_pow3(3);
bool result2 = o_pow3(8);
bool result3 = o_pow3(159);

}
