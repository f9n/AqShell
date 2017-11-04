#ifndef __HISTORY_H__
  #define __HISTORY_H__

  #define INPUT_LEN 100
  struct Node  {
    char * commandName;
    struct Node* next;
    struct Node* prev;
  };
  struct Node* GetNewNode(char * command);
  struct Node* InsertAtHead(struct Node * head, char * input);
  void Print(struct Node * head);
#endif