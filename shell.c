/**
 * References:
 * 	- https://stackoverflow.com/questions/24708700/c-detect-when-user-presses-arrow-key
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getch.h"
#include "execute.h"
#include "shell.h"

#define INPUT_LEN 100
#define ENTER 10
#define BACKSPACE 127
#define HORIZONTAL_TAB 9
#define VERTIVAL_TAB 11

void displayPrompt(char * username, char * hostname, char * pwd) {
  // display pdw
  // [username@hostname pwd]$
  printf("[%s@%s %s]$ ", username, hostname, pwd);
}

void ShellMenu(void) {
  char * input = malloc(sizeof(char) * INPUT_LEN);
  char * _USERNAME = getenv("USER");
  char * _HOSTNAME = getenv("HOSTNAME");
  char * _PWD = getenv("PWD");
  char CharInput; // like UP and DOWN key
  int result = 0; // $?  last command status
  int index = 0;
  int isDeleted = 1; // 1 is False and 0 is True. isDeleted = deleted shell command status.
  /*
	Tasks:
		Parse input. Check exists 'cd' command in input. and then modify _PWD variable
		Check exit 
		Ctrl+L control!
		Signals control! like Ctrl+C and Ctrl+D
  */
  while(1) {
	if (index == 0 && isDeleted == 1) {
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
				printf("UP\n");
				break;

			case 66:
				printf("DOWN\n");
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
		if (index != 0) {
			//SaveCommandToHistory(input);
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
		}
    } else if (CharInput == HORIZONTAL_TAB || CharInput == VERTIVAL_TAB) { // Horizontal Tab or Vertical Tab
		printf("Pressed Horizontal Tab\n");
    } else {
		printf("%c", CharInput);
		input[index] = CharInput;
		index++;
    }
  }// while

  free(input);
}
