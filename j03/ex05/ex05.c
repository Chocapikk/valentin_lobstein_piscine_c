#include <unistd.h>
#include "o_linked_list.h"


Chain * my_list;

my_list = o_new_list();

my_list = o_add_node(my_list,1);
my_list = o_add_node(my_list,4);
my_list = o_add_node(my_list,17);

o_display(my_list);
