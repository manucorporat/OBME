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
	long long i = -1000;
	for(; i < 1000; ++i) {
		long long obf = OBME(i);
		printf("%lld: %lld \n", OBME(obf), obf);
	}
	
	return 1;
}
