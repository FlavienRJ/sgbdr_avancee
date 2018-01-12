#ifndef relation_helper_h
#define relation_helper_h

#include <stdio.h>
#include "nuplet_helper.h"

RELATION newRELATION(int attsize, int maxsize);
int compatible(RELATION r, NUPLET n);
void insert(RELATION* r, NUPLET n);
void insertPos(RELATION* r, NUPLET n, int pos);
NUPLET getNUPLET(RELATION r, int ligne);
int findNuplet(const RELATION r, const int* att);
void afficheRELATION(RELATION r);
NUPLET fullscanNext(const RELATION r, const char* name);

#endif
