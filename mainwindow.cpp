#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "weather.h"
#include <QPixmap>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);

    // mise en forme de la fenetre de l'application pour l'image de fond

    QDesktopWidget bureau;
    QRect surface_bureau = bureau.screenGeometry();
    int x = surface_bureau.width()/2 - width()/2;
    int y = surface_bureau.height()/2 - height()/2;
    move(x,y);

    // image de fond de l'application

    QPixmap pix(":/pic/sky.jpg");
    ui->fond->setPixmap(pix.scaled(867, 867, Qt::KeepAspectRatio));

    // affichage du titre de la fenetre

    this->setWindowTitle("===/ METEO /===");

    // affichage heure

    showTime();
    QTimer *timer=new QTimer(this);
    timer->start();
    connect(timer, SIGNAL(timeout()),this,SLOT(showTime()));

    // affichage date

    ui->Date_Time->setText(QDate::currentDate().toString("dddd d MMMM yyyy"));

    // font label Interieur et Exterieur

    QFont f("Courier",14, QFont::Bold);
    ui->labelINT->setFont(f);
    ui->labelEXT->setFont(f);
    QFont f2("Arial",10,QFont::Bold);
    ui->labelActuel->setFont(f2);
    ui->labelPrevision->setFont(f2);
    ui->Date_Time->setFont(f2);
    ui->Digital_clock->setFont(f2);

    // affichage des labels des previsions de la semaine

    weather wPrevMeteo;
    ui->lineEditPrev1Date->setText(wPrevMeteo.metJourSemaine()[0]+" "+wPrevMeteo.metRecupDateSemaine()[0]);
    ui->lineEditPrev2Date->setText(wPrevMeteo.metJourSemaine()[1]+" "+wPrevMeteo.metRecupDateSemaine()[1]);
    ui->lineEditPrev3Date->setText(wPrevMeteo.metJourSemaine()[2]+" "+wPrevMeteo.metRecupDateSemaine()[2]);
    ui->lineEditPrev4Date->setText(wPrevMeteo.metJourSemaine()[3]+" "+wPrevMeteo.metRecupDateSemaine()[3]);
    ui->lineEditPrev5Date->setText(wPrevMeteo.metJourSemaine()[4]+" "+wPrevMeteo.metRecupDateSemaine()[4]);

    // affichage pictogramme et temperature actuel

    QString meteo;
    meteo = wPrevMeteo.metPictogrammeTmpActuel();
    ui->soleil->setScaledContents(1);
    ui->soleil->setPixmap(wPrevMeteo.metCreationPixmap(meteo));

    // affichage des données Exterieur Actuel en Celcius

    ui->lineEditExtHumidity->setText(wPrevMeteo.metMeteoExt()[0]); // humidity
    ui->lineEditExtMax->setText(wPrevMeteo.metMeteoExt()[1]);      // temp max celcius
    ui->lineEditExtMin->setText(wPrevMeteo.metMeteoExt()[2]);      // temp min celcius

    // affichage des données de température des prévisions de la semaine en celcius

    ui->lineEditPrev1Temp->setText(wPrevMeteo.metPrevTmpDateC().values()[0]);
    ui->lineEditPrev2Temp->setText(wPrevMeteo.metPrevTmpDateC().values()[1]);
    ui->lineEditPrev3Temp->setText(wPrevMeteo.metPrevTmpDateC().values()[2]);
    ui->lineEditPrev4Temp->setText(wPrevMeteo.metPrevTmpDateC().values()[3]);
    ui->lineEditPrev5Temp->setText(wPrevMeteo.metPrevTmpDateC().values()[4]);

    // affichage des pictogrammes des previsions de la semaine

    ui->pict1->setScaledContents(1);
    ui->pict1->setPixmap(wPrevMeteo.metCreationPixmap(wPrevMeteo.metPictogrammeTmpPrevision()[0]));
    ui->pict2->setScaledContents(1);
    ui->pict2->setPixmap(wPrevMeteo.metCreationPixmap(wPrevMeteo.metPictogrammeTmpPrevision()[1]));
    ui->pict3->setScaledContents(1);
    ui->pict3->setPixmap(wPrevMeteo.metCreationPixmap(wPrevMeteo.metPictogrammeTmpPrevision()[2]));
    ui->pict4->setScaledContents(1);
    ui->pict4->setPixmap(wPrevMeteo.metCreationPixmap(wPrevMeteo.metPictogrammeTmpPrevision()[3]));
    ui->pict5->setScaledContents(1);
    ui->pict5->setPixmap(wPrevMeteo.metCreationPixmap(wPrevMeteo.metPictogrammeTmpPrevision()[4]));

    // affichage des datas du capteur en CELCIUS

    ui->lineEditIntTemp->setText(wPrevMeteo.capteur()[0]);
    ui->lineEditIntHumidity->setText(wPrevMeteo.capteur()[3]);
    ui->lineEditPression->setText(wPrevMeteo.capteur()[2]);

    // graphique des prévisions à venir en Celcius

    weather wPrevGraf;
    ui->gridLayout->addWidget(wPrevGraf.metChartviewC(wPrevMeteo.metPrevTmpDateC().values()));
}

    // methode format d'affichage de l'heure

void MainWindow::showTime(){
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    if ((time.second() % 2)== 0){
    time_text[3]= ' ';
    time_text[8]= ' ';
}
 ui->Digital_clock->setText(time_text);
}

MainWindow::~MainWindow(){
    delete ui;
}
       // methode de fermeture de la fenetre fichier => quitter

void MainWindow::on_actionQuitter_triggered(){
    this->close();
}

void MainWindow::on_checkBoxF_stateChanged(int arg1)
{
    if(ui->checkBoxF->isChecked()){

       // affichage des données exterieur Actuel en FAHRENHEIT

           weather wFahrenheit;
           ui->lineEditExtHumidity->setText(wFahrenheit.metMeteoExtF()[0]);
           ui->lineEditExtMax->setText(wFahrenheit.metMeteoExtF()[1]);
           ui->lineEditExtMin->setText(wFahrenheit.metMeteoExtF()[2]);

       // affichage des temperatures des previsions de la semaine en FAHRENHEIT

           ui->lineEditPrev1Temp->setText(wFahrenheit.metPrevTmpDateF().values()[0]);
           ui->lineEditPrev2Temp->setText(wFahrenheit.metPrevTmpDateF().values()[1]);
           ui->lineEditPrev3Temp->setText(wFahrenheit.metPrevTmpDateF().values()[2]);
           ui->lineEditPrev4Temp->setText(wFahrenheit.metPrevTmpDateF().values()[3]);
           ui->lineEditPrev5Temp->setText(wFahrenheit.metPrevTmpDateF().values()[4]);

        // affichage des labels des previsions de la semaine en FAHRENHEIT

           ui->lineEditPrev1Date->setText(wFahrenheit.metJourSemaine()[0]+" "+wFahrenheit.metRecupDateSemaine()[0]);
           ui->lineEditPrev2Date->setText(wFahrenheit.metJourSemaine()[1]+" "+wFahrenheit.metRecupDateSemaine()[1]);
           ui->lineEditPrev3Date->setText(wFahrenheit.metJourSemaine()[2]+" "+wFahrenheit.metRecupDateSemaine()[2]);
           ui->lineEditPrev4Date->setText(wFahrenheit.metJourSemaine()[3]+" "+wFahrenheit.metRecupDateSemaine()[3]);
           ui->lineEditPrev5Date->setText(wFahrenheit.metJourSemaine()[4]+" "+wFahrenheit.metRecupDateSemaine()[4]);

        // affichage des datas du capteur FAHRENHEIT

        ui->lineEditIntTemp->setText(wFahrenheit.capteur()[1]);
        ui->lineEditPression->setText(wFahrenheit.capteur()[2]);

    }else{

        // affichage des temperatures exterieur actuel CELCIUS

            weather wCelcius;
            ui->lineEditExtHumidity->setText(wCelcius.metMeteoExt()[0]);
            ui->lineEditExtMax->setText(wCelcius.metMeteoExt()[1]);
            ui->lineEditExtMin->setText(wCelcius.metMeteoExt()[2]);

        // affichage des temperatures des previsions de la semaine en CELCIUS

            ui->lineEditPrev1Temp->setText(wCelcius.metPrevTmpDateC().values()[0]);
            ui->lineEditPrev2Temp->setText(wCelcius.metPrevTmpDateC().values()[1]);
            ui->lineEditPrev3Temp->setText(wCelcius.metPrevTmpDateC().values()[2]);
            ui->lineEditPrev4Temp->setText(wCelcius.metPrevTmpDateC().values()[3]);
            ui->lineEditPrev5Temp->setText(wCelcius.metPrevTmpDateC().values()[4]);

        // affichage des labels des previsions de la semaine CELCIUS

            ui->lineEditPrev1Date->setText(wCelcius.metJourSemaine()[0]+" "+wCelcius.metRecupDateSemaine()[0]);
            ui->lineEditPrev2Date->setText(wCelcius.metJourSemaine()[1]+" "+wCelcius.metRecupDateSemaine()[1]);
            ui->lineEditPrev3Date->setText(wCelcius.metJourSemaine()[2]+" "+wCelcius.metRecupDateSemaine()[2]);
            ui->lineEditPrev4Date->setText(wCelcius.metJourSemaine()[3]+" "+wCelcius.metRecupDateSemaine()[3]);
            ui->lineEditPrev5Date->setText(wCelcius.metJourSemaine()[4]+" "+wCelcius.metRecupDateSemaine()[4]);

        // affichage des datas du capteur CELCIUS

            ui->lineEditIntTemp->setText(wCelcius.capteur()[0]);
            ui->lineEditIntHumidity->setText(wCelcius.capteur()[3]);
            ui->lineEditPression->setText(wCelcius.capteur()[2]);

    }
}






