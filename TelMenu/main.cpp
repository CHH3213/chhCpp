#include <iostream>
#include "showMenu.h"
#include "Addressbooks.h"
#include "addPerson.h"
#include "showPerson.h"
#include "deletePerson.h"
#include "findPerson.h"
#include "clearPerson.h"
using namespace std;
int main() {
    int select=0;
    while (true){
        showMenu();
        cout<<"����������ѡ��: ";
        cin>>select;
        //����ͨѶ¼
        Addressbooks abs;
        //��ʼ��ͨѶ¼������
        abs.m_Size = 0;
        switch(select){
            case 1: // �����ϵ��
                addPerson(&abs);
                break;
            case 2: // ��ʾ��ϵ��
                showPerson(&abs);
                break;
            case 3: // ɾ����ϵ��
                deletePerson(&abs);
                break;
            case 4: //������ϵ��
                findPerson(&abs);
                break;
            case 6: // ���
                cleanPerson(&abs);
                break;
            case 0: // �����ϵ��
                cout<<"��ӭ�´�ʹ��"<<endl;
                system("pause");
                return 0;
            default:
                break;


        }
    }

}
