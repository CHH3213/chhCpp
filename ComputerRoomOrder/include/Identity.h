//
// Created by CHH3213 on 2022/6/14.
//

#ifndef COMPUTERROOMORDER_IDENTITY_H
#define COMPUTERROOMORDER_IDENTITY_H


#pragma once
#include<iostream>
using namespace std;
#include "globalFile.h"
#include <fstream>
#include "ComputerRoom.h"
#include<vector>
//身份抽象类
class Identity
{
public:

    //操作菜单
    virtual void operMenu() = 0;

    string m_Name; //用户名
    string m_Pwd;  //密码
};


#endif //COMPUTERROOMORDER_IDENTITY_H
