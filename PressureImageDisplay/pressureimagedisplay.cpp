#include "pressureimagedisplay.h"

PressureImageDisplay::PressureImageDisplay(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.LoadFileButton, SIGNAL(clicked()),this, SLOT(LoadAndDisplayFile()));
	QObject::connect(ui.FrameSlider, SIGNAL(valueChanged(int)), this, SLOT(PaintNextFrame(int)));
	QObject::connect(ui.LoadSimuBtton, SIGNAL(clicked()), this, SLOT(GetSimuFilePath()));
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(CheckIfModified()));
	QObject::connect(ui.UpdateSimuCheckbox, SIGNAL(toggled(bool)), this, SLOT(ToggleUpdateSimu(bool)));

	timer->setInterval(33);
	timer->setSingleShot(false);
	/*
	HANDLE pipe = CreateFile(
		L"\\\\.\\pipe\\my_pipe",
		GENERIC_READ, // only need read access
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
		);
	DWORD mode = PIPE_READMODE_MESSAGE;
	SetNamedPipeHandleState(pipe, &mode, NULL, NULL);
	mode = PIPE_NOWAIT;
	SetNamedPipeHandleState(pipe, &mode, NULL, NULL);*/
}

PressureImageDisplay::~PressureImageDisplay()
{

}

void PressureImageDisplay::LoadAndDisplayFile() {
	path = QFileDialog::getOpenFileName(ui.centralWidget, "Choose File", "");
	int* size = new int();
	fileData = std::vector<double>(LoadFile(path.toStdString(),size));
	ui.FrameSlider->setMaximum(*size);
	ui.FrameSlider->setValue(0);
	ui.FilePath->setText(path);
	paintFileData();
}

void PressureImageDisplay::PaintNextFrame(int v) {
	fileData = std::vector<double>(NextImage(v));
	ui.FrameNumDisp->setText("Frame: " + QString::number(v));
	paintFileData();
}

void PressureImageDisplay::paintFileData() {
	QImage img = QImage(500, 580, QImage::Format::Format_RGB32);
	double max = 0;
	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 25; j++) {
			if (fileData[i * 25 + j] > max) {
				max = fileData[i * 25 + j];
			}
		}
	}
	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 25; j++) {
			QColor c = getColor(fileData[i * 25 + j]);
			for (int k1 = 1; k1 < 21; k1++) {
				for (int k2 = 0; k2 < 20; k2++) {
					img.setPixelColor(500-(j*20 + k1), i*20 + k2, c);
				}
			}			
		}
	}
	ui.FileData->setPixmap(QPixmap::fromImage(img));
	ui.FileData->repaint();
}

void PressureImageDisplay::paintSimuData() {
	QImage img = QImage(500, 580, QImage::Format::Format_RGB32);
	double max = 0;
	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 25; j++) {
			if (simData[i * 25 + j] > max) {
				max = simData[i * 25 + j];
			}
		}
	}
	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 25; j++) {
			QColor c = getColor(simData[i * 25 + j], max);
			for (int k1 = 0; k1 < 20; k1++) {
				for (int k2 = 0; k2 < 20; k2++) {
					img.setPixelColor(499 - (j * 20 + k1), i * 20 + k2, c);
				}
			}
		}
	}
	ui.SimulationData->setPixmap(QPixmap::fromImage(img));
	ui.SimulationData->repaint();
}

void PressureImageDisplay::GetSimuFilePath() {
	pathSimu = QFileDialog::getOpenFileName(ui.centralWidget, "Choose File", "");
	ui.SimuPath->setText(pathSimu);

	QFileInfo simuInfo(pathSimu);
	lastModif = simuInfo.lastModified();

	timer->start();
	ui.UpdateSimuCheckbox->setEnabled(true);

	ReloadSimuFile();
}

void PressureImageDisplay::ReloadSimuFile() {
	simData = readDataFromSim(pathSimu.toStdString());
	paintSimuData();
}

void PressureImageDisplay::CheckIfModified() {
	QFileInfo simuInfo(pathSimu);

	if (lastModif < simuInfo.lastModified()) {
		lastModif = simuInfo.lastModified();
		ReloadSimuFile();
	}
}

void PressureImageDisplay::ToggleUpdateSimu(bool u) {
	if (u) {
		timer->start();
	}
	else {
		timer->stop();
	}
}

void PressureImageDisplay::ReceiveMessage() {
	double truc[725];
	ReadFile(pipe,
		truc,
		sizeof(truc),
		NULL,
		NULL);
	simData = std::vector<double>(std::begin(truc), std::end(truc));
}
