#include "stdafx.h"
#include "MapClass.h"
#include <fstream>
#include <iostream>



MapClass::MapClass(int level){
	switch (level) {//不同的关卡，对应不同的人物初始位置。
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

void MapClass::readMap(int level) {//根据输入的关卡，读取相对文件名，；
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
		
		for (int i = 0; i < 12; i++)       //将txt文件中的字符串数据，装入map【12】【13】;
			for (int j = 0; j < 13; j++)
			{
				map[i][j] = input.get();
				
			}
		
	
}

void MapClass::refreshMap(int level) {   //刷新地图，作用与构造函数相同！
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


void MapClass::printMap() {           //打印地图到控制台
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 13; j++)
			cout << map[i][j];

}

bool MapClass::jugeDeath(int level) {//判断游戏是否失败的方法：
	bool result=false;               //如果箱子的正前方和左边或者右边有墙壁，同时，箱子并不在任何坑位上，则判断游戏失败。

	if (map[mX - 1][mY] == "O")//先判断箱子的正前方和左边或者右边是否有墙壁
		if ((map[mX - 2][mY] == "#"&&map[mX - 1][mY - 1] == "#") || (map[mX - 2][mY] == "#"&&map[mX - 1][mY + 1] == "#"))		
			result= true;

	if (map[mX][mY - 1] == "O")//箱子的“前"方，共有上左下右4个方向，因此有4条判断语句。
		if ((map[mX][mY - 2] == "#"&&map[mX - 1][mY - 1] == "#") || (map[mX][mY - 2] == "#"&&map[mX + 1][mY - 1] == "#"))
			result = true;

	if (map[mX + 1][mY] == "O")
	   if ((map[mX + 2][mY] == "#"&&map[mX + 1][mY + 1] == "#") || (map[mX + 2][mY] == "#"&&map[mX + 1][mY - 1] == "#"))
		   result = true;
	   
	if (map[mX][mY+1] == "O")
		if ((map[mX][mY + 2] == "#"&&map[mX + 1][mY + 1] == "#") || (map[mX][mY + 2] == "#"&&map[mX - 1][mY + 1] == "#"))
			result = true;

	switch (level) {//再结合所选关卡，判断箱子是否不在任何一个坑位上，返回结果
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
		
		



bool MapClass::jugeWin(int level) {//所有坑位坐标上的“X” 均变为“O”，则游戏获胜。如何让X变O，请看下文recoverPoint方法
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



void MapClass::manMove(char moving, int mX1, int mY1,int level) {//推动箱子的算法
	mX = mX1;
	mY = mY1;
	

	switch (moving) {
	case 'w':
		if (map[mX - 1][mY] == "O"&&(map[mX - 2][mY] == " "||map[mX - 2][mY] == "X")) {//向上推时，如果人前有箱子，箱子前面又为空或者坑位X
		map[mX][mY] = " ";         //则将人走后的位置，用空格代替
		map[mX - 1][mY] = "I";     //原箱子位，用人I代替
		map[mX - 2][mY] = "O";     //原空位或者坑位，用箱子O代替
		--mX;                      //刷新人物移动方向坐标
		
	}
			 else if (map[mX-1][mY]==" ") {//如果人前面没箱子，为空位的代替情况
				 map[mX - 1][mY] = "I";
				 map[mX][mY] = " ";
				 --mX;
				 		 
	}
			 else if (map[mX - 1][mY] == "X") {//如果人前面没箱子，为坑位的代替情况
				 map[mX - 1][mY] = "I";
				 map[mX][mY] = " ";
				 --mX;
				 
			 };
		break;

	case 'a':
		if (map[mX ][mY-1] == "O"&&(map[mX ][mY-2] == " "|| map[mX][mY - 2] == "X")) {//同上，方向变为左
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

void MapClass::recoverPoint(int level) {//如果原坑位坐标上的数据，既非人I，也非箱子O，则恢复坑位数据X
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