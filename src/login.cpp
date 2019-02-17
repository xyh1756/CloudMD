#include "login.h"
#include "ui_login.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QPluginLoader>
#include <QMessageBox>
#include <QApplication>


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_clicked()
{
    QSqlDatabase account=QSqlDatabase::addDatabase("QMYSQL");
    account.setHostName("127.0.0.1");
    account.setDatabaseName("markdown");
    account.setUserName("root");
    account.setPassword("1234");
    if(!account.open())
    {
        QMessageBox box;
        box.setWindowTitle(tr("连接失败"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("服务器连接失败，请联系维护人员！"));
        box.exec();
    }
    QSqlQuery query("select * from account;",account);
    if(query.exec())
    {
        while(query.next())
        {
            QString id=query.value(0).toString().trimmed();
            QString password=query.value(1).toString().trimmed();
            if(ui->usrlineEdit->text().trimmed()==id&&ui->pwdlineEdit->text().trimmed()==password)
            {
                account.close();
                this->close();
                emit login(id);
                return;
            }
        }
        account.close();
    }
    QMessageBox box;
    box.setWindowTitle(tr("登录失败"));
    box.setIcon(QMessageBox::Information);
    box.setText(tr("用户名或密码错误！"));
    box.exec();
    return;
}



void Login::on_pushButton_2_clicked()
{
    QSqlDatabase account=QSqlDatabase::addDatabase("QMYSQL");
    account.setHostName("127.0.0.1");
    account.setDatabaseName("markdown");
    account.setUserName("root");
    account.setPassword("1234");
    if(!account.open())
    {
        QMessageBox box;
        box.setWindowTitle(tr("连接失败"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("服务器连接失败，请联系维护人员！"));
        box.exec();
    }
    QSqlQuery query1("select * from account;",account);
    if(query1.exec())
    {
        while(query1.next())
        {
            QString id=query1.value(0).toString().trimmed();
            if(ui->usrlineEdit->text().trimmed()==id)
            {
                account.close();
                QMessageBox box;
                box.setWindowTitle(tr("注册失败"));
                box.setIcon(QMessageBox::Information);
                box.setText(tr("用户名已被注册！"));
                box.exec();
                return;
            }
        }
    }
    QString add="insert into account(id,password)values('"+ui->usrlineEdit->text().trimmed()+"','"+ui->pwdlineEdit->text().trimmed()+"');";
    QSqlQuery query(add,account);
    query.exec();
    QMessageBox box;
    box.setWindowTitle(tr("注册成功"));
    box.setIcon(QMessageBox::Information);
    box.setText(tr("注册成功！"));
    box.exec();
    account.close();
    return;
}
