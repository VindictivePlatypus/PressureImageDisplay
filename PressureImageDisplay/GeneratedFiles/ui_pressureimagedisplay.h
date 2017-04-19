/********************************************************************************
** Form generated from reading UI file 'pressureimagedisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESSUREIMAGEDISPLAY_H
#define UI_PRESSUREIMAGEDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PressureImageDisplayClass
{
public:
    QWidget *centralWidget;
    QPushButton *LoadFileButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *FileData;
    QLabel *SimulationData;
    QSlider *FrameSlider;
    QLabel *FrameNumDisp;
    QLabel *FilePath;
    QPushButton *LoadSimuBtton;
    QLabel *SimuPath;
    QCheckBox *UpdateSimuCheckbox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PressureImageDisplayClass)
    {
        if (PressureImageDisplayClass->objectName().isEmpty())
            PressureImageDisplayClass->setObjectName(QStringLiteral("PressureImageDisplayClass"));
        PressureImageDisplayClass->resize(1040, 794);
        centralWidget = new QWidget(PressureImageDisplayClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LoadFileButton = new QPushButton(centralWidget);
        LoadFileButton->setObjectName(QStringLiteral("LoadFileButton"));
        LoadFileButton->setGeometry(QRect(30, 620, 151, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 590, 71, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(760, 590, 61, 20));
        FileData = new QLabel(centralWidget);
        FileData->setObjectName(QStringLiteral("FileData"));
        FileData->setGeometry(QRect(0, 0, 500, 580));
        SimulationData = new QLabel(centralWidget);
        SimulationData->setObjectName(QStringLiteral("SimulationData"));
        SimulationData->setGeometry(QRect(540, 0, 500, 580));
        FrameSlider = new QSlider(centralWidget);
        FrameSlider->setObjectName(QStringLiteral("FrameSlider"));
        FrameSlider->setGeometry(QRect(220, 620, 160, 22));
        FrameSlider->setMaximum(0);
        FrameSlider->setOrientation(Qt::Horizontal);
        FrameNumDisp = new QLabel(centralWidget);
        FrameNumDisp->setObjectName(QStringLiteral("FrameNumDisp"));
        FrameNumDisp->setGeometry(QRect(400, 620, 51, 16));
        FilePath = new QLabel(centralWidget);
        FilePath->setObjectName(QStringLiteral("FilePath"));
        FilePath->setGeometry(QRect(20, 680, 491, 16));
        LoadSimuBtton = new QPushButton(centralWidget);
        LoadSimuBtton->setObjectName(QStringLiteral("LoadSimuBtton"));
        LoadSimuBtton->setGeometry(QRect(590, 620, 151, 23));
        SimuPath = new QLabel(centralWidget);
        SimuPath->setObjectName(QStringLiteral("SimuPath"));
        SimuPath->setGeometry(QRect(540, 680, 491, 16));
        UpdateSimuCheckbox = new QCheckBox(centralWidget);
        UpdateSimuCheckbox->setObjectName(QStringLiteral("UpdateSimuCheckbox"));
        UpdateSimuCheckbox->setEnabled(true);
        UpdateSimuCheckbox->setGeometry(QRect(810, 620, 141, 17));
        UpdateSimuCheckbox->setCheckable(true);
        UpdateSimuCheckbox->setChecked(false);
        PressureImageDisplayClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PressureImageDisplayClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1040, 21));
        PressureImageDisplayClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PressureImageDisplayClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PressureImageDisplayClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PressureImageDisplayClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PressureImageDisplayClass->setStatusBar(statusBar);

        retranslateUi(PressureImageDisplayClass);

        QMetaObject::connectSlotsByName(PressureImageDisplayClass);
    } // setupUi

    void retranslateUi(QMainWindow *PressureImageDisplayClass)
    {
        PressureImageDisplayClass->setWindowTitle(QApplication::translate("PressureImageDisplayClass", "PressureImageDisplay", 0));
        LoadFileButton->setText(QApplication::translate("PressureImageDisplayClass", "Load Pressure File", 0));
        label->setText(QApplication::translate("PressureImageDisplayClass", "Ground Truth", 0));
        label_2->setText(QApplication::translate("PressureImageDisplayClass", "Simulation", 0));
        FileData->setText(QString());
        SimulationData->setText(QString());
        FrameNumDisp->setText(QApplication::translate("PressureImageDisplayClass", "Frame:0", 0));
        FilePath->setText(QApplication::translate("PressureImageDisplayClass", "Path", 0));
        LoadSimuBtton->setText(QApplication::translate("PressureImageDisplayClass", "Get Simulation File", 0));
        SimuPath->setText(QApplication::translate("PressureImageDisplayClass", "Path", 0));
        UpdateSimuCheckbox->setText(QApplication::translate("PressureImageDisplayClass", "Update Simulation Data", 0));
    } // retranslateUi

};

namespace Ui {
    class PressureImageDisplayClass: public Ui_PressureImageDisplayClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESSUREIMAGEDISPLAY_H
