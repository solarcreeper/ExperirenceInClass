#ifndef INSERT_H
#define INSERT_H

#include"astack.h"

class Insert{
private:
	int compare;//临时存储比较数值
	int swap;

	AStack<int> *source;//未排序栈
	AStack<int> *store;//临时存储
	AStack<int> *ordered;//排序栈

	
	void getNextCompareVaule(); // 获得下一个需要排序的值，放入成员变量compare
	bool compareOrderedTopValue();//将需要排序的值与排列好的栈顶端值比较
	void moveToStore();//将排好的栈值移动到临时存储栈
	void moveFromStore();//临时栈的值返回ordered中
	void addNewValue();//向ordered添加新的值
	int getLength(AStack<int> *stack);

public:
	Insert();
	~Insert();

	void initValues(AStack<int> *astack);
	AStack<int> *sort();


	
};
#endif