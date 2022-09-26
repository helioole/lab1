#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


int main(){
struct node* array[3]={NULL};
int index;
int value;
char option;
int nr;
int list2 = 0;
int list1 = 0;
int start = 0;
while(1){
    printf("\nChoose an option:");
    printf("\nc - Choose a list");
    printf("\n1 - Append");
    printf("\n2 - Prepend");
    printf("\n3 - Reverse");
    printf("\n4 - Add a value to the specific index");
    printf("\n5 - Remove a value at the specific index");
    printf("\n6 - Search");
    printf("\n7 - Sort");
    printf("\n8 - Backwards traversal");
    printf("\n9 - Join two lists");
    printf("\nw - Save data in a file");
    printf("\nr - Load data from a file");
    printf("\n0 - Abort the program");

    printf("\nYou want to choose: ");
    scanf("%s", &option);
    printf("\n");
    switch(option){

        case 'c':{
            for(int i=0; i < 3; i++){
                printList(array[i]);
            }

            printf("Choose the list: \n");
            scanf("%d", &start);
            break;

        }       

        case '1':{
            printf("Enter a node: ");
            scanf("%d", &value);
            append(&array[start], value);
            printList(array[start]);
            break;
        }

        case '2':{
            printf("Enter a node: ");
            scanf("%d", &value);
            prepend(&array[start], value);
            printList(array[start]);
            break;
        }

        case '3':{
            printf("The reversed linked list: ");
            reverse(&array[start], value);
            printList(array[start]);
            break;
        }

        case '4':{
            printf("\nEntr the index: ");
            scanf("%d", &index);
            printf("\nEnter the value: ");
            scanf("%d", &value);
            add_at(&array[start], index, value);
            printList(array[start]);
            break;
        }

        case '5':{
            printf("Enter the index: ");
            scanf("%d", &index);
            remove_at(&array[start], index);
            printList(array[start]);
            break;
        }

        case '6':{
            printf("Enter a node: ");
            scanf("%d", &value);
            search(array[start], value); 
            break;
            }

        case '7':{
            sort(array[start]);
            printf("The sorted linked list: ");
            printList(array[start]); 
            break;
            }

        case '8':{
            traverse(&array[start]);
            printList(array[start]);
            break;
        }

        case '9':{

            printf("Which lists you want to join?: ");
            scanf("%d %d", &list1, &list2);
            
            array[start] = join(array[list1], array[list2]);
            printList(array[start]);

            break;
        }

        case 'w':{
            serialize(array[start]);
            break;
        }

        case 'r':{
            deserialize(array[start]);
            printList(array[start]);
            break;
        }  

        case '0':{
            return 0;
        }
}
}
    return 0;
}