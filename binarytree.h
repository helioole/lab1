#ifndef binarytree_h
#define binarytree_h


#endif /* binarytree_h */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define FLAG -1

typedef struct node
{
    int value;
    struct node* left;
    struct node* right;
} binaryTree;

binaryTree* minValue(binaryTree* node);
binaryTree* createNode(int value);
binaryTree* insert(binaryTree* node, int value);
binaryTree* delete_node(binaryTree* root, int value);
binaryTree* search(binaryTree* node, int value);
void inorder(binaryTree* node);
void preorder(binaryTree* node);
void posorder(binaryTree* node);
void serialize(binaryTree* node, char name[]);
void deserialize(binaryTree** node, char name[]);
void storeInorder(binaryTree* node, int inorder[], int* index_ptr);
int countNodes(binaryTree* root);
int compare(const void* a, const void* b);
void binaryTreeToBST(binaryTree* root);


binaryTree* minValue(binaryTree* node){
binaryTree* current = node;
    while(current && current->left != NULL)
            current = current -> left;

    return current;
}

binaryTree* createNode(int value){
    binaryTree* new_node = (binaryTree*)malloc(sizeof(binaryTree));
    new_node -> value = value;
    new_node -> left = new_node -> right = NULL;
    return new_node;
}

binaryTree* insert(binaryTree* node, int value){
    int k;
    if (node == NULL)
        node = createNode(value);

    else{
            printf("Current element: %d\n ", node->value);
            if (node->left != NULL) 
            printf("Left: %d\n ", node->left->value);
            else printf("Left: Free\n ");

            if (node->right != NULL) 
            printf("Right: %d\n ", node->right->value);
            else printf("Right: Free\n ");

            printf("\n Add to the \n1 - left, 2 - right\n"); 
            scanf("%d", &k);
            
            switch(k){ 
                case 1: {node->left = insert(node->left, value); break;}
                case 2: {node->right = insert(node->right, value); break;}
            }
        }
    return node;
    }

binaryTree* delete_node(binaryTree* root, int value){
    //base case
    if(root == NULL)
        return root;

    //the second case
    //in the left witn no children
    if(value < root -> value)
        root->left = delete_node(root -> left, value);

    //in the right with no children
    else if(value > root -> value)
        root->right = delete_node(root ->right, value);
    
    //the third case
    else {
        //node with no children or just one
        if (root->left == NULL){
            binaryTree* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            binaryTree* temp = root->left;
            free(root);
            return temp;
        }
            //root with 2 children
            //finding the minimum value in the right subtree
            binaryTree* temp = minValue(root->right);
            //make it inorder
            root->value = temp-> value;   
            //delete the inorder      
            root->right = delete_node(root->right, temp->value);
    }
    return root;
}

binaryTree* search(binaryTree* node, int value)
{
    if (node == NULL){
        return node;
    }

    else if (node->value == value){
        return node;
    }

    else if (value < node->value)
        search(node->left, value);

    else if (value > node->value)
        search(node->right, value);
    
    return node;
}

void inorder(binaryTree* node){
    if(node){
        inorder(node->left);
        printf("%d ", node->value);
        inorder(node->right);
    }
}

void preorder(binaryTree* node){
    if(node){
        printf("%d ", node->value);
        preorder(node->left);     
        preorder(node->right);
    }
}

void postorder(binaryTree* node){
    if(node){
        
        postorder(node->left);     
        postorder(node->right);
        printf("%d ", node->value);
    }
}

//write the binary tree to a file
void serialize(binaryTree* node, char name[]){
    FILE* file = fopen(name, "w");

    if(file == NULL){
        printf("Can't open the file\n");
        exit(1);
    }
    
    while(node != NULL)
    {
        fprintf(file, " %d ->", node->value);
        node = node->left;
        fprintf(file, " %d ->", node->value);
        node = node->right;
    }
    fprintf(file, " NULL");
    fclose(file);
}


//read the binary tree from a file
void deserialize(binaryTree** node, char name[]){
    FILE* file = fopen(name, "r");

    if(file == NULL){
        printf("Can't read the file\n");
        exit(2);
    }
    
    int value = 0;
    while(fscanf(file, " %d ->", &value) > 0)
    {
        insert(*node, value);
    }
    fclose(file);
}

void storeInorder(binaryTree* node, int inorder[], int* index_ptr)
{
    // Base Case
    if (node == NULL)
        return;
 
    /* first store the left subtree */
    storeInorder(node->left, inorder, index_ptr);
 
    /* Copy the root's value */
    inorder[*index_ptr] = node->value;
    (*index_ptr)++; // increase index for next entry
 
    /* finally store the right subtree */
    storeInorder(node->right, inorder, index_ptr);
}
 
/* A helper function to count nodes in a Binary Tree */
int countNodes(binaryTree* root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
 
// Following function is needed for library function qsort()
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

void arrayToBST(int* arr, binaryTree* root, int* index_ptr)
{
    // Base Case
    if (root == NULL)
        return;
 
    /* first update the left subtree */
    arrayToBST(arr, root->left, index_ptr);
 
    /* Now update root's value and increment index */
    root->value = arr[*index_ptr];
    (*index_ptr)++;
 
    /* finally update the right subtree */
    arrayToBST(arr, root->right, index_ptr);
}
 
// This function converts a given Binary Tree to BST
void binaryTreeToBST(binaryTree* root)
{
    // base case: tree is empty
    if (root == NULL)
        return;
 
    /* Count the number of nodes in Binary Tree so that
    we know the size of temporary array to be created */
    int n = countNodes(root);
 
    // Create a temp array arr[] and store inorder traversal of tree in arr[]
    int* arr = malloc(n * sizeof(*arr));
    int i = 0;
    storeInorder(root, arr, &i);
 
    // Sort the array using library function for quick sort
    qsort(arr, n, sizeof(arr[0]), compare);
 
    // Copy array elements back to Binary Tree
    i = 0;
    arrayToBST(arr, root, &i);
 
    // delete dynamically allocated memory to avoid memory leak
    free(arr);

    //inorder traversal 
    if(root){
       inorder(root->left);
       printf("%d ", root->value);
       inorder(root->right);
    }
}