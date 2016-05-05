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
 * MALLOC(pointer, size);
 * CALLOC(pointer, number, size);
 * REALLOC(pointer, size);
 * FREE(pointer);
 * EIF(TRUE);
 * 		if TRUE is 0, exit program.
 * FOPEN(fp, filepath, parameter);
 * 		if the file cannot be opened, exit program.
 */

#define MALLOC(p,s)\
	if( ! ((p) = malloc(s))) {\
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE);\
	}

#define CALLOC(p,n,s)\
	if( ! ((p) = calloc(n, s))) {\
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE);\
 	}

#define REALLOC(p,s)\
	if( ! ((p) = realloc(s))) {\
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE);\
	}

#define FREE(p)\
	if( ! (p) ) {\
		fprintf(stderr, "freeN(): The variable has NULL value. It cannot be free\n");\
	} else {\
		free(p);\
		p = NULL;\
	}\
		
#define EIF(TRUE)\
	if( ! (TRUE) ) {\
		fprintf(stderr, "FALSE!! FALSE!!\n"); \
		exit(EXIT_FAILURE);\
	}
#define FOPEN(fp,path,param)\
	if (! ( (fp) = fopen( (path), (param)))) {\
		fprintf(stderr, "FILE OPERNING FAILURE!\n");\
		exit(EXIT_FAILURE);\
	}

#endif /* errorcheck_h */
