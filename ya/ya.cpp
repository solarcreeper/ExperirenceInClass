// ya.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Goods.h"
#include "ManageGoods.h"

using namespace std;

void main(){
	ManageGoods manage;
	manage.showList();
	manage.showHelp();
	string check;
	while (cin >> check){
		manage.checkIn(check);
	}
	return;
}
