/*********************************************

Author: Sujayyendhiren RS

Description: Doubly linked list for beginners

How to test
    (i)  gcc dll.c   or clang dll.c
    (ii) ./a.out
**********************************************/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node *prev;
    struct node *next;
};

struct node *head=NULL;
struct node *tail=NULL;

void add_ll(int value) {
    /* Add at the end */

    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->value = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL)
        head = tail = newnode;
    else{
        newnode-> prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}

void del_ll(int value){
    if(head == NULL){
        printf("List is empty\n");
    } 
    else{
        struct node *tmp = head;

        while(tmp != NULL){
            if(tmp->value == value){

                if(tmp != head && tmp != tail){
                    tmp->prev->next = tmp->next;
                    tmp->next->prev = tmp->prev;
                    free(tmp);
                }

                else if(tmp == head && head != tail){
                   head = head->next; 
                   head->prev = NULL;
                   free(tmp);
                }

                else if(tmp == head && head == tail){
                   head = NULL; 
                   tail = NULL; 
                   free(tmp);
                }
                else if (tmp == tail){
                   tail = tail->prev; 
                   tail->next = NULL;
                   free(tmp);
                }
            }
            tmp = tmp->next;
        }
    }
}

void print_ll(){
    if(head == NULL){
        printf("List is empty\n");
    } 
    else{
        struct node *tmp = head;

        while(tmp != NULL){
            printf("Value %d\n", tmp->value);
            tmp = tmp->next;
        }
    }
}

int main() {

    /********************************
      Test1: Add elems to linked list
    **********************************/
    add_ll(10);
    add_ll(10);
    add_ll(100);
    add_ll(100);
    add_ll(1000);
    add_ll(1000);

    printf("===================\n");
    printf("After adding \n");
    printf("===================\n");
    print_ll();

    /************************************
      Test2: Delete elems from linked list
      
      Note: Deletion is expected to remove 
            elements that are repeated
    *************************************/
    del_ll(10);
    del_ll(100);
    //del_ll(1000);
    printf("===================\n");
    printf("After deleting \n");
    printf("===================\n");
    print_ll();
}
