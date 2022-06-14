//
// Created by CHH3213 on 2022/6/14.
//

#ifndef COMPUTERROOMORDER_TEACHER_H
#define COMPUTERROOMORDER_TEACHER_H

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "Identity.h"
#include "OrderFile.h"
class Teacher:public Identity {
public:

    //默认构造
    Teacher();

    //有参构造 (职工编号，姓名，密码)
    Teacher(int empId, string name, string pwd);

    //菜单界面
    virtual void operMenu();

    //查看所有预约
    void showAllOrder();

    //审核预约
    void validOrder();

    int m_EmpId; //教师编号
};


#endif //COMPUTERROOMORDER_TEACHER_H
