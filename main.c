#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

void startingMenu() {
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

int execute(char* string) {
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

int main() {
    char input[100];
    startingMenu();
    printf("> ");
    scanf("%s", &input);
    printf("%s\n", input);
    /*
    int result = execute("ls -la");
    printf("%d\n", result);
    */
    return 0;
}
