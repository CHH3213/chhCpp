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
        cout<<"请输入您的选择: ";
        cin>>select;
        //创建通讯录
        Addressbooks abs;
        //初始化通讯录中人数
        abs.m_Size = 0;
        switch(select){
            case 1: // 添加联系人
                addPerson(&abs);
                break;
            case 2: // 显示联系人
                showPerson(&abs);
                break;
            case 3: // 删除联系人
                deletePerson(&abs);
                break;
            case 4: //查找联系人
                findPerson(&abs);
                break;
            case 6: // 清空
                cleanPerson(&abs);
                break;
            case 0: // 添加联系人
                cout<<"欢迎下次使用"<<endl;
                system("pause");
                return 0;
            default:
                break;


        }
    }

}
