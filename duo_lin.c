#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int value;
    struct node* next;
    struct node* prev;
};

void remove_first(struct node ** head);
void printlist(struct node *head ){
    struct node *node_n;
    node_n=head;
    while(node_n != NULL){
        printf("%d -", node_n->value);
        node_n=node_n->next;
    }
    printf("\n");
}


void insert_at_tail ( struct node ** head, int data){
    struct node * node_n;
    node_n=malloc(sizeof(struct node));
    node_n->value=data;
    node_n->next=NULL;

    struct node * current_node;
    current_node=*head;

    if(*head == NULL){
        node_n->prev= NULL;
        *head=node_n;
        return;
    }

    while(current_node->next!=NULL){
        current_node=current_node->next;
    }
    node_n->prev=current_node;
    current_node->next=node_n;
}

void insert_at_head(struct node ** head, int data){
    struct node * new_node;
    new_node=malloc(sizeof(struct node));
    new_node->prev=NULL;
    new_node->value=data;
    new_node->next=*head;
    if((*head)!= NULL){
        (*head)->prev=new_node;
    }
    *head=new_node;

}

void insert_after_node(struct node* prev_node, int data){
    struct node * new_node;
    new_node=malloc(sizeof(struct node));
    new_node->value=data;
    new_node->next=prev_node->next;
    new_node->prev= prev_node;
    prev_node->next=new_node;

    if(new_node->next != NULL){
        new_node->next->prev =new_node;
    } 
}

void remove_last(struct node ** head){
    struct node* current;
    if (*head == NULL){
        printf("List is empty!");
        return;
    }

    current=*head;
    while(current->next->next !=NULL){
        current=current->next;
    }
    free(current->next);
    current->next=NULL;
}

void remove_first(struct node ** head){
    if(*head == NULL){
        printf("List is empty");
        return;
    }

    struct node * new_head;
    new_head=(*head)->next;
    new_head->prev=NULL;
    free(*head);
    *head=new_head;
}

void remove_by_index(struct node ** head, int indx){
    
    if(indx == 0){
        return remove_first(head);
    }

    struct node* current =*head;
    struct node* temp= NULL;
    for (int i=0; i<indx-1; i++){
        if(current->next==NULL) return;
        current= current->next;
    }

    temp=current->next;
    current->next=temp->next;
    temp->next->prev=current;
    free(temp);
}

int main() {

    struct node *head =NULL;
    struct node * tmp;

    for(int i =0; i<6; i++){
        insert_at_tail(&head, i);
    }
    insert_at_head(&head,112);
    insert_after_node(head,44);

    printlist(head);

    remove_first(&head);

    printlist(head);

    remove_last(&head);

    printlist(head);

    remove_by_index(&head,2);
    
    printlist(head);

    return 0;

}