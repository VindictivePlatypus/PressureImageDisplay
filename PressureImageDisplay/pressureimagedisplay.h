#ifndef PRESSUREIMAGEDISPLAY_H
#define PRESSUREIMAGEDISPLAY_H

#include <QtWidgets/QMainWindow>
#include "ui_pressureimagedisplay.h"
#include "ImageLoader.h"
#include <QtWidgets\qfiledialog.h>
#include <qdatetime.h>
#include <qtimer.h>
#include <windows.h>
#include <iterator>

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
	std::vector<double> fileData = std::vector<double>(725);
	std::vector<double> simData = std::vector<double>(725);
	QString path, pathSimu;
	QDateTime lastModif;
	QTimer* timer = new QTimer();
	HANDLE pipe;

public slots:
	void LoadAndDisplayFile();
	void PaintNextFrame(int v);
	void GetSimuFilePath();
	void ReloadSimuFile();
	void CheckIfModified();
	void ToggleUpdateSimu(bool u);
	void ReceiveMessage();
};

#endif // PRESSUREIMAGEDISPLAY_H
