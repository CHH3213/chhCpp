//
// Created by CHH3213 on 2022/6/12.
//
#pragma once
#ifndef WORKERMANAGER_EMPLOYEE_H
#define WORKERMANAGER_EMPLOYEE_H
#include <iostream>
using namespace std;
#include "worker.h"
class Employee: public Worker{
public:
    Employee(int id,string name, int dId);

    virtual void showInfo();

    virtual string getDeptName();
};


#endif //WORKERMANAGER_EMPLOYEE_H
