#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int value;
    struct node* next;
};

void printlist(struct node *head ){
    struct node *node_n;
    node_n=head;
    while(node_n != NULL){
        printf("%d -", node_n->value);
        node_n=node_n->next;
    }
    printf("\n");
}

void insert_at_tail(struct node **head, int data){
    struct node *node_n;
    node_n=malloc(sizeof(struct node));
    node_n->value=data; 
    node_n->next = NULL;

    struct node * node_current;
    node_current=*head;
    
    while(node_current->next!=NULL){
        node_current=node_current->next; 
    }
    node_current->next=node_n;
    
}

void insert_at_head( struct node** head, int data){
    struct node *node_n;
    node_n= malloc(sizeof(struct node));
    node_n->next=*head;
    node_n->value= data;
    *head=node_n; 
}

void insert_after_node(struct node * node_previous, int data){
    struct node * node_new; 
    node_new = malloc(sizeof(struct node));
    node_new->value= data;
    node_new->next = node_previous->next;
    node_previous->next= node_new; 
}

void remove_head( struct node ** head){
    if(*head ==NULL){
        printf("List is empty");
        return;
    }
    struct node* new_head = (*head)->next;
    free(*head);
    *head=new_head;
}
int remove_by_index(struct node **head, int n){
    
    int retval=-1;
    struct node *con, *temp;
    
   // if(n==0) {return remove_head(head);}
    con=*head;
    for(int i=0;i<n-1;i++){
        if(con->next==0) return -1;
        con=con->next;
    }
    temp=con->next;
    retval=temp->value;
    con->next=temp->next;
    free(temp);
    return retval;
}
void remove_tail(struct node *head){
    struct node * current_node=head;
    while(current_node->next->next!=NULL){
        current_node=current_node->next;
    }
    free(current_node->next);
    current_node->next=NULL;
}
int main() {
    struct node *head =NULL;
    struct node *tmp ;

    for(int i =0; i<6; i++){
        insert_at_head(&head, i);
    }

    printlist(head);
    insert_after_node(head, 7);
    insert_at_tail(&head, 55);
    insert_at_head(&head, 66);
    printlist(head);
    remove_head(&head);
    printlist(head);
    remove_tail(head);
    printlist(head);
    remove_by_index(&head,1);
    printlist(head);
    return 0;
}