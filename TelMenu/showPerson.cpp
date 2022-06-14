//
// Created by CHH3213 on 2022/6/12.
//

#include "showPerson.h"
void showPerson(Addressbooks * abs){
    {
        if (abs->m_Size == 0)
        {
            cout << "当前记录为空" << endl;
        }
        else
        {
            for (int i = 0; i < abs->m_Size; i++)
            {
                cout << "姓名：" << abs->personArray[i].name << "\t";
                cout << "性别：" << (abs->personArray[i].sex == 1 ? "男" : "女") << "\t";
                cout << "年龄：" << abs->personArray[i].age << "\t";
                cout << "电话：" << abs->personArray[i].phone << "\t";
                cout << "住址：" << abs->personArray[i].address << endl;
            }
        }

        system("pause");
        system("cls");
    }
}

