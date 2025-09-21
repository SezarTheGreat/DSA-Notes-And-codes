// Write the code
// Problem Statement:
// Implement Singly Linked List Program with following functionalities:
// 1. Create: Creates an Empty Linked List. It is always the first command to be called in the program. It is called only once at the start of the program.
// Input Command: 1: "Create"

// 2. Print: It prints the data of linked list in following format:
// Example:
// If Linked List is empty: NULL
// If Linked List is not empty: 10->20->30->NULL
// Input Command: 2: "Print"

// 3. Insertion: It inserts the new node at the specified position.
// atBeg x: atBeg inserts the x number at beginning of the linked list. It takes 1 input after atBeg command. 
// atEnd x: atEnd inserts the x number at end of the linked list. It takes 1 input after atEnd command.  
// afterPos x p: afterPos inserts the x number after position p. It takes 2 inputs after afterPos command. Position starts from 0 index.
// Input Commands: 3: "InsertatBeg", 4: "InsertafterPos", 5: "InsertatEnd"

// 4. Deletion: It deletes the node from the specified position.
// atBeg: atBeg deletes the node from the beginning of the linked list.
// atEnd: atEnd deletes the node from the end of the linked list.
// atPos p: atPos deletes the node from position p. It takes 1 input after atPos command. Position starts from 0 index.
// Input Commands: 6: "DeleteatBeg", 7: "DeleteatPos", 8: "DeleteatEnd"

// 5. Program is terminated by "Exit" command.

// Input Command Codes: 
// 1: "Create"
// 2: "Print"
// 3: "InsertatBeg"
// 4: "InsertafterPos"
// 5: "InsertatEnd"
// 6: "DeleteatBeg"
// 7: "DeleteatPos"
// 8: "DeleteatEnd"
// 9: "Exit"
// NOTE:Create is called only once at the start of the program
// Print is called only once throughput the program
// Exit is called only once at the end of the program
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
	int data;
	struct Node*next;
}Node;

Node* head = NULL;

void create(){
	head = NULL;
}

void printList(){
	if (head == NULL) {
		printf("NULL\n");
		return;
	}
	Node* temp = head;
	while (temp){
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

void insertAtBeg(int x){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = head;
	head = newNode;
}

void insertAtEnd(int x){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = NULL;
	
	if(head == NULL){
		head = newNode;
		return;
	}
	
	Node* temp = head;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = newNode;
}

void insertAtPos(int x,int pos){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	
	if (pos == 0){
		newNode->next = head;
		head = newNode;
		return;
	}
	
	Node* temp = head;
	for(int i = 0;i < pos-1 && temp;i++){
		temp = temp->next;
	}
	
	if(temp == NULL){
		free(newNode);
		return;
	}
	
	newNode->next = temp->next;
	temp->next = newNode;
}

void deleteAtBeg(){
	if (head == NULL) return;
	Node* temp = head;
	head = head->next;
	free(temp);
}

void deleteAtEnd() {
	if (head == NULL) return;
	if (head->next == NULL){
		free(head);
		head = NULL;
		return;
	}
	
	Node* temp = head;
	while(temp->next->next){
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
}

void deleteAtPos(int pos){
	if (head == NULL) return;
	if (pos == 0){
		deleteAtBeg();
		return;
	}
	
	Node* temp = head;
	for(int i = 0;i < pos-1 && temp->next;i++){
		temp = temp->next;
	}
	if(temp->next == NULL){
		return;
	}
	
	Node* delNode = temp->next;
	temp->next = delNode->next;
	free(delNode);
}

int main(){
	int command, x, p;
	while (1){
		scanf("%d",&command);
		switch (command) {
			case 1: create(); break;
			case 2: printList(); break;
			case 3: scanf("%d",&x); insertAtBeg(x); break;
			case 4: scanf("%d %d",&x, &p); insertAtPos(x, p); break;
			case 5: scanf("%d",&x); insertAtEnd(x); break;
			case 6: deleteAtBeg(); break;
			case 7: scanf("%d", &p); deleteAtPos(p); break;
			case 8: deleteAtEnd(); break;
			case 9: return 0;
		}
	}
	return 0;
}