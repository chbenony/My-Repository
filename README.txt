STRING.H
---------------------------------------

size_t String_ChrLen(char*)
	-Returns the length of the character
	-Will count the number of characters until the null terminator ('\0')
	 is reached.

int String_EqualLen(String*, String*)
	-Calculates whether two strings are of equal length
	-Returns 1 (TRUE) or 0 (FALSE)


int String_New(String*, char*)
	-Gives a new string
	-If there is no memory available to be allocated, the function returns 0 (FALSE)
	-Else, it allocates memory, initialized the length of the String object, and returns 1 (TRUE)/

int String_Equal(String*, String*)
	-allocates memory for the first and second strings
	-if these two String objects are equal, the program returns 1 (TRUE)
	-if these two String objects are not equal, the program returns (FALSE)

void String_Delete(String*)
	-Deallocates the string
	-Frees the string while resetting every value in the String Object to 0

char* String_Get
	-returns the contents of the String Object
	-returns 0 (FALSE) if the String Object is empty

int String_Append
	-Appends an array of characters to the String Object
	-reallocates the memory to accomodate this array

void String_Free(String *)
	-Deallocates the String Object
	-(See String_Delete for more information)

char String_GetChar(const String *,const size_t)
	-returns a character at the specified index
	-returns NULL if a character is not found.

void String_SetChar(String *strObj,const size_t index, const char c)
	-sets a character to the string
	-Returns NULL if the size of the String Object is too small

String * String_Cpy ( String *, const String * )
	-Copies a string object to the destination String Object

String * String_nCpy ( String * , const String * , size_t)
	-Copies a number of characters to the source array 
	-If the source array is too small, the function returns 0 (FALSE)
	-else, the function returns the source array.

String * String_Cat ( String *, const String * )
	-Appends the null-terminated string pointed to by source to the null-terminated string pointed to by destination.
	-Source and destination may not overlap.

String * String_nCat ( String * , const String * , size_t )
	-Appends not more than n characters (a null character that follows it is not appended) from the array pointed to by source to the end of the string pointed to by destination
	-Source and destination may not overlap.

int String_Cmp ( const String * , const String *)
	-compares the String Object pointed to by string 1 to the string pointed to by string 2
	-returns 0 (EQUAL TO), 1 (GREATER THAN), or -1 (LESS THAN)

int String_nCmp ( const String * , const String * , size_t)
	-Compaeres up to n characters of the string pointed to by s1 to the string pointed to by s2.
	-returns 0 (EQUAL TO), 1 (GREATER THAN), or -1 (LESS THAN)

String * String_Chr (String * str, int character )
	-Locates the first occurence of c (concerted to a character) in the string pointed to by the String Object
	-returns a pointer to the lcoated character
	-if the character does not occur, the function returns NULL

size_t String_cSpn ( const String * str1, const String * str2 )
	-Computes the length of the maximum initial segment of the string pointed to by string 1 which consists of characters not from the string pointed to string 2
	-returns the length of the segment

String * String_pBrk (const String * str1, const String * str2 )
	-Locates the first occurance in the string pointed to by String Object 1 of any character String object pointed to by string 2
	-returns a pointer to the character
	-if no character from String Object 1 occurs in String Object 2, it returns NULL

String * String_rChr (const String * , int  )
	-Locates the last occurence of c (concerted to a char) in the String Object
	-returns a pointer to  the located character
	-if the character does not occur in the string object, it returns NULL

size_t String_spn ( const String * , const String *  )
	-Computes the maximum initial segment of the string pointed to by String Object 1 which consists of characters from the string pointed to by String Object 2
	-The strspn() function returns the length of the segment.

String * String_Str (String * , const String * )
	-The strstr() function locates the ﬁrst occurrence in the string pointed to by s1 of the sequence of characters (excluding the terminating null character) in the string pointed to by s2.
	-The strstr function returns a pointer to the located string, or a null pointer if the string is not found. If s2 points to a string with zero length, the function returns s1.

size_t String_Len ( const String * )
	-The strlen() function shall compute the number of bytes in the string to which s points, not including the terminating null byte.

size_t String_GetHashCode(const String * )
	-retrieves the hashcode of the characters of the String Object

size_t String_CreateHash(const char *)
	-creates the hashcode of the characters of the String Object

String * String_Trim(String * str)
	-trims whitespace of the characters of the String Object
	-if there is no whitespace to be trimmed, then it returns the String Object

String * String_LTrim(String * str)
	-trims the whitespace to the left of the String Object

String * String_RTrim(String * str)
	-trims the whitespace to the right of the String Object

char String_GetCharFromIndex(const String * str, int index)
	-retrieves the character from the index specified
	-if the character does not exist, returns NULL

int String_IndexOfChar(const String * str, char c)
	-returns the index of the specified character
	-if the character is not found, return 0 (FALSE)

String * String_Lower(String * str)
	-reverts a String Object from UPPERCASE LETTERS to lowercase letters

String * String_Upper(String * str)
	-reverts a String Object from lowercase letters to UPPERCASE LETTERS

String * String_Reverse(String * str)
	-reverses a String Object
	-if a String Object is reversed, it reverts the string back to its original position

size_t String_WordCount(const String * str)
	-counts how many words are in a String Object
	
-------------------------------------------------------------------------
-------------------------------------------------------------------------

ARRAYLIST.H
---------------------------------------

boolean ArrayList_New(ArrayList * list)
	-specifies a new ArrayList object

boolean ArrayList_Expand(ArrayList * list)
	-checks to see if an ArrayList object can be expanded
	-expands the size of the ArrayList if possible

boolean ArrayList_Add(ArrayList * list, void * item)
	-adds an item to the ArrayList, of any type

void * ArrayList_GetList(ArrayList * list)
	-retrieves the ArrayList object

inline size_t ArrayList_GetSize(ArrayList * list)
	-retrieves the number of items in the ArrayList object

boolean ArrayList_Free(ArrayList * list)
	-Deallocates the ArrayList object

boolean ArrayList_Remove(ArrayList * list, size_t index)
	-removes an item from a specified index from the ArrayList object
	-if the object doesn't exist, returns NULL
	-if the index doesn't exist, returns NULL

boolean ArrayList_RemoveLast(ArrayList *list)
	-remove last item and updates

boolean ArrayList_Set(ArrayList *, size_t , void * )
	-it will expand if needed 
	-sets a value at a specifics index in the ArrayList object
	-if the index doesn't exist, returns NULL

void * ArrayList_Get(ArrayList *list, size_t index)
	-retrieves the contents of the ArrayList object at the specified index
	-if the index doesn't exist, returns NULL

boolean ArrayList_Clear(ArrayList * list)
	 -must do compact
	 -erases the ArrayList

boolean ArrayList_Copy(ArrayList * destination, const ArrayList * source)
	-copies contents of source ArrayList object into the destination ArrayList object

boolean ArrayList_ExpandReserved(ArrayList * list, size_t reserved)
	-expans the capacity of the ArrayList if possible by the reserved value specified
	-if not possible, returns 0 (FALSE)

boolean ArrayList_Compact(ArrayList * list)
	-it compacts to size + 100 if possible
	-if not possible, returns 0 (FALSE)





