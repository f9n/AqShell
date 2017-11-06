/**
 * References:
 *  - https://cboard.cprogramming.com/c-programming/31839-trim-string-function-code.html
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parserPipe.h"

struct parser Parser(char * command) {
    struct parser cs;
    int i, k = 0, j = 0;
    int commandsize = 1;
    char ** commands = malloc(commandsize * sizeof(char*));
    char * buffer = malloc(MAX_SIZE * sizeof(char));
    for (i = 0; i < strlen(command); i++) {
        //printf("%c\n", command[i]);
        if (command[i] == '|' && command[i+1] != '|') {
            //printf("%s|\n", buffer);
            if (command[i-1] == ' ') k--;
            if (command[i+1] == ' ') i++;
            commandsize++;
            commands = realloc(commands, commandsize * sizeof(char*));
            commands[j] = malloc(k * sizeof(char));
            buffer = trim(buffer);
            strncpy(commands[j], buffer, k);
            memset(buffer, 0, MAX_SIZE);
            j++;
            k = 0;
        }
        buffer[k] = command[i];
        k++;
    }
    buffer = trim(buffer);
    commands[j] = malloc(k * sizeof(char));
    strncpy(commands[j], buffer, k);
    free(buffer);
    cs.commandsize = commandsize;
    cs.commands = commands;
    return cs;
}

void FreeCommandsInParserStruct(struct parser n) {
    int i;
    for(i = 0; i < n.commandsize; i++) {
        free(n.commands[i]);
    }
}

void PrintCommands(struct parser n) {
    int i;
    for(i = 0; i < n.commandsize; i++) {
        printf("%s\n", n.commands[i]);
    }
}

char* trim (char *s) {
  int i = 0;
  int j = strlen(s) - 1;
  int k = 0;
  while (isspace(s[i]) && s[i] != '\0' )
    i++;
  while (isspace(s[j]) && j >= 0 )
    j--;
  while (i <= j)
    s[k++] = s[i++];
 
  s[k] = '\0';
  return s;
}