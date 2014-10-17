#ifndef GOODS_H
#define GOODS_H
#include <string>
#include <iostream>
#include "stdafx.h"

using namespace std;

class Goods{
private:
	int    num;
	string name;
	float  price;
	string producedate;
	string deadline;
	string description;


	//�Գ�Ա���������ú���
	void setGoodsNum(int num);	     //������Ʒ����
	void initGoodsNum();			 //��ʼ����Ʒ���������ڹ��쵥��ʾ��
	void setProducedata(string date);
	void setDeadline(string date);
	void setDescription(string desc);
	void setName(string name);
	void setPrice(float price);
	

public:
	Goods();						 //Ĭ�Ϲ���
	~Goods();
	Goods(int num, string name,float price,string pdate, string dline, string desc);//����
	Goods(Goods &goods);		     //��������
	void   showGoods();			     //��ʾ��Ʒ��Ϣ
	string getName();				 //���name
	float  getPrice();				 //���price
	string getProducedate();		 //�����������
	string getDeadline();			 //��ñ�����
	string getDescription();		 //�����Ʒ����
	int    getGoodsNum();			 //�����Ʒ����
	
};
#endif