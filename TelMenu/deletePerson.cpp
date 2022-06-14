//
// Created by CHH3213 on 2022/6/12.
//
#include <iostream>
#include "isExist.h"



void deletePerson(Addressbooks * abs){
    cout << "请输入您要删除的联系人" << endl;
    string m_name;
    cin >> m_name;

    int ret = isExist(abs, m_name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}