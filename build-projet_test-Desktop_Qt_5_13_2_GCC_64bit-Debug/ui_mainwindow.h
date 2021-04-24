/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QWidget *centralWidget;
    QLabel *labelEXT;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEditPression;
    QSplitter *splitter_8;
    QLineEdit *lineEditIntTemp;
    QLineEdit *lineEditExtHumidity;
    QLineEdit *lineEditIntHumidity;
    QSplitter *splitter_7;
    QLineEdit *lineEditExtMin;
    QLabel *label_3;
    QLineEdit *lineEditExtMax;
    QSplitter *splitter_9;
    QLabel *labelFormat;
    QCheckBox *checkBoxF;
    QLabel *labelActuel;
    QLabel *soleil;
    QSplitter *splitter_2;
    QLineEdit *lineEditPrev1Temp;
    QLineEdit *lineEditPrev2Temp;
    QLineEdit *lineEditPrev3Temp;
    QLineEdit *lineEditPrev4Temp;
    QLineEdit *lineEditPrev5Temp;
    QSplitter *splitter_3;
    QLabel *pict1;
    QLabel *pict2;
    QLabel *pict3;
    QLabel *pict4;
    QLabel *pict5;
    QLabel *labelPrevision;
    QLabel *Date_Time;
    QLabel *Digital_clock;
    QLabel *labelINT;
    QSplitter *splitter;
    QLabel *lineEditPrev1Date;
    QLabel *lineEditPrev2Date;
    QLabel *lineEditPrev3Date;
    QLabel *lineEditPrev4Date;
    QLabel *lineEditPrev5Date;
    QLabel *fond;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(857, 495);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        labelEXT = new QLabel(centralWidget);
        labelEXT->setObjectName(QString::fromUtf8("labelEXT"));
        labelEXT->setGeometry(QRect(30, 20, 171, 41));
        labelEXT->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(690, 230, 61, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(680, 110, 91, 31));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(690, 170, 61, 21));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(80, 190, 61, 31));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(60, 110, 101, 31));
        lineEditPression = new QLineEdit(centralWidget);
        lineEditPression->setObjectName(QString::fromUtf8("lineEditPression"));
        lineEditPression->setGeometry(QRect(680, 210, 81, 21));
        splitter_8 = new QSplitter(centralWidget);
        splitter_8->setObjectName(QString::fromUtf8("splitter_8"));
        splitter_8->setGeometry(QRect(680, 90, 81, 22));
        splitter_8->setOrientation(Qt::Horizontal);
        lineEditIntTemp = new QLineEdit(splitter_8);
        lineEditIntTemp->setObjectName(QString::fromUtf8("lineEditIntTemp"));
        splitter_8->addWidget(lineEditIntTemp);
        lineEditExtHumidity = new QLineEdit(centralWidget);
        lineEditExtHumidity->setObjectName(QString::fromUtf8("lineEditExtHumidity"));
        lineEditExtHumidity->setGeometry(QRect(80, 170, 71, 21));
        lineEditIntHumidity = new QLineEdit(centralWidget);
        lineEditIntHumidity->setObjectName(QString::fromUtf8("lineEditIntHumidity"));
        lineEditIntHumidity->setGeometry(QRect(680, 150, 81, 21));
        splitter_7 = new QSplitter(centralWidget);
        splitter_7->setObjectName(QString::fromUtf8("splitter_7"));
        splitter_7->setGeometry(QRect(50, 90, 141, 22));
        splitter_7->setOrientation(Qt::Horizontal);
        lineEditExtMin = new QLineEdit(splitter_7);
        lineEditExtMin->setObjectName(QString::fromUtf8("lineEditExtMin"));
        splitter_7->addWidget(lineEditExtMin);
        label_3 = new QLabel(splitter_7);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        splitter_7->addWidget(label_3);
        lineEditExtMax = new QLineEdit(splitter_7);
        lineEditExtMax->setObjectName(QString::fromUtf8("lineEditExtMax"));
        splitter_7->addWidget(lineEditExtMax);
        splitter_9 = new QSplitter(centralWidget);
        splitter_9->setObjectName(QString::fromUtf8("splitter_9"));
        splitter_9->setGeometry(QRect(330, 130, 159, 24));
        splitter_9->setOrientation(Qt::Horizontal);
        labelFormat = new QLabel(centralWidget);
        labelFormat->setObjectName(QString::fromUtf8("labelFormat"));
        labelFormat->setGeometry(QRect(340, 60, 231, 31));
        checkBoxF = new QCheckBox(centralWidget);
        checkBoxF->setObjectName(QString::fromUtf8("checkBoxF"));
        checkBoxF->setGeometry(QRect(490, 60, 41, 31));
        labelActuel = new QLabel(centralWidget);
        labelActuel->setObjectName(QString::fromUtf8("labelActuel"));
        labelActuel->setGeometry(QRect(320, 110, 171, 16));
        soleil = new QLabel(centralWidget);
        soleil->setObjectName(QString::fromUtf8("soleil"));
        soleil->setGeometry(QRect(340, 130, 151, 121));
        soleil->setScaledContents(false);
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(150, 410, 540, 22));
        splitter_2->setOrientation(Qt::Horizontal);
        lineEditPrev1Temp = new QLineEdit(splitter_2);
        lineEditPrev1Temp->setObjectName(QString::fromUtf8("lineEditPrev1Temp"));
        splitter_2->addWidget(lineEditPrev1Temp);
        lineEditPrev2Temp = new QLineEdit(splitter_2);
        lineEditPrev2Temp->setObjectName(QString::fromUtf8("lineEditPrev2Temp"));
        splitter_2->addWidget(lineEditPrev2Temp);
        lineEditPrev3Temp = new QLineEdit(splitter_2);
        lineEditPrev3Temp->setObjectName(QString::fromUtf8("lineEditPrev3Temp"));
        splitter_2->addWidget(lineEditPrev3Temp);
        lineEditPrev4Temp = new QLineEdit(splitter_2);
        lineEditPrev4Temp->setObjectName(QString::fromUtf8("lineEditPrev4Temp"));
        splitter_2->addWidget(lineEditPrev4Temp);
        lineEditPrev5Temp = new QLineEdit(splitter_2);
        lineEditPrev5Temp->setObjectName(QString::fromUtf8("lineEditPrev5Temp"));
        splitter_2->addWidget(lineEditPrev5Temp);
        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setGeometry(QRect(150, 330, 541, 71));
        splitter_3->setOrientation(Qt::Horizontal);
        pict1 = new QLabel(splitter_3);
        pict1->setObjectName(QString::fromUtf8("pict1"));
        splitter_3->addWidget(pict1);
        pict2 = new QLabel(splitter_3);
        pict2->setObjectName(QString::fromUtf8("pict2"));
        splitter_3->addWidget(pict2);
        pict3 = new QLabel(splitter_3);
        pict3->setObjectName(QString::fromUtf8("pict3"));
        splitter_3->addWidget(pict3);
        pict4 = new QLabel(splitter_3);
        pict4->setObjectName(QString::fromUtf8("pict4"));
        splitter_3->addWidget(pict4);
        pict5 = new QLabel(splitter_3);
        pict5->setObjectName(QString::fromUtf8("pict5"));
        splitter_3->addWidget(pict5);
        labelPrevision = new QLabel(centralWidget);
        labelPrevision->setObjectName(QString::fromUtf8("labelPrevision"));
        labelPrevision->setGeometry(QRect(340, 280, 171, 20));
        Date_Time = new QLabel(centralWidget);
        Date_Time->setObjectName(QString::fromUtf8("Date_Time"));
        Date_Time->setGeometry(QRect(340, 10, 191, 16));
        Digital_clock = new QLabel(centralWidget);
        Digital_clock->setObjectName(QString::fromUtf8("Digital_clock"));
        Digital_clock->setGeometry(QRect(380, 30, 121, 16));
        labelINT = new QLabel(centralWidget);
        labelINT->setObjectName(QString::fromUtf8("labelINT"));
        labelINT->setGeometry(QRect(640, 20, 171, 41));
        labelINT->setAlignment(Qt::AlignCenter);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(170, 300, 541, 31));
        splitter->setOrientation(Qt::Horizontal);
        lineEditPrev1Date = new QLabel(splitter);
        lineEditPrev1Date->setObjectName(QString::fromUtf8("lineEditPrev1Date"));
        splitter->addWidget(lineEditPrev1Date);
        lineEditPrev2Date = new QLabel(splitter);
        lineEditPrev2Date->setObjectName(QString::fromUtf8("lineEditPrev2Date"));
        splitter->addWidget(lineEditPrev2Date);
        lineEditPrev3Date = new QLabel(splitter);
        lineEditPrev3Date->setObjectName(QString::fromUtf8("lineEditPrev3Date"));
        splitter->addWidget(lineEditPrev3Date);
        lineEditPrev4Date = new QLabel(splitter);
        lineEditPrev4Date->setObjectName(QString::fromUtf8("lineEditPrev4Date"));
        splitter->addWidget(lineEditPrev4Date);
        lineEditPrev5Date = new QLabel(splitter);
        lineEditPrev5Date->setObjectName(QString::fromUtf8("lineEditPrev5Date"));
        splitter->addWidget(lineEditPrev5Date);
        fond = new QLabel(centralWidget);
        fond->setObjectName(QString::fromUtf8("fond"));
        fond->setGeometry(QRect(-2, 0, 861, 461));
        MainWindow->setCentralWidget(centralWidget);
        fond->raise();
        labelEXT->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        lineEditPression->raise();
        splitter_8->raise();
        lineEditExtHumidity->raise();
        lineEditIntHumidity->raise();
        splitter_7->raise();
        splitter_9->raise();
        labelFormat->raise();
        checkBoxF->raise();
        labelActuel->raise();
        soleil->raise();
        splitter_2->raise();
        splitter_3->raise();
        labelPrevision->raise();
        Date_Time->raise();
        Digital_clock->raise();
        labelINT->raise();
        splitter->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 857, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionQuitter);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQuitter->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
#if QT_CONFIG(shortcut)
        actionQuitter->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        labelEXT->setText(QCoreApplication::translate("MainWindow", "  Ext\303\251rieur", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Pression", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Temp\303\251rature", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Humidit\303\251", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Humidit\303\251", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Temp Min / Max", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        labelFormat->setText(QCoreApplication::translate("MainWindow", "Temp\303\251rature en : \302\260 C", nullptr));
        checkBoxF->setText(QCoreApplication::translate("MainWindow", "\302\260 F", nullptr));
        labelActuel->setText(QCoreApplication::translate("MainWindow", "              AUJOURD'HUI", nullptr));
        soleil->setText(QCoreApplication::translate("MainWindow", "label soleil", nullptr));
        pict1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pict2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pict3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pict4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pict5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelPrevision->setText(QCoreApplication::translate("MainWindow", "              PREVISIONS", nullptr));
        Date_Time->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        Digital_clock->setText(QCoreApplication::translate("MainWindow", "Heure", nullptr));
        labelINT->setText(QCoreApplication::translate("MainWindow", " Int\303\251rieur", nullptr));
        lineEditPrev1Date->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lineEditPrev2Date->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lineEditPrev3Date->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lineEditPrev4Date->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lineEditPrev5Date->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        fond->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("MainWindow", "Fichier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
