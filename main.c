#include <stdio.h>
#include <stdlib.h>
#include "getch.h"
#include "execute.h"
#include "menu.h"

#define INPUT_LEN 100

void displayPrompt(char * username, char * hostname, char * pwd) {
  // display pdw
  // [username@hostname pwd]$
  printf("[%s@%s %s]$ ", username, hostname, pwd);
}
int main() {
    char * input = malloc(sizeof(char) * INPUT_LEN);
    char * _USERNAME = "galiba";
    char * _HOSTNAME = "alibaba-host";
    char * _PWD = "/home/galiba/Documents";
    char CharInput1, CharInput2, CharInput3; // like UP and DOWN key
    int result = 0; // $?  last command status
    startingMenu();
    while(1) {
      displayPrompt(_USERNAME, _HOSTNAME, _PWD);
      /* 
	 // https://stackoverflow.com/questions/24708700/c-detect-when-user-presses-arrow-key
	 char c,d,e;
	 c = getch();
	 d = getch();
	 e = getch();
	 // Using 3 char type, Cause up down right left consist with 3 character
	 if ((c==27)&&(d=91)) {
	   if (e==65) { printf("UP");}
	   if (e==66) { printf("DOWN");}
	   if (e==67) { printf("RIGHT");}
           if (e==68) { printf("LEFT");}
	 }
      */
      CharInput1 = getch();
      // Up, Down, Left, Right key
      if (CharInput1 == 27) {
	CharInput2 = getch();
	if (CharInput2 == 91) {
	  CharInput3 = getch();
	  switch(CharInput3) {
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
      } else if (CharInput1 == 0x0A) {
	printf("Pressed Enter key!\n");
      } else {
	/*
	  # Read with spaces in scanf
	  http://www.c4learn.com/c-programming/c-reading-string-with-spaces-scanf/
	  https://stackoverflow.com/questions/13726499/how-can-i-scan-strings-with-spaces-in-them-using-scanf
	*/
	printf("%c", CharInput1);
	scanf("%99[^\n]s", input+1);
	input[0] = CharInput1;
	// Parse input. Check exists 'cd' command in input. and then modify _PWD variable
	// Check exit 
	result = execute(input);
	// Ctrl+L control!
	// Signals control!
      }
    }// while

    free(input);
    return 0;
}
