//
// Created by KK on 2023/10/30.
//

#define MAXSIZE 100

enum return_status{
    ERR = -1,
    OK = 0,
};

typedef int dataType;

struct Sqlist{
    dataType data[MAXSIZE];
    int length;
}sqlist_t;

dataType init_list(struct Sqlist list)
{
    list.length = 0;
    return OK;
}

dataType get_element_from_list(struct Sqlist list, int index)
{
    if(index < 0 || index > list.length)
        return ERR;
    else
        return list.data[index];
}

dataType get_length_from_list(struct Sqlist list)
{
    return list.length;
}

dataType insert_element_by_index(struct Sqlist list, int index, int value)
{
    //index = 0 right forward,then insert
    if(index < 0 || index > list.length + 1)
        return ERR;
    for(int i = 0; i < list.length - index; i++){
        list.data[list.length - i] = list.data[list.length - i -1];
    }
    //if index = 2;length = 8; data0 1 --2 3 4 5 6 7
    list.data[index] = value;
}

int main(){
    struct Sqlist list;
    init_list()
}