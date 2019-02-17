/********************************************************************************
** Form generated from reading UI file 'cloudfile.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOUDFILE_H
#define UI_CLOUDFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_cloudFile
{
public:
    QPushButton *pushButton;
    QTableWidget *tableWidget;

    void setupUi(QDialog *cloudFile)
    {
        if (cloudFile->objectName().isEmpty())
            cloudFile->setObjectName(QStringLiteral("cloudFile"));
        cloudFile->resize(412, 344);
        pushButton = new QPushButton(cloudFile);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 270, 89, 25));
        tableWidget = new QTableWidget(cloudFile);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(146, 50, 114, 179));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(0, 0));
        tableWidget->setSizeIncrement(QSize(0, 0));
        tableWidget->setBaseSize(QSize(0, 0));
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setRowCount(5);
        tableWidget->setColumnCount(1);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setVisible(true);

        retranslateUi(cloudFile);

        QMetaObject::connectSlotsByName(cloudFile);
    } // setupUi

    void retranslateUi(QDialog *cloudFile)
    {
        cloudFile->setWindowTitle(QApplication::translate("cloudFile", "\351\200\211\346\213\251\344\272\221\347\253\257\346\226\207\344\273\266", Q_NULLPTR));
        pushButton->setText(QApplication::translate("cloudFile", "\351\200\211\346\213\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cloudFile: public Ui_cloudFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOUDFILE_H
