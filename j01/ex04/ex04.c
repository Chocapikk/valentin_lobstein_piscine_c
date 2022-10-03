#include <unistd.h>
#include <string.h>
#include <stdio.h>


void main(){
	
        for (char c = 90; c >= 65; c--){
                write(1, &c, strlen(&c));
                write(1, "\n", 1);
        }
}
