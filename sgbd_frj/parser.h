#ifndef parser_h
#define parser_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>
#include <stdio.h>
#include <ctype.h>

#include "sgbd.h"
#include "operateurs.h"
#include "nuplet_helper.h"
#include "relation_helper.h"
#include "iohelper.h"

void filter(char* src);
RELATION parser(int argc, char **argv, BDD* bdd);
RELATION stR(char* s, BDD* bdd);

#endif /* parser_h */

