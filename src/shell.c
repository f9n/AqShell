/**
 * References:
 *  - https://stackoverflow.com/questions/24708700/c-detect-when-user-presses-arrow-key
 *  - https://academic.evergreen.edu/projects/biophysics/technotes/program/ascii_ctrl.htm
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getch.h"
#include "execute.h"
#include "shell.h"
#include "history.h"

#define ENTER 10
#define BACKSPACE 127
#define HORIZONTAL_TAB 9
#define VERTIVAL_TAB 11
#define CONTROL_L 12
#define CONTROL_C 3
#define CONTROL_D 4

void displayPrompt(char * username, char * hostname, char * pwd) {
  // [username@hostname pwd]$
  printf("[%s@%s %s]$ ", username, hostname, pwd);
}

void getBackInLine(int size) {
  int i;
  for(i = 0; i < size; i++) {
    printf("\b \b");
  }
}
void ShellMenu(void) {
  char * input = malloc(sizeof(char) * INPUT_LEN);
  struct Node* head = NULL;
  struct Node* temp = NULL;
  char * _USERNAME = getenv("USER");
  char * _HOSTNAME = getenv("HOSTNAME");
  char * _PWD = getenv("PWD");
  char CharInput; // like UP and DOWN key
  int result = 0; // $?  last command status
  int index = 0;
  int isDeleted = 1; // 1 is False and 0 is True. isDeleted = deleted shell command status.
  int isPressedUp = 1;
  int isPressedDown = 1;
  /*
		Tasks:
		Parse input. Check exists 'cd' command in input. and then modify _PWD variable
		Parse Pipe(|)
  */
  while(1) {
    if (index == 0 && isDeleted == 1 && isPressedUp == 1 && isPressedDown == 1) {
		    displayPrompt(_USERNAME, _HOSTNAME, _PWD);
    }
    CharInput = getch();
    // Up, Down, Left, Right key
    if (CharInput == 27) {
      CharInput = getch();
      if (CharInput == 91) {
        CharInput = getch();
        switch(CharInput) {
        case 65:
          isPressedUp = 0;
          if (isPressedDown == 0 && temp != NULL) {
            if (temp->next != NULL) {
              temp = temp->next;
              isPressedDown = 1;
            }
          }
          if(head != NULL) {
            memset(input, 0, INPUT_LEN); // set empty
            getBackInLine(index);
            if (temp == NULL) temp = head;
            index = strlen(temp->commandName);
            strcpy(input, temp->commandName);
            printf("%s", input);
            if(temp->next != NULL) {
              temp = temp->next;
            }
          }
          break;

        case 66:
          isPressedDown = 0;
          if (isPressedUp == 0 && temp != NULL) {
            if (temp->prev != NULL) {
              temp = temp->prev;
              isPressedUp = 1;
            }
          }
          if(head != NULL) {
            memset(input, 0, INPUT_LEN); // set empty
            getBackInLine(index);
            if (temp == NULL) {
              index = 0;
            } else {
              index = strlen(temp->commandName);
              strcpy(input, temp->commandName);
              printf("%s", input);
              temp = temp->prev;
            }
          }
          break;

        case 67:
          printf("RIGHT\n");
          break;

        case 68:
          printf("LEFT\n");
          break;

        default :
          printf("Oh no!\n");
        }
      }
    } else if (CharInput == ENTER) {
     //printf("Pressed Enter key!\n");
      printf("\n");
      isDeleted = 1;
      isPressedDown = 1;
      isPressedUp = 1;
      if (index != 0) {
        head = InsertAtHead(head, input);
        //Print(head);
        temp = head;
        result = execute(input);
        index = 0;
        memset(input, 0, INPUT_LEN); // set empty
      }
    } else if (CharInput == BACKSPACE) {
      //printf("Pressed BackSpace\n");
      isDeleted = 0;
      if (index != 0) {
        printf("\b \b");
        index--;
        input[index] = 0;
      } else {
        temp = head;
      }
    } else if (CharInput == HORIZONTAL_TAB || CharInput == VERTIVAL_TAB) { // Horizontal Tab or Vertical Tab
      printf("Pressed Horizontal Tab\n");
    } else if (CharInput == CONTROL_L) {
      system("clear");
    } else if (CharInput == CONTROL_C || CharInput == CONTROL_D) {
      exit(0);
    } else {
      printf("%c", CharInput);
      input[index] = CharInput;
      index++;
    }
  }// while

 free(input);
 FreeContent(head);
 free(head);
}
