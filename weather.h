#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QByteArray>
#include <QString>
#include <QTimer>
#include <QDateTime>
#include <QtAlgorithms>
#include <QList>
#include <QBoxLayout>
#include <QLabel>

#include <stdio.h>
#include <iostream>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLegend>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtCore/QRandomGenerator>
#include <QtCharts/QBarCategoryAxis>
#include <QtWidgets/QApplication>
#include <QtCharts/QValueAxis>
#include <QLineSeries>
#include <QSplineSeries>

class weather : public QObject
{
private :

    QMap<QString,QString>PrevDateC;

    QString ExtHumidityF;
    QString ExtTmpMaxF;
    QString ExtTmpMinF;
    QMap<QString,QString>PrevDateF;

    QList<QString>dataCapteur;

    QString pictoActuel;
    QPixmap pixMap;

    QList<QString>stringPrevision;

    QList<QString>RecupDateSemaine;
    QList<QString>listSemaine;

    QString AffDate;

    QList<QString>listeExt;
    QList<QString>listeExtF;

    QChartView *myChart;

public:
    weather();

    QString metPictogrammeTmpActuel();
    QPixmap metCreationPixmap(QString);
    QList<QString>metPictogrammeTmpPrevision();
    QPixmap metPixMapPrev(QString);

    QMap<QString,QString>metPrevTmpDateC();
    QMap<QString,QString>metPrevTmpDateF();

    QList<QString>metRecupDateSemaine();
    QList<QString>metJourSemaine();

    QString metAffichageDate();

    QList<QString>metMeteoExt();
    QList<QString>metMeteoExtF();

    QChartView *metChartviewC(QList<QString>);

    QList<QString>capteur();

};

#endif // WEATHER_H
