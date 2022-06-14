//
// Created by CHH3213 on 2022/6/14.
//

#ifndef COMPUTERROOMORDER_ORDERFILE_H
#define COMPUTERROOMORDER_ORDERFILE_H
#pragma  once
#include <map>
#include "globalFile.h"
#include "Identity.h"
using namespace std;
class OrderFile {
public:

    //构造函数
    OrderFile();

    //更新预约记录
    void updateOrder();

    //记录的容器  key --- 记录的条数  value --- 具体记录的键值对信息
    map<int, map<string, string>> m_orderData;

    //预约记录条数
    int m_Size;
};


#endif //COMPUTERROOMORDER_ORDERFILE_H
