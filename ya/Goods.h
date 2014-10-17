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


	//对成员变量的设置函数
	void setGoodsNum(int num);	     //设置商品件数
	void initGoodsNum();			 //初始化商品件数，用于构造单个示例
	void setProducedata(string date);
	void setDeadline(string date);
	void setDescription(string desc);
	void setName(string name);
	void setPrice(float price);
	

public:
	Goods();						 //默认构造
	~Goods();
	Goods(int num, string name,float price,string pdate, string dline, string desc);//构造
	Goods(Goods &goods);		     //拷贝构造
	void   showGoods();			     //显示商品信息
	string getName();				 //获得name
	float  getPrice();				 //获得price
	string getProducedate();		 //获得生产日期
	string getDeadline();			 //获得保质期
	string getDescription();		 //获得商品描述
	int    getGoodsNum();			 //获得商品件数
	
};
#endif