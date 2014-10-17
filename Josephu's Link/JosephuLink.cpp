#include "JosephuLink.h"


JosephuLink::JosephuLink(){

}
JosephuLink::JosephuLink(int first){
	Node *node = new Node;
	this->first = node;
	this->first->pos = 1;
	this->first->data = first;
	this->first->next = this->first;
	this->length = 1;
}

JosephuLink::~JosephuLink(){

}

//插入一个值,i为插入的位置，t为插入的值，插入到i的后面
bool JosephuLink::Insert(int i, int t){
	int indexnum = i + 1;
	Node *node = new Node; //需要插入的点
	node->data = t;
	node->pos = indexnum;
	if (i <= 0 || i-1 > this->length){
		return false;
	}
	Node *curr = this->first;
	int currPos = 1;              //当前curr的位置为1
	while (i!= currPos){          //找到第i个位置，将点插入到i的后面
		curr = curr->next;
		currPos++;;
	}
	node->next = curr->next;
	curr->next = node;
	this->length++;
	return true;
}

//移除一个值，i为需要移除的位置，为了移除第i位，需要找到第i位的前一位
bool JosephuLink::Remove(int i){
	if (i <= 0 || i-1 > this->length){
		return false;
	}
	int findIPos = i + this->getLength() - 2;
	Node *curr = this->first;
	for (int n = 0; n < findIPos; n++){
		curr = curr->next;
	}
	if (i == 1){
		Node *temp = curr->next;
		this->first = temp->next;
		curr->next = this->first;
		delete temp;
		this->length--;
	}
	else{
		Node *temp = curr->next;
		curr->next = temp->next;
		delete temp;
		this->length--;
	}
	return true;
}

//获得第i个元素值
int JosephuLink::getElment(int i){
	if (i <= 0 || i-1 > this->length){
		return NULL;
	}
	Node *curr = this->first;
	while (i > 1){
		curr = curr->next;
		i--;
	}
	return curr->data;
}

//获得元素的位置
int JosephuLink::getPos(int i){
	if (i <= 0 || i - 1 > this->length){
		return NULL;
	}
	Node *curr = this->first;
	while (i > 1){
		curr = curr->next;
		i--;
	}
	return curr->pos;
}
int JosephuLink::getLength(){
	return this->length;
}

void JosephuLink::printLink(){
	cout << first->data << "  ";

	Node *curr = this->first->next;
	while (curr != this->first){
		cout << curr->data << "  ";
		curr = curr->next;
	}
	cout << endl;
}

//index为需要报的数字，pos为当前报数人的位置
void JosephuLink::josephu(int index, int pos){
	Node *curr = this->first;
	for (int n = 0; n < pos - 1; n++){
		curr = curr->next;
	}
	int sIndex = 1;           //开始报数，第一个为1
	int currPos = pos;		  //当前报数人的位置
	while (sIndex != index){
		sIndex++;
		curr = curr->next;
		currPos = (currPos++) % this->length;
	}
	int realPos = getPos(currPos);  //真是的位置，即不算出队的情况下的位置
	int nextIndex = getElment(currPos);  //下一个要报的数
	cout << realPos << " ";
	Remove(currPos);
	if (this->length > 0){
		josephu(nextIndex, (currPos++) % this->length);
	}
}