#include "tweets.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TDA LINKED LIST, APPEND WITH A FINAL NODE















// 1) USO DE INSERTSORT
/*void insertionSort(tweet * headref, tweet *sorted, tweet *head){
    sorted = NULL;
    tweet* current = headref;
    while (current != NULL)
    {
        // Store next for next iteration
        tweet* next = current->sgte;
        sortedInsert(current,sorted);
        current = next;
    }
    head = sorted;
}
void sortedInsert(tweet* newnode, tweet *sorted){
    // Special case for the head end
    if (sorted == NULL ||
        sorted->fecha >= newnode->fecha){
        newnode->sgte = sorted;
        sorted = newnode;
    }
    else{
        tweet* current = sorted;
        while (current->sgte != NULL &&
                current->sgte->fecha < newnode->fecha)
        {
            current = current->sgte;
        }
        newnode->sgte = current->sgte;
        current->sgte = newnode;
    }
}

// Function to print linked list
void printlist(tweet* head){
    while (head != NULL)
    {
        printf("%s",head->fecha);
        head = head->sgte;
    }
}*/
