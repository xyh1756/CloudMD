#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmarkdowntextedit.h"
#include <QMap>
#include <QDebug>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUuid>
#include <QDir>
#include <QLineEdit>
#include <QPushButton>
#include <QPageLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QPrinter>
#include <QPainter>
#include <QRect>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QNetworkReply>
#include <QVariant>
#include <QEventLoop>
#include <QtCore>
#include <QtNetwork>
#include <QTextCursor>
#include <QWebEngineSettings>
#include <QScrollBar>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isUntitled=true;
    isModified=false;
    isLogin=false;
    curFile=tr("new.md");
    curFileName=tr("new.md");
    setWindowTitle(curFileName);
    findDlg=new QDialog(this);
    findDlg->setWindowTitle(tr("查找"));
    findLineEdit=new QLineEdit(findDlg);
    QPushButton *btn1=new QPushButton(tr("查找下一个"),findDlg);
    QPushButton *btn2=new QPushButton(tr("查找上一个"),findDlg);
    QVBoxLayout *layout=new QVBoxLayout(findDlg);
    layout->addWidget(findLineEdit);
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    connect(btn1,&QPushButton::clicked,this,&MainWindow::showFindText1);
    connect(btn2,&QPushButton::clicked,this,&MainWindow::showFindText2);
    permanent=new QLabel;
    permanent->setText(tr("离线模式"));
    ui->statusBar->addPermanentWidget(permanent);
    MarkDown=new QMarkdownTextEdit(this);
    MarkDown->setGeometry(493,76,481,511);
    MarkDown->show();
    MarkDown->setReadOnly(true);
    MarkDown->setHighlightingEnabled(true);
    connect(ui->plainTextEdit->verticalScrollBar(),SIGNAL(valueChanged(int)),MarkDown->verticalScrollBar(),SLOT(setValue(int)));
    id="";
    ui->action_D->setDisabled(true);
    ui->action_T->setDisabled(true);
    ui->action_Q->setDisabled(true);
    //setWindowIcon(QIcon(QStringLiteral(":/icon/icon1")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::maybeSave()
{
    if(isModified)
    {
        QMessageBox box;
        box.setWindowTitle(tr("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile+tr("尚未保存，是否保存？"));
        QPushButton *yesBtn=box.addButton(tr("是(&Y))"),QMessageBox::YesRole);
        box.addButton(tr("否(&N)"),QMessageBox::NoRole);
        QPushButton *cancelBtn=box.addButton(tr("取消"),QMessageBox::RejectRole);
        box.exec();
        if(box.clickedButton()==yesBtn)
            return save();
        else if(box.clickedButton()==cancelBtn)
            return false;
    }
    return true;
}


bool MainWindow::save()
{
    if(isUntitled)
    {
        return saveAs();
    }
    else
    {
        return saveFile(curFile);
    }
}

bool MainWindow::saveAs()
{
    QString fileName=QFileDialog::getSaveFileName(this,tr("另存为"),curFile);
    if(fileName.isEmpty())
        return false;
    return saveFile(fileName);
}

bool MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("多文档编辑器"),
                             tr("无法写入文件 %1: /n %2").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out<<ui->plainTextEdit->toPlainText();
    QApplication::restoreOverrideCursor();
    isUntitled=false;
    curFile=QFileInfo(fileName).canonicalFilePath();
    curFileName=fileName;
    curFileName=curFileName.remove(QRegExp("^/(\\w+/)*"));
    setWindowTitle(curFileName);
    isModified=false;
    return true;
}

void MainWindow::newFile()
{
    if(maybeSave())
    {
        isUntitled=true;

        curFile=tr("new.md");
        curFileName=tr("new.md");
        setWindowTitle(curFileName);
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setVisible(true);
        isModified=false;
    }
}

bool MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("多文档编辑器"),
                             tr("无法读取文件 %1: /n %2").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->plainTextEdit->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();
    curFile=QFileInfo(fileName).canonicalFilePath();
    curFileName=fileName;
    curFileName=curFileName.remove(QRegExp("^/(\\w+/)*"));
    isUntitled=false;
    isModified=false;
    setWindowTitle(curFileName);
    qDebug()<<curFileName;
    return true;
}

void MainWindow::logOut()
{
    ui->action_L->setEnabled(true);
    ui->action_D->setDisabled(true);
    ui->action_T->setDisabled(true);
    ui->action_Q->setDisabled(true);
    id="";
    isLogin=false;
    permanent->setText("离线模式");
}

void MainWindow::uploadForm(QString path, QMap<QString, QString> params, QString fileFormName)
{
    QString BOUNDARY=QUuid::createUuid().toString();
    QByteArray sb=QByteArray();

    for(QMap<QString,QString>::Iterator t=params.begin();t!=params.end();++t)
    {
        sb.append("--"+BOUNDARY+"\r\n");
        sb.append(QString("Content-Disposition: form-data;name=\"")+t.key()+QString("\"")+QString("\r\n"));
        sb.append("\r\n");
        sb.append(t.value()+"\r\n");
    }

    //QString curPath=QDir::currentPath();
    //QString newFileName=curFile.mid(curPath.length()+1);
    QString newFileName=curFileName;
    sb.append("--"+BOUNDARY+"\r\n");
    sb.append(QString("Content-Disposition: form-data;name=\"")+fileFormName+QString("\";filename=\"")+newFileName+QString("\"")+QString("\r\n"));
    sb.append("\r\n");


    sb.append(ui->plainTextEdit->toPlainText());
    sb.append("\r\n");
    sb.append("--"+BOUNDARY+"\r\n");

    QNetworkAccessManager *_uploadManager=new QNetworkAccessManager();
    QNetworkRequest request=QNetworkRequest(QUrl(path));
    request.setRawHeader(QString("Content-Type").toLatin1(),QString("multipart/form-data;boundary="+BOUNDARY).toLatin1());
    request.setRawHeader(QString("Content-Length").toLatin1(),QString::number(sb.length()).toLatin1());

    QNetworkReply *reply=_uploadManager->post(request,sb);
    qDebug()<<sb.data();
    QEventLoop loop;
    connect(reply,&QNetworkReply::finished,&loop,&QEventLoop::quit);
    loop.exec();
    QVariant statusCode=reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if(statusCode.isValid())
        qDebug()<<statusCode.toInt();
    qDebug()<<reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();

    //QVariant statusCode=reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    //if(statusCode.isValid())
    //    qDebug()<<statusCode.toInt();
    //qDebug()<<reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
}

void MainWindow::islogin(QString id)
{
    QMessageBox box;
    box.setWindowTitle(tr("登录成功"));
    box.setIcon(QMessageBox::Information);
    box.setText("欢迎回来，"+id);
    box.exec();
    this->id=id;
    isLogin=true;
    ui->action_L->setDisabled(true);
    ui->action_D->setEnabled(true);
    ui->action_T->setEnabled(true);
    ui->action_Q->setEnabled(true);
    permanent->setText("云同步模式，当前用户："+id);
}

void MainWindow::openCloudFile(QString filename)
{
    qDebug()<<filename;
    QString urlStr="http://127.0.0.1/"+filename;
    QUrl url(urlStr);
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply;

    reply=manager.get(QNetworkRequest(url));
    connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();

    QString content=reply->readAll();
    ui->plainTextEdit->setPlainText(content);
    curFile=filename.remove(QRegExp("^\\w+/"));
    curFileName=curFile;
    setWindowTitle(curFile);
    isUntitled=true;
}

void MainWindow::on_action_N_triggered()
{
    newFile();
}

void MainWindow::on_action_S_triggered()
{
    save();
}

void MainWindow::on_action_B_triggered()
{
    saveAs();
}

void MainWindow::on_action_O_triggered()
{
    if(maybeSave())
    {
        QString fileName=QFileDialog::getOpenFileName(this);
        if(!fileName.isEmpty())
        {
            loadFile(fileName);
            ui->plainTextEdit->setVisible(true);
        }
    }
}

void MainWindow::on_action_C_triggered()
{
    if(maybeSave())
    {
        ui->plainTextEdit->setVisible(false);
    }
}

void MainWindow::on_action_X_triggered()
{
    on_action_C_triggered();
    qApp->quit();
}

void MainWindow::on_action_Z_triggered()
{
    ui->plainTextEdit->undo();
}

void MainWindow::showFindText1()
{
    QString str=findLineEdit->text();
    if(!ui->plainTextEdit->find(str))
    {
        QMessageBox::warning(this,tr("查找"),tr("找不到%1").arg(str));

    }

}

void MainWindow::showFindText2()
{
    QString str=findLineEdit->text();
    if(!ui->plainTextEdit->find(str,QTextDocument::FindBackward))
    {
        QMessageBox::warning(this,tr("查找"),tr("找不到%1").arg(str));

    }

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(maybeSave())
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void MainWindow::on_action_triggered()
{
    findDlg->show();
}

void MainWindow::on_plainTextEdit_textChanged()
{
    isModified=true;
    MarkDown->setPlainText(ui->plainTextEdit->toPlainText());
    MarkDown->verticalScrollBar()->setValue(ui->plainTextEdit->verticalScrollBar()->value());

    ui->plainTextEdit->setFocus();

}

void MainWindow::on_actionpdf_triggered()
{
    if(isUntitled)
    {
        QMessageBox box;
        box.setWindowTitle(tr("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请先保存"));
        QPushButton *yesBtn=box.addButton(tr("确定(&Y))"),QMessageBox::YesRole);
        QPushButton *cancelBtn=box.addButton(tr("取消"),QMessageBox::RejectRole);
        box.exec();
        if(box.clickedButton()==yesBtn)
            save();
        else if(box.clickedButton()==cancelBtn)
            return;
    }
    QString fileName=curFile.remove(QRegExp("(\\.md)"))+".html";
    MarkDown->generateHtml(fileName);
    QMessageBox box;
    box.setWindowTitle(tr("导出成功"));
    box.setIcon(QMessageBox::Information);
    box.setText(fileName+tr("导出成功"));
    box.exec();
}

void MainWindow::on_action_Pdf_triggered()
{
    if(isUntitled)
    {
        QMessageBox box;
        box.setWindowTitle(tr("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请先保存"));
        QPushButton *yesBtn=box.addButton(tr("确定(&Y))"),QMessageBox::YesRole);
        QPushButton *cancelBtn=box.addButton(tr("取消"),QMessageBox::RejectRole);
        box.exec();
        if(box.clickedButton()==yesBtn)
            save();
        else if(box.clickedButton()==cancelBtn)
            return;
    }
    QString fileName=curFile.remove(QRegExp("(\\.md)"))+".html";
    MarkDown->generatePdf(fileName);
    QMessageBox box;
    box.setWindowTitle(tr("导出成功"));
    box.setIcon(QMessageBox::Information);
    fileName=curFile.remove(QRegExp("(\\.html)"))+".pdf";
    box.setText(fileName+tr("导出成功"));
    box.exec();
}

void MainWindow::on_action_L_triggered()
{
    Login *login=new Login(this);
    connect(login,SIGNAL(login(QString)),this,SLOT(islogin(QString)));
    login->exec();
}

void MainWindow::on_action_D_triggered()
{
    QMessageBox box;
    box.setWindowTitle(tr("注销"));
    box.setIcon(QMessageBox::Warning);
    box.setText(tr("是否注销？"));
    QPushButton *yesBtn=box.addButton(tr("确定(&Y))"),QMessageBox::YesRole);
    QPushButton *cancelBtn=box.addButton(tr("取消"),QMessageBox::RejectRole);
    box.exec();
    if(box.clickedButton()==yesBtn)
    {
        logOut();
        return;
    }
    else if(box.clickedButton()==cancelBtn)
    {
        box.close();
        return;
    }
}

void MainWindow::on_action_T_triggered()
{
    if(isUntitled)
    {
        QMessageBox box;
        box.setWindowTitle(tr("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请先保存"));
        QPushButton *yesBtn=box.addButton(tr("确定(&Y))"),QMessageBox::YesRole);
        QPushButton *cancelBtn=box.addButton(tr("取消"),QMessageBox::RejectRole);
        box.exec();
        if(box.clickedButton()==yesBtn)
            save();
        else if(box.clickedButton()==cancelBtn)
            return;
    }
    QString path="http://127.0.0.1/disk/";
    QMap<QString,QString> params_send;
    params_send.insert("username",id);
    QString fileFormName="file";
    //QFile *file1=new QFile(curFile);
    uploadForm(path,params_send,fileFormName);
}

void MainWindow::on_action_Q_triggered()
{
    cloudFile *cloudfile=new cloudFile(this,id);
    connect(cloudfile,SIGNAL(selectFile(QString)),this,SLOT(openCloudFile(QString)));
    cloudfile->exec();
}

void MainWindow::on_action_Y_triggered()
{
    QDialog *dialog=new QDialog(this);
    dialog->setGeometry(50,50,520,570);
    dialog->setWindowTitle("预览");
    webView=new QWebEngineView(dialog);

    webView->setGeometry(25,25,475,525);
    QString text="<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" /><script src=\"http://libs.baidu.com/jquery/2.0.0/jquery.min.js\"></script> <script src=\"https://cdn.bootcss.com/showdown/1.3.0/showdown.min.js\"></script> <script type=\"text/javascript\"> var content =\""+ui->plainTextEdit->toPlainText().replace(QRegularExpression("\r|\n")," \\n")+"\";\n var converter = new showdown.Converter();\n var htmlcontent  = converter.makeHtml(content);\n document.write(htmlcontent);\n</script><style type=\"text/css\"> <!-- @import url(1.css); --> </style>";
    webView->setHtml(text);
    webView->settings()->setFontFamily(QWebEngineSettings::StandardFont,"Source Code Pro");
    webView->show();
    dialog->exec();
}
