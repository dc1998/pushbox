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
	cin >> level;//����ؿ���ѡ�ء�
	MapClass mapClass(level);//���캯��ֻ��ʼ����������&������
	while (true) {
		
		mapClass.readMap(level); //��ȡ��ͼ�ļ�
		mapClass.printMap();//��ӡ��ͼ������̨


		while (!mapClass.jugeDeath(level)&&!mapClass.jugeWin(level)) {//��Ϸ�߼����ڼ�û�л�ʤ��Ҳû��ʧ�ܵ�����¿�ʼ
			cout << endl;                                              //��ʤ��ʧ�ܵ��ж����������л�ע��
			cout << "Please input a CMD: ";
			char moving;
			cin >> moving;
			mapClass.manMove(moving, mapClass.mX, mapClass.mY, level);//���������Ӻ���
			mapClass.recoverPoint(level);                             //�˺�����������������뿪��λ�󣬻ָ���λԭò����Ϸ�п�λΪ��X��
			mapClass.steps++;
			mapClass.printMap();
		}

		if (mapClass.jugeWin(level)) {//�����whileѭ����������ʤ����ʧ���������򵽴��if�ж���䡣
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

