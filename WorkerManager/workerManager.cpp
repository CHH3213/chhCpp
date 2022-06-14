//
// Created by CHH3213 on 2022/6/12.
//

#include "workerManager.h"
workerManager::workerManager() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    if(!ifs.is_open()){
        cout << "文件不存在" << endl; //测试输出
        this->m_EmpNum = 0;  //初始化人数
        this->m_FileIsEmpty = true; //初始化文件为空标志
        this->m_EmpArray = NULL; //初始化数组
        ifs.close(); //关闭文件
        return;
    }
    //文件存在，并且没有记录
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空!" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }
    int num =  this->get_EmpNum();
//    cout << "职工个数为：" << num << endl;  //测试代码
    this->m_EmpNum = num;  //更新成员属性
    //根据职工数创建数组
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    //初始化职工
    init_Emp();



}


void workerManager::showMenu() {
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void workerManager::exitSystem() {
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}
workerManager::~workerManager() {
    if (this->m_EmpArray != NULL)
    {
        delete[] this->m_EmpArray;
    }
}

void workerManager::Add_Emp() {
    cout << "请输入增加职工数量： " << endl;

    int addNum = 0;
    cin >> addNum;

    if(addNum>0){
        int newSize = this->m_EmpNum+addNum;
        Worker **newSpace = new Worker*[newSize];
        //将原空间下内容存放到新空间下
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //输入新数据
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dSelect;

            cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
            cin >> id;


            cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
            cin >> name;


            cout << "请选择该职工的岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;


            Worker * worker = NULL;
            switch (dSelect)
            {
                case 1: //普通员工
                    worker = new Employee(id, name, 1);
                    break;
                case 2: //经理
                    worker = new Manager(id, name, 2);
                    break;
                case 3:  //老板
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
            }


            newSpace[this->m_EmpNum + i] = worker;
        }
        //释放原有空间
        delete[] this->m_EmpArray;

        //更改新空间的指向
        this->m_EmpArray = newSpace;

        //更新新的个数
        this->m_EmpNum = newSize;

        //更新职工不为空标志
        this->m_FileIsEmpty = false;

        //提示信息
        cout << "成功添加" << addNum << "名新职工！" << endl;
        this->save();
    }
    else
    {
        cout << "输入有误" << endl;
    }

    system("pause");
    system("cls");

}

void workerManager::save() {
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    for(int i=0;i<this->m_EmpNum;i++){
        ofs<<this->m_EmpArray[i]->m_Id<<" "
        << this->m_EmpArray[i]->m_Name << " "
        << this->m_EmpArray[i]->m_DeptId << endl;

    }

    ofs.close();
}

int workerManager::get_EmpNum() {

    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        //记录人数
        num++;
    }
    ifs.close();

    return num;
}

void workerManager::init_Emp() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker * worker = NULL;
        //根据不同的部门Id创建不同对象
        if (dId == 1)  // 1普通员工
        {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2) //2经理
        {
            worker = new Manager(id, name, dId);
        }
        else //总裁
        {
            worker = new Boss(id, name, dId);
        }
        //存放在数组中
        this->m_EmpArray[index] = worker;
        index++;
    }

}

void workerManager::Show_Emp() {
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i++)
        {
            //利用多态调用接口
            this->m_EmpArray[i]->showInfo();
        }
    }

    system("pause");
    system("cls");
}

void workerManager::Del_Emp() {
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录为空！" << endl;
    } else {
        //按职工编号删除
        cout << "请输入想要删除的职工号：" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);

        if (index != -1)  //说明index上位置数据需要删除
        {
            for (int i = index; i < this->m_EmpNum - 1; i++) {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;

            this->save(); //删除后数据同步到文件中
            cout << "删除成功！" << endl;
        } else {
            cout << "删除失败，未找到该职工" << endl;
        }
    }

    system("pause");
    system("cls");
}

int workerManager::IsExist(int id){
    int index = -1;

    for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_Id == id) {
            index = i;

            break;
        }
    }
    return index;
}

void workerManager::Mod_Emp() {
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请输入修改职工的编号：" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1)
        {
            //查找到编号的职工

            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
            cin >> newId;

            cout << "请输入新姓名： " << endl;
            cin >> newName;

            cout << "请输入岗位： " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker * worker = NULL;
            switch (dSelect)
            {
                case1:
                    worker = new Employee(newId, newName, dSelect);
                    break;
                case2:
                    worker = new Manager(newId, newName, dSelect);
                    break;
                case 3:
                    worker = new Boss(newId, newName, dSelect);
                    break;
                default:
                    break;
            }

            //更改数据 到数组中
            this->m_EmpArray[ret]= worker;

            cout << "修改成功！" << endl;

            //保存到文件中
            this->save();
        }
        else
        {
            cout << "修改失败，查无此人" << endl;
        }
    }

    //按任意键 清屏
    system("pause");
    system("cls");
}

void workerManager::Find_Emp() {
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请输入查找的方式：" << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按姓名查找" << endl;

        int select = 0;
        cin >> select;


        if (select == 1) //按职工号查找
        {
            int id;
            cout << "请输入查找的职工编号：" << endl;
            cin >> id;

            int ret = IsExist(id);
            if (ret != -1)
            {
                cout << "查找成功！该职工信息如下：" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "查找失败，查无此人" << endl;
            }
        }
        else if(select == 2) //按姓名查找
        {
            string name;
            cout << "请输入查找的姓名：" << endl;
            cin >> name;

            bool flag = false;  //查找到的标志
            for (int i = 0; i < m_EmpNum; i++)
            {
                if (m_EmpArray[i]->m_Name == name)
                {
                    cout << "查找成功,职工编号为："
                         << m_EmpArray[i]->m_Id
                         << " 号的信息如下：" << endl;

                    flag = true;

                    this->m_EmpArray[i]->showInfo();
                }
            }
            if (flag == false)
            {
                //查无此人
                cout << "查找失败，查无此人" << endl;
            }
        }
        else
        {
            cout << "输入选项有误" << endl;
        }
    }


    system("pause");
    system("cls");
}

void workerManager::Sort_Emp() {
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "请选择排序方式： " << endl;
        cout << "1、按职工号进行升序" << endl;
        cout << "2、按职工号进行降序" << endl;

        int select = 0;
        cin >> select;


        for (int i = 0; i < m_EmpNum; i++)
        {
            int minOrMax = i;
            for (int j = i + 1; j < m_EmpNum; j++)
            {
                if (select == 1) //升序
                {
                    if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
                else  //降序
                {
                    if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
            }

            if (i != minOrMax)
            {
                Worker * temp = m_EmpArray[i];
                m_EmpArray[i] = m_EmpArray[minOrMax];
                m_EmpArray[minOrMax] = temp;
            }

        }

        cout << "排序成功,排序后结果为：" << endl;
        this->save();
        this->Show_Emp();
    }

}

void workerManager::Clean_File() {
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        //打开模式 ios::trunc 如果存在删除文件并重新创建
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != NULL)
                {
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功！" << endl;
    }

    system("pause");
    system("cls");

}
