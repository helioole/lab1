#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* link;
	struct node* prev;
};


void append(struct node** head_ref, int new_data){
 struct node* new_node = (struct node*) malloc(sizeof(struct node));
 struct node *last = *head_ref;

 new_node->data = new_data;
 new_node->link = NULL;

 //If the Linked List is empty, then make the new node as head */
 if (*head_ref == NULL)
 {
 *head_ref = new_node;
 return;
 }
 
 //traverse till the last node
 while (last->link != NULL)
  last = last->link;

 last ->link = new_node;
 return;
}

void prepend(struct node** head_ref, int new_data){
struct node *new_node = (struct node*)malloc(sizeof(struct node));
new_node -> data = new_data;
new_node->link = (*head_ref);
(*head_ref) = new_node;
}

void printList(struct node *node)
{
  while (node != NULL)
  {
     printf("%d -> ", node ->data);
     node = node->link;
  }
  printf("NULL");
  printf("\n");
}


void reverse(struct node** head_ref, int new_data){
struct node *prev = NULL;
struct node *current = *head_ref;
struct node *link = NULL;
while(current != NULL){
	link = current -> link;
	current -> link = prev;
	prev = current;
	current = link;
}
*head_ref = prev;
}


int list_length(struct node* node){
int x = 0;
while(node != NULL){
	x++;
	node = node -> link;
}
return x;
}

void add_at(struct node** head_ref, int index, int new_data) {
struct node* new_node = (struct node*)malloc(sizeof(struct node*));
struct node* current = *head_ref;

new_node -> data = new_data;
new_node -> link = NULL;

if(index > list_length(*head_ref)){
	printf("Out of bounds\n");
    return;
}

//the needed node is set at the beginning
if(index == 1){
	prepend(head_ref, new_data);
	return;
}
else{
for(int i = 1 ; i < index - 1; i++){
	current = current -> link;
}
new_node -> link = current -> link;
current -> link = new_node;
}
}

void remove_at(struct node** head, int index){
struct node* prev = (struct node*) malloc(sizeof(struct node));
struct node* current = *head;
struct node* next_node = NULL;

    if (*head == NULL)
        return;
		
    if (index == 1)
    {
        next_node = current->link;
        free(*head);
        *head = next_node;
        return;
    }

    for(int i = 1 ; i < index; i++){
        prev = current;
        current = current->link;
        next_node = current -> link;
    }

    prev->link = next_node;
    free(current);

	}

void search(struct node* head, int value){
	int index = 1;
	if(head == NULL){
		printf("Sorry, a linked list doesn't exist yet\n");
		return;
	}
	//traverse until you haven't found the value
	while(head -> data != value && head-> link != NULL){
		index++;
		head = head -> link;
	}

	if(head -> data == value){
		printf("\nYou found the value at the index %d", index);
		printf("\n");
	}
	else printf("\nThere is no given value\n");
}

void sort(struct node *start) { 
    int swapped, i; 
    struct node *node1; 
    struct node *node2 = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        node1 = start; 
  
        while (node1-> link != NULL) 
        { 
            if (node1->data > node1->link->data) 
            {   
                int temp = node1 -> data;
                node1 -> data = node1 -> link -> data;
                node1 -> link -> data = temp;
                swapped = 1; 
            } 
            node1 = node1->link; 
        } 
        node2 = node1; 
    } 
    while (swapped); 
}  

void push(struct node** head_ref, struct node* new_node){
    new_node->prev = NULL;
    new_node->link = (*head_ref);
 
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    (*head_ref) = new_node;
	return;
}

void traverse(struct node** head_ref){
    struct node* new_head = NULL;
    struct node *current = *head_ref, *link;

    if (!(*head_ref) || !((*head_ref)->link))
        return;
 
    while (current != NULL) {
        //poniter to the next node
        link = current->link;
        push(&new_head, current);

        //update
        current = link;
    }
    
    *head_ref = new_head;
	return;
}


void serialize(struct node* head){   
    FILE* file = fopen("example.txt", "w");

    if(file == NULL)
        exit(1);

    while(head != NULL)
    {   
        fprintf(file, " %d ->", head->data);
        head = head-> link;
    }
    fprintf(file, " NULL");
    fclose(file);
}

void deserialize(struct node *head){
    FILE* file = fopen("example.txt", "r");
    struct node *node = NULL;

    if(file == NULL){
        printf("Can't read the file\n");
        exit(2);
    }
    
    int val = 0;
    while((fscanf(file, " %d ->", &val)) > 0){
        append(&node, val);
    }

    fclose(file);
    
}

struct node* join(struct node* list1, struct node* list2) {
      struct node *joined = NULL;
    
    
    if (list1 == NULL || list2 == NULL){
        printf("Nothing to join.\n");
        return 0;
    }
    
    while (list1 != NULL){
        append(&joined, list1->data);
        list1 = list1->link;
    }
    
    while (list2 != NULL){
        append(&joined, list2->data);
        list2 = list2->link;
    }

    return joined;
}