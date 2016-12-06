#ifndef PRESSUREIMAGEDISPLAY_H
#define PRESSUREIMAGEDISPLAY_H

#include <QtWidgets/QMainWindow>
#include "ui_pressureimagedisplay.h"
#include "ImageLoader.h"
#include <QtWidgets\qfiledialog.h>

class PressureImageDisplay : public QMainWindow
{
	Q_OBJECT

public:
	PressureImageDisplay(QWidget *parent = 0);
	~PressureImageDisplay();
	void paintFileData();
	void paintSimuData();

private:
	Ui::PressureImageDisplayClass ui;
	std::vector<double> fileData = std::vector<double>(725, 0.);
	std::vector<double> simData = std::vector<double>(725, 0.);
	QString path, pathSimu;

public slots:
	void LoadAndDisplayFile();
	void PaintNextFrame(int v);
	void GetSimuFilePath();
	void ReloadSimuFile();
};

#endif // PRESSUREIMAGEDISPLAY_H
