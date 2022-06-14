//
// Created by CHH3213 on 2022/6/12.
//
#pragma once
#ifndef WORKERMANAGER_MANAGER_H
#define WORKERMANAGER_MANAGER_H
#include <iostream>
#include "worker.h"

class Manager: public Worker{
public:

    Manager(int id,string name, int dId);

    virtual void showInfo();

    virtual string getDeptName();
};


#endif //WORKERMANAGER_MANAGER_H
