#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMap>
#include <QtWebView/QtWebView>
#include <QWebEngineView>
#include "login.h"
#include "cloudfile.h"

class QLineEdit;
class QDialog;
class QLabel;
class QMarkdownTextEdit;
class QFile;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void newFile();
    bool maybeSave();
    bool save();
    bool saveAs();
    bool saveFile(const QString &fileName);
    bool loadFile(const QString &fileName);
    void logOut();
    void uploadForm(QString path,QMap<QString,QString> params,QString fileFormName);
    QLabel *permanent;
    QLineEdit *findLineEdit;
    QDialog *findDlg;
    QMarkdownTextEdit *MarkDown;
    QString id;
    QWebEngineView *webView;

public slots:
    void islogin(QString id);
    void openCloudFile(QString filename);

private slots:
    void on_action_N_triggered();

    void on_action_S_triggered();

    void on_action_B_triggered();

    void on_action_O_triggered();

    //void on_textEdit_textChanged();

    void on_action_C_triggered();

    void on_action_X_triggered();

    void on_action_Z_triggered();

    void showFindText1();

    void showFindText2();

    void on_action_triggered();

    void on_plainTextEdit_textChanged();

    void on_actionpdf_triggered();

    void on_action_Pdf_triggered();

    void on_action_L_triggered();

    void on_action_D_triggered();

    void on_action_T_triggered();

    void on_action_Q_triggered();

    void on_action_Y_triggered();

private:
    Ui::MainWindow *ui;
    bool isUntitled;
    bool isModified;
    bool isLogin;
    QString curFile;
    QString curFileName;

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
