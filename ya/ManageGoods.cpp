#include"stdafx.h"
#include"ManageGoods.h"

ManageGoods::ManageGoods(){
	this->initTypeNum();
	this->readList();
}

ManageGoods::~ManageGoods(){

}

void ManageGoods::readList(){
	string *name		= new string[2000];
	float *price		= new float[2000];
	string *producedate = new string[2000];
	string *deadline    = new string[2000];
	string *description = new string[2000];
	int goodsnum;
	int i = 0;
	ifstream file; 
	char buffer[256];
	file.open("GoodsList.txt",ios::in);
	file.getline(buffer, 256, '\n');
	while(!file.eof()) //读取数据到数组
	{ 
		file >> goodsnum;
		file >> name[i];
		file >> price[i];
		file >> producedate[i];
		file >> deadline[i];
		file.getline(buffer, 256, '\n');
		description[i] = buffer;

		Goods x(goodsnum, name[i], price[i], producedate[i], deadline[i],description[i]);
		this->goodsList[i] = x;
		this->addTypeNum();
		i++; 
	} 
	this->reduceTypeNum();
	file.close();
	delete []name;
	delete []price;
	delete []producedate;
	delete []deadline;
	delete []description;
}

void ManageGoods::storeList(){
	ofstream in;
	in.open("GoodsList.txt",ios::trunc); //ios::trunc表示在打开文件前将文件清空,由于是写入,文件不存在则创建
	int endnum = this->getTypenum();
	in << "amount" << "\t" << "   name   " << "\t" << "price" <<  "\t" << "produce Date" <<  "\t" << "shelf life" << "\t" << "introduction" <<"\n";
	for(int i = 0; i < endnum; i++){
		in << this->goodsList[i].getGoodsNum()		<< "\t";
		in << this->goodsList[i].getName()			<< "\t";
		in << this->goodsList[i].getPrice()			<< "\t";
		in << this->goodsList[i].getProducedate()   << "\t";
		in << this->goodsList[i].getDeadline()		<< "     \t";
		string desc = this->goodsList[i].getDescription();
		desc.erase(0, desc.find_first_not_of(" \t"));
		//desc.erase(desc.find_last_not_of(" \t"));
		in <<  desc << "\n";
	}
	in.close();//关闭文件
}

void ManageGoods::addGoods(Goods &goods){
	int i = this->getTypenum();
	this->goodsList[i] = goods;
	this->addTypeNum();
}

bool ManageGoods::delGoods(string name){
	bool flag = false;
	for(int i = 0; i < this->getTypenum(); i++){
		if(name == this->goodsList[i].getName()){
			for(int j = i; j < this->getTypenum(); j++){
				this->goodsList[j] = this->goodsList[j+1];
			}
			flag = true;
		}
	}
	this->reduceTypeNum();
	this->storeList();
	return flag;
}

void ManageGoods::modifyGoods(string name, const Goods &goods){
	for(int i = 0; i < this->getTypenum(); i++){
		if(name == goodsList[i].getName()){
			this->goodsList[i] = goods;
		}
	}
}

void ManageGoods::initTypeNum(){
	this->typeNum = 0;
}
void ManageGoods::addTypeNum(){
	this->typeNum++;
}

void ManageGoods::reduceTypeNum(){
	if(this->typeNum > 0 )
		this->typeNum--;
}

int ManageGoods::getTypenum(){
	return this->typeNum;
}

Goods ManageGoods::getGoods(int i){
	return this->goodsList[i];
}

void ManageGoods::showList(){
	cout << "amount	   name   	price	produce Date	shelf life	introduction" << endl;
	for(int i = 0; i < this->getTypenum(); i++){
		this->goodsList[i].showGoods();
	}
	cout << endl;
}

void ManageGoods::findByNum(int x){
	for(int i = 0; i < this->getTypenum(); i++){
		if(x == goodsList[i].getGoodsNum()){
			this -> goodsList[i].showGoods();
		}
	}
}
Goods ManageGoods::getByName(string name){
	for(int i = 0; i < this->getTypenum(); i++){
		if(name == goodsList[i].getName()){
			return this -> goodsList[i];
		}
	}
}

bool ManageGoods::findByName(string name){
	bool flag = false;
	for(int i = 0; i < this->getTypenum(); i++){
		if(name == goodsList[i].getName()){
			this -> goodsList[i].showGoods();
			flag = true;
		}
	}
	return flag;
}

void ManageGoods::checkIn(string in){

	if(in == "ADD"){
		cout << "please enter a new goods(enter all the properties of one goods in order!!):" << endl;
		int num;
		string name;
		float price;
		string produceDate;
		string deadline;
		string desc;
		cin >> num >> name >> price >> produceDate >> deadline >> desc;
		Goods goods(num, name, price, produceDate, deadline, desc);
		this->addGoods(goods);
		this->storeList();
		system("cls");
		this->showList();
	}

	else if(in == "ALTER"){
		cout << "enter the name of the goods:";
		string findname;
		cin >> findname;
		if(this->findByName(findname)){
			cout << "FIND THE GOODS  " << findname << "  AND ENTER THE CHANGED GOODS PROPERTY:" << endl;
			int num;
			string name;
			float price;
			string pData;
			string Dline;
			string desc;
			cin >> num >> name >> price >> pData >> Dline >> desc;
			Goods goods(num, name, price, pData, Dline, desc);
			this->modifyGoods(findname, goods);
			system("cls");
			cout << "SUCCESS!!!" << endl;
			this->showList();

		}
		else{
			system("cls");
			cout << "CAN NOT FIND THIS GOODS!!!" << endl << endl;
			this->showList();
		}
	}

	else if(in == "DEL"){
		cout << "please enter the name of the goods:";
		string name;
		cin >> name;
		if(this->delGoods(name)){
			system("cls");
			cout << "SUCCESS!!!" << endl << endl;
			this->showList();
		}
		else{
			system("cls");
			cout << "FAIL!!!" << endl << endl;
			this->showList();
		}
	}

	else if(in == "QUERY"){
		cout << "please enter the name of the goods:";
		string name;
		cin >> name;
		if(this->findByName(name)){
			system("cls");
			cout << "SUCCESS!!!" << endl << endl;
			Goods goods = this ->getByName(name);
			goods.showGoods();
		}
		else{
			system("cls");
			cout << "FAIL!!!" << endl << endl;
			this->showList();
		}
	}

	else if(in == "HELP"){
		system("cls"); 
		this->showHelp();
	}

	else if(in == "LIST"){
		system("cls");
		this->showList();
	}

	else if(in == "EXIT"){
		exit(0);
	}

	else{
		cout << "PLEASE ENSURE YOUR COMMAND IS RIGHT!!!"<< endl;
	}
}
void ManageGoods::showHelp(){
	cout << endl;
	cout << "*************************" << endl;
	cout << "* 操作方法：            *" << endl;
	cout << "* 输入“LIST”查看列表  *" << endl;
	cout << "* 输入”ADD”添加商品   *" << endl;
	cout << "* 输入“ALTER“修改商品 *" << endl;
	cout << "* 输入”DEL“删除商品   *" << endl;
	cout << "* 输入”QUERY“查找商品 *" << endl;
	cout << "* 输入”HELP“查找帮助  *" << endl;
	cout << "* 输入“EXIT”退出系统  *" << endl;
	cout << "*************************" << endl;
	cout << endl;
}