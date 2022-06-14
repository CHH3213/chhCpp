//
// Created by CHH3213 on 2022/6/12.
//
#include "isExist.h"
int isExist(Addressbooks * abs, string m_name){
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].name == m_name)
        {
            return i;
        }
    }
    return -1;
}