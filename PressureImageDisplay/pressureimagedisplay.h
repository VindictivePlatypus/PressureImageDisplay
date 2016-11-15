#ifndef PRESSUREIMAGEDISPLAY_H
#define PRESSUREIMAGEDISPLAY_H

#include <QtWidgets/QMainWindow>
#include "ui_pressureimagedisplay.h"

class PressureImageDisplay : public QMainWindow
{
	Q_OBJECT

public:
	PressureImageDisplay(QWidget *parent = 0);
	~PressureImageDisplay();

private:
	Ui::PressureImageDisplayClass ui;
};

#endif // PRESSUREIMAGEDISPLAY_H
