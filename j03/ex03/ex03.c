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

char o_strcpy(char * string1, const char * string2) {

  size_t i = 0;
  while (string2[i] != '\0') {
    string1[i] = string2[i];
    i++;
  }

  string1[i] = '\0';
  return *string1;
}


char o_strjoin(int size, char **arr,char *sep){

    char result = (char *) malloc(sizeof(char) * size);
    for(int i = 0; i <= size; i++){
        o_strcpy(result, *arr);
        o_strcpy(result, sep);

    }
    return result;
}




void main(){



}