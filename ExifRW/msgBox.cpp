#include "msgBox.h"

MsgBox::MsgBox(QWidget *parent):QDialog(parent){
	this->setFixedSize(325, 245);

	this->displayMsg = new QLabel(this);
	displayMsg->setGeometry(40, 60, 245, 60);
	displayMsg->setAlignment(Qt::AlignCenter);
	//ÉèÖÃ×ÖÌå
	QFont f;
	f.setPointSize(15);
	//
	displayMsg->setFont(f);
	this->Btn_OK = new QToolButton(this);
	Btn_OK->setGeometry(115, 175, 95, 40);
	Btn_OK->setText("OK");
	connect(Btn_OK, SIGNAL(clicked()), this, SLOT(close()));
}

MsgBox::~MsgBox(){

}


void MsgBox::showMsg(QString title, QString msg){
	this->setWindowTitle(title);
	this->displayMsg->setText(msg);
	this->exec();
}
