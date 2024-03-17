//
// Created by acer on 3/14/2024.
//

#ifndef C___DSALIBRARY_H
#define C___DSALIBRARY_H
#include "stdio.h"
#include "stdlib.h"
#define MAX_SIZE 10

// < --- For Single linked listed --->

// structure of node :
 struct SLL_Node{
    int data;
    struct SLL_Node *next;
};

//  Single Linked Listed Node function creating
struct SLL_Node* SLL_createNode (int newData){
    struct SLL_Node* newNode = (struct SLL_Node*) malloc(sizeof(struct SLL_Node));
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

// function for inserting at beginning
void SLL_insertAtBeginning( struct SLL_Node** head, int newData){
    struct SLL_Node* newNode = SLL_createNode(newData);
    newNode->next = *head;
    *head = newNode;
}

// function for showing all data in linked list
void SLL_showAllData (struct SLL_Node *node){

    if (node == NULL){
        printf("Can't show the data form NULL\n");
    }

    while ( node != NULL){
        printf("Data : %d\n", node->data);
        node = node->next;
    }
}

// function for deleting a specific node in linked list.
void SLL_deleteNode (struct SLL_Node** head, int key){

    struct SLL_Node* temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL){
        printf("Your object is NULL or Can't find the key on the object");
        return;
    }

    prev->next = temp->next;
    free(temp);
}


// <---- Double Lined Listed ---->

// double linked listed structure
struct DLL_Node{
    int data;
    struct DLL_Node *prev;
    struct DLL_Node *next;
};

struct DLL_Node* DLL_creatNode(int newData){

    struct DLL_Node* newNode = (struct DLL_Node*)malloc(sizeof(struct DLL_Node));
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void DLL_insertAtBeginning (struct DLL_Node** head, int newData){

    struct DLL_Node* newNode = DLL_creatNode(newData);
    newNode->next = *head;

    if (*head != NULL){

        (*head)->prev = newNode;
    }

    *head = newNode;
}

void DLL_append (struct DLL_Node** head, int newData){

    struct DLL_Node* newNode = DLL_creatNode(newData);
    struct DLL_Node* last = *head;

    if (*head == NULL){
        *head = newNode;
        return;
    }

    while (last->next != NULL){
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

void DLL_allData(struct DLL_Node* node){

    if(node == NULL){
        return;
    }

    while (node!= NULL){
        printf("Data : %d\n", node->data);
        node = node->next;
    }
}

void DLL_Traverse_allData (struct DLL_Node* node){

    struct DLL_Node* last = node;

    if (node != NULL){

        while (last-> next   != NULL){
            last = last->next;
        }

        while (last != NULL){
            printf("Data : %d\n", last->data);
            last = last->prev;
        }
    } else{
        printf("Your Double Linked list is Empty!\n");
    }
}

void DLL_delete(struct DLL_Node** head, int key){

    struct DLL_Node* temp = *head, *prev = NULL;

    if (temp != NULL && temp->data==key){

        temp->next->prev = NULL;
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key){

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL){
        printf("Your Double Linked list is Empty (or) can't find the key in it!\n");
        return;
    }

    prev->next = temp->next;
    temp->next->prev = prev;
    free(temp);
}


// <---- Stack Data Structure ---->

// stack data structure
struct Stack  {
    int *items;
    int top;
};

// function for initialing stack structure
struct Stack* stack_initialize(int capacity){
    struct Stack *stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->items = (int*) malloc(capacity * sizeof(int));
    stack->top = -1;
    return stack;
}

int stackisFull (struct Stack *stack){
    return (stack->top == MAX_SIZE-1);  // return 1 if true, else return 0
}

int stackisEmpty(struct Stack *stack){
    return (stack->top == -1);
}

void stack_push(struct Stack *stack, int value){
    if (stackisFull(stack)){
        printf("Stack is Full\n");
        exit(1);
    } else {
        stack->items[++stack->top] = value;
        printf("Value is inserted : index : %d, value : %d\n", stack->top, value );
    }
}

int stack_pop (struct Stack *stack){
    if(stackisEmpty(stack)){
        printf("Stack-underFlow!\n");
        exit(1);
    }else{
        return stack->items[stack->top--];
    }
}

int stack_peek(struct Stack *stack){
    if(stackisEmpty(stack)){
        printf("Stack-underFlow!\n");
        exit(1);
    }else{
        return stack->items[stack->top];
    }
}


#endif //C___DSALIBRARY_H
