/*
 * Exercise 2: Stack Implementation using Linked List
 * Assignment 7 - IPFCE 2025
 * 
 * Implement all the stack functions declared in include/stack.h
 * The stack should be implemented using a linked list structure.
 * 
 * Functions to implement:
 * - initialize: Create an empty stack
 * - push: Insert an item at the top of the stack
 * - pop: Remove and return the top item
 * - full: Check if stack is full (always false for linked list)
 * - empty: Check if stack is empty
 * - print: Print all items in the stack
 */

#include "stack.h"

/* Create an empty stack */
void initialize(stack *s)
{
    /* pre-condition: true */
    /* post-condition: stack is empty */

    s->head = NULL; //stacken er tom - ingen elementer endnu
}

/* Insert item x at the top of stack s */
void push(int x, stack *s)
{
    /* pre-condition: true (linked list can always accept more items) */
    /* post-condition: x is added to top of stack */

    //oprettelse af ny node
    node *new_node = malloc(sizeof(node)); //sørger for at gøre plads til hukommelsen og gemme data for en ny node

    //Tjekker om malloc lykkedes
    if(new_node == NULL){
        printf("ERROR: memory allocation failed\n"); //Fejlbesked hvis malloc fejler
        exit(1); //stopper programmet
    }

    new_node->data = x; //gemmer data i noden

    new_node->next = s->head; //peg på den gamle top

    s->head = new_node; //opdaterer stackens top
}

/* Return (and remove) the top item of stack s */
int pop(stack *s)
{
  /* pre-condition: stack must not be empty */
  /* post-condition: top item is removed and returned */

  if(empty(s)){
    printf("Error: pop from an empty stack\n"); //fejlbesked hvis stacken er tom
    exit(1); //stopper programmet
  }

  node *temp = s->head; //gemmer den øverste node midlertidigt

  int value = temp->data; //gemmer dens værdi

  s->head = temp->next; //flytter toppen til næste node

  return value; //returnerer den fjernede værdi
}

/* Test whether a stack can accept more pushes */
bool full(stack *s)
{
    /* pre-condition: true */
    /* post-condition: Returns true if stack is full, false otherwise */
    return false;
}

/* Test whether a stack can accept more pops */
bool empty(stack *s)
{
    /* pre-condition: true */
    /* post-condition: returns true if stack is empty, false otherwise */

    return s->head == NULL; //stacken er tom hvis top er NULL
}

/* Print the contents of the stack */
void print(stack *s)
{
    /* pre-condition: true */
    /* post-condition: prints all items in the stack */

    node *current = s->head; //starter fra toppen af

    printf("Stack contents (Top to bottom): ");

    while(current != NULL){
        printf("%d", current->data); //udskriver data
        current = current->next; //går videre til næste node
    }
    printf("\n");
}


