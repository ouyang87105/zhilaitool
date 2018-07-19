#ifndef GUICREATOR_H
#define GUICREATOR_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <license.h>
#include <rs_data.h>
#include <QVector>

namespace Ui {
class GUICreator;
}

class GUICreator : public QMainWindow
{
    Q_OBJECT

public:
    explicit GUICreator(QWidget *parent = 0);

    float get_fr_feature_similarity(const float * feature1, const float * feature2, int dimension);

    ~GUICreator();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void recSerialData();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::GUICreator *ui;
    QSerialPort *serial;
    rspacket m_packet;
    QByteArray m_sendbuf;
    QByteArray ba;
    QVector<QString> feature;
    QVector<QByteArray> m_revbuf;
};

#endif // GUICREATOR_H
