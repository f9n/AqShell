#include <termios.h>
#include <stdio.h>
#include "getch.h"

/*
  # getch() and getche() in linux
  https://stackoverflow.com/questions/3276546/how-to-implement-getch-function-of-c-in-linux
*/

static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo) {
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) {
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) {
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) {
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) {
  return getch_(1);
}


/*
 # Without Pressing Enter, for history
 https://stackoverflow.com/questions/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed
 http://www.it.iitb.ac.in/frg/wiki/images/3/38/P13324_Sandeep_Prasad_Week_3_Report_6_Input_Without_Pressing_Enter.pdf
 https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1045691686&id=1043284392/
 */
/*
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
*/
