//
//  errorcheck.h
//
//  Created by Kim, Myeong-jae on 4/29/16.
//  Copyright © 2016 KimMyeong-jae. All rights reserved.
//

#ifndef errorcheck_h
#define errorcheck_h
#include <stdlib.h>

/* Error Checking Macro *
 *
 * ERROR_MSG(msg);
 * MALLOC(pointer, size);
 * CALLOC(pointer, number, size);
 * REALLOC(pointer, size);
 * FREE(pointer);
 * EIF(TRUE);
 * 		if TRUE is 0, exit program.
 * EIN(TRUE);
 * 		if TRUE is NULL, exit program.
 * FOPEN(fp, filepath, parameter);
 * 		if the file cannot be opened, exit program.
 * SWAP(x, y, temp);
 * 		swap x and y.
 */

#define ERROR_MSG(msg) fprintf(stderr, "ERROR: %s\n", msg)
#define MEM_ERR "INSUFFICIENT MEMORY\n"

#define MALLOC(p,s)\
	if( ! ((p) = malloc(s))) {\
		ERROR_MSG(MEM_ERR); \
		exit(EXIT_FAILURE);\
	}

#define CALLOC(p,n,s)\
	if( ! ((p) = calloc(n, s))) {\
		ERROR_MSG(MEM_ERR); \
		exit(EXIT_FAILURE);\
 	}

#define REALLOC(p,s)\
	if( ! ((p) = realloc(s))) {\
		ERROR_MSG(MEM_ERR); \
		exit(EXIT_FAILURE);\
	}

#define FREE(p)\
	if( ! (p) ) {\
		ERROR_MSG("freeN(): The variable has NULL value. It cannot be free\n");\
	} else {\
		free(p);\
		p = NULL;\
	}\
		
#define EIF(TRUE)\
	if( ! (TRUE) ) {\
		ERROR_MSG("FALSE FALSE!\n"); \
		exit(EXIT_FAILURE);\
	}
#define EIN(TRUE)\
	if( ! (TRUE) ) {\
		ERROR_MSG("NULL ADDRESS\n"); \
		exit(EXIT_FAILURE);\
	}
#define FOPEN(fp,path,param)\
	if (! ( (fp) = fopen((path), (param)))) {\
		ERROR_MSG("FILE OPERNING FAILURE\n");\
		exit(EXIT_FAILURE);\
	}
#define SWAP(x,y,temp) ((temp) = (x), (x) = (y), (y) = (temp))

#endif /* errorcheck_h */
