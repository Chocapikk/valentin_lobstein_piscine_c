#include <stdlib.h>
#include <unistd.h>

typedef struct Chain{

    void *data;
    struct Chain *next;

} Chain;

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


Chain * o_new_list(){

    return NULL;

}


Chain * o_add_node(Chain * list, char * e){

    Chain * first_node;

    first_node = (Chain *) malloc(sizeof(Chain));
    first_node -> data = e;
    first_node -> next = list;

    return first_node;

}


void o_display(Chain * list){

    Chain * ptr = list;
   

    while(ptr != NULL){
        o_print_string("List --> ");
        o_print_string(ptr -> data);
        ptr = ptr-> next; 
        o_print_string("\n");
    }
    


}

int main(){

    Chain * my_list;

    my_list = o_new_list();

    my_list = o_add_node(my_list,"Test1\n");
    my_list = o_add_node(my_list,"Test2\n");
    my_list = o_add_node(my_list,"Test3\n");

    o_display(my_list);
    free(my_list);

    return EXIT_SUCCESS;
}