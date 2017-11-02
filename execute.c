#include <stdio.h>
#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include "execute.h"

int execute(char* string) {
   // concat 2 string.
   // First string is "cd Pwd";
   // Second string is "ls -la"; 
    pid_t pid;
    /* fork another process */
    pid = fork();
    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed");
        return 1;
    } else if (pid == 0) { /* child process */
        execlp("/bin/bash", "/bin/bash", "-c", string, NULL);
    } else { /* parent process */
        /* parent will wait for the child */
        wait(NULL);
        return 0;
    }
}
