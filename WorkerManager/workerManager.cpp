//
// Created by CHH3213 on 2022/6/12.
//

#include "workerManager.h"
workerManager::workerManager() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    if(!ifs.is_open()){
        cout << "�ļ�������" << endl; //�������
        this->m_EmpNum = 0;  //��ʼ������
        this->m_FileIsEmpty = true; //��ʼ���ļ�Ϊ�ձ�־
        this->m_EmpArray = NULL; //��ʼ������
        ifs.close(); //�ر��ļ�
        return;
    }
    //�ļ����ڣ�����û�м�¼
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "�ļ�Ϊ��!" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }
    int num =  this->get_EmpNum();
//    cout << "ְ������Ϊ��" << num << endl;  //���Դ���
    this->m_EmpNum = num;  //���³�Ա����
    //����ְ������������
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    //��ʼ��ְ��
    init_Emp();



}


void workerManager::showMenu() {
    cout << "********************************************" << endl;
    cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
    cout << "*************  0.�˳��������  *************" << endl;
    cout << "*************  1.����ְ����Ϣ  *************" << endl;
    cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
    cout << "*************  3.ɾ����ְְ��  *************" << endl;
    cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
    cout << "*************  5.����ְ����Ϣ  *************" << endl;
    cout << "*************  6.���ձ������  *************" << endl;
    cout << "*************  7.��������ĵ�  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void workerManager::exitSystem() {
    cout << "��ӭ�´�ʹ��" << endl;
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
    cout << "����������ְ�������� " << endl;

    int addNum = 0;
    cin >> addNum;

    if(addNum>0){
        int newSize = this->m_EmpNum+addNum;
        Worker **newSpace = new Worker*[newSize];
        //��ԭ�ռ������ݴ�ŵ��¿ռ���
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //����������
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dSelect;

            cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
            cin >> id;


            cout << "������� " << i + 1 << " ����ְ��������" << endl;
            cin >> name;


            cout << "��ѡ���ְ���ĸ�λ��" << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
            cin >> dSelect;


            Worker * worker = NULL;
            switch (dSelect)
            {
                case 1: //��ͨԱ��
                    worker = new Employee(id, name, 1);
                    break;
                case 2: //����
                    worker = new Manager(id, name, 2);
                    break;
                case 3:  //�ϰ�
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
            }


            newSpace[this->m_EmpNum + i] = worker;
        }
        //�ͷ�ԭ�пռ�
        delete[] this->m_EmpArray;

        //�����¿ռ��ָ��
        this->m_EmpArray = newSpace;

        //�����µĸ���
        this->m_EmpNum = newSize;

        //����ְ����Ϊ�ձ�־
        this->m_FileIsEmpty = false;

        //��ʾ��Ϣ
        cout << "�ɹ����" << addNum << "����ְ����" << endl;
        this->save();
    }
    else
    {
        cout << "��������" << endl;
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
        //��¼����
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
        //���ݲ�ͬ�Ĳ���Id������ͬ����
        if (dId == 1)  // 1��ͨԱ��
        {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2) //2����
        {
            worker = new Manager(id, name, dId);
        }
        else //�ܲ�
        {
            worker = new Boss(id, name, dId);
        }
        //�����������
        this->m_EmpArray[index] = worker;
        index++;
    }

}

void workerManager::Show_Emp() {
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i++)
        {
            //���ö�̬���ýӿ�
            this->m_EmpArray[i]->showInfo();
        }
    }

    system("pause");
    system("cls");
}

void workerManager::Del_Emp() {
    if (this->m_FileIsEmpty) {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    } else {
        //��ְ�����ɾ��
        cout << "��������Ҫɾ����ְ���ţ�" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);

        if (index != -1)  //˵��index��λ��������Ҫɾ��
        {
            for (int i = index; i < this->m_EmpNum - 1; i++) {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;

            this->save(); //ɾ��������ͬ�����ļ���
            cout << "ɾ���ɹ���" << endl;
        } else {
            cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
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
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else
    {
        cout << "�������޸�ְ���ı�ţ�" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1)
        {
            //���ҵ���ŵ�ְ��

            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
            cin >> newId;

            cout << "�������������� " << endl;
            cin >> newName;

            cout << "�������λ�� " << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
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

            //�������� ��������
            this->m_EmpArray[ret]= worker;

            cout << "�޸ĳɹ���" << endl;

            //���浽�ļ���
            this->save();
        }
        else
        {
            cout << "�޸�ʧ�ܣ����޴���" << endl;
        }
    }

    //������� ����
    system("pause");
    system("cls");
}

void workerManager::Find_Emp() {
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else
    {
        cout << "��������ҵķ�ʽ��" << endl;
        cout << "1����ְ����Ų���" << endl;
        cout << "2������������" << endl;

        int select = 0;
        cin >> select;


        if (select == 1) //��ְ���Ų���
        {
            int id;
            cout << "��������ҵ�ְ����ţ�" << endl;
            cin >> id;

            int ret = IsExist(id);
            if (ret != -1)
            {
                cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "����ʧ�ܣ����޴���" << endl;
            }
        }
        else if(select == 2) //����������
        {
            string name;
            cout << "��������ҵ�������" << endl;
            cin >> name;

            bool flag = false;  //���ҵ��ı�־
            for (int i = 0; i < m_EmpNum; i++)
            {
                if (m_EmpArray[i]->m_Name == name)
                {
                    cout << "���ҳɹ�,ְ�����Ϊ��"
                         << m_EmpArray[i]->m_Id
                         << " �ŵ���Ϣ���£�" << endl;

                    flag = true;

                    this->m_EmpArray[i]->showInfo();
                }
            }
            if (flag == false)
            {
                //���޴���
                cout << "����ʧ�ܣ����޴���" << endl;
            }
        }
        else
        {
            cout << "����ѡ������" << endl;
        }
    }


    system("pause");
    system("cls");
}

void workerManager::Sort_Emp() {
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "��ѡ������ʽ�� " << endl;
        cout << "1����ְ���Ž�������" << endl;
        cout << "2����ְ���Ž��н���" << endl;

        int select = 0;
        cin >> select;


        for (int i = 0; i < m_EmpNum; i++)
        {
            int minOrMax = i;
            for (int j = i + 1; j < m_EmpNum; j++)
            {
                if (select == 1) //����
                {
                    if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
                else  //����
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

        cout << "����ɹ�,�������Ϊ��" << endl;
        this->save();
        this->Show_Emp();
    }

}

void workerManager::Clean_File() {
    cout << "ȷ����գ�" << endl;
    cout << "1��ȷ��" << endl;
    cout << "2������" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        //��ģʽ ios::trunc �������ɾ���ļ������´���
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
        cout << "��ճɹ���" << endl;
    }

    system("pause");
    system("cls");

}
