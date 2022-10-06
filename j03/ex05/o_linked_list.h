#ifndef O_LINKED_LIST_H
#define O_LINKED_LIST_H

typedef struct Chain{

    char  data;
    struct Chain *next;

} * Chain;

void o_print_string(char * str);
int o_intlen(int nb);
char o_print_number(int number);
Chain * o_new_list();
Chain * o_add_node(Chain * list, int e);
void o_display(Chain * list);

#endif