#include <stdio.h>
#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include "execute.h"
#include "parserPipe.h"

pid_t pid = -1 ; //Global

void kill_child(int sig) {
  kill(pid, SIGKILL);
}

int execute(char* command) {
    signal(SIGINT,(void (*)(int))kill_child);
    if (strcmp(command, "exit") == 0) {
      exit(0);
    }
    struct parser parser_result = Parser(command);
    //PrintCommands(parser_result);
    FreeCommandsInParserStruct(parser_result);
    // cd is problem!
    /* fork another process */
    pid = fork();
    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed");
        return 1;
    } else if (pid == 0) { /* child process */
        execlp("/bin/bash", "/bin/bash", "-c", command, NULL);
    } else { /* parent process */
        /* parent will wait for the child */
        wait(NULL);
        return 0;
    }
}
