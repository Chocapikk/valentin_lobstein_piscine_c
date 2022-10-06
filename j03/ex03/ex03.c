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

char* o_strjoin(int size, char **arr,char *sep){

    char *result = (char *) malloc(sizeof(*arr) * size);
    for(int i = 0; i < size; i++){

        char *str = o_strcat(result, arr[i]);
        str = o_strcat(str, sep);
        o_strcpy(result, str);
        
    }
    return result;
}




void main(){
  char *array[3] = {"test1","test2","test3"};
  
  char *result = o_strjoin(3,array,"---->\n");

  o_print_string(result);
  
  free(result);
}