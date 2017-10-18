#ifndef TLPI_HDR_H
#define TLPI_HDR_H

#include <sys/types.h> //Types definitions used by many programs
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Prototypes for many system calss
#include <errno.h> //Declares errno and defines error constants
#include <string.h> //Commonly used by string-handling functions

#include "get_num.h" //Declares our functions for handling numeric argument 
#include "err_functions.h"//Declares our error-handling functions

typedef enum {FALSE,TRUE} Boolean;

#define min(m,n) ((m) < (n) ? (m) : (n))
#define max(m,n) ((m) > (n) ? (m) : (n))

#endif
