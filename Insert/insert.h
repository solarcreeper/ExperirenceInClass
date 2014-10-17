#ifndef INSERT_H
#define INSERT_H

#include"astack.h"

class Insert{
private:
	int compare;//��ʱ�洢�Ƚ���ֵ
	int swap;

	AStack<int> *source;//δ����ջ
	AStack<int> *store;//��ʱ�洢
	AStack<int> *ordered;//����ջ

	
	void getNextCompareVaule(); // �����һ����Ҫ�����ֵ�������Ա����compare
	bool compareOrderedTopValue();//����Ҫ�����ֵ�����кõ�ջ����ֵ�Ƚ�
	void moveToStore();//���źõ�ջֵ�ƶ�����ʱ�洢ջ
	void moveFromStore();//��ʱջ��ֵ����ordered��
	void addNewValue();//��ordered����µ�ֵ
	int getLength(AStack<int> *stack);

public:
	Insert();
	~Insert();

	void initValues(AStack<int> *astack);
	AStack<int> *sort();


	
};
#endif