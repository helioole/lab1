#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binarytree.h"

int main(){
    binaryTree* root = NULL;
    char name[50];
    int value;
    char option;
    while(1){
    printf("\nChoose an option:");
    printf("\n1 - Add a node");
    printf("\n2 - Delete a node");
    printf("\n3 - Search for a node");
    printf("\n4 - In-order tarversal");
    printf("\n5 - Pre-order traversal");
    printf("\n6 - Post-order traversal");
    printf("\n7 - Make a BST");
    printf("\n8 - Make a balanced tree");
    printf("\nw - Write your binary tree in a file");
    printf("\nr - Load a binary tree from a file");
    printf("\n0 - End of execution\n");

        printf("\nYou want to choose: ");
        scanf("%s", &option); 
        printf("\n");

        switch(option){

            case '1':{
            printf("Enter a node: ");
            scanf("%d", &value);
            if(root == NULL){
               root = insert(root, value);
            }
            else {insert(root, value);}
            break;
        }
            case '2':{
                printf("Enter a node: ");
                scanf("%d", &value);
                if(root == NULL){
                    printf("There are no nodes yet\n");
                }
                else {
                    delete_node(root, value);
                    printf("You've deleted the node %d\n", value);
                    printf("\n");
                    }
                break;
            }

            case '3':{
                if(root == NULL){
                printf("There are no nodes yet\n");
                }
                else {
                    printf("Enter a node: ");
                    scanf("%d", &value);
                    printf("Is it in the tree? \n");
                    search(root, value);
                    printf("\n");
                    }
                break;
            }

            case '4':{
                if(root == NULL){
                    printf("There are no nodes yet\n");
                }
                else {
                    printf("In-order traversal: ");
                    inorder(root);
                    printf("\n");
                    }
                break;
            }

            case '5':{
                if(root == NULL){
                    printf("There are no nodes yet\n");
                }
                else {
                    printf("Pre-order traversal: ");
                    preorder(root);
                    printf("\n");
                    }
                break;
            }

            case '6':{
                if(root == NULL){
                    printf("There are no nodes yet\n");
                }
                else {
                    printf("Post-order traversal: ");
                    postorder(root);
                    printf("\n");
                    }
                break;
            }
            
            case 'w':{
                printf("Write a file name: ");
                scanf("%s", name);
                serialize(root, name);
                break;               
            }

            case 'r':{
                printf("Write a file name: ");
                scanf("%s", name);
                deserialize(&root, name); 
                break;
            }

            case '0': {
                return 0;
            }
        }
    }

    return 0;
}