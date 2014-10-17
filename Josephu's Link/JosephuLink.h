#ifndef JOSEPHULINK_H
#define JOSEPHULINK_H
#include "Node.h"

class JosephuLink{
public:
	Node *first;

	JosephuLink();
	JosephuLink(int first);     //初始位置为1
	~JosephuLink();
	bool Insert(int i, int t);	//插入一个值,i为插入的位置，t为插入的值，插入到i的后面
	bool Remove(int i);			//移除一个值，i为需要移除的位置
	int getLength();			//获得环的长度
	int getElment(int i);       //获得第i个元素值
	int getPos(int i);			//获得元素的位置
	void printLink();			//打印整个环	
	void josephu(int index, int pos);  //index为需要报的数字，pos为当前报数人的位置

private:
	int length;					//环的长度
};
#endif