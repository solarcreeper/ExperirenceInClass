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
	void  readList();						      //���ļ��ж�ȡ����

public:

	ManageGoods();
	~ManageGoods();	
	void  storeList();									  //�洢���ݵ��ļ�
	void  addGoods(Goods &goods);						  //����λ���һ��goods
	bool  delGoods(string name);						  //ɾ������һ��goods
	void  modifyGoods(string name, const Goods &goods);   //�޸�һ��goods
	void  findByNum(int x);								  //ͨ����Ʒ��������
	bool  findByName(string name);						  //ͨ����������
	Goods getByName(string name);                         //����ûɶ����
	Goods getGoods(int i);						
	void  showList();
	int   getTypenum();
	void  checkIn(string in);
	void  showHelp();
};
#endif