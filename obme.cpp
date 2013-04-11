/*
 * OBME: OBfuscated MEmory
 *
 * Copyright (c) 2011-2013 FORZEFIELD Studios S.L.
 * Copyright (c) 2013 Manuel Martínez-Almeida
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "obme.h"

#ifdef __cplusplus
extern "C" {
#include "mersenne/mt64.h"
}
#else
#include "mersenne/mt64.h"
#endif

namespace obme {
    obme_type* _OBME_MASK = NULL;
    
    void obme_init()
    {
        // Init random generator
        init_genrand64(time(NULL));
        
        // Allocates the mask in the heap because of security reasons.
        _OBME_MASK = (obme_type*)malloc(sizeof(obme_type));
        *_OBME_MASK = 0;
        
        do {
            *_OBME_MASK = genrand64_int64();
            
        // almost impossible, 5.42 * 10^-20
        } while(*_OBME_MASK == 0);
        
        // printf("%llX\n", *_OBME_MASK);
    }
    
    
    void obme_free()
    {
        if(_OBME_MASK != NULL) {
            free(_OBME_MASK);
            _OBME_MASK = NULL;
        }
    }
    
    
    char* OBME_D(char *data, int length)
    {
        while(length > 1) {
            --length;
            data[length] = OBME(data[length]);
        }
        return data;
    }
    
    
    char* OBME_T(char *text)
    {
        return OBME_D(text, strlen(text));
    }
}
