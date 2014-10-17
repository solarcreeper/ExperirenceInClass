#ifndef EXIFRW_H
#define EXIFRW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets\qtoolbutton.h>
#include <QtWidgets\qlabel.h>
#include <QtWidgets\qlineedit.h>
#include <qfiledialog.h>
#include <QtWidgets\qmenu.h>
#include <QtWidgets\qpushbutton.h>
#include <qpainter.h>
#include "Exif.h"
#include "msgBox.h"

class ExifRW : public QMainWindow
{
	Q_OBJECT

public:
	ExifRW(QWidget *parent = 0);
	~ExifRW();

	EXIFInfo result;
	MsgBox msgBox;
private slots:
	void onActionOpen();
	void onActionSave();
	void onActionExit();
private:

	//下拉菜单
	QMenu *Mu_base;
	QAction *Ma_open;
	QAction *Ma_save;
	QAction *Ma_exit;
	
	QPushButton *menu;						  //菜单栏

	QImage *toImage;		
	QPixmap *image;
	QLabel *iamgeLoader;					  //显示图片

	QLabel *Lb_cameraMake;
	QLabel *Lb_cameraModel;
	QLabel *Lb_software;
	QLabel *Lb_bitsPS;                        //Bits per sample
	QLabel *Lb_imageWidth;
	QLabel *Lb_imageHeight;
	QLabel *Lb_description;
	QLabel *Lb_orientation;
	QLabel *Lb_copyright;
	QLabel *Lb_imageTime;
	QLabel *Lb_originalTime;
	QLabel *Lb_digitizeTime;
	QLabel *Lb_subsecondTime;
	QLabel *Lb_exposureTime;
	QLabel *Lb_fStop;
	QLabel *Lb_isoSpeed;
	QLabel *Lb_subjectDistance;
	QLabel *Lb_exposureBias;
	QLabel *Lb_flashUsed;
	QLabel *Lb_meteringMode;
	QLabel *Lb_lensFocalLength;
	QLabel *Lb_mmFocalLength;
	QLabel *Lb_gpsLatitude;
	QLabel *Lb_gpsLongitude;
	QLabel *Lb_gpsAltitude;						//海拔高度

	QLineEdit *Le_cameraMake;
	QLineEdit *Le_cameraModel;
	QLineEdit *Le_software;
	QLineEdit *Le_bitsPS;
	QLineEdit *Le_imageWidth;
	QLineEdit *Le_imageHeight;
	QLineEdit *Le_description;
	QLineEdit *Le_orientation;
	QLineEdit *Le_copyright;
	QLineEdit *Le_imageTime;
	QLineEdit *Le_originalTime;
	QLineEdit *Le_digitizeTime;
	QLineEdit *Le_subsecondTime;
	QLineEdit *Le_exposureTime;
	QLineEdit *Le_fStop;
	QLineEdit *Le_isoSpeed;
	QLineEdit *Le_subjectDistance;
	QLineEdit *Le_exposureBias;
	QLineEdit *Le_flashUsed;
	QLineEdit *Le_meteringMode;
	QLineEdit *Le_lensFocalLength;
	QLineEdit *Le_mmFocalLength;
	QLineEdit *Le_gpsLatitude;
	QLineEdit *Le_gpsLongitude;
	QLineEdit *Le_gpsAltitude;
};

#endif // EXIFRW_H
