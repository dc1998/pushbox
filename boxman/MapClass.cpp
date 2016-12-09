#include "stdafx.h"
#include "MapClass.h"
#include <fstream>
#include <iostream>



MapClass::MapClass(int level){
	switch (level) {//��ͬ�Ĺؿ�����Ӧ��ͬ�������ʼλ�á�
	case 1: mX = 4; mY = 3; steps = 0;
		break;
	case 2: mX = 1; mY = 1; steps = 0;
		break;
	case 3: mX = 6; mY = 2; steps = 0;
		break;
	case 4: mX = 2; mY = 1; steps = 0;
		break;
	case 5: mX = 1; mY = 2; steps = 0;
		break;
	case 6: mX = 3; mY = 8; steps = 0;
		break;
	case 7: mX = 6; mY = 8; steps = 0;
		break;
	case 8: mX = 10; mY = 8; steps = 0;
		break;
	}
}

MapClass::~MapClass()
{
}

void MapClass::readMap(int level) {//��������Ĺؿ�����ȡ����ļ�������
	ifstream input;
	string fileName;

	switch (level) {
	case 1:
		fileName = "level1.txt";
		break;
	case 2:
		fileName = "level2.txt";
		break;
	case 3:fileName = "level3.txt";
		break;
	case 4:fileName = "level4.txt";
		break;
	case 5:fileName = "level5.txt";
		break;
	case 6:fileName = "level6.txt";
		break;
	case 7:fileName = "level7.txt";
		break;
	case 8:fileName = "level8.txt";
		break;
	}
		input.open(fileName);
		
		for (int i = 0; i < 12; i++)       //��txt�ļ��е��ַ������ݣ�װ��map��12����13��;
			for (int j = 0; j < 13; j++)
			{
				map[i][j] = input.get();
				
			}
		
	
}

void MapClass::refreshMap(int level) {   //ˢ�µ�ͼ�������빹�캯����ͬ��
	switch (level) {
	case 1: mX = 4; mY = 3; steps = 0;
		break;
	case 2: mX = 1; mY = 1; steps = 0;
		break;
	case 3: mX = 6; mY = 2; steps = 0;
		break;
	case 4: mX = 2; mY = 1; steps = 0;
		break;
	case 5: mX = 1; mY = 2; steps = 0;
		break;
	case 6: mX = 3; mY = 8; steps = 0;
		break;
	case 7: mX = 6; mY = 8; steps = 0;
		break;
	case 8: mX = 10; mY = 8; steps = 0;
		break;

	}
}


void MapClass::printMap() {           //��ӡ��ͼ������̨
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 13; j++)
			cout << map[i][j];

}

bool MapClass::jugeDeath(int level) {//�ж���Ϸ�Ƿ�ʧ�ܵķ�����
	bool result=false;               //������ӵ���ǰ������߻����ұ���ǽ�ڣ�ͬʱ�����Ӳ������κο�λ�ϣ����ж���Ϸʧ�ܡ�

	if (map[mX - 1][mY] == "O")//���ж����ӵ���ǰ������߻����ұ��Ƿ���ǽ��
		if ((map[mX - 2][mY] == "#"&&map[mX - 1][mY - 1] == "#") || (map[mX - 2][mY] == "#"&&map[mX - 1][mY + 1] == "#"))		
			result= true;

	if (map[mX][mY - 1] == "O")//���ӵġ�ǰ"����������������4�����������4���ж���䡣
		if ((map[mX][mY - 2] == "#"&&map[mX - 1][mY - 1] == "#") || (map[mX][mY - 2] == "#"&&map[mX + 1][mY - 1] == "#"))
			result = true;

	if (map[mX + 1][mY] == "O")
	   if ((map[mX + 2][mY] == "#"&&map[mX + 1][mY + 1] == "#") || (map[mX + 2][mY] == "#"&&map[mX + 1][mY - 1] == "#"))
		   result = true;
	   
	if (map[mX][mY+1] == "O")
		if ((map[mX][mY + 2] == "#"&&map[mX + 1][mY + 1] == "#") || (map[mX][mY + 2] == "#"&&map[mX - 1][mY + 1] == "#"))
			result = true;

	switch (level) {//�ٽ����ѡ�ؿ����ж������Ƿ����κ�һ����λ�ϣ����ؽ��
	case 1:
		return result&&map[1][4] == "X"&&map[3][1] == "X"&&map[6][3] == "X"&&map[4][6]=="X";
		
	case 2:
		return result&&map[3][7] == "X"&&map[4][7] == "X"&&map[5][7] == "X";			
	case 3:
		return result&&map[7][2] == "X"&&map[7][3] == "X"&&map[8][2] == "X"&&map[8][3] == "X";			
	case 4:
		return result&&map[5][1] == "X"&&map[6][1] == "X"&&map[6][2] == "X"&&map[6][4] == "X";			
	case 5:
		return result&&map[4][1] == "X"&&map[5][1] == "X"&&map[6][1] == "X";			
	case 6:
		return result&&map[8][1] == "X"&&map[8][2] == "X"&&map[8][3] == "X"&&map[8][4] == "X"&&map[8][5] == "X";			
	case 7:
		return result&&map[5][2] == "X"&&map[6][1] == "X"&&map[6][2] == "X"&&map[7][1] == "X"&&map[7][2] == "X";			
	case 8:
		return result&&map[7][4] == "X"&&map[7][5] == "X"&&map[7][6] == "X"&&map[8][4] == "X"&&map[8][5] == "X"&&map[8][6] == "X";
	}
	
	
}
		
		



bool MapClass::jugeWin(int level) {//���п�λ�����ϵġ�X�� ����Ϊ��O��������Ϸ��ʤ�������X��O���뿴����recoverPoint����
	bool result=false;
	switch (level) {
	case 1:
		if (map[1][4] == "O"&&map[3][1] == "O"&&map[6][3] == "O"&&map[4][6] == "O")
			result = true;
		break;
			case 2:
				if (map[3][7] == "O"&&map[4][7] == "O"&&map[5][7]=="O")
					result = true;
				break;
			case 3:
				if (map[7][2] == "O"&&map[7][3] == "O"&&map[8][2]=="O"&&map[8][3] == "O")
					result = true;
				break;
			case 4:
				if (map[5][1] == "O"&&map[6][1] == "O"&&map[6][2] == "O"&&map[6][4] == "O")
					result = true;
				break;
			case 5:
				if (map[4][1] == "O"&&map[5][1] == "O"&&map[6][1] == "O")
					result = true;
				break;
			case 6:
				if (map[8][1] == "O"&&map[8][2] == "O"&&map[8][3] == "O"&&map[8][4] == "O"&&map[8][5] == "O")
					result = true;
				break;
			case 7:
				if (map[5][2] == "O"&&map[6][1] == "O"&&map[6][2] == "O"&&map[7][1] == "O"&&map[7][2] == "O")
					result = true;
				break;
			case 8:
				if (map[7][4] == "O"&&map[7][5] == "O"&&map[7][6] == "O"&&map[8][4] == "O"&&map[8][5] == "O"&&map[8][6] == "O")
					result = true;
				break;
			default: return false;
			}
		
	return result;

}



void MapClass::manMove(char moving, int mX1, int mY1,int level) {//�ƶ����ӵ��㷨
	mX = mX1;
	mY = mY1;
	

	switch (moving) {
	case 'w':
		if (map[mX - 1][mY] == "O"&&(map[mX - 2][mY] == " "||map[mX - 2][mY] == "X")) {//������ʱ�������ǰ�����ӣ�����ǰ����Ϊ�ջ��߿�λX
		map[mX][mY] = " ";         //�����ߺ��λ�ã��ÿո����
		map[mX - 1][mY] = "I";     //ԭ����λ������I����
		map[mX - 2][mY] = "O";     //ԭ��λ���߿�λ��������O����
		--mX;                      //ˢ�������ƶ���������
		
	}
			 else if (map[mX-1][mY]==" ") {//�����ǰ��û���ӣ�Ϊ��λ�Ĵ������
				 map[mX - 1][mY] = "I";
				 map[mX][mY] = " ";
				 --mX;
				 		 
	}
			 else if (map[mX - 1][mY] == "X") {//�����ǰ��û���ӣ�Ϊ��λ�Ĵ������
				 map[mX - 1][mY] = "I";
				 map[mX][mY] = " ";
				 --mX;
				 
			 };
		break;

	case 'a':
		if (map[mX ][mY-1] == "O"&&(map[mX ][mY-2] == " "|| map[mX][mY - 2] == "X")) {//ͬ�ϣ������Ϊ��
			map[mX][mY] = " ";
			map[mX ][mY-1] = "I";
			map[mX ][mY-2] = "O";
			--mY;
			
		}
		else if (map[mX ][mY-1] == " ") {
			map[mX ][mY-1] = "I";
			map[mX][mY] = " ";
			--mY;
			
		}
		else if (map[mX][mY - 1] == "X") {
			map[mX][mY - 1] = "I";
			map[mX][mY] = " ";
			--mY;
			
		};
		break;

	case 's':
		if (map[mX + 1][mY] == "O"&&(map[mX + 2][mY] == " "|| map[mX + 2][mY] == "X")) {
			map[mX][mY] = " ";
			map[mX + 1][mY] = "I";
			map[mX + 2][mY] = "O";
			++mX;
		
		}
		else if (map[mX + 1][mY] == " ") {
			map[mX + 1][mY] = "I";
			map[mX][mY] = " ";
			++mX;
			
		}
		else if (map[mX + 1][mY] == "X") {
			map[mX + 1][mY] = "I";
			map[mX][mY] = " ";
			++mX;
			
		}
		;

		break;

	case 'd':
		if (map[mX][mY+1] == "O"&&(map[mX][mY+2] == " "|| map[mX][mY + 2] == "X")) {
			map[mX][mY] = " ";
			map[mX][mY+1] = "I";
			map[mX][mY+2] = "O";
			++mY;
			
		}
		else if (map[mX][mY+1] == " ") {
			map[mX][mY+1] = "I";
			map[mX][mY] = " ";
			++mY;
			
		}
		else if (map[mX][mY + 1] == "X") {
			map[mX][mY + 1] = "I";
			map[mX][mY] = " ";
			++mY;
			
		};
		break;
	}

}

void MapClass::recoverPoint(int level) {//���ԭ��λ�����ϵ����ݣ��ȷ���I��Ҳ������O����ָ���λ����X
	switch (level) {
	case 1:if ((map[1][4] != "O" )&&( map[1][4] != "I"))
		    map[1][4] = "X";
		
		if ((map[3][1] != "O") && (map[3][1] != "I"))
			map[3][1] = "X";
		
		if ((map[6][3] != "O" )&&( map[6][3] != "I"))
			map[6][3] = "X";

		break;
		
	case 2:
		
		if ((map[3][7] != "O") && (map[3][7] != "I"))
			map[3][7] = "X";

		if ((map[4][7] != "O") && (map[4][7] != "I"))
			map[4][7] = "X";

		if ((map[5][7] != "O") && ( map[5][7] != "I"))
			map[5][7] = "X";

		break;
	case 3:
		
		if ((map[7][2] != "O" ) && ( map[7][2] != "I"))
			map[7][2] = "X";

		if ((map[8][2] != "O" ) && ( map[8][2] != "I"))
			map[8][2] = "X";

		if ((map[8][3] != "O") && ( map[8][3] != "I"))
			map[8][3] = "X";
		
		if ((map[7][3] != "O") && (map[7][3] != "I"))
			map[7][3] = "X";

		break;
	case 4:

		if ((map[5][1] != "O") && (map[5][1] != "I"))
			map[5][1] = "X";

		if ((map[6][1] != "O") && (map[6][1] != "I"))
			map[6][1] = "X";

		if ((map[6][2] != "O" ) && ( map[6][2] != "I"))
			map[6][2] = "X";

		if (map[6][4] != "O" && map[6][4] != "I")
			map[6][4] = "X";

		break;
	case 5:
	
		if ((map[4][1] != "O") &&( map[4][1] != "I"))
			map[4][1] = "X";

		 if ((map[5][1] != "O") && (map[5][1] != "I"))
			map[5][1] = "X";

		 if ((map[6][1] != "O" )&& (map[6][1] != "I"))
			map[6][1] = "X";

		break;
	case 6:
		
		if ((map[8][1] != "O" ) && (map[8][1] != "I"))
			map[8][1] = "X";

		if (map[8][2] != "O" && map[8][2] != "I")
			map[8][2] = "X";

		if (map[8][3] != "O" && map[8][3] != "I")
			map[8][3] = "X";

		if (map[8][4] != "O" && map[8][4] != "I")
			map[8][4] = "X";
		
		if (map[8][5] != "O" && map[8][5] != "I")
			map[8][5] = "X";

		break;
	case 7:
	
		if (map[5][2] != "O" && map[5][2] != "I")
			map[5][2] = "X";

		if (map[6][1] != "O" && map[6][1] != "I")
			map[6][1] = "X";

		if (map[6][2] != "O" && map[6][2] != "I")
			map[6][2] = "X";

		if (map[7][1] != "O" && map[7][1] != "I")
			map[7][1] = "X";

		if (map[7][2] != "O" && map[7][2] != "I")
			map[7][2] = "X";

		break;
	case 8:
		
		if (map[7][4] != "O" && map[7][4] != "I")
			map[7][4] = "X";

		if (map[7][5] != "O" && map[7][5] != "I")
			map[7][5] = "X";

		if (map[7][6] != "O" && map[7][6] != "I")
			map[7][6] = "X";

		if (map[8][4] != "O" && map[8][4] != "I")
			map[8][4] = "X";

		if (map[8][4] != "O" && map[8][4] != "I")
			map[8][4] = "X";

		if (map[8][5] != "O" && map[8][5] != "I")
			map[8][5] = "X";

		if (map[8][6] != "O" && map[8][6] != "I")
			map[8][6] = "X";
		break;
	}

}