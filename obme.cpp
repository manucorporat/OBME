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

#include <stdlib.h>
#include "obme.h"
#include "mersenne/mersenne.h"

namespace obme {
    obme_type* _OBME_MASK = NULL;
    
    void obme_init()
    {
        // Allocates the mask in the heap because of security reasons.
        _OBME_MASK = (obme_type*)malloc(sizeof(obme_type));
        
        int a = ms_rand();
#if OBME_64BITS
        int b = ms_rand();
        
        // Create 64bits random numbers using two 32bits numbers.
        *_OBME_MASK = 0;
        *_OBME_MASK = a;
        *_OBME_MASK <<= 32;
        *_OBME_MASK |= b;
#else
        *_OBME_MASK = a;
#endif
    }
    
    
    void obme_free()
    {
        if(_OBME_MASK != NULL) {
            free(_OBME_MASK);
            _OBME_MASK = NULL;
        }
    }
    
    
    char* OBME_T(char *text)
    {
        char *c = text;
        while(*c != '\0') {
            *c = OBME(*c);
            ++c;
        }
        return text;
    }
}
