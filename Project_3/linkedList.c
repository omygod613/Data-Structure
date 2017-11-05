#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>


struct Link* listInsertionSort(struct Link* head) {
    
    /*
     * This function should perform an insertion sort on the list whose head is
     * provided as the function's argument, so that the values in the list are
     * sorted in ascending order, starting at the head.
     *
     * The sort should be done without allocating any new Link structs or any
     * other auxiliary data structures.
     *
     * Return a pointer to the new head of the list.
     */
    struct Link * current = head;
    struct Link * insertionpointer = head;
    current = current->next;
    
    while( current != NULL)
    {
        insertionpointer = head;
        
        while(insertionpointer != current)
        {
            if(insertionpointer->value > current->value)
            {
                int tem = current->value;
                current->value = insertionpointer->value;
                insertionpointer->value = tem;
            }
            else
            {
                insertionpointer = insertionpointer->next;
            }
        }
        
        current = current->next;
    }
    return head;
    
}


struct Link* reverseList(struct Link* head) {
    
    /*
     * This function should iteratively reverse the list whose head is provided
     * as the function's argument.
     *
     * The reversal must be done totally in place, i.e. you may not allocate any
     * new Link structs or any other auxiliary data structures.
     *
     * Return a pointer to the new head of the list.
     */
    struct Link * previous = NULL;
    struct Link * current = head;
    struct Link * next = NULL;
    
    while(current != NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;

        
    }
    head = previous;
    
    return head;
    
}


struct Link* reverseListRecursive(struct Link* head){
    
    /*
     * Write this function for extra credit.  It should do the exact same thing
     * as reverseList() above, except it should do it recursively instead of
     * iteratively (i.e. no loops allowed).
     *
     * Again, you may not allocate any new Link structs or any other auxiliary
     * data structures.  You may, however, define an auxiliary function to help
     * you do the recursion.
     *
     * Return a pointer to the new head of the list.
     */
    
    struct Link * tem;
    
    if(head == NULL || head->next == NULL)
        return head;

    tem = reverseListRecursive(head->next);

    head->next->next = head;
    head->next = NULL;
    return tem;
}
