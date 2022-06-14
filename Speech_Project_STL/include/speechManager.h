//
// Created by CHH3213 on 2022/6/14.
//

#ifndef SPEECH_PROJECT_STL_SpeechManager_H
#define SPEECH_PROJECT_STL_SpeechManager_H
#pragma once
#include <iostream>
#include <vector>
#include <map>
#include"Speaker.h"
#include<algorithm>
#include <deque>
#include<cmath>
#include <numeric>
#include <fstream>
using namespace std;

class SpeechManager {
public:
    SpeechManager();
    ~SpeechManager();
    void show_Menu();
    void exitSystem();
    //初始化属性
    void initSpeech();
    //初始化创建12名选手
    void createSpeaker();
    //开始比赛 - 比赛流程控制
    void startSpeech();
    //抽签
    void speechDraw();
    //比赛
    void speechContest();

    //显示比赛结果
    void showScore();
    //保存记录
    void saveRecord();


    //读取记录
    void loadRecord();
    //显示往届得分
    void showRecord();

    //清空记录
    void clearRecord();

    //文件为空的标志
    bool fileIsEmpty;

    //往届记录
    map<int, vector<string>> m_Record;


    //比赛选手 容器  12人
    vector<int>v1;

    //第一轮晋级容器  6人
    vector<int>v2;

    //胜利前三名容器  3人
    vector<int>vVictory;

    //存放编号 以及对应的 具体选手 容器
    map<int, Speaker> m_Speaker;

    int m_Index;
};


#endif //SPEECH_PROJECT_STL_SpeechManager_H
