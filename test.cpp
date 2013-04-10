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

void testInt32Bits()
{
    int32_t value = 10;

    printf("\n32bits INTEGER TEST\n");
    printf("Original value: %d \n", value);
    value = OBME(value);
	printf("Obfuscated value: %d \n", value);
    value = OBME(value);
	printf("Restored value: %d \n", value);
}

void testInt64Bits()
{
    int64_t value = 444535345454;
    
    printf("\n64bits INTEGER TEST\n");
    printf("Original value: %lld \n", value);
    value = OBME(value);
	printf("Obfuscated value: %lld \n", value);
    value = OBME(value);
	printf("Restored value: %lld \n", value);
}

void testFloat32Bits()
{
    float value = 34.3253f;
    
    printf("\n32bits FLOAT TEST\n");
    printf("Original value: %f \n", value);
    value = OBME(value);
	printf("Obfuscated value: %f \n", value);
    value = OBME(value);
	printf("Restored value: %f \n", value);
}

void testFloat64Bits()
{
    double value = 2342.785643;
    
    printf("\n64bits DOUBLE TEST\n");
    printf("Original value: %f \n", value);
    value = OBME(value);
	printf("Obfuscated value: %f \n", value);
    value = OBME(value);
	printf("Restored value: %f \n", value);
}



int main()
{
    testInt32Bits();
    testInt64Bits();
    testFloat32Bits();
    testFloat64Bits();
    
    char text[100];
    strcpy(text, "hey Lou, how are you?");
    printf("f: %s \n", text);
    OBME_T(text);
    printf("f: %s \n", text);
    OBME_T(text);
    printf("f: %s \n", text);
    
    return 1;
}
