//
//  journalisation.h
//  sgbd_frj
//
//  Created by Flavien Ronteix--jacquet on 13/01/2018.
//  Copyright © 2018 frj. All rights reserved.
//

#ifndef journalisation_h
#define journalisation_h

#include <stdio.h>
#include <stdlib.h>
#include "sgbd.h"

JOURNAL openLog(const char* path);
int logNewCommand(JOURNAL* log, const char* command);
int closeLog(JOURNAL log);

#endif /* journalisation_h */
