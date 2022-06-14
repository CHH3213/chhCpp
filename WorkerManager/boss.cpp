//
// Created by CHH3213 on 2022/6/12.
//

#include "boss.h"

string Boss::getDeptName() {
    return string("总裁");
}

void Boss::showInfo() {
    cout << "职工编号： " << this->m_Id
         << " \t职工姓名： " << this->m_Name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：管理公司所有事务" << endl;
}

Boss::Boss(int id, string name, int dId) {
    this->m_Id=id;
    this->m_Name=name;
    this->m_Id=dId;

}
