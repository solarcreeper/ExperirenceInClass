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
	cout << "删除队列头：" << bqueue.dequeueHead() << endl;
	int a;
	cout << "输入添加到队列首部的值：";
	cin >> a;
	bqueue.enqueueHead(a);
	cout << "队首值："  <<bqueue.headValue() << endl;
	cout << "队尾值："<<bqueue.tailValue() << endl;
	cout << "删除的队尾值：" << bqueue.dequeueTail() << endl;
	system("pause");
	return 0;
}
