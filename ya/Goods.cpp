#include "stdafx.h"
#include "Goods.h"

Goods::Goods(){
}

Goods::~Goods(){

}

Goods::Goods(Goods&goods){
	this->setGoodsNum(goods.getGoodsNum());
	this->setName(goods.getName());
	this->setPrice(goods.getPrice());
	this->setProducedata(goods.getProducedate());
	this->setDeadline(goods.getDeadline());
	this->setDescription(goods.getDescription());
	this->setGoodsNum(goods.getGoodsNum());
}

Goods::Goods(int num, string name, float price, string pdate, string dline, string desc){
	this->setGoodsNum(num);
	this->setName(name);
	this->setPrice(price);
	this->setProducedata(pdate);
	this->setDeadline(dline);
	this->setDescription(desc);
}

string Goods::getName(){
	return this->name;
}

float Goods::getPrice(){
	return this->price;
}

string Goods::getProducedate(){
	return this->producedate;
}

string Goods::getDeadline(){
	return this->deadline;
}

string Goods::getDescription(){
	return this->description;
}

void Goods::setName(string name){
	this->name = name;
}

void Goods::setPrice(float price){
	this->price = price;
}

void Goods::setProducedata(string date){
	this->producedate = date;
}

void Goods::setDeadline(string date){
	this->deadline = date;
}

void Goods::setDescription(string desc){
	this->description = desc;
}


void Goods::showGoods(){
	string description = this->getDescription();
	string name		   = this->getName();
	name.resize(12);
	string price = to_string(this->getPrice());
	price.resize(4);
	description.erase(0, description.find_first_not_of(" \t")); // 去掉头部空格
    description.erase(description.find_last_not_of(" \t") + 1); // 去掉尾部空格
	cout << this->getGoodsNum() << "	  ";
	cout << name<< "	";
	cout << price<< "    ";
	cout << this->getProducedate()<< "	";
	cout << this->getDeadline()<< "      ";
	cout << description << endl;
}

void Goods::initGoodsNum(){
	this->num = 0;
}

void Goods::setGoodsNum(int num){
	this->num = num;
}

int Goods::getGoodsNum(){
	return this->num;
}