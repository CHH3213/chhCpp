//
// Created by CHH3213 on 2022/6/12.
//

#include "addPerson.h"

void addPerson(Addressbooks *abs){
    //�жϵ绰���Ƿ�����
    if (abs->m_Size == MAX)
    {
        cout << "ͨѶ¼�������޷����" << endl;
        return;
    }
    else
    {
        //����
        string name;
        cout << "������������" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].name = name;

        cout << "�������Ա�" << endl;
        cout << "1 -- ��" << endl;
        cout << "2 -- Ů" << endl;

        //�Ա�
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].sex = sex;
                break;
            }
            cout << "������������������";
        }

        //����
        cout << "���������䣺" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].age = age;

        //��ϵ�绰
        cout << "��������ϵ�绰��" << endl;
        string phone = "";
        cin >> phone;
        abs->personArray[abs->m_Size].phone = phone;

        //��ͥסַ
        cout << "�������ͥסַ��" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].address= address;

        //����ͨѶ¼����
        abs->m_Size++;

        cout << "��ӳɹ�" << endl;
        system("pause");
        system("cls");
    }

}
