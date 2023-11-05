//
// Created by KK on 2023/10/30.
//
#include <iostream>

#define MAX_LENGTH 100

enum STATUS{
    OK = 1,
    ERR = -1,
};
typedef int dataType;

typedef struct Sqlist{
    dataType data[MAX_LENGTH];
    dataType length;
}sqlist_t;

//init add del query modify
dataType init_sqlist(sqlist_t *list)
{
    list->length = 0;
    return OK;
}

// add
dataType add_to_sqlist_by_index(sqlist_t *list, int index, dataType value)
{
    // 0 1 2 3  insert into 3 length=4
    if(index < 0 || index > list->length)
        return ERR;
    // 0 1 2 3 insert 4 into 2   0  1 -4- 2  3
    for(int i = list->length; i > index; i--){
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = value;
    list->length ++;
    return OK;
}

//del
dataType del_sqlist_by_index(sqlist_t *list, int index)
{
    // 0 1 2   len:3
    if(index < 0 || index > list->length)
        return ERR;
    for(int i = index; i < list->length; i ++){
        list->data[i] = list->data[i+1];
    }
    list->length--;
    return OK;
}
//query
dataType query_by_index(sqlist_t *list, int index)
{
    if(index < 0 || index >list->length)
        return ERR;
    else
        return list->data[index];
}
//return the first index
dataType query_by_value(sqlist_t *list, dataType value)
{
    for(int i = 0; i < list->length; i++){
        if(value == list->data[i])
            return i;
    }
    return ERR;
}
//modify
dataType modify_sqlist(sqlist_t *list, dataType value, int index)
{
    if(index < 0 || index > list->length)
        return ERR;
    list->data[index] = value;
    return OK;
}

int main(){
    sqlist_t list;
    init_sqlist(&list);
    for(int i = 0; i < 5; i++){
        add_to_sqlist_by_index(&list, i ,2*i);
    }
    del_sqlist_by_index(&list, 1);
    for(int i = 0; i <list.length ; i++){
        std::cout << "data "<< i << "value: " << list.data[i] << std::endl;
    }
}