//
//  test.cpp
//  OBME: OBfuscated MEmory
//
//  Created by Manuel Martinez-Almeida on 04/10/13.
//  Copyright 2013 Manuel Martinez-Almeida. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "obme.h"

using namespace obme;

static float _score;

void addScore(float add)
{
    _score = OBME(OBME(_score) + add);
    printf("Adding %f\n",add);
    printf("Value in memory: %f\n\n", _score);
}


int main()
{
    _score = OBME(0.0f);
    addScore(100);
    addScore(110);
    addScore(210);
    
    printf("0+100+110+210 = 420\n");
    printf("Print score: %f\n", OBME(_score));
    
    return 1;
}
