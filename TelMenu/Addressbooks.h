//
// Created by CHH3213 on 2022/6/12.
//

#ifndef TELMENU_ADDRESSBOOKS_H
#define TELMENU_ADDRESSBOOKS_H
# include "Person.h"
#define MAX 1000 //�������
//ͨѶ¼�ṹ��
struct Addressbooks
{
    struct Person personArray[MAX]; //ͨѶ¼�б������ϵ������
    int m_Size; //ͨѶ¼����Ա����
};
#endif //TELMENU_ADDRESSBOOKS_H

