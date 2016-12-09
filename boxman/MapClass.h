#pragma once
#ifndef MAPCLASS_H
#define MAPCLASS_H
#include<String>
using namespace std;

class MapClass {
public:
	int mX, mY,steps;//������������manX��manY ������
	
	string map[12][13];//������ά���飬���ڴ�����йؿ��ĵ�ͼ����

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
