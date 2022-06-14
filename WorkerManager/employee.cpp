//
// Created by CHH3213 on 2022/6/12.
//

#include "employee.h"

Employee::Employee(int id, string name, int dId) {
    this->m_Id=id;
    this->m_Name=name;
    this->m_Id=dId;
}

string Employee::getDeptName() {
    return string ("员工");
}

void Employee::showInfo() {
    cout << "职工编号： " << this->m_Id
         << " \t职工姓名： " << this->m_Name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：完成经理交给的任务" << endl;
}
