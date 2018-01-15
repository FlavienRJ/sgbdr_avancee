//
//  indexation.h
//  sgbd_frj
//
//  Created by Flavien Ronteix--jacquet on 14/01/2018.
//  Copyright © 2018 frj. All rights reserved.
//

#ifndef indexation_h
#define indexation_h

#include <stdio.h>
#include <stdlib.h>
#include "sgbd.h"
#include "nuplet_helper.h"

RELATION_INDEX convertToIndex(const RELATION org);
NUPLET convertToNuplet(const NUPLET_INDEX org);

#endif /* indexation_h */
