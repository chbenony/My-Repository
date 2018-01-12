//
//  main.c
//  Assignment1
//
//  Created by Chelsea Benony on 7/6/17.
//  Copyright © 2017 Chelsea Benony. All rights reserved.
//

#include <stdio.h>
#include "String.h"
#include "ArrayList.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    //char* message = "Hello!";
    //printf("%zu\n", String_ChrLen(message));
    String* string1 = malloc(sizeof(String*)); //we have to allocate memory before
                                            //putting anything into string1
    String_New(string1, "Hello!");
    String* string2 = malloc(sizeof(String*));
    String_New(string2, "Equal!");
    printf("------------------------------------------------------------------\n\n");
    printf("Checking to see if equal: \n");
    printf("String1 and String2 is:  %d\n", String_Equal(string1, string2)); //1 is true, 0 is false
    printf("Equal Length String1 and String2 is:  %d\n", String_EqualLen(string1, string2)); //1 is true, 0 is false
    printf("String1 is:  %s\n", String_Get(string1)); //retrieves whatever is in string1
    printf("String2 is:  %s\n", String_Get(string2)); //retrieves whatever is in string2
    String_Append(string1, " WORLD!"); //appends a string to the end of a given string
    
    printf("The length of this string is %zu\n", String_ChrLen(string1->str)); //returns the length of the string
    printf("The length of this string is %zu\n", String_ChrLen(string2->str)); //returns the length of the string
    
    printf("String1 is now: %s\n", String_Get(string1));
    printf("------------------------------------------------------------------\n\n");
    printf("The character is %c\n", String_GetChar(string1, 10)); //retrieves a character from the string
    printf("The original string is %s\n", String_Get(string2));
    String_SetChar(string2, 4, 'l');
    String_SetChar(string2, 5, 's');
    printf("The new string is %s\n", String_Get(string2)); //replaces the character of a string
     printf("------------------------------------------------------------------\n\n");
    String* string3 = malloc(sizeof(String));
    String_Cpy(string3, string2);
    printf("String 3 is: %s\n", String_Get(string3));

    String* string4 = malloc(sizeof(String) * 100);
    //String_New(string4, NULL);
    String_nCpy(string4, string2, 2);
    printf("String 4 is: %s\n", String_Get(string4));
    printf("The length of the string is: %zu\n", String_Len(string1));
    
    String_Cat(string4, string3);
    
    printf("String 4 is %s\n", String_Get(string4));
    String_Cat(string4, string2);
    printf("The new string 4 is %s\n", String_Get(string4));
    String_Cat(string4, string1);
    printf("The new string 4 is %s\n", String_Get(string4));
    printf("------------------------------------------------------------------\n");
    
    String_nCat(string3, string1, 5);
    printf("String 3 is %s\n", String_Get(string3));

    //String_Cmp compares the lengths of the strings
    //if return is 1, then the first string is greater than the second string
    //if return is 0, then the strings are equal
    //if return is -1, then the first string is less than the second string
    printf("String 1 %s and String 2 %s is %d\n", String_Get(string1), String_Get(string2), String_Cmp(string1, string2));
    printf("String3 and String4 is %d\n", String_Cmp(string3, string4)); //string 3 is less than string 4
    printf("------------------------------------------------------------------\n");
    String* string5 = malloc(sizeof(String) * 100);
    //String* string5 = NULL;
    String_New(string5, "http://www.en.wikipedia.org");
    printf("The original string is %s\n", String_Get(string5));
    String_Chr(string5, '.');
    printf("String after |%c| is - |%s|\n", '.', String_Get(string5));
 
    String* string6 = malloc(sizeof(String)*100);
   // String* string6 = NULL;
    String_New(string6, "Angels");
    String* string7 = malloc(sizeof(String)*100);
    String_New(string7, "OutofAir");
    
    //String_cSpn(string4, string2);
    printf("There are %zu characters in String 7\n", String_cSpn(string7, string6));
 
    
    String_pBrk(string1, string2);
    printf("The string is %s\n", String_Get(String_pBrk(string1, string2)));
    /*
    printf("The string is %s\n", String_Get(String_rChr(string3, 'r')));
    
    printf("%zu\n", String_spn(string6, string7));*/
    
    String_Str(string3, string1);
    printf("The new string is %s\n", String_Get(String_Str(string3, string1)));
    printf("------------------------------------------------------------------\n\n");
    printf("The hashcode of String 1 is %zu\n", String_GetHashCode(string1));
    printf("The hashcode of String 2 is %zu\n", String_GetHashCode(string2));
    printf("The hashcode of String 4 is %zu\n", String_GetHashCode(string4));
    printf("------------------------------------------------------------------\n\n");
    
    String* string8 = malloc(sizeof(String) * 100);
    String_New(string8, "   This is a test");
    printf("This is the original String5: %s\n", String_Get(string8));
    String_LTrim(string8);
    printf("This is String8: %s\n", String_Get(string8));
    
    String* string9 = malloc(sizeof(String) * 100);
    String_New(string9, "This is a new test        ");
    printf("this is the original String9: %s\n", String_Get(string9));
    String_RTrim(string9);
    printf("This is the new String9: %s\n", String_Get(string9));
    
    String* string10 = malloc(sizeof(String)*100);
    String_New(string10, "    This is the final test      ");
    printf("This is the original string10: %s\n", String_Get(string10));
    String_Trim(string10);
    printf("This is the final string10: %s\n", String_Get(string10));
    
    printf("------------------------------------------------------------------\n\n");
    printf("The character is: %c\n", String_GetCharFromIndex(string1, 3));
    printf("------------------------------------------------------------------\n\n");
    printf("The index of character %c is %d\n", 'l', String_IndexOfChar(string1, 'l'));
    printf("------------------------------------------------------------------\n\n");
    
    String* string11 = malloc(sizeof(String)*100);
    String_New(string11, "ALLUPPERCASE");
    printf("The original string 11 is: %s\n", String_Get(string11));
    String_Lower(string11);
    printf("The new string 11 is: %s\n", String_Get(string11));
    String_Upper(string11);
    printf("Returning the original string 11 to: %s\n", String_Get(string11));
    printf("------------------------------------------------------------------\n\n");
    
    String_Reverse(string11);
    printf("The new string 11 is: %s\n", String_Get(string11));
    printf("------------------------------------------------------------------\n\n");
    String* string12 = malloc(sizeof(String) * 100);
    String_New(string12, "This is a new string of many words.");
    //String_Append(string12, "of many words.");
    printf("This string has %zu words\n", String_WordCount(string12));
    printf("------------------------------------------------------------------\n\n");
    
    String* string13 = malloc(sizeof(String) * 100);
    String_New(string13, "This");
    String_StartsWith(string12, string13);
    
    printf("String12 /%s/ \nstarts with String13 \n/%s/ and so the string is /%s/\n", String_Get(string12), String_Get(string13),String_Get(String_StartsWith(string12, string13)));
    printf("------------------------------------------------------------------\n\n");

    String* string14 = malloc(sizeof(String) * 100);
    String_New(string14, "Finishedd");
    String_TrimChar(string14, "d");
    printf("String 14 is: %s\n", String_Get(string14));
    printf("------------------------------------------------------------------\n\n");
    
    /*String_Tok(string2, "forget");
    printf("The tokenized string is: %s", String_Get(string2));*/
    
    printf("------------------------------------------------------------------\n\n");

    
    printf("-------------------------FREEING STRINGS----------------------------\n\n");
    
    String_Free(string1); //frees string1
    String_Free(string2); //frees string2
    String_Free(string3); //frees string3
    String_Free(string4); //frees string4
    //String_Free(string5); //frees string5
    //String_Free(string6); //frees string6
    //String_Free(string7);
    String_Free(string8);
    String_Free(string9);
    String_Free(string10);
    String_Free(string11);
    String_Free(string12);
    String_Free(string13);

    

   
    printf("--------------------------TESTING ARRAYLIST--------------------------\n\n\n");
    
    String* a = malloc(sizeof(String));
    String* b = malloc(sizeof(String));
    String* d = malloc(sizeof(String));
    String* c = malloc(sizeof(String));
    String* e = malloc(sizeof(String));
    String* f = malloc(sizeof(String));
    String* g = malloc(sizeof(String));
    String* h = malloc(sizeof(String));
    String* j = malloc(sizeof(String));

    
    String_New(a, "Eggs");
    String_New(b, "Bread");
    String_New(c, "Cheese");
    String_New(d, "Milk");
    String_New(e, "Butter");
    String_New(f, "Tomatoes");
    String_New(g, "Broccoli");
    String_New(h, "Lettuce");
    String_New(j, "Fish");
    
    
   /* ArrayList list1;
    ArrayList_New(&list1);
    for (int i = 0; i < 500; i++){
        if (i > 400)
            ArrayList_Add(&list1, a);
        else{
            if ((i%2) == 0)
                ArrayList_Add(&list1, d);
            else
                ArrayList_Add(&list1, c);
        }
    }*/
    ArrayList groceryList;
    ArrayList_New(&groceryList);
    ArrayList_Add(&groceryList, a);
    ArrayList_Add(&groceryList, b);
    ArrayList_Add(&groceryList, c);
    ArrayList_Add(&groceryList, d);
    ArrayList_Add(&groceryList, e);
    ArrayList_Add(&groceryList, f);
    ArrayList_Add(&groceryList, g);
    ArrayList_Add(&groceryList, h);
    ArrayList_Add(&groceryList, j);
    
    printf("Printing ArrayList Grocery List \n");
    for (int i = 0; i < groceryList.size; i++){
        String* s = (String*)groceryList.arr[i];
        printf("%d. %s\n", i + 1, s->str);
    }
    printf("The size of our grocery list is now %zu\n", groceryList.size);
    printf("---------------------------------------------------------------------\n\n");
    printf("Looks like we don't need cheese. Let's remove it from the list.\n");
    ArrayList_Remove(&groceryList, 2);
    printf("This is the new Grocery List\n");
    for (int i = 0; i < groceryList.size; i++){
        String* s = (String*)groceryList.arr[i];
        printf("%d. %s\n", i + 1, s->str);
    }
    printf("The size of our grocery list is now %zu\n", groceryList.size);
    
    printf("---------------------------------------------------------------------\n\n");
    ArrayList_RemoveLast(&groceryList);
    printf("Removing the last item from the grocery list we get: \n");
    //printf("%s", String_Get((String*)ArrayList_GetList(&groceryList)));
    ArrayList_Compact(&groceryList);
    for (int i = 0; i < groceryList.size; i++){
        String* s = (String*)groceryList.arr[i];
        printf("%d. %s\n", i + 1, s->str);
    }
    printf("---------------------------------------------------------------------\n\n");
    //ArrayList_Get(&groceryList, 7);
    printf("The %dth item of the grocery list is: %s\n", 7, String_Get((String*)ArrayList_Get(&groceryList, 6)));
    
    printf("---------------------------------------------------------------------\n\n");
    ArrayList_Expand(&groceryList);
    ArrayList newGroceryList;
    ArrayList_New(&newGroceryList);
    ArrayList_Copy(&newGroceryList, &groceryList);
    
    printf("The copied grocery list is: \n");
    for (int i = 0; i < newGroceryList.size; i++){
        String* s = (String*)newGroceryList.arr[i];
        printf("%d. %s\n", i + 1, s->str);
    }
    
    printf("---------------------------FREEING ARRAYLISTS-------------------------\n\n");
    String_Free(a);
    String_Free(b);
    String_Free(c);
    String_Free(d);
    String_Free(e);
    String_Free(f);
    String_Free(g);
    String_Free(h);
    String_Free(j);
    
    ArrayList_Free(&groceryList);
    ArrayList_Free(&newGroceryList);
    
    return 0;
}
