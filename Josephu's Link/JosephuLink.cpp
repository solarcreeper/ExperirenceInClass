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

//����һ��ֵ,iΪ�����λ�ã�tΪ�����ֵ�����뵽i�ĺ���
bool JosephuLink::Insert(int i, int t){
	int indexnum = i + 1;
	Node *node = new Node; //��Ҫ����ĵ�
	node->data = t;
	node->pos = indexnum;
	if (i <= 0 || i-1 > this->length){
		return false;
	}
	Node *curr = this->first;
	int currPos = 1;              //��ǰcurr��λ��Ϊ1
	while (i!= currPos){          //�ҵ���i��λ�ã�������뵽i�ĺ���
		curr = curr->next;
		currPos++;;
	}
	node->next = curr->next;
	curr->next = node;
	this->length++;
	return true;
}

//�Ƴ�һ��ֵ��iΪ��Ҫ�Ƴ���λ�ã�Ϊ���Ƴ���iλ����Ҫ�ҵ���iλ��ǰһλ
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

//��õ�i��Ԫ��ֵ
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

//���Ԫ�ص�λ��
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

//indexΪ��Ҫ�������֣�posΪ��ǰ�����˵�λ��
void JosephuLink::josephu(int index, int pos){
	Node *curr = this->first;
	for (int n = 0; n < pos - 1; n++){
		curr = curr->next;
	}
	int sIndex = 1;           //��ʼ��������һ��Ϊ1
	int currPos = pos;		  //��ǰ�����˵�λ��
	while (sIndex != index){
		sIndex++;
		curr = curr->next;
		currPos = (currPos++) % this->length;
	}
	int realPos = getPos(currPos);  //���ǵ�λ�ã���������ӵ�����µ�λ��
	int nextIndex = getElment(currPos);  //��һ��Ҫ������
	cout << realPos << " ";
	Remove(currPos);
	if (this->length > 0){
		josephu(nextIndex, (currPos++) % this->length);
	}
}