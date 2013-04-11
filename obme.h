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


#ifndef __OBME__
#define __OBME__

#include <stdint.h>
#include <string.h>

namespace obme {
    
    typedef uint64_t obme_type;
    extern obme_type *_OBME_MASK;
    
    void obme_init();
    void obme_free();
    
    template <typename T> T OBME(T value)
    {
        // Lazy initialization
        if(_OBME_MASK == NULL)
            obme_init();
        
        
        union {
            T value;
            obme_type integer;
        } reinterpret;
        reinterpret.integer = 0;
        reinterpret.value = value;
        reinterpret.integer ^= *_OBME_MASK;
        
        return reinterpret.value;
    }
    
    char* OBME_D(char *text, int length);
    char* OBME_T(char *text);
}

#endif
