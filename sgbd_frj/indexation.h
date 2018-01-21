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

/** 
 * @brief  Convertie une relation en relation indexée
 * @note   
 * @param  org: la relation originale
 * @retval la même relation mais avec un index sur les NUPLET
 */
RELATION_INDEX convertToIndex(const RELATION org);

/** 
 * @brief  convertie un NUPLET en NUPLET avec numero d'index
 * @note   
 * @param  org: le NUPLET originale
 * @retval la NUPLET convertie
 */
NUPLET convertToNuplet(const NUPLET_INDEX org);

#endif /* indexation_h */
