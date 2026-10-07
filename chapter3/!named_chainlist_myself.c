#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Person{   
    int id;
    char* name;
    struct Person* next;
} Person;

Person* create_person(Person* head, int id, const char* name){
    Person* new_head = (Person*) malloc(sizeof(Person));
    if (NULL == new_head){
        printf("malloc failed\n");
        return head;
    }

    new_head -> name = (char*) malloc(strlen(name) + 1);  // ***
    if (NULL == new_head -> name){
        printf("malloc failed");
        free(new_head);
        return head;
    }

    new_head -> id = id;
    strcpy(new_head -> name, name);
    new_head -> next = head;
    
    return new_head;
}

void print_list(Person* head){
    Person* current = head;
    if (NULL == current){
        printf("empty list\n");
        return;
    }
    while (current != NULL)
    {
        printf("ID: %d, Name: %s -> ", current -> id, current -> name);
        current = current -> next;
    }
}

void free_list(Person* head){
    Person* current = head;
    Person* next = NULL;
    if (NULL == current){
        return;
    }
    while (current -> next != NULL)
    {
        next = current -> next;
        free(current -> name);
        free(current);
        current = next;
    }
        free(current -> name);
        free(current);
}

int main(void){
    Person* Anna = create_person(NULL, 1, "Anna");
    Person* John = create_person(Anna, 2, "afuh,,cgs,bvua.osv.asdhvbas.ohvibhkbvsni.evkl");
    Person* Mike = create_person(John, 3, "Mike");

    print_list(Mike);

    free_list(Mike);

    return 0;
}