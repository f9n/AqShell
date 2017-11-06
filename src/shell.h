#ifndef __SHELL_H__
    #define __SHELL_H__

    #define ENTER 10
    #define BACKSPACE 127
    #define HORIZONTAL_TAB 9
    #define VERTIVAL_TAB 11
    #define CONTROL_L 12
    #define CONTROL_C 3
    #define CONTROL_D 4

    #define ANSI_COLOR_RED     "\x1b[31m"
    #define ANSI_COLOR_GREEN   "\x1b[32m"
    #define ANSI_COLOR_YELLOW  "\x1b[33m"
    #define ANSI_COLOR_BLUE    "\x1b[34m"
    #define ANSI_COLOR_MAGENTA "\x1b[35m"
    #define ANSI_COLOR_CYAN    "\x1b[36m"
    #define ANSI_COLOR_RESET   "\x1b[0m"

    void getBackInLine(int size);
    void displayPrompt(char * username, char * hostname, char * pwd);
    void ShellMenu(void);

#endif
