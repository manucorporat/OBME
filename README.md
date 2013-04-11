OBME: OBFuscated MEmory
====
####Fast and easy to use tool in simple C++ to avoid memory cheating by scanning (searching). See [igameguardian](http://gameguardian.net/forum/files/file/85-igameguardian/), "Cheat Engine"...


***What is memory cheating by scanning?***

Well, it's a cheating method that access to the RAM of your app/game searching patterns. Common cheating tools like this are able to find Int8, Int16, Int32 and Float32 types easily and modify them.

***IDEA: Modify the variable that stores the gameplay's score.***

1. If in t=0, the score is 50, the cheater will search that value in the game's RAM.
2. Surely there are thousand of variables with that value, so he comes back to the game and change the score to 75 (for example, he kills a new buddy)
3. He performs a new filter and he gets the pointer that changed from 50 to 75, and bingo!!! he knows the address of the score's variable.
4. Now he can change it.

---

At initialization, OBME generates a 64bits cryptographically secure pseudorandom number stored in the heap as "mask".

OBME's API:

```C
	template <typename T> T OBME( T value <any primitive type> )
	char* OBME_T( char* value <c-array text> )
```


**USAGE: with integers.**

```
    int64_t value = 444535345454;
    printf("\n64bits INTEGER TEST\n");
    printf("Original value: %lld \n", value);
    value = OBME(value);
	printf("Obfuscated value: %lld \n", value);
    value = OBME(value);
    printf("Restored value: %lld \n", value);
```

Output:

```
64bits INTEGER TEST
Original value: 444535345454 
Obfuscated value: 7095209165337824491 
Restored value: 444535345454 
```

------
**PRACTICAL USAGE: with floats**

```
float _score; 
init {
    _score = OBME( 0.0f )
}

addToScore(float add) {
   _score = OBME( OBME(score) + add )
}
```
Real values are never exposed.