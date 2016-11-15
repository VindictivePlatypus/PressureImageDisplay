#include "pressureimagedisplay.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PressureImageDisplay w;
	w.show();
	return a.exec();
}
