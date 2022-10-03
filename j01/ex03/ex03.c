#include <unistd.h>
#include <string.h>


void main(){

	char c;

	write(1,"10\n",3);
	for (int i=9; i>=1; i--){
		c = i + '0';
		write(1,&c,strlen(&c));
		write(1,"\n",1);
	}
}
