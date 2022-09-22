#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#define N 5

int main(){
struct node* data = NULL;
struct node* array[N] = {NULL};
char name[100];
int index;
int value;
int opt = 0;
char option;
while(1){
    printf("\nChoose an option:");
    printf("\np - Print");
    printf("\n1 - Append");
    printf("\n2 - Prepend");
    printf("\n3 - Reverse");
    printf("\n4 - Add a value to the specific index");
    printf("\n5 - Remove a value to the specific index");
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
            printList(array[N]);
            break;
        }


        case '1':{
            printf("Enter a node: ");
            scanf("%d", &value);
            append(&array[N], value);
            break;
        }

        case '2':{
            printf("Enter a node: ");
            scanf("%d", &value);
            prepend(&array[N], value);
            break;
        }

        case '3':{
            printf("The reversed linked list: ");
            reverse(&array[N], value);
            printList(array[N]);
            break;
        }

        case '4':{
            printf("\nProvide the index: ");
            scanf("%d", &index);
            printf("\nEnter the value: ");
            scanf("%d", &value);
            add_at(&array[N], index, value);
            printList(array[N]);
            break;
        }

        case '5':{
            printf("Enter the index: ");
            scanf("%d", &index);
            remove_at(&array[N], index);
            printList(array[N]);
            break;
        }

        case '6':{
            printf("Enter a node: ");
            scanf("%d", &value);
            search(array[N], value); 
            break;
            }

        case '7':{
            bubbleSort(array[N]);
            printf("The sorted linked list: ");
            printList(array[N]); 
            break;
            }

        case '8':{
            traverse(&array[N]);
            printList(array[N]);
        }

        case 'w':
            printf("\nEnter a file name: ");
            scanf("%s", &name);
            serialize(array[opt], name);
            break;

        case 'r':{
            printf("\nEnter a file name: ");
            scanf("%s", name);
            deserialize(&array[opt], name);
            break;
        }
        
        case '0':{
            return 0;
        }
}
}
    return 0;
}