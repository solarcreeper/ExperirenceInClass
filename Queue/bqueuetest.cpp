#include "stdafx.h"
#include <iostream>
#include "bqueue.h"

using namespace std;

int main() {
	BQueue<int> bqueue(10);
	int array[10];
	for (int i = 0; i < 10; i++){
		array[i] = i;
	}
	for (int i = 0; i < 10; i++){
		bqueue.enqueueTail(array[i]);
	}
	cout << "ɾ������ͷ��" << bqueue.dequeueHead() << endl;
	int a;
	cout << "������ӵ������ײ���ֵ��";
	cin >> a;
	bqueue.enqueueHead(a);
	cout << "����ֵ��"  <<bqueue.headValue() << endl;
	cout << "��βֵ��"<<bqueue.tailValue() << endl;
	cout << "ɾ���Ķ�βֵ��" << bqueue.dequeueTail() << endl;
	system("pause");
	return 0;
}
