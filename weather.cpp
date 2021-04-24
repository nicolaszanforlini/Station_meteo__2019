
#include "weather.h"
#include "mainwindow.h"

weather::weather(){}

    // methode api recupération des données Exterieur Actuel en CELCIUS

QList<QString>weather::metMeteoExt(){
    QList<QString>listetmp;
    QNetworkRequest request(QUrl("http://api.openweathermap.org/data/2.5/weather?q=Paris&units=metric&appid=1ca25422b331304ab48eab60d0d1ab54"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkAccessManager mgr;
    QNetworkReply * reply = mgr.get(request);
    while(!reply->isFinished()){
        qApp->processEvents();}
    QByteArray reponse = reply->readAll();
    QJsonDocument configJsonDoc = QJsonDocument::fromJson(reponse);
    QJsonDocument jsonResponse = configJsonDoc;
    QJsonObject jsonObject = jsonResponse.object();
    QJsonValue ress = jsonObject.value("main");
    QJsonValue ress2 = ress["humidity"];
    int n = ress2.toInt();
    QString nn;
    nn = QString::number(n);
    QJsonValue ressMax = ress["temp_max"];
    double nMax = ressMax.toDouble();
    QString nnMax;
    nnMax = QString::number(nMax);
    QJsonValue ressMin = ress["temp_min"];
    double nMin = ressMin.toDouble();
    QString nnMin;
    nnMin = QString::number(nMin);
    listetmp.push_back(nn);
    listetmp.push_back(nnMax);
    listetmp.push_back(nnMin);
    this->listeExt=listetmp;
    return listeExt;
}

// methode api recupération des données Exterieur Actuel en FAHRENHEIT

QList<QString>weather::metMeteoExtF(){
    QList<QString>listetmp;
    QNetworkRequest request(QUrl("http://api.openweathermap.org/data/2.5/weather?q=Paris&units=imperial&appid=1ca25422b331304ab48eab60d0d1ab54"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkAccessManager mgr;
    QNetworkReply * reply = mgr.get(request);
    while(!reply->isFinished()){
        qApp->processEvents();}
    QByteArray reponse = reply->readAll();
    QJsonDocument configJsonDoc = QJsonDocument::fromJson(reponse);
    QJsonDocument jsonResponse = configJsonDoc;
    QJsonObject jsonObject = jsonResponse.object();
    QJsonValue ress = jsonObject.value("main");
    QJsonValue ress2 = ress["humidity"];
    int n = ress2.toInt();
    QString nn;
    nn = QString::number(n);
    QJsonValue ressMax = ress["temp_max"];
    double nMax = ressMax.toDouble();
    QString nnMax;
    nnMax = QString::number(nMax);
    QJsonValue ressMin = ress["temp_min"];
    double nMin = ressMin.toDouble();
    QString nnMin;
    nnMin = QString::number(nMin);
    listetmp.push_back(nn);
    listetmp.push_back(nnMax);
    listetmp.push_back(nnMin);
    this->listeExtF=listetmp;
    return listeExtF;
}
    // methode api des previsions meteo CELCIUS

QMap<QString,QString>weather::metPrevTmpDateC(){
        QNetworkRequest request(QUrl("http://api.openweathermap.org/data/2.5/forecast?q=Paris&units=metric&appid=1ca25422b331304ab48eab60d0d1ab54"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QNetworkAccessManager mgr;
        QNetworkReply * reply = mgr.get(request);
        while(!reply->isFinished()){
            qApp->processEvents();}
        QByteArray reponse = reply->readAll();
        QJsonDocument configJsonDoc = QJsonDocument::fromJson(reponse);
        QJsonDocument jsonResponse = configJsonDoc;
        QJsonObject jsonObject = jsonResponse.object();
        QJsonValue ress = jsonObject.value("list");
        QMap<QString,QString>dico;
        for(int i=0;i<40;i++){
            QJsonValue ress3 = ress[i]["dt_txt"];
            QStringList t = ress3.toString().split(' ');
            if(t[1]=="09:00:00"){
                QString val_string = t[0];
                QJsonValue ress4 = ress[i]["main"];
                double tmp_p = ress4["temp"].toDouble();
                QString np;
                np = QString::number(tmp_p);
                dico[t[0]]=np;
            }else{continue;}
        }
        this->PrevDateC=dico;
        return this->PrevDateC;
}
    // methode api des previsions meteo FAHRENHEIT

QMap<QString,QString>weather::metPrevTmpDateF(){
        QNetworkRequest request(QUrl("http://api.openweathermap.org/data/2.5/forecast?q=Paris&units=imperial&appid=1ca25422b331304ab48eab60d0d1ab54"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QNetworkAccessManager mgr;
        QNetworkReply * reply = mgr.get(request);
        while(!reply->isFinished()){
            qApp->processEvents();}
        QByteArray reponse = reply->readAll();
        QJsonDocument configJsonDoc = QJsonDocument::fromJson(reponse);
        QJsonDocument jsonResponse = configJsonDoc;
        QJsonObject jsonObject = jsonResponse.object();
        QJsonValue ress = jsonObject.value("list");
        QMap<QString,QString>dico;
        for(int i=0;i<40;i++){
            QJsonValue ress3 = ress[i]["dt_txt"];
            QStringList t = ress3.toString().split(' ');
            if(t[1]=="09:00:00"){
                QString val_string = t[0];
                QJsonValue ress4 = ress[i]["main"];
                double tmp_p = ress4["temp"].toDouble();
                QString np;
                np = QString::number(tmp_p);
                dico[t[0]]=np;
            }else{continue;}
        }
        this->PrevDateF=dico;
        return this->PrevDateF;
}
    // methode recolte des datas du capteur

QList<QString>weather::capteur(){

    int file;
    char *bus = "/dev/i2c-1";
    if((file = open(bus, O_RDWR)) < 0)
    {
        printf("Failed to open the bus. \n");
        exit(1);
    }
    // Get I2C device, BME280 I2C address is 0x76(136)
    ioctl(file, I2C_SLAVE, 0x76);

    // Read 24 bytes of data from register(0x88)
    char reg[1] = {static_cast<char>(0x88)};

    write(file, reg, 1);
    char b1[24] = {0};
    if(read(file, b1, 24) != 24)
    {
        printf("Error : Input/Output error \n");
        exit(1);
    }

    // Convert the data
    // temp coefficents
    int dig_T1 = (b1[0] + b1[1] * 256);
    int dig_T2 = (b1[2] + b1[3] * 256);
    if(dig_T2 > 32767)
    {
        dig_T2 -= 65536;
    }
    int dig_T3 = (b1[4] + b1[5] * 256);
    if(dig_T3 > 32767)
    {
        dig_T3 -= 65536;
    }

    // pressure coefficents
    int dig_P1 = (b1[6] + b1[7] * 256);
    int dig_P2 = (b1[8] + b1[9] * 256);
    if(dig_P2 > 32767)
    {
        dig_P2 -= 65536;
    }
    int dig_P3 = (b1[10] + b1[11] * 256);
    if(dig_P3 > 32767)
    {
        dig_P3 -= 65536;
    }
    int dig_P4 = (b1[12] + b1[13] * 256);
    if(dig_P4 > 32767)
    {
        dig_P4 -= 65536;
    }
    int dig_P5 = (b1[14] + b1[15] * 256);
    if(dig_P5 > 32767)
    {
    dig_P5 -= 65536;
    }
    int dig_P6 = (b1[16] + b1[17] * 256);
    if(dig_P6 > 32767)
    {
        dig_P6 -= 65536;
    }
    int dig_P7 = (b1[18] + b1[19] * 256);
    if(dig_P7 > 32767)
    {
        dig_P7 -= 65536;
    }
    int dig_P8 = (b1[20] + b1[21] * 256);
    if(dig_P8 > 32767)
    {
    dig_P8 -= 65536;
    }
    int dig_P9 = (b1[22] + b1[23] * 256);
    if(dig_P9 > 32767)
    {
        dig_P9 -= 65536;
    }

    // Read 1 byte of data from register(0xA1)
    reg[0] = 0xA1;
    write(file, reg, 1);
    char data[8] = {0};
    read(file, data, 1);
    int dig_H1 = data[0];

    // Read 7 bytes of data from register(0xE1)
    reg[0] = 0xE1;
    write(file, reg, 1);
    read(file, b1, 7);

    // Convert the data
    // humidity coefficents
    int dig_H2 = (b1[0] + b1[1] * 256);
    if(dig_H2 > 32767)
    {
        dig_H2 -= 65536;
    }
    int dig_H3 = b1[2] & 0xFF ;
    int dig_H4 = (b1[3] * 16 + (b1[4] & 0xF));
    if(dig_H4 > 32767)
    {
        dig_H4 -= 65536;
    }
    int dig_H5 = (b1[4] / 16) + (b1[5] * 16);
    if(dig_H5 > 32767)
    {
        dig_H5 -= 65536;
    }
    int dig_H6 = b1[6];
    if(dig_H6 > 127)
    {
        dig_H6 -= 256;
    }

    // Select control humidity register(0xF2)
    // Humidity over sampling rate = 1(0x01)
    char config[2] = {0};
    config[0] = 0xF2;
    config[1] = 0x01;
    write(file, config, 2);
    // Select control measurement register(0xF4)
    // Normal mode, temp and pressure over sampling rate = 1(0x27)
    config[0] = 0xF4;
    config[1] = 0x27;
    write(file, config, 2);
    // Select config register(0xF5)
    // Stand_by time = 1000 ms(0xA0)
    config[0] = 0xF5;
    config[1] = 0xA0;
    write(file, config, 2);

    // Read 8 bytes of data from register(0xF7)
    // pressure msb1, pressure msb, pressure lsb, temp msb1, temp msb, temp lsb, humidity lsb, humidity msb
    reg[0] = 0xF7;
    write(file, reg, 1);
    read(file, data, 8);

    // Convert pressure and temperature data to 19-bits
    long adc_p = ((long)(data[0] * 65536 + ((long)(data[1] * 256) + (long)(data[2] & 0xF0)))) / 16;
    long adc_t = ((long)(data[3] * 65536 + ((long)(data[4] * 256) + (long)(data[5] & 0xF0)))) / 16;
    // Convert the humidity data
    long adc_h = (data[6] * 256 + data[7]);

    // Temperature offset calculations
    float var1 = (((float)adc_t) / 16384.0 - ((float)dig_T1) / 1024.0) * ((float)dig_T2);
    float var2 = ((((float)adc_t) / 131072.0 - ((float)dig_T1) / 8192.0) *
                    (((float)adc_t)/131072.0 - ((float)dig_T1)/8192.0)) * ((float)dig_T3);
    float t_fine = (long)(var1 + var2);
    float cTemp = (var1 + var2) / 5120.0;
    float fTemp = cTemp * 1.8 + 32;

    // Pressure offset calculations
    var1 = ((float)t_fine / 2.0) - 64000.0;
    var2 = var1 * var1 * ((float)dig_P6) / 32768.0;
    var2 = var2 + var1 * ((float)dig_P5) * 2.0;
    var2 = (var2 / 4.0) + (((float)dig_P4) * 65536.0);
    var1 = (((float) dig_P3) * var1 * var1 / 524288.0 + ((float) dig_P2) * var1) / 524288.0;
    var1 = (1.0 + var1 / 32768.0) * ((float)dig_P1);
    float p = 1048576.0 - (float)adc_p;
    p = (p - (var2 / 4096.0)) * 6250.0 / var1;
    var1 = ((float) dig_P9) * p * p / 2147483648.0;
    var2 = p * ((float) dig_P8) / 32768.0;
    float pressure = (p + (var1 + var2 + ((float)dig_P7)) / 16.0) / 100;

    // Humidity offset calculations
    float var_H = (((float)t_fine) - 76800.0);
    var_H = (adc_h - (dig_H4 * 64.0 + dig_H5 / 16384.0 * var_H)) * (dig_H2 / 65536.0 * (1.0 + dig_H6 / 67108864.0 * var_H * (1.0 + dig_H3 / 67108864.0 * var_H)));
    float humidity = var_H * (1.0 -  dig_H1 * var_H / 524288.0);
    if(humidity > 100.0)
    {
        humidity = 100.0;
    }else
    if(humidity < 0.0)
    {
        humidity = 0.0;
    }

    // Output data to screen

    QList<QString>liste;

// 1 "Temperature in Celsius ";
// 2 "Temperature in Fahrenheit ";
// 3 "Pressure ";
// 4 "Relative Humidity ";

    QString temp_cel;
    temp_cel.setNum(cTemp);
    QString temp_fer;
    temp_fer.setNum(fTemp);
    QString pression;
    pression.setNum(pressure);
    QString humidite;
    humidite.setNum(humidity);

    liste.push_back(temp_cel);
    liste.push_back(temp_fer);
    liste.push_back(pression);
    liste.push_back(humidite);

    this->dataCapteur = liste;

    return this->dataCapteur;
}

    // methode recuperation du temp actuel pour affichage des pictogrammes

QString weather::metPictogrammeTmpActuel(){
        QNetworkRequest request(QUrl("http://api.openweathermap.org/data/2.5/weather?q=Paris&units=imperial&appid=1ca25422b331304ab48eab60d0d1ab54"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QNetworkAccessManager mgr;
        QNetworkReply * reply = mgr.get(request);
        while(!reply->isFinished()){
            qApp->processEvents();}
        QByteArray reponse = reply->readAll();
        QJsonDocument configJsonDoc = QJsonDocument::fromJson(reponse);
        QJsonDocument jsonResponse = configJsonDoc;
        QJsonObject jsonObject = jsonResponse.object();
        QJsonValue ress = jsonObject.value("weather");
        QJsonArray item = ress.toArray();
        QJsonObject o = item[0].toObject();
        QString str = o["main"].toString();
        this->pictoActuel=str;
        return this->pictoActuel;
}
    // methode creation du pixmap

QPixmap weather::metCreationPixmap(QString val){

    QPixmap res;
    if(val == "Rain")
        res = QPixmap(":/new/prefix1/logo/pluie.png");
    else if(val=="Mist")
        res=QPixmap(":/new/prefix1/logo/nuage-leger.png");
    else if(val == "Clear")
        res = QPixmap(":/new/prefix1/logo/soleil.png");
    else if(val == "Clouds")
        res = QPixmap(":/new/prefix1/logo/nuage.png");
    else if(val == "Snow")
        res = QPixmap(":/new/prefix1/logo/neige.png");
    else if(val == "Drizzle")
        res = QPixmap(":/new/prefix1/logo/nuage-leger.png");
    else if(val == "Thunderstorm")
        res = QPixmap(":/new/prefix1/logo/nuage3.png");

    this->pixMap=res;
    return this->pixMap;
}
    // methode recuperation du temps des previsions

QList<QString>weather::metPictogrammeTmpPrevision(){

    QList<QString>listePrev;
        QNetworkRequest request(QUrl("http://api.openweathermap.org/data/2.5/forecast?q=Paris&units=imperial&appid=1ca25422b331304ab48eab60d0d1ab54"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QNetworkAccessManager mgr;
        QNetworkReply * reply = mgr.get(request);
        while(!reply->isFinished()){
            qApp->processEvents();}
        QByteArray reponse = reply->readAll();
        QJsonDocument configJsonDoc = QJsonDocument::fromJson(reponse);
        QJsonDocument jsonResponse = configJsonDoc;
        QJsonObject jsonObject = jsonResponse.object();
        QJsonValue ress = jsonObject.value("list");
        for(int i=0;i<40;i++){
            QJsonValue ress9 = ress[i]["dt_txt"];
            QStringList t = ress9.toString().split(' ');
            if(t[1]=="09:00:00"){
                QJsonArray item2 = ress[i]["weather"].toArray();
                QJsonObject obj2 = item2[0].toObject();
                QString str = obj2["main"].toString();
                listePrev.push_back(str);
            }
        }
        this->stringPrevision=listePrev;
        return this->stringPrevision;
}
    // methode en cour recuperer les dates pour afficher les jours de la semaines

QList<QString>weather::metRecupDateSemaine(){

    QNetworkRequest request(QUrl("http://api.openweathermap.org/data/2.5/forecast?q=Paris&units=imperial&appid=1ca25422b331304ab48eab60d0d1ab54"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkAccessManager mgr;
    QNetworkReply * reply = mgr.get(request);
    while(!reply->isFinished()){
        qApp->processEvents();}
    QByteArray reponse = reply->readAll();
    QJsonDocument configJsonDoc = QJsonDocument::fromJson(reponse);
    QJsonDocument jsonResponse = configJsonDoc;
    QJsonObject jsonObject = jsonResponse.object();
    QJsonValue ress = jsonObject.value("list");
    QList<QString>listTmp;
    for(int i=0;i<40;i++){
        QJsonValue ress3 = ress[i]["dt_txt"];
        QStringList t = ress3.toString().split(' ');
        if(t[1]=="09:00:00"){
        QStringList t2 = t[0].split('-');
        listTmp.push_back(t2[2]);
        }
    }
    this->RecupDateSemaine=listTmp;
    return this->RecupDateSemaine;
}
    // methode manipulation des datas pour un affichage des jours de la semaine

QList<QString>weather::metJourSemaine(){

    QList<QString>listLundi;
    listLundi={"mardi","mercredi","jeudi","vendredi","samedi"};
    QList<QString>listmardi;
    listmardi={"mercredi","jeudi","vendredi","samedi","dimanche"};
    QList<QString>listmercredi;
    listmercredi={"jeudi","vendredi","samedi","dimanche","lundi"};
    QList<QString>listjeudi;
    listjeudi={"vendredi","samedi","dimanche","lundi","mardi"};
    QList<QString>listvendredi;
    listvendredi={"samedi","dimanche","lundi","mardi","mercredi"};
    QList<QString>listsamedi;
    listsamedi={"dimanche","lundi","mardi","mercredi","jeudi"};
    QList<QString>listdimanche;
    listdimanche={"lundi","mardi","mercredi","jeudi","vendredi"};
    QList<QString>maList;
    QDateTime dateTime=QDateTime::currentDateTime();
    QString datetimetext=dateTime.toString();
    QStringList t3 = datetimetext.split('.');
    if(t3[0]=="sam"){
        maList=listsamedi;
    }else if(t3[0]=="dim"){
        maList=listdimanche;
    }else if(t3[0]=="lun"){
        maList=listLundi;
    }else if(t3[0]=="mar"){
        maList=listmardi;
    }else if(t3[0]=="mer"){
        maList=listmercredi;
    }else if(t3[0]=="jeu"){
        maList=listjeudi;
    }else if(t3[0]=="ven"){
        maList=listvendredi;
    }
    this->listSemaine = maList;
    return this->listSemaine;
}

  // methode affichage graphique des previsions en Celcius

QChartView * weather::metChartviewC(QList<QString>lst){
    QLineSeries *seriestmp = new QLineSeries;
    lst.push_front(0);
    for(int i=0; i <  lst.size(); i++){
       seriestmp->append(i, lst.at(i).toDouble());
    }
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(seriestmp);
    chart->createDefaultAxes();
    chart->setTitle("graphique des prévisions à venir");
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QCategoryAxis *axisX = new QCategoryAxis();
    QDate dateAuj = QDate::currentDate();
    for (int i = 1; i <= 5; i++){
        axisX->append((dateAuj.addDays(i)).toString("dddd") ,i);
    }
    axisX->setRange(0, 5);
    chartView->chart()->setAxisX(axisX,seriestmp);
    this->myChart=chartView;
    return this->myChart;
}


