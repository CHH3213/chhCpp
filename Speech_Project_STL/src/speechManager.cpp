//
// Created by CHH3213 on 2022/6/14.
//


#include "../include/speechManager.h"


SpeechManager::SpeechManager() {
    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();
}

SpeechManager::~SpeechManager() {

}

void SpeechManager::show_Menu() {
    cout << "********************************************" << endl;
    cout << "*************  welcome ************" << endl;
    cout << "*************  1.begin  *************" << endl;
    cout << "*************  2.search  *************" << endl;
    cout << "*************  3.clear  *************" << endl;
    cout << "*************  0.exit  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void SpeechManager::exitSystem() {

    cout << "welcome next time" << endl;
    system("pause");
    exit(0);
}

void SpeechManager::initSpeech() {
    //容器保证为空
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();
    //初始化比赛轮数
    this->m_Index = 1;
    this->m_Record.clear();

}

void SpeechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++)
    {
        string name = "speaker_";
        name += nameSeed[i];

        Speaker sp;
        sp.m_Name = name;
        for (int i = 0; i < 2; i++)
        {
            sp.m_Score[i] = 0;
        }

        //12名选手编号
        this->v1.push_back(i + 10001);

        //选手编号 以及对应的选手 存放到map容器中
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }

}

void SpeechManager::startSpeech() {
    //第一轮比赛
    //1、抽签
    this->speechDraw();

    //2、比赛
    this->speechContest();
    //3、显示晋级结果
    this->showScore();
    //第二轮比赛
    this->m_Index++;
    //1、抽签
    this->speechDraw();
    //2、比赛
    this->speechContest();
    //3、显示最终结果
    this->showScore();
    //4、保存分数
    this->saveRecord();

    this->initSpeech();

    this->createSpeaker();
    this->loadRecord();

}

void SpeechManager::speechDraw() {
    cout << "No.<< " << this->m_Index << " >> draw"<<endl;
    cout << "---------------------" << endl;
    cout << "order: " << endl;
    if (this->m_Index == 1)
    {
        random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        random_shuffle(v2.begin(), v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "---------------------" << endl;
    system("pause");
    cout << endl;

}

void SpeechManager::speechContest()
{
    cout << "------------- NO. "<< this->m_Index << "game start:-------------" << endl;

    multimap<double, int, greater<int>> groupScore; //临时容器，保存key分数 value 选手编号

    int num = 0; //记录人员数，6个为1组

    vector <int>v_Src;   //比赛的人员容器
    if (this->m_Index == 1)
    {
        v_Src = v1;
    }
    else
    {
        v_Src = v2;
    }

    //遍历所有参赛选手
    for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
    {
        num++;

        //评委打分
        deque<double>d;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f;  // 600 ~ 1000
            //cout << score << " ";
            d.push_back(score);
        }

        sort(d.begin(), d.end(), greater<double>());				//排序
        d.pop_front();												//去掉最高分
        d.pop_back();												//去掉最低分

        double sum = accumulate(d.begin(), d.end(), 0.0f);				//获取总分
        double avg = sum / (double)d.size();									//获取平均分

        //每个人平均分
        //cout << "编号： " << *it  << " 选手： " << this->m_Speaker[*it].m_Name << " 获取平均分为： " << avg << endl;  //打印分数
        this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

        //6个人一组，用临时容器保存
        groupScore.insert(make_pair(avg, *it));
        if (num % 6 == 0)
        {

            cout << "NO." << num / 6 << "team order:" << endl;
            for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "ID. " << it->second << " NAME:  " << this->m_Speaker[it->second].m_Name << " SCORE:  " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
            }

            int count = 0;
            //取前三名
            for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
            {
                if (this->m_Index == 1)
                {
                    v2.push_back((*it).second);
                }
                else
                {
                    vVictory.push_back((*it).second);
                }
            }

            groupScore.clear();

            cout << endl;

        }
    }
    cout << "------------- NO. " << this->m_Index << "GAME END  ------------- " << endl;
    system("pause");
}

void SpeechManager::showScore() {
    cout << "---------NO." << this->m_Index << " circle Speakers info are as followed: -----------" << endl;
    vector<int>v;
    if (this->m_Index == 1)
    {
        v = v2;
    }
    else
    {
        v = vVictory;
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "ID" << *it << " NAME: " << m_Speaker[*it].m_Name << " SCORE: " << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
    }
    cout << endl;

    system("pause");
    system("cls");
    this->show_Menu();

}

void SpeechManager::saveRecord() {
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app); // 用输出的方式打开文件  -- 写文件

    //将每个人数据写入到文件中
    for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
    {
        ofs << *it << ","
            << m_Speaker[*it].m_Score[1] << ",";
    }
    ofs << endl;

    //关闭文件
    ofs.close();

    cout << "record saved!" << endl;

    this->fileIsEmpty= false;

}

void SpeechManager::loadRecord()
{
    ifstream ifs("speech.csv", ios::in); //输入流对象 读取文件

    if (!ifs.is_open())
    {
        this->fileIsEmpty = true;
        cout << "file not exist" << endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "file is none" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    //文件不为空
    this->fileIsEmpty = false;

    ifs.putback(ch); //读取的单个字符放回去

    string data;
    int index = 0;
    while (ifs >> data)
    {
        //cout << data << endl;
        vector<string>v;

        int pos = -1;
        int start = 0;

        while (true)
        {
            pos = data.find(",", start); //从0开始查找 ','
            if (pos == -1)
            {
                break; //找不到break返回
            }
            string tmp = data.substr(start, pos - start); //找到了,进行分割 参数1 起始位置，参数2 截取长度
            v.push_back(tmp);
            start = pos + 1;
        }

        this->m_Record.insert(make_pair(index, v));
        index++;
    }

    ifs.close();
}

void SpeechManager::showRecord() {
    if(this->fileIsEmpty){
        cout<<"file empty!"<<endl;
        return;
    }
    for (int i = 0; i < this->m_Record.size(); i++)
    {
        cout << "NO. " << i + 1 <<
             "CHAMPION ID" << this->m_Record[i][0] << " SCORE: " << this->m_Record[i][1] << " "
                                                                                  "SECOND ID" << this->m_Record[i][2] << " SCORE: " << this->m_Record[i][3] << " "
                                                                                                                                                       "THIRD ID: " << this->m_Record[i][4] << " SCORE: " << this->m_Record[i][5] << endl;
    }
    system("pause");
    system("cls");

}

void SpeechManager::clearRecord() {
    cout << "are you sure？" << endl;
    cout << "1. yes" << endl;
    cout << "2. no" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        //打开模式 ios::trunc 如果存在删除文件并重新创建
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();

        //初始化属性
        this->initSpeech();

        //创建选手
        this->createSpeaker();

        //获取往届记录
        this->loadRecord();


        cout << "clear success!" << endl;
    }

    system("pause");
    system("cls");

}



