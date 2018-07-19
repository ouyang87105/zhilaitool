#include "guicreator.h"
#include "ui_guicreator.h"
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QTextStream>

#define SAVE_DATA "J_SAVE.dat"

GUICreator::GUICreator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GUICreator)
{
    ui->setupUi(this);
    serial = new QSerialPort;
    QObject::connect(serial,SIGNAL(readyRead()),this,SLOT(recSerialData()));
    serial->setPortName("COM5");
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setParity(QSerialPort::NoParity);
    serial->setDataBits(QSerialPort::Data8);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if(serial->open(QIODevice::ReadWrite))
    {
        qDebug()<<"open success";
    }
    else
    {
        qDebug()<<"open failed";
    }
    ui->pushButton_5->setEnabled(false);
    on_pushButton_2_clicked();

}

float GUICreator::get_fr_feature_similarity(const float *feature1, const float *feature2, int dimension)
{
    float similarity = 0.0;
    double x = 0.0, y1 = 0.0, y2 = 0.0;
    for (int i = 0; i < dimension; i++)
    {
        x += feature1[i] * feature2[i];
        y1 += feature1[i] * feature1[i];
        y2 += feature2[i] * feature2[i];
    }
    similarity = x / (sqrt(y1)*sqrt(y2));
    return similarity;
}

GUICreator::~GUICreator()
{
    delete ui;
}

/*开始*/
void GUICreator::on_pushButton_clicked()
{
    m_packet.head.magic[0] = 'R';
    m_packet.head.magic[1] = 'E';
    m_packet.head.magic[2] = 'A';
    m_packet.head.magic[3] = 'D';
    m_packet.head.magic[4] = 'S';
    m_packet.head.magic[5] = 'E';
    m_packet.head.magic[6] = 'N';
    m_packet.head.magic[7] = 'S';
    m_packet.head.magic[8] = 'E';
    m_packet.head.version = 0;
    m_packet.head.id = 0;
    m_packet.head.cmdtype = 0x13;
    m_packet.head.bodysize = 0;
    m_sendbuf.clear();
    m_sendbuf[0] = m_packet.head.magic[0];
    m_sendbuf[1] = m_packet.head.magic[1];
    m_sendbuf[2] = m_packet.head.magic[2];
    m_sendbuf[3] = m_packet.head.magic[3];
    m_sendbuf[4] = m_packet.head.magic[4];
    m_sendbuf[5] = m_packet.head.magic[5];
    m_sendbuf[6] = m_packet.head.magic[6];
    m_sendbuf[7] = m_packet.head.magic[7];
    m_sendbuf[8] = m_packet.head.magic[8];
    m_sendbuf[9] = m_packet.head.version;
    m_sendbuf[10] = m_packet.head.id;
    m_sendbuf[11] = m_packet.head.cmdtype;
    m_sendbuf[12] = 0;
    m_sendbuf[13] = 0;
    m_sendbuf[14] = 0;
    m_sendbuf[15] = m_packet.head.bodysize;
    serial->write(m_sendbuf);
}

/*结束*/
void GUICreator::on_pushButton_2_clicked()
{
    m_packet.head.magic[0] = 'R';
    m_packet.head.magic[1] = 'E';
    m_packet.head.magic[2] = 'A';
    m_packet.head.magic[3] = 'D';
    m_packet.head.magic[4] = 'S';
    m_packet.head.magic[5] = 'E';
    m_packet.head.magic[6] = 'N';
    m_packet.head.magic[7] = 'S';
    m_packet.head.magic[8] = 'E';
    m_packet.head.version = 0;
    m_packet.head.id = 0;
    m_packet.head.cmdtype = 0x14;
    m_packet.head.bodysize = 0;
    m_sendbuf.clear();
    m_sendbuf[0] = m_packet.head.magic[0];
    m_sendbuf[1] = m_packet.head.magic[1];
    m_sendbuf[2] = m_packet.head.magic[2];
    m_sendbuf[3] = m_packet.head.magic[3];
    m_sendbuf[4] = m_packet.head.magic[4];
    m_sendbuf[5] = m_packet.head.magic[5];
    m_sendbuf[6] = m_packet.head.magic[6];
    m_sendbuf[7] = m_packet.head.magic[7];
    m_sendbuf[8] = m_packet.head.magic[8];
    m_sendbuf[9] = m_packet.head.version;
    m_sendbuf[10] = m_packet.head.id;
    m_sendbuf[11] = m_packet.head.cmdtype;
    m_sendbuf[12] = 0;
    m_sendbuf[13] = 0;
    m_sendbuf[14] = 0;
    m_sendbuf[15] = m_packet.head.bodysize;
    serial->write(m_sendbuf);
}

/*拍照*/
void GUICreator::on_pushButton_3_clicked()
{
    m_packet.head.magic[0] = 'R';
    m_packet.head.magic[1] = 'E';
    m_packet.head.magic[2] = 'A';
    m_packet.head.magic[3] = 'D';
    m_packet.head.magic[4] = 'S';
    m_packet.head.magic[5] = 'E';
    m_packet.head.magic[6] = 'N';
    m_packet.head.magic[7] = 'S';
    m_packet.head.magic[8] = 'E';
   m_packet.head.version = 0;
   m_packet.head.id = 0;
   m_packet.head.cmdtype = RS_CMD_TAKE_PHOTO;
   m_packet.head.bodysize = 1;
   m_packet.buffer[0] = 0x01;
   m_sendbuf.clear();
   m_sendbuf[0] = m_packet.head.magic[0];
   m_sendbuf[1] = m_packet.head.magic[1];
   m_sendbuf[2] = m_packet.head.magic[2];
   m_sendbuf[3] = m_packet.head.magic[3];
   m_sendbuf[4] = m_packet.head.magic[4];
   m_sendbuf[5] = m_packet.head.magic[5];
   m_sendbuf[6] = m_packet.head.magic[6];
   m_sendbuf[7] = m_packet.head.magic[7];
   m_sendbuf[8] = m_packet.head.magic[8];
   m_sendbuf[9] = m_packet.head.version;
   m_sendbuf[10] = m_packet.head.id;
   m_sendbuf[11] = m_packet.head.cmdtype;
   m_sendbuf[12] = m_packet.head.bodysize;
   m_sendbuf[13] = 0;
   m_sendbuf[14] = 0;
   m_sendbuf[15] = 0;
   m_sendbuf[16] = m_packet.buffer[0];
   serial->write(m_sendbuf);
}


void GUICreator::recSerialData()
{
    ba = serial->readAll();
   // qDebug()<<ba.toHex();
    ui->textEdit->insertPlainText(ba.toHex());
}

/*特征值暂存*/
void GUICreator::on_pushButton_4_clicked()
{
    QFile ExpandData(SAVE_DATA);
    QString str = ui->textEdit->toPlainText();
    str = str.right(4096);
    feature.clear();
    feature.append(str);

    if(ExpandData.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
    {
        QTextStream Out(&ExpandData);
        Out <<str<<"\n";

        ExpandData.close();
    }
    //qDebug()<<feature[feature.size()-1];
    ui->pushButton_5->setEnabled(true);
    on_pushButton_2_clicked();
    ui->textEdit->clear();
}
struct
{
    union
    {
        float f;
        unsigned char buf[4];
    }f_union;
}f_data[512];

/*特征值比较*/
void GUICreator::on_pushButton_5_clicked()
{
    on_pushButton_2_clicked();

    QString feature1 = ui->textEdit->toPlainText();
    QString feature2 = feature[feature.size()-1];
    QStringList c,e;
    feature1 = feature1.right(4096);
    for(int i=0;i<feature1.size()/2;++i)
    {
        c<<feature1.mid(2*i,2);
    }
    for(int i=0;i<feature2.size()/2;++i)
    {
        e<<feature2.mid(2*i,2);
    }
    QByteArray d,r;
    for(int i=0;i<c.size();++i)
    {
        d[i] = c.at(i).toInt(NULL,16);
    }
    for(int i=0;i<c.size();++i)
    {
        r[i] = e.at(i).toInt(NULL,16);
    }
    // qDebug()<<d;

    float f2[512],f3[512];
    for(int i=0;i<512;i++)
    {
        f_data[i].f_union.buf[0]=d[i*4];
        f_data[i].f_union.buf[1]=d[i*4+1];
        f_data[i].f_union.buf[2]=d[i*4+2];
        f_data[i].f_union.buf[3]=d[i*4+3];
        f2[i] = f_data[i].f_union.f;
       // qDebug()<<"f2["<<i<<"]"<<f2[i];

    }
    for(int i=0;i<512;i++)
    {
        f_data[i].f_union.buf[0]=r[i*4];
        f_data[i].f_union.buf[1]=r[i*4+1];
        f_data[i].f_union.buf[2]=r[i*4+2];
        f_data[i].f_union.buf[3]=r[i*4+3];
        f3[i] = f_data[i].f_union.f;
        //qDebug()<<"f3["<<i<<"]"<<f3[i];

    }
    float f4=get_fr_feature_similarity(f2,f3,512);
    QString f4_str = QString("%1").arg(f4);
    ui->lineEdit->setText(f4_str);
    //qDebug()<<f4;


}
