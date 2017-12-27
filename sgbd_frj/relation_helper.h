#ifndef relation_helper_h
#define relation_helper_h

#include <stdio.h>
#include "nuplet_helper.h"

RELATION newRELATION(int attsize, int maxsize);
int compatible(RELATION r, NUPLET n);
void insert(RELATION* r, NUPLET n);
NUPLET getNUPLET(RELATION r, int ligne);
void afficheRELATION(RELATION r);

#endif