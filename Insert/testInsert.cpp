#include"insert.h"

using namespace std;

void main(){
	AStack<int> *astack = new AStack<int>(100);
	for (int i = 0; i < 100; i++)
		astack->push(i);
	Insert a;
	a.initValues(astack);
	a.sort();
}