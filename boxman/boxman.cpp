// boxman.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "MapClass.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{
	
	int level;//
	cout << "please enter the game level, example 1,2...";
	cin >> level;//输入关卡，选关。
	MapClass mapClass(level);//构造函数只初始化人物坐标&步数；
	while (true) {
		
		mapClass.readMap(level); //读取地图文件
		mapClass.printMap();//打印地图到控制台


		while (!mapClass.jugeDeath(level)&&!mapClass.jugeWin(level)) {//游戏逻辑仅在既没有获胜，也没有失败的情况下开始
			cout << endl;                                              //获胜和失败的判定函数在类中会注释
			cout << "Please input a CMD: ";
			char moving;
			cin >> moving;
			mapClass.manMove(moving, mapClass.mX, mapClass.mY, level);//调用推箱子函数
			mapClass.recoverPoint(level);                             //此函数用于人物和箱子离开坑位后，恢复坑位原貌，游戏中坑位为“X”
			mapClass.steps++;
			mapClass.printMap();
		}

		if (mapClass.jugeWin(level)) {//上面的while循环，如果因获胜或者失败跳出，则到达此if判断语句。
			cout << endl;
			cout << "You Win, the total steps are  ";
			cout << mapClass.steps << endl;
			cout <<"retry? y/n" << endl;
			
			string choose;
			cin >> choose;
			if (choose == "y") {
				mapClass.refreshMap(level);
			}
			else {
				exit(0);
			}

		}
		else {
			cout << endl;
			cout << "you failed, retry? y/n " << endl;
			string choose;
			cin >> choose;
			if (choose == "y") {
				mapClass.refreshMap(level);
			}
			else  {
				exit(0);
			}
		}
	}

	
	system("pause");
	

}

