#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <termios.h>

#define INPUT_LEN 100

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

/*
 # Without Pressing Enter, for history
 https://stackoverflow.com/questions/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed
 http://www.it.iitb.ac.in/frg/wiki/images/3/38/P13324_Sandeep_Prasad_Week_3_Report_6_Input_Without_Pressing_Enter.pdf
 https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1045691686&id=1043284392/
 */
 char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
            perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
            perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
            perror ("tcsetattr ~ICANON");
    return (buf);
}

int main() {
    char * input = malloc(sizeof(char) * INPUT_LEN);
    // startingMenu();
    char first = getch();
    printf("%c > ", first);
    /*
        # Read with spaces in scanf
        http://www.c4learn.com/c-programming/c-reading-string-with-spaces-scanf/
        https://stackoverflow.com/questions/13726499/how-can-i-scan-strings-with-spaces-in-them-using-scanf
    */
    scanf("%99[^\n]s", input+1);
    input[0] = first;
    printf("%s\n", input);
    int result = execute(input);
    printf("%d\n", result);

    free(input);
    return 0;
}
