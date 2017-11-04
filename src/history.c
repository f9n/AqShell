#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

struct Node* GetNewNode(char * command) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->commandName = malloc(sizeof(char) * INPUT_LEN);
	 strcpy(newNode->commandName, command);
	 newNode->prev = NULL;
	 newNode->next = NULL;
	 return newNode;
}

struct Node* InsertAtHead(struct Node* head, char * input) {
  struct Node* newNode = GetNewNode(input);
	 if(head == NULL) {
		  return newNode;
	 }
	 head->prev = newNode;
	 newNode->next = head; 
	 head = newNode;
	 return head;
}

void Print(struct Node* head) {
  struct Node* temp = head;
  while(temp != NULL) {
    printf("%s\n",temp->commandName);
    temp = temp->next;
  }
  printf("\n");
}

void FreeContent(struct Node* head) {
  struct Node* temp = head;
	 struct Node* temp2 = NULL;
	 while(temp != NULL) {
	   temp2 = temp;
	   temp = temp->next;
	   free(temp2);
  }
}