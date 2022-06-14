//
// Created by CHH3213 on 2022/6/12.
//

#ifndef TELMENU_ADDRESSBOOKS_H
#define TELMENU_ADDRESSBOOKS_H
# include "Person.h"
#define MAX 1000 //最大人数
//通讯录结构体
struct Addressbooks
{
    struct Person personArray[MAX]; //通讯录中保存的联系人数组
    int m_Size; //通讯录中人员个数
};
#endif //TELMENU_ADDRESSBOOKS_H

