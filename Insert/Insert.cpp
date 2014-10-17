#include"insert.h"

Insert::Insert(){
	source = new AStack<int>(100);
	store = new AStack<int>(100);
	ordered = new AStack<int>(100);
}

void Insert::initValues(AStack<int> *astack){
	this->source = astack;
	this->ordered->push(this->source->topValue());
	this->source->pop();
}
void Insert::getNextCompareVaule(){
	this->compare = this->source->topValue();
	this->source->pop();
}
bool Insert::compareOrderedTopValue(){
	this->getNextCompareVaule();
	if (this->compare > this->ordered->topValue())
		return true;
	else
		return false;
}
void Insert::moveToStore(){
	this->store->push(this->ordered->topValue());
	this->ordered->pop();
}
void Insert::moveFromStore(){
	this->ordered->push(this->store->topValue());
	this->store->pop();
}

void Insert::addNewValue(){
	this->ordered->push(this->compare);
}

int Insert::getLength(AStack<int> *astack){
	return astack->length();
}

AStack<int> *Insert::sort(){
	int cLength = this->getLength(this->source);
	for (int n = 0; n < cLength; n++){
		while (this->compareOrderedTopValue()){
			this->moveToStore();
		}
		this->addNewValue();
		int sLength = this->getLength(this->store);
		for (int i = 0; i < sLength; i++){
			this->ordered->push(this->store->topValue());
			this->store->pop();
		}
	}
	return this->ordered;
}