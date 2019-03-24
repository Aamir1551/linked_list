#include "node.h"
#include <stdlib.h>
#include <stdio.h>


int myfunc(struct node *n) {
    if(n->value == 2) {
        return 0;
    }
    return -1;
}

int main() {

    struct linked_list * list = (struct linked_list *) create_list();


    add_item(list, 1);
    add_item(list, 3);
    add_item(list, 5);

    printf("%d \n", get_item(1, list));

    printf("%d \n", filter(myfunc, list));

    remove_item(1, list);

    printf("%d \n", get_item(1, list));

    delete_list(list);


    //printf("%d", get_item(0, list));







    return 0;
}