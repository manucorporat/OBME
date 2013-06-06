OBME: OBfuscated MEmory
====
**Fast and easy to use tool in simple C++ to avoid memory cheating by scanning (searching). See [igameguardian](http://gameguardian.net/forum/files/file/85-igameguardian/), "Cheat Engine"…**


##What is memory cheating by scanning?

Well, it's a cheating method that access to the physical memory of an app/game searching patterns. Common cheating tools like this are able to find Int8, Int16, Int32 and Float32 types easily and modify them.

####IDEA: Modify the variable that stores the gameplay's score.

1. If in t=0, the score is 50, the cheater will search that value in the game's RAM.
2. Surely there are thousand of variables with that value, so he comes back to the game and change the score to 75 (for example, he kills a new buddy)
3. He performs a new filter and he gets the pointer that changed from 50 to 75, and bingo!!! he knows the address of the score's variable.
4. Now he can change it.

##How does OBME work?

1. A 64bits cryptographic pseudorandom number is generated and stored as the "mask".
2. OBME(T variable) returns a xor function applied to the bits of "variable".  

	```cpp
return (variable ^ mask);
```


##API

```cpp
template <typename T> T OBME( T value <any primitive type> )
char* OBME_T( char* value <c-array text> )
```


##Usage

###With integers:

```cpp
int64_t value = 100;
printf("Original value: %lld \n", value);

value = OBME(value);
printf("Obfuscated value: %lld \n", value);

value = OBME(value);
printf("Restored value: %lld \n", value);
```

Output:

```
Original value: 100 
Obfuscated value: 7095209165337824491 
Restored value: 100 
```
The obfuscated values change each time the app is started, this is because they are generated using a random generated mask of bits.

###Any Type:
```cpp
int64_t value64 = 1;
uint32_t value32 = -2;
int8_t value8 = 3;
float valueF = 4.4f;
double valueD = 5.2f;

// Obfuscating values
value64	= OBME(value64);
value32	= OBME(value32);
value8	= OBME(value8);
valueF	= OBME(valueF);
valueD	= OBME(valueD);

// Restoring values
value64	= OBME(value64);
value32	= OBME(value32);
value8	= OBME(value8);
valueF	= OBME(valueF);
valueD	= OBME(valueD);
```

###Practicar usage:

```cpp
float _score; 
void init() {
    _score = OBME( 0.0f );
    
    addToScore(10);
    addToScore(25);
    
    printScore(); // prints "The score is 35"
    printf("%d\n", _score); // prints a random number
}

void addToScore(float add) {
   _score = OBME( OBME(_score) + add );
}

void printScore() {
	printf(@"The score is: %d \n", OBME(_score));
}
```

Real values are never exposed.
