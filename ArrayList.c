//
//  ArrayList.c
//  Assignment1
//
//  Created by Chelsea Benony on 7/9/17.
//  Copyright © 2017 Chelsea Benony. All rights reserved.
//

#include "ArrayList.h"

boolean ArrayList_New(ArrayList * list){
    list->size = 0;
    list->arr = calloc(INITIAL_SIZE_STRING_LIST, INITIAL_SIZE_STRING_LIST * sizeof(void*));
    
    if (list->arr == NULL)
        return FALSE;
    list->reserved = INITIAL_SIZE_STRING_LIST;
    return TRUE;
}

boolean ArrayList_Expand(ArrayList * list){
    if (list->size < list->reserved)
        return TRUE;
    
    size_t newReserved = list->size * 2 + 1;
    void* tmp = realloc(list->arr, newReserved * sizeof(void*));
    if (tmp == NULL)
        return FALSE;
    list->reserved = newReserved;
    list->arr = tmp;
    
    return TRUE;
}

boolean ArrayList_Add(ArrayList * list, void * item){
    if (!ArrayList_Expand(list))
        return FALSE;
    
    list->arr[list->size] = item;
    list->size += 1;
    return 0;
}

void * ArrayList_GetList(ArrayList * list){
    
    return list->arr;
}

inline size_t ArrayList_GetSize(ArrayList * list){
    return list->size;
}

//also need to define

boolean ArrayList_Free(ArrayList * list){
   /* strObj->size = -1;
    free(strObj);
    strObj->str = NULL;
    strObj->hashcode = 0;*/
    if (list == NULL)
        return FALSE;
    list->size = -1;
    list->arr = NULL;
    list->reserved = 0;
    return TRUE;
}

boolean ArrayList_Remove(ArrayList * list, size_t index){
    //ArrayList* tmp = realloc(list, sizeof(list->size - 1) * sizeof(ArrayList));
    ArrayList *tmp = list;
/*
    if (tmp == NULL && list->size > 1)
        return FALSE;
    list->size = list->size - 1;
 */
    if (list == NULL && list->size > 1)
        return FALSE;
    
    for (int i = 0; tmp->arr[i] != '\0' && i < tmp->size; i++)
        if (i == index){
            tmp->arr[index] = list->arr[i + 1];
        }
    list->size = list->size-1;
    
    list = tmp;
    
    return TRUE;
}

boolean ArrayList_RemoveLast(ArrayList *list) //remove last item and updates
{
    if (list == NULL)
        return FALSE;
    //ArrayList* tmp = realloc(list, sizeof(list->size - 1) * sizeof(ArrayList));
    ArrayList_Remove(list, list->size - 1);
    
    return TRUE;
}
//it will expand if needed
boolean ArrayList_Set(ArrayList *list, size_t index, void * item){
    for (int i = 0; list->arr[i] != NULL; i++)
        if (i == index){
            list->arr[i] = item;
            return TRUE;
        }
    return FALSE;
}

void * ArrayList_Get(ArrayList *list, size_t index){
    for (int i = 0; list->arr[i] != NULL; i++)
        if (i == index)
            list->arr = list->arr[i];
    return list->arr;
}

boolean ArrayList_Clear(ArrayList * list) //must do compact
{
    if (list == NULL)
        return FALSE;
    
    for (int i = 0; i < list->size; i++)
        list->arr[i] = NULL;
    ArrayList_Compact(list);
    return TRUE;
}

boolean ArrayList_Copy(ArrayList * destination, const ArrayList * source){
    
    destination = calloc(sizeof(ArrayList), source->size);
   /* if (destination->size < source->size)
        return FALSE;*/
    while (*source->arr != '\0'){
        ArrayList_Add(destination, *source->arr);
        return TRUE;
    }
   // free(tmp);
    return FALSE;
}
boolean ArrayList_ExpandReserved(ArrayList * list, size_t reserved){
    size_t oldCapacity = list->reserved;
    ArrayList* oldData = malloc(sizeof(ArrayList) + reserved);
    if (reserved > oldCapacity){
        oldData = list;
        size_t newCapacity = (oldCapacity * 3)/2 + 1;
        
        if (newCapacity < reserved)
            newCapacity = reserved;
        list->reserved = newCapacity;
        
        ArrayList_Copy(list, oldData);
        return TRUE;
    }
    return FALSE;
}

boolean ArrayList_Compact(ArrayList * list) //it compacts to size + 100 if possible.
{
    size_t oldCapacity = list->reserved;
    ArrayList* oldlist = malloc(sizeof(ArrayList) - list->reserved);
    oldlist = list;
    if (list->size < oldCapacity){
        ArrayList_Copy(list, oldlist);
        return TRUE;
    }
    
    return FALSE;
}

//optional
///boolean ArrayList_InitStruct(ArrayList ** list);
///boolean ArrayList_FreeStruct(ArrayList ** list);
