#include "cloudfile.h"
#include "ui_cloudfile.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QApplication>
#include <QRegExp>


cloudFile::cloudFile(QWidget *parent, QString id) :
    QDialog(parent),
    ui(new Ui::cloudFile)
{
    ui->setupUi(this);
    username=id;
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->tableWidget->verticalHeader()->setVisible(true);
    QSqlDatabase selectfile=QSqlDatabase::addDatabase("QMYSQL");
    selectfile.setHostName("127.0.0.1");
    selectfile.setDatabaseName("markdown");
    selectfile.setUserName("root");
    selectfile.setPassword("1234");
    selectfile.open();
    QSqlQuery query("select * from disk_user where username='"+id+"';",selectfile);
    QStringList files;
    files<<"文件";
    ui->tableWidget->setHorizontalHeaderLabels(files);
    if(query.exec())
    {
        int i=0;
        while(query.next())
        {
            QString filename=query.value(2).toString().trimmed();
            filename=filename.remove(QRegExp("^\\w+/"));
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(filename));
            ++i;
        }
    }
    selectfile.close();
}

cloudFile::~cloudFile()
{
    delete ui;
}

void cloudFile::on_pushButton_clicked()
{
    selectFile(username+"/"+ui->tableWidget->currentItem()->text());
    this->close();
}
