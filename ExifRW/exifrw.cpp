#include "exifrw.h"


ExifRW::ExifRW(QWidget *parent) : QMainWindow(parent){

	//set mainwindow
	this->setFixedSize(800, 450);
	this->setWindowTitle("ExifRW");

	//set background image
	QPalette mainWindowPalette;
	//need to finish

	//LOAD && SET UI
	//location control
	const int menuReservedHeight = 22;	   //菜单栏高度

	const int labelWidth = 120;			   //label的宽度	
	const int labelHeight = 14;			   //label的高度

	const int textWidth = 200;			   //editText的宽度
	const int textHeight = 14;			   //editText的高度

	const int gap = 3;                     //各个显示属性的label的间距
	int i = 0;
	int j = 0;

	//LOAD MENU TEST
	this->Mu_base = new QMenu(this);
	this->Ma_open = new QAction(Mu_base);
	this->Ma_save = new QAction(Mu_base);
	this->Ma_exit = new QAction(Mu_base);

	Mu_base->addAction(Ma_open);
	Mu_base->addAction(Ma_save);
	Mu_base->addAction(Ma_exit);

	Ma_open->setText("open");
	Ma_save->setText("save");
	Ma_exit->setText("exit");

	this->menu = new QPushButton("menu", this);
	menu->setGeometry(1, 1, 100, 20);
	menu->setMenu(Mu_base);


	this->iamgeLoader = new QLabel(this);
	iamgeLoader->setScaledContents(true);
	iamgeLoader->setGeometry(322, 23, 476, 420);

	//LOAD ATTRIBUTIONS
	this->Lb_cameraMake = new QLabel(this);
	Lb_cameraMake->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_cameraMake->setText("Camera make       : ");
	this->Lb_cameraModel = new QLabel(this);
	Lb_cameraModel->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_cameraModel->setText("Camera model      : ");
	this->Lb_software = new QLabel(this);
	Lb_software->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_software->setText("Software          : ");
	this->Lb_bitsPS = new QLabel(this);
	Lb_bitsPS->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_bitsPS->setText("Bits per sample   : ");
	this->Lb_imageWidth = new QLabel(this);
	Lb_imageWidth->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_imageWidth->setText("Image width       : ");
	this->Lb_imageHeight = new QLabel(this);
	Lb_imageHeight->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_imageHeight->setText("Image height      : ");
	this->Lb_description = new QLabel(this);
	Lb_description->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_description->setText("Image description : ");
	this->Lb_orientation = new QLabel(this);
	Lb_orientation->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_orientation->setText("Image orientation : ");
	this->Lb_copyright = new QLabel(this);
	Lb_copyright->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_copyright->setText("Image copyright   : ");
	this->Lb_imageTime = new QLabel(this);
	Lb_imageTime->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_imageTime->setText("Image date/time   : ");
	this->Lb_originalTime = new QLabel(this);
	Lb_originalTime->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_originalTime->setText("Original date/time: ");
	this->Lb_digitizeTime = new QLabel(this);
	Lb_digitizeTime->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_digitizeTime->setText("Digitize date/time: ");
	this->Lb_subsecondTime = new QLabel(this);
	Lb_subsecondTime->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_subsecondTime->setText("Subsecond time    : ");
	this->Lb_exposureTime = new QLabel(this);
	Lb_exposureTime->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_exposureTime->setText("Exposure time     : ");
	this->Lb_fStop = new QLabel(this);
	Lb_fStop->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_fStop->setText("F-stop            : ");
	this->Lb_isoSpeed = new QLabel(this);
	Lb_isoSpeed->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_isoSpeed->setText("ISO speed         : ");
	this->Lb_subjectDistance = new QLabel(this);
	Lb_subjectDistance->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_subjectDistance->setText("Subject distance  : ");
	this->Lb_exposureBias = new QLabel(this);
	Lb_exposureBias->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_exposureBias->setText("Exposure bias     : ");
	this->Lb_flashUsed = new QLabel(this);
	Lb_flashUsed->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_flashUsed->setText("Flash used        : ");
	this->Lb_meteringMode = new QLabel(this);
	Lb_meteringMode->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_meteringMode->setText("Metering mode     : ");
	this->Lb_lensFocalLength = new QLabel(this);
	Lb_lensFocalLength->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_lensFocalLength->setText("Lens focal length : ");
	this->Lb_mmFocalLength = new QLabel(this);
	Lb_mmFocalLength->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_mmFocalLength->setText("35mm focal length : ");
	this->Lb_gpsLatitude = new QLabel(this);
	Lb_gpsLatitude->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_gpsLatitude->setText("GPS Latitude      : ");
	this->Lb_gpsLongitude = new QLabel(this);
	Lb_gpsLongitude->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_gpsLongitude->setText("GPS Longitude     : ");
	this->Lb_gpsAltitude = new QLabel(this);
	Lb_gpsAltitude->setGeometry(3, (i++)*(labelHeight + gap) + menuReservedHeight, labelWidth, labelHeight);
	Lb_gpsAltitude->setText("GPS Altitude      : ");

	this->Le_cameraMake = new QLineEdit(this);
	Le_cameraMake->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_cameraModel = new QLineEdit(this);
	Le_cameraModel->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_software = new QLineEdit(this);
	Le_software->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_bitsPS = new QLineEdit(this);
	Le_bitsPS->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_imageWidth = new QLineEdit(this);
	Le_imageWidth->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_imageHeight = new QLineEdit(this);
	Le_imageHeight->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_description = new QLineEdit(this);
	Le_description->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_orientation = new QLineEdit(this);
	Le_orientation->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_copyright = new QLineEdit(this);
	Le_copyright->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_imageTime = new QLineEdit(this);
	Le_imageTime->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_originalTime = new QLineEdit(this);
	Le_originalTime->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_digitizeTime = new QLineEdit(this);
	Le_digitizeTime->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_subsecondTime = new QLineEdit(this);
	Le_subsecondTime->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_exposureTime = new QLineEdit(this);
	Le_exposureTime->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_fStop = new QLineEdit(this);
	Le_fStop->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_isoSpeed = new QLineEdit(this);
	Le_isoSpeed->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_subjectDistance = new QLineEdit(this);
	Le_subjectDistance->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_exposureBias = new QLineEdit(this);
	Le_exposureBias->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_flashUsed = new QLineEdit(this);
	Le_flashUsed->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_meteringMode = new QLineEdit(this);
	Le_meteringMode->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_lensFocalLength = new QLineEdit(this);
	Le_lensFocalLength->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_mmFocalLength = new QLineEdit(this);
	Le_mmFocalLength->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_gpsLatitude = new QLineEdit(this);
	Le_gpsLatitude->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_gpsLongitude = new QLineEdit(this);
	Le_gpsLongitude->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);
	this->Le_gpsAltitude = new QLineEdit(this);
	Le_gpsAltitude->setGeometry(121, (j++)*(gap + textHeight) + menuReservedHeight, textWidth, textHeight);

	//SLOTS
	connect(Ma_open, &QAction::triggered, this, &ExifRW::onActionOpen);
	connect(Ma_save, &QAction::triggered, this, &ExifRW::onActionSave);
	connect(Ma_exit, &QAction::triggered, this, &ExifRW::onActionExit);
}

ExifRW::~ExifRW(){

}

void ExifRW::onActionOpen(){
	//LOAD FILE
	QString file = QFileDialog::getOpenFileName(this, tr("open file"), " ", tr("imagefile(*.jpg)"));
	QByteArray temp = file.toLatin1();                //将QString转换为char*
	const char *filename = temp.data();
	//LOAD IMAGE


	FILE *fp;
	fopen_s(&fp, filename, "rb");
	if (!fp) {
		msgBox.showMsg("WARNING", "Open File Error!");
	}
	else{
		fseek(fp, 0, SEEK_END);
		unsigned long fsize = ftell(fp);
		rewind(fp);
		unsigned char *buf = new unsigned char[fsize];
		if (fread(buf, 1, fsize, fp) != fsize) { 
			msgBox.showMsg("WARNING", "Parse File Error!");
			delete[] buf;
		}
		fclose(fp);

		// Parse EXIF
		int code = this->result.parseFrom(buf, fsize);
		delete[] buf;
		if (code) {
			msgBox.showMsg("WARNING", "Error parsing EXIF!\n errcode:"+code);
		}
		else{
			QString relFile = file.replace('/', '\\');
			this->toImage = new QImage(relFile);
			this->image = new QPixmap();
			image->convertFromImage(*toImage);
			iamgeLoader->setPixmap(*image);

			Le_cameraMake->setText(result.Make.c_str());
			Le_cameraModel->setText(result.Model.c_str());
			Le_software->setText(result.Software.c_str());
			Le_bitsPS->setText(QString::number(result.BitsPerSample));
			Le_imageWidth->setText(QString::number(result.ImageWidth));
			Le_imageHeight->setText(QString::number(result.ImageHeight));
			Le_description->setText(result.ImageDescription.c_str());
			Le_orientation->setText(QString::number(result.Orientation));
			Le_copyright->setText(result.Copyright.c_str());
			Le_imageTime->setText(result.DateTime.c_str());
			Le_originalTime->setText(result.DateTimeOriginal.c_str());
			Le_digitizeTime->setText(result.DateTimeDigitized.c_str());
			Le_subsecondTime->setText(result.SubSecTimeOriginal.c_str());
			Le_exposureTime->setText(QString::number(result.ExposureTime));
			Le_fStop->setText(QString::number(result.FNumber));
			Le_isoSpeed->setText(QString::number(result.ISOSpeedRatings));
			Le_subjectDistance->setText(QString::number(result.SubjectDistance));
			Le_exposureBias->setText(QString::number(result.ExposureBiasValue));
			Le_flashUsed->setText(QString(result.Flash));
			Le_meteringMode->setText(QString::number(result.MeteringMode));
			Le_lensFocalLength->setText(QString::number(result.FocalLength));
			Le_mmFocalLength->setText(QString::number(result.FocalLengthIn35mm));
			QString latitude = 
				(QString::number(result.GeoLocation.LatComponents.degrees) + " deg "
				+ QString::number(result.GeoLocation.LatComponents.minutes) + " min "
				+ QString::number(result.GeoLocation.LatComponents.seconds) + " sec "
				+ QString(result.GeoLocation.LatComponents.direction));
			QString longitude = 
				(QString::number(result.GeoLocation.LonComponents.degrees) + " deg "
				+ QString::number(result.GeoLocation.LonComponents.minutes) + " min "
				+ QString::number(result.GeoLocation.LonComponents.seconds) + " sec "
				+ QString(result.GeoLocation.LonComponents.direction));
			Le_gpsLatitude->setText(latitude);
			Le_gpsLongitude->setText(longitude);
			Le_gpsAltitude->setText(QString::number(result.GeoLocation.Altitude)+" m ");

		}
	}
}

void ExifRW::onActionSave(){
	msgBox.showMsg("function not found", "this functin need to be finished later");
}

void ExifRW::onActionExit(){
	this->close();
}