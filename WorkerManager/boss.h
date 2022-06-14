//
// Created by CHH3213 on 2022/6/12.
//
#pragma once
#ifndef WORKERMANAGER_BOSS_H
#define WORKERMANAGER_BOSS_H
using namespace std;
#include "worker.h"

class   Boss:public Worker {
public:
    Boss(int id,string name, int dId);

    virtual void showInfo();

    virtual  string getDeptName();
};


#endif //WORKERMANAGER_BOSS_H
