#ifndef MSGBOX_H
#define MSGBOX_H
#include <QtWidgets\qdialog.h>
#include <qlabel.h>
#include <qtoolbutton.h>

class MsgBox : public QDialog{
	Q_OBJECT

public:
	explicit MsgBox(QWidget *parent = 0);
	~MsgBox();

public slots:
	void showMsg(QString title, QString msg);

private:
	QLabel *displayMsg;
	QToolButton *Btn_OK;
};
#endif