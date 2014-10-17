#ifndef JOSEPHULINK_H
#define JOSEPHULINK_H
#include "Node.h"

class JosephuLink{
public:
	Node *first;

	JosephuLink();
	JosephuLink(int first);     //��ʼλ��Ϊ1
	~JosephuLink();
	bool Insert(int i, int t);	//����һ��ֵ,iΪ�����λ�ã�tΪ�����ֵ�����뵽i�ĺ���
	bool Remove(int i);			//�Ƴ�һ��ֵ��iΪ��Ҫ�Ƴ���λ��
	int getLength();			//��û��ĳ���
	int getElment(int i);       //��õ�i��Ԫ��ֵ
	int getPos(int i);			//���Ԫ�ص�λ��
	void printLink();			//��ӡ������	
	void josephu(int index, int pos);  //indexΪ��Ҫ�������֣�posΪ��ǰ�����˵�λ��

private:
	int length;					//���ĳ���
};
#endif