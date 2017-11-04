#ifndef __GETCH_H__
    #define __GETCH_H__
    /*
        # getch() and getche() in linux
        https://stackoverflow.com/questions/3276546/how-to-implement-getch-function-of-c-in-linux
    */
    
    /* Initialize new terminal i/o settings */
    void initTermios(int echo);

    /* Restore old terminal i/o settings */
    void resetTermios(void);

    /* Read 1 character - echo defines echo mode */
    char getch_(int echo);

    /* Read 1 character without echo */
    char getch(void);

    /* Read 1 character with echo */
    char getche(void);
#endif
