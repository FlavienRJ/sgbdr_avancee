#ifndef nuplet_helper_h
#define nuplet_helper_h

#include <stdio.h>
#include <stdlib.h>

#include "sgbd.h"

NUPLET newNUPLET(int size);
void set(NUPLET n, int col, int val);
int get(NUPLET n, int col);
void copy(const NUPLET org, NUPLET* cpy);
NUPLET newErrNUPLET(void);
void afficheNUPLET(NUPLET n);

#endif
