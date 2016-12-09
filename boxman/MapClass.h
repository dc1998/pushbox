#pragma once
#ifndef MAPCLASS_H
#define MAPCLASS_H
#include<String>
using namespace std;

class MapClass {
public:
	int mX, mY,steps;//声明人物坐标manX，manY 及步数
	
	string map[12][13];//声明二维数组，用于存放所有关卡的地图数据

	MapClass(int level);
	~MapClass();
	void readMap(int level);
	void refreshMap(int level);
	void printMap();
	bool jugeDeath(int level);
	bool jugeWin(int level);
	void manMove(char w,int mX,int mY,int level);
	void recoverPoint(int level);
	


};

#endif
