//
// Created by CHH3213 on 2022/6/12.
//

#include "showPerson.h"
void showPerson(Addressbooks * abs){
    {
        if (abs->m_Size == 0)
        {
            cout << "��ǰ��¼Ϊ��" << endl;
        }
        else
        {
            for (int i = 0; i < abs->m_Size; i++)
            {
                cout << "������" << abs->personArray[i].name << "\t";
                cout << "�Ա�" << (abs->personArray[i].sex == 1 ? "��" : "Ů") << "\t";
                cout << "���䣺" << abs->personArray[i].age << "\t";
                cout << "�绰��" << abs->personArray[i].phone << "\t";
                cout << "סַ��" << abs->personArray[i].address << endl;
            }
        }

        system("pause");
        system("cls");
    }
}

