#include <iostream>
#include "include/speechManager.h"
#include <time.h>
int main() {
    srand((unsigned int)time(NULL));
    SpeechManager sm;

    int choice;
    while (true)
    {
        sm.show_Menu();

        cout << "input choice:" << endl;
        cin >> choice; // 接受用户的选项

        switch (choice)
        {
            case 1:  //开始比赛
            sm.startSpeech();
                break;
            case 2:  //查看记录
            sm.showRecord();
                break;
            case 3:  //清空记录
            sm.clearRecord();
                break;
            case 0:  //退出系统
                sm.exitSystem();
                break;
            default:
                system("cls"); //清屏
                break;
        }
    }

    system("pause");

    return 0;
}
