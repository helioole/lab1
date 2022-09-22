#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


int main(){
struct node* head = NULL;
struct node* head2 = NULL;
int index;
int value;
char option;
while(1){
    printf("\nChoose an option:");
    printf("\np - Print");
    printf("\n1 - Append");
    printf("\n2 - Prepend");
    printf("\n3 - Reverse");
    printf("\n4 - Add a value to the specific index");
    printf("\n5 - Remove a value at the specific index");
    printf("\n6 - Search");
    printf("\n7 - Sort");
    printf("\n8 - Backwards traversal");
    printf("\nw - Save data in a file");
    printf("\nr - Load data from a file");
    printf("\n0 - Abort the program");

    printf("\nYou want to choose: ");
    scanf("%s", &option);
    printf("\n");
    switch(option){

        case 'p':{
            printf("The obtained linked list: ");
            printList(head);
            break;
        }

        case '1':{
            printf("Enter a node: ");
            scanf("%d", &value);
            append(&head, value);
            break;
        }

        case '2':{
            printf("Enter a node: ");
            scanf("%d", &value);
            prepend(&head, value);
            break;
        }

        case '3':{
            printf("The reversed linked list: ");
            reverse(&head, value);
            printList(head);
            break;
        }

        case '4':{
            printf("\nProvide the index: ");
            scanf("%d", &index);
            printf("\nEnter the value: ");
            scanf("%d", &value);
            add_at(&head, index, value);
            printList(head);
            break;
        }

        case '5':{
            printf("Enter the index: ");
            scanf("%d", &index);
            remove_at(&head, index);
            printList(head);
            break;
        }

        case '6':{
            printf("Enter a node: ");
            scanf("%d", &value);
            search(head, value); 
            break;
            }

        case '7':{
            bubbleSort(head);
            printf("The sorted linked list: ");
            printList(head); 
            break;
            }

        case '8':{
            traverse(&head);
            printList(head);
            break;
        }

        case 'w':{
            serialize(head);
            break;
        }

        case 'r':{
            deserialize(&head2);
            printList(head2);
            break;
        }  

        case '0':{
            return 0;
        }
}
}
    return 0;
}