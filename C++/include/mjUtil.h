#ifndef mjUtil_h
#define mjUtil_h
#include <cstdlib>

/* Utility Macro *
 *
 * ANSI color supported.
 *
 * ERROR_MSG(msg);
 * FREE(pointer);
 * EIF(TRUE);
 *          if TRUE is 0, exit program.
 * EIN(TRUE);
 *          if TRUE is NULL, exit program.
 * FOPEN(fp, filepath, parameter);
 *          if the file cannot be opened, exit program.
 * ARG_CHECK(number);
 *          if argc != number, print error message and exit program.
 * FLUSH();
 *          flush stdin.
 *
 */

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"

#define ERROR_MSG(msg) fprintf(stderr, ANSI_COLOR_RED "\tERROR: " ANSI_COLOR_YELLOW "%s" ANSI_COLOR_RESET, msg)
#define MEM_ERR "INSUFFICIENT MEMORY\n"

#define FREE(p)\
    do{\
        if( ! (p) ) {\
            ERROR_MSG("free(): The variable has NULL value. It cannot be free.\n");\
        } else {\
            free(p);\
            p = nullptr;\
        }\
    }while(0)
        
#define EIF(TRUE)\
    do{\
        if( ! (TRUE) ) {\
            ERROR_MSG("FALSE FALSE!\n"); \
            exit(EXIT_FAILURE);\
        }\
    }while(0)

#define EIN(TRUE)\
    do {\
        if( ! (TRUE) ) {\
            ERROR_MSG("NULL ADDRESS\n"); \
            exit(EXIT_FAILURE);\
        }\
    }while(0)

#define FOPEN(fp,path,param)\
    do{\
        if (! ( (fp) = fopen((path), (param)))) {\
            ERROR_MSG("FILE OPERNING FAILURE\n");\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

#define ARG_CHECK(number)\
    do{\
        if( (argc) != (number) )\
        {\
            ERROR_MSG("CHECK COMMAND LINE ARGUMENTS.\n");\
            ERROR_MSG("ARGUMENT COUNTER SHOULD BE "); fprintf(stderr, ANSI_COLOR_CYAN "%d.\n" ANSI_COLOR_RESET, number);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

#define FLUSH()\
    do{\
        char CBUFF_FOR_FLUSHING = 0;\
        while((CBUFF_FOR_FLUSHING = getchar()) != '\n' && CBUFF_FOR_FLUSHING != EOF);\
    }while(0)

#endif /* mjUtil_h */
