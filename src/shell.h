#ifndef __SHELL_H__
    #define __SHELL_H__

    #define ENTER 10
    #define BACKSPACE 127
    #define HORIZONTAL_TAB 9
    #define VERTIVAL_TAB 11
    #define CONTROL_L 12
    #define CONTROL_C 3
    #define CONTROL_D 4

    void getBackInLine(int size);
    void displayPrompt(char * username, char * hostname, char * pwd);
    void ShellMenu(void);

#endif
