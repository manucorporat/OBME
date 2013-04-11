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
int main()
{
    char text[100];
    strcpy(text, "hey Lou, how are you?");
    printf("Original: %s \n", text);
    OBME_T(text);
    
    printf("Obfuscated: %s \n", text);
    OBME_T(text);
    printf("Restored: %s \n", text);
    
    return 1;
}
