#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    /* data */
    int data;
    struct Node* next;

} Node;

Node* insert_front(Node* head, int value){
    Node* new = (Node*) malloc(sizeof(Node));
    if (new == NULL){
        printf("error: malloc failed\n");
        return head;
    }
    new -> data = value;
    new -> next = head;
    return new;
}

Node* insert_back(Node* head, int value){
    Node* new_rear = (Node*) malloc(sizeof(Node));
    if (new_rear == NULL) { 
        return head; 
    }
    new_rear -> data = value;
    new_rear -> next = NULL;
    if (head == NULL) {
        return new_rear; 
    }
    Node* current = head;
    while (current -> next != NULL){
        current = current -> next;
    }
    current -> next = new_rear;
    return head;
}

Node* delete_node(Node* head, int value){
    if (head -> data == value){
        Node* new_head = head -> next;
        free (head);
        return new_head;
    }
    else{
        Node* current = head;
        while (current -> next != NULL){
            if (current -> next -> data == value){
                if (current -> next -> next == NULL){
                    free(current -> next);
                    current -> next = NULL;
                }
                else{
                    Node* temp = current -> next;
                    current -> next = temp -> next;
                    free (temp);
                }
            }
            current = current -> next;
            }
        printf("no value match requirment\n");
        return head;
        }
    }

Node* reverse_list(Node* head){
    if (head == NULL){
        return head;
    }
    else if (head -> next == NULL){
        return head;
    }
    Node* current = head;
    Node *prev = NULL;
    Node* next = current -> next;
    while (current != NULL){
        next = next -> next;
        current -> next = prev;

        prev = current;
        current = next;

    }
    return current;
}

void print_list(Node* head){
    Node* current = head;
    while (current -> next != NULL)
    {
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("%d -> NULL\n", current -> data);
}

void free_list(Node* head){
    Node* current = head;
    while (current -> next != NULL)
    {   Node* temp = current -> next;
        free (current);
        current = temp; 
    }
    free (current);
}

int main(void){
    Node* n30 = insert_front(NULL, 30);
    Node* n20 = insert_front(n30, 20);
    Node* n10 = insert_front(n20, 10);
    Node* n40 = insert_back(n10, 40);

    print_list(n10);

    free_list(n10);

    return 0;
}