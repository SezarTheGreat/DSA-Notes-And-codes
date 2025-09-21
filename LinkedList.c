#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void addNewNode(int newNode){}

int main(){
    struct node *head = NULL;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    // temp -> data = 10;
    // temp -> next = NULL;

    // head = temp;
    
    // temp = head;
    // if(temp==NULL) printf("NULL\n");
    // while (temp != NULL){
    //     printf("%d->",temp -> data);
    //     temp = temp->next;
    // }
    // printf("NULL\n");

    printf("Insert: ");
    int choice;
    scanf("%d",&choice);
    while (choice != -1){
        printf("Do you want to continue: ");
        scanf("%d",newNode -> data);
        newNode -> next = NULL;
    }

    // struct node *newNode = (struct node *)malloc(sizeof(struct node));
    // newNode->data = 20;
    // newNode->next = NULL;

    // temp=head;
    // while(temp -> next != NULL){
    //     temp = temp -> next;
    // }
    // temp -> next = newNode;

    // temp = head;
    // while (temp != NULL){
    //     printf("%d->",temp -> data);
    //     temp = temp -> next;
    // }
    // printf("NULL");

    return 0;
}