#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

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
    int result = execute("ls -la");
    printf("%d\n", result);
    return 0;
}
