#include <unistd.h>
#include <string.h>


void main(){

	char c;
	for (int i=1; i<=9; i++){
		c = i + '0';
		write(1,&c,strlen(&c));
		write(1,"\n",1);
	}
	write(1,"10\n",3);
}
