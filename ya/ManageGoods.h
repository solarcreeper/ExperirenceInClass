#include "Goods.h"
#include <fstream>
#include <stdio.h>

using namespace std;

#ifndef MANAGEGOODS_H
#define MANAGEGOODS_H

class ManageGoods{
private:
	Goods goodsList[1000];
	int   typeNum;				

	void  initTypeNum();
	void  addTypeNum();
	void  reduceTypeNum();
	void  readList();						      //从文件中读取数据

public:

	ManageGoods();
	~ManageGoods();	
	void  storeList();									  //存储数据到文件
	void  addGoods(Goods &goods);						  //在列位添加一个goods
	bool  delGoods(string name);						  //删除任意一个goods
	void  modifyGoods(string name, const Goods &goods);   //修改一个goods
	void  findByNum(int x);								  //通过商品数量查找
	bool  findByName(string name);						  //通过姓名查找
	Goods getByName(string name);                         //好像没啥用了
	Goods getGoods(int i);						
	void  showList();
	int   getTypenum();
	void  checkIn(string in);
	void  showHelp();
};
#endif