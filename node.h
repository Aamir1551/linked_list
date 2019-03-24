#include <stdio.h>
#include <stdlib.h>
struct linked_list {
    struct node *head;
    int length;
};

struct node{
    int value;
    struct node * next_node;
};

struct linked_list * create_list() {
    struct linked_list * list = (struct linked_list*) malloc(sizeof(struct linked_list));
    list->head = malloc(sizeof(struct node));
    list->length = 0;
    return list;
}

int add_item(struct linked_list * list, int data) {
    struct node * new_node = list->head;
    for(int i = 0;i<list->length;i++) {
        new_node = new_node->next_node;
    }

    new_node->value = data;
    new_node->next_node = 0;
    new_node->next_node = malloc(sizeof(struct linked_list));
    list->length++;
}

int delete_list(struct linked_list * list) {
    struct node * current_item = list->head;
    struct node * temp = current_item;
    for(int i = 0; i< list->length; i++) {
        temp = current_item;
        current_item = current_item->next_node;
        free(temp);
    }
    free(current_item);
    free(list);
}


int get_item(int index, struct linked_list * list) {
    if(index > list->length - 1) {
        puts("error");
        return 0;
    }
    struct node * current_node = list->head;
    for(int i = 0; i< index;i++) {
        current_node = current_node->next_node;
    }
    return current_node->value;
}

int filter(int (*f)(struct node *), struct linked_list * list) {
    struct node * current_item = list->head;
    for(int i = 0; i<list->length;i++) {
        if(f(current_item) == 0) {
            return i;
        }
        current_item = current_item->next_node;
    }
    return -1;
}

int remove_item(int index, struct linked_list * list) {
    if(index > list->length -1) {
        puts("Error");
    }
    struct node * current_node = list->head;
    for(int i = 0; i< index - 1; i++) {
        current_node = current_node -> next_node;
    }
    struct node * n = current_node->next_node;
    current_node->next_node = current_node->next_node->next_node;
    list->length--;
    free(n);
}

