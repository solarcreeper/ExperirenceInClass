#include "exifrw.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	ExifRW w;
	w.show();
	return a.exec();
}
