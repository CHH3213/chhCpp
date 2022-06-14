//
// Created by CHH3213 on 2022/6/12.
//
#pragma once
#ifndef WORKERMANAGER_WORKER_H
#define WORKERMANAGER_WORKER_H
#include <iostream>
#include <string>
using  namespace std;
class Worker{
public:

    virtual void showInfo()=0;
    virtual string getDeptName()=0;

    int m_Id;
    string m_Name;
    int m_DeptId;
};
#endif //WORKERMANAGER_WORKER_H
