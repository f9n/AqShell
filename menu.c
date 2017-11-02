#include <stdio.h>
#include <stdlib.h> // system warning
#include <string.h>
#include <ctype.h> // isupper, tolower, toupper warning
#include <unistd.h> // usleep warning
#include "menu.h"

void startingMenu(void) {
    char* starting = "Starting the Project";
    char starting2[20];
    char ch, buff;
    for(int i=1; i < 5; i++) {
      int j = 1;
      while(j < 20) {
        strcpy(starting2, starting);
        if(isupper(starting2[j])) {
            buff = tolower(starting2[j]);
        } else {
            buff = toupper(starting2[j]);
        }
        starting2[j] = buff;
        switch(j % 3) {
        case 0: ch = '/'; break;
        case 1: ch = '-'; break;
        case 2: ch = '\\';break;
        }
        system("clear");
        printf("[+] %s ... %c\n", starting2, ch);
        usleep(50 * 1000);
        j += 1;
      }
  }
}
