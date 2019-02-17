#ifndef CLOUDFILE_H
#define CLOUDFILE_H

#include <QDialog>

namespace Ui {
class cloudFile;
}

class cloudFile : public QDialog
{
    Q_OBJECT

public:
    explicit cloudFile(QWidget *parent = 0, QString id="");
    ~cloudFile();

private:
    Ui::cloudFile *ui;
    QString username;

signals:
    void selectFile(QString filename);
private slots:
    void on_pushButton_clicked();
};

#endif // CLOUDFILE_H
