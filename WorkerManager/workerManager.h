//
// Created by CHH3213 on 2022/6/12.
//
#pragma once
#ifndef WORKERMANAGER_WORKERMANAGER_H
#define WORKERMANAGER_WORKERMANAGER_H
#define  FILENAME "empFile.txt"
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

using namespace std;

class workerManager {
public:
    workerManager();


//    展示菜单
    void showMenu();
    //退出
    void exitSystem();
    //增加职工
    void Add_Emp();
    //统计人数
    int get_EmpNum();
    //保存文件
    void save();

    //初始化员工
    void init_Emp();
    //显示职工
    void Show_Emp();
    //删除职工
    void Del_Emp();
    //按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
    int IsExist(int id);
    //修改职工
    void Mod_Emp();
    //查找职工
    void Find_Emp();

    //排序职工
    void Sort_Emp();
    //清空文件
    void Clean_File();

    ~workerManager();

public:
    //记录文件中的人数个数
    int m_EmpNum;

    //员工数组的指针
    Worker ** m_EmpArray;
    //标志文件是否为空
    bool m_FileIsEmpty;

};


#endif //WORKERMANAGER_WORKERMANAGER_H
