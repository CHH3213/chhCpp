//
// Created by CHH3213 on 2022/6/12.
//

#ifndef TELMENU_FINDPERSON_H
#define TELMENU_FINDPERSON_H
#include <iostream>
#include "isExist.h"
void findPerson(Addressbooks * abs)
{
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名：" << abs->personArray[ret].name << "\t";
        cout << "性别：" << abs->personArray[ret].sex << "\t";
        cout << "年龄：" << abs->personArray[ret].age << "\t";
        cout << "电话：" << abs->personArray[ret].phone << "\t";
        cout << "住址：" << abs->personArray[ret].address << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");

}
#endif //TELMENU_FINDPERSON_H
