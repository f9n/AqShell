#ifndef __PARSER_PIPE_H__
    #define __PARSER_PIPE_H__

    #define MAX_SIZE 10

    struct parser {
        unsigned int commandsize;
        char ** commands;
    }; 

    struct parser Parser(char * command);
    void FreeCommandsInParserStruct(struct parser n);
    char * trim (char * s);
    void PrintCommands(struct parser n);
#endif