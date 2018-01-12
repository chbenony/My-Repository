//
//  String.c
//  Assignment1
//
//  Created by Chelsea Benony on 7/6/17.
//  Copyright © 2017 Chelsea Benony. All rights reserved.
//

#include "String.h"

size_t String_ChrLen(char *s){
    char* tmp = s;
    size_t count = 0;
    
    while (*tmp != '\0'){
        count++;
        tmp++;
    }
    return count;
}

int String_EqualLen(String *lhs, String *rhs){
    return (lhs->size == rhs->size);
}

int String_New(String * strObj,char * str){
    
    strObj->size = String_ChrLen(str);
    strObj->str = (char*)malloc(1 + sizeof(char) * 100);
    if (strObj->str == NULL)
        return 0;
    for (int i =0; i < strObj->size; i++)
        strObj->str[i] = str[i];
    //String_Free(strObj);
    
    return 1;

}

int String_Equal(String * lhs, String * rhs){
    //return (String_ChrLen(lhs->str) == String_ChrLen(rhs->str));
    lhs = calloc(sizeof(String), lhs->size);
    rhs = calloc(sizeof(String), rhs->size);
    
    if (!String_EqualLen(lhs, rhs))
        return 0;
    for (int i = 0; i < lhs->size; i++)
        if (lhs->str[i] != rhs->str[i])
            return 0;
    free(lhs);
    free(rhs);
    return 1;
}

void String_Delete(String* strObj){
    strObj->size = -1;
    free(strObj);
    strObj->str = NULL;
    strObj->hashcode = 0;
}

char * String_Get(String * strObj){
    if (strObj == NULL)
        return 0;
    return strObj->str;
}

int String_Append(String * strObj, char * strAppend){
    size_t sizeOfNewString = String_ChrLen(strAppend);
    char* tmp = realloc(strObj->str, strObj->size + sizeOfNewString);
    
    if (tmp == NULL)
        return 0; //false
    strObj->str = tmp;
    int i = (int)strObj->size - 1;
    int k = 0;
    
    while (strAppend[k] != '\0')
        strObj->str[i++] = strAppend[k++];
    strObj->str[i] = '\0';
    strObj->size = i + 1;
    
    return 1;
}

void String_Free(String * strObj){
    String_Delete(strObj);
}

//define get and set for a given char. only if is within bounds
//get a character at a certain index
char String_GetChar(const String *strObj,const size_t index){
    size_t i;
    for (i = 0; strObj->str[i] != '\0' && i <= index; i++){
        if (i == index)
            return strObj->str[i];
    }
    
    return 0;
}
//places a character into the a given string if the index is within bounds
void String_SetChar(String *strObj,const size_t index, const char c){
    size_t i;
    for (i = 0; strObj->str[i] != '\0' && i <= index; i++){
        if (i == index)
            strObj->str[i] = c;
    }
}


//The following are the signature you requried
String * String_Cpy ( String * destination, const String * source ){
    String_New(destination, source->str);
    return destination;
}

String * String_nCpy ( String * destination, const String * source, size_t num ){
    
    String* s = calloc(sizeof(String), destination->size);
    s = (String*)destination;
   
    for (size_t i = 0; num > 0 && source->str[i] != '\0'; i++){
        String_New(s, &source->str[i]);
        num--;
    }
    while (num > 0){
        *s->str++ = '\0';
        num--;
    }
    
    String_Cpy(destination, s);
    //free(s);
    return destination;
}

String * String_Cat ( String * destination, const String * source ){
    size_t i, j;
    //destination = realloc((String*)source, sizeof(String) + String_Len(destination));
    //destination = realloc((String*)source, sizeof(String) + String_Len(source));
    for (i = 0; destination->str[i] != '\0'; i++)
        ;
    for (j = 0; source->str[j] != '\0'; j++)
        destination->str[i + j] = source->str[j];
    destination->str[i + j] = '\0';
    
    return destination;
}

String * String_nCat ( String * destination, const String * source, size_t num ){
    if (num != 0){
        char* d = destination->str;
        char* s = source->str;
        
        while (*d != 0)
            d++;
        while (--num != 0){
            if ((*d = *s++) == 0)
                return 0;
            d++;
        }
        *d = 0;
    }
    
    return destination;
}

int String_Cmp ( const String * str1, const String * str2 ){
    if (String_Len(str1) < String_Len(str2))
        return -1;
    if (String_Equal((String*)str1, (String*)str2))
        return 0;
    if (String_Len(str1) > String_Len(str2))
        return 1;
    
    return 0;
}

int String_nCmp ( const String * str1, const String * str2, size_t num ){
    //char* tmp1 = realloc((String*)str1, str1->size);
    char* tmp1 = calloc(sizeof(char*), str1->size);
    //char* tmp2 = realloc((String*)str2, str2->size);
    char* tmp2 = calloc(sizeof(char*), str2->size);
    
    for (; num > 0; tmp1++, tmp2++, num--){
        if (*tmp1 != *tmp2)
            return ((*tmp1 < *tmp2) ? -1 : +1);
        else if (*tmp1 == '\0')
            return 0;
    }
    
    return 0;
}
String * String_Chr (String * str, int character ){
   /* String* tmp = calloc(sizeof(String), character);
    tmp = str;
    while (*tmp->str != character && *tmp->str != '\0'){
        if (!*tmp->str++){
            *tmp->str++ = '\0';
            return 0;
        }
    }
    str = tmp;
    free(tmp);*/
    //String_New(str, tmp->str);
    //free(tmp);
    /*char ch = character;
    //String* tmp = realloc(str, sizeof(String));
    String* tmp = str;
    
    for (; *tmp->str != ch; tmp->str++)
        if (*tmp->str == '\0')
            return 0;
    str = tmp;
    //free(tmp);*/
    while (*str->str != (char)character)
        if (!*str->str++)
            return 0;
    str->str[str->size - 1] = '\0';
    
    return str;
}
size_t String_cSpn ( const String * str1, const String * str2 ){
    size_t num = 0;
    String* tmp = (String*)str1;
    while (*str1->str){
        if (String_Chr((String*)str2, *tmp->str))
            return num;
        else{
            tmp->str++;
            num++;
        }
    }
    free(tmp);
    return num;
}

String * String_pBrk (const String * str1, const String * str2 ){
   /* String* scanp;
    String* tmp = (String*)str1;
    int c, sc;
    
    while ((c = *tmp->str++) != '\0'){
        for (scanp = (String*)str2; (sc = *scanp->str++) != '\0';)
            if (sc == c){
                tmp->str = str1->str - 1;
                return tmp;
            }
    }
    */
    String* tmp = (String*)str1;
    //String* tmp2 = str2;
    
    while (*str1->str){
        if (String_Chr((String*)str2, *tmp->str++)){
            tmp->str = (char*)tmp->str--;
            str1 = tmp;
            free(tmp);
            return (String*)str2;
        }
        
    }
    return NULL;
}

String * String_rChr (const String * str, int character ){
    String* val = 0;
    String* tmp = (String*)str;
    
    /*while (*tmp->str++){
        if (*tmp->str == (char)character)
            val = tmp;
    }*/
    for (size_t i = 0; tmp->str[i] != '\0'; i++){
        if (tmp->str[i] == (char)character){
            String_New(val, tmp->str);
            return val;
        }
    }
    return 0;
}

size_t String_spn ( const String * str1, const String * str2 ){
    //String* tmp1 = (String*)str1;
    //String* tmp2 = (String*)str2;
    
   /* size_t i, j;
    size_t count = 0;
    for (i = 0; i < String_Len(str1); i++){
        for (j = 0; j < String_Len(str2); j++){
            if (str2->str[j] == str1->str[i])
                count++;
        }
        if (!str2->str[j])
            return 0;
    }
    return i;*/
    size_t ret = 0;
    String* tmp = (String*)str1;
    while (str1->str && String_Chr((String*)str2, *tmp->str++))
        ret++;
    return ret;
}

String * String_Str (String * str1, const String * str2 ){
    //size_t num = String_Len(str2);
    while (*str1->str){
        String* begin = str1;
        String* pattern = (String*)str2;
        
        while (*str1->str && *pattern->str && *str1->str == *pattern->str){
            str1->str++;
            pattern->str++;
        }
        if (!*pattern->str){
            return begin;
        }
            
        str1->str = begin->str + 1;
    }
    return str1;
}

size_t String_Len ( const String * str ){
    size_t i;
    size_t count = 0;
    
    for (i = 0; str->str[i] != '\0'; i++)
        count++;
    return count;
}

size_t String_GetHashCode(const String * str){
    return String_CreateHash(str->str);
}

size_t String_CreateHash(const char* str){
    size_t hash = 5381;
    size_t c;
    
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    
    return hash;
}
String * String_Trim(String * str){
    String_LTrim(str);
    String_RTrim(str);
    return str;
}

String * String_LTrim(String * str){
    while((*str->str == ' ' && *str->str != '\0') || *str->str == '\n' || *str->str == '\t'){
        str->str++;
    }
    return str;
}
String * String_RTrim(String * str){
    char* end;
    end = str->str + String_Len(str) - 1;
    while ((end > str->str && *end == ' ')){
        end--;
        *(end + 1) = '\0';
    }
    return str;
}

char String_GetCharFromIndex(const String * str, int index){
    //String* tmp = (String*)str;
    
    for (int i = 0; str->str[i] != '\0' && i < String_Len(str); i++)
        if (i == index)
            return *str->str;
    
    return 0;
}

int String_IndexOfChar(const String * str, char c){
    for (int i = 0; str->str[i] != '\0'; i++)
        if (str->str[i] == c)
            return i;
    return 0;
}

String * String_Lower(String * str){
    for (int i = 0; str->str[i] != '\0'; i++)
        if (str->str[i] >= 'A' && str->str[i] <= 'Z')
            str->str[i] += 32;
    return str;
}

String * String_Upper(String * str){
    for (int i = 0; str->str[i] != '\0'; i++)
        if (str->str[i] >= 'a' && str->str[i] <= 'z')
            str->str[i] -= 32;
    return str;
}

String * String_Reverse(String * str){
    
    int len = 0;
    int c;
    char* start, *end, tmp;
    
    len = (int)String_Len(str);
    start = str->str;
    end = str->str;
    
    for (c = 0; c < len - 1; c++ )
        end++;
    for (c = 0; c < len/2; c++){
        tmp = *end;
        *end = *start;
        *start = tmp;
        
        start++;
        end--;
    }
    
    return str;
}

size_t String_WordCount(const String * str){
    size_t count = 0;
    for (size_t i = 0; i <= String_Len(str) ; i++)
        if (str->str[i] == ' ' || str->str[i] == '\n' || str->str[i] == '\t')
            count++;
    return count + 1;
}

//return new string
String * String_StartsWith (const String * str, const String * startsWith){
    for (int i = 0; startsWith->str[i] != '\0'; i++){
        if (startsWith->str[i] == str->str[i]){
            startsWith->str[startsWith->size] = '\0';
            str->str[str->size - 1] = '\0';
            return (String*)str;
        }
        
    }
    return NULL;
}

String * String_TrimChar(String * str, const char * c){
    char* end;
    end = str->str + String_Len(str) - 1;
    while (end > str->str && *end == *c)
        end--;
    *(end + 1) = '\0';
    
    return str;
}

//extra credit

char * String_Tok ( String * str, const char * delimiters ){
    char* p = 0;
    String* tmp = str;
    String* tmp2 = calloc(sizeof(String), str->size);
    tmp->str = (char*)delimiters;
    
    if (str->str){
        p = str->str;
        tmp2->str = p;
    }
    else if (!p)
        return 0;
    str->str = p + String_spn(tmp2, tmp);
    p = str->str + String_cSpn(str, tmp);
    
    p = *p ? *p = 0, p + 1 : 0;
    free(tmp);
    free(tmp2);
    
    return str->str;
    
}

//optional
///void String_InitStruct(String ** strObj);
///void String_FreeStruct(String ** strObj);
