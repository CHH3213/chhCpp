//
// Created by CHH3213 on 2022/6/12.
//

#ifndef TELMENU_CLEARPERSON_H
#define TELMENU_CLEARPERSON_H
#include "Addressbooks.h"
//6、清空所有联系人
void cleanPerson(Addressbooks * abs)
{
    abs->m_Size = 0;
    cout << "通讯录已清空" << endl;
    system("pause");
    system("cls");
}
#endif //TELMENU_CLEARPERSON_H
