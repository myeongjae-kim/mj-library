//
//  mjCUtil.h
//  Created by Kim, Myeong-jae on 4/29/16.
//

#ifndef mjCUtil_h
#define mjCUtil_h
#include <stdlib.h>

typedef enum mjBool { false, true } bool; // this is an alternative way for including stdbool.h
// #include <stdbool.h>

/* Below is the codes in stdbool.h
 * #define bool _Bool
 * #define true 1
 * #define false 0  */

/* Error Checking Macro *
 *
 * DoNothing();
 *          Literally do nothing. It is used in empty while loop.
 * ERROR_MSG( msg );
 * MALLOC( pointer, size );
 * CALLOC( pointer, number, size );
 * REALLOC( pointer, size );
 * FREE( pointer );
 * EIF( variable );
 *          if variable is false, exit program.
 * EIN( variable );
 *          if variable is NULL, exit program.
 * FOPEN( fp, filepath, parameter );
 *          if the file cannot be opened, exit program.
 * SWAP( x, y, temp );
 *          swap x and y.
 * ARG_CHECK( number );
 *          if argc != number, print error message and exit program.
 * FLUSH();
 *          flush stdin.
 */

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"

#define DoNothing()

#define ERROR_MSG( msg ) fprintf( stderr, ANSI_COLOR_RED "\tERROR: "ANSI_COLOR_YELLOW"%s" ANSI_COLOR_RESET, msg )
#define MEM_ERR "INSUFFICIENT MEMORY\n"

#define MALLOC( p, s )\
    do {\
        if ( ( (p) = malloc(s) ) == (NULL) ) {\
            ERROR_MSG( MEM_ERR ); \
            exit( EXIT_FAILURE );\
        }\
    } while ( false )

#define CALLOC( p, n, s )\
    do {\
        if ( ( (p) = calloc(n, s) ) == (NULL) ) {\
            ERROR_MSG( MEM_ERR ); \
            exit( EXIT_FAILURE );\
        }\
    } while ( false )

#define REALLOC( p, s )\
    do {\
        p = realloc( p, s );\
        if ( (p) == (NULL) ) {\
            ERROR_MSG( MEM_ERR ); \
            exit( EXIT_FAILURE );\
        }\
    } while ( false )

#define FREE( p )\
    do {\
        if ( (p) == (NULL) ) {\
            ERROR_MSG( "free(): The variable has NULL value. It cannot be free.\n" );\
        } else {\
            free( p );\
            p = NULL;\
        }\
    } while ( false )
        
#define EIF( variableIsTrue )\
    do {\
        if( (variableIsTrue) == (false) ) {\
            ERROR_MSG( "FALSE FALSE!\n" ); \
            exit( EXIT_FAILURE );\
        }\
    } while ( false )

#define EIN( variableHasValue )\
    do {\
        if( (variableHasValue) == (NULL) ) {\
            ERROR_MSG( "NULL ADDRESS\n" ); \
            exit( EXIT_FAILURE );\
        }\
    } while ( false )

#define FOPEN( fp, path, param )\
    do{\
        if ( ( (fp) = fopen( (path), (param) ) )  == (NULL) )  {\
            ERROR_MSG( "FILE OPERNING FAILURE\n" );\
            exit( EXIT_FAILURE );\
        }\
    } while ( false )

#define SWAP( x, y, temp ) ( (temp) = (x), (x) = (y), (y) = (temp) )

#define ARG_CHECK( number )\
    do{\
        if( (argc) != (number) )\
        {\
            ERROR_MSG( "CHECK COMMAND LINE ARGUMENTS.\n" );\
            ERROR_MSG( "ARGUMENT COUNTER SHOULD BE " ); fprintf( stderr, ANSI_COLOR_CYAN "%d.\n"ANSI_COLOR_RESET, number );\
            exit( EXIT_FAILURE );\
        }\
    } while ( false )

#define FLUSH()\
    do{\
        char CBUFF_FOR_FLUSHING = '\0';\
        while ( ( ( (CBUFF_FOR_FLUSHING) = getchar() ) != ('\n') ) && ( (c) != (EOF) ) );\
    } while ( false )
#endif /* mjCUtil_h */
