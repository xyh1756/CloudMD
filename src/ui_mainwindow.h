/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_N;
    QAction *action_S;
    QAction *action_B;
    QAction *action_O;
    QAction *action_C;
    QAction *action_X;
    QAction *action_Z;
    QAction *action;
    QAction *actionpdf;
    QAction *action_Pdf;
    QAction *action_L;
    QAction *action_D;
    QAction *action_T;
    QAction *action_Q;
    QAction *action_Y;
    QWidget *centralWidget;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(987, 611);
        QIcon icon;
        icon.addFile(QStringLiteral("../icon/iconfinder_50_Cloud_Arrow_Up_183463.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_N = new QAction(MainWindow);
        action_N->setObjectName(QStringLiteral("action_N"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../icon/document-new.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_N->setIcon(icon1);
        action_S = new QAction(MainWindow);
        action_S->setObjectName(QStringLiteral("action_S"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../icon/document-save.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_S->setIcon(icon2);
        action_B = new QAction(MainWindow);
        action_B->setObjectName(QStringLiteral("action_B"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../icon/edit-copy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_B->setIcon(icon3);
        action_O = new QAction(MainWindow);
        action_O->setObjectName(QStringLiteral("action_O"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../icon/document-open.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_O->setIcon(icon4);
        action_C = new QAction(MainWindow);
        action_C->setObjectName(QStringLiteral("action_C"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../icon/application-exit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_C->setIcon(icon5);
        action_X = new QAction(MainWindow);
        action_X->setObjectName(QStringLiteral("action_X"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../icon/system-shutdown.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_X->setIcon(icon6);
        action_Z = new QAction(MainWindow);
        action_Z->setObjectName(QStringLiteral("action_Z"));
        QIcon icon7;
        icon7.addFile(QStringLiteral("../icon/go-previous.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_Z->setIcon(icon7);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        QIcon icon8;
        icon8.addFile(QStringLiteral("../icon/edit-find.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon8);
        actionpdf = new QAction(MainWindow);
        actionpdf->setObjectName(QStringLiteral("actionpdf"));
        QIcon icon9;
        icon9.addFile(QStringLiteral("../icon/html.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionpdf->setIcon(icon9);
        action_Pdf = new QAction(MainWindow);
        action_Pdf->setObjectName(QStringLiteral("action_Pdf"));
        QIcon icon10;
        icon10.addFile(QStringLiteral("icon/document-print.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_Pdf->setIcon(icon10);
        action_L = new QAction(MainWindow);
        action_L->setObjectName(QStringLiteral("action_L"));
        QIcon icon11;
        icon11.addFile(QStringLiteral("icon/folder-cloud.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_L->setIcon(icon11);
        action_D = new QAction(MainWindow);
        action_D->setObjectName(QStringLiteral("action_D"));
        QIcon icon12;
        icon12.addFile(QStringLiteral("icon/dialog-cancel.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_D->setIcon(icon12);
        action_T = new QAction(MainWindow);
        action_T->setObjectName(QStringLiteral("action_T"));
        QIcon icon13;
        icon13.addFile(QStringLiteral("icon/view-refresh.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_T->setIcon(icon13);
        action_Q = new QAction(MainWindow);
        action_Q->setObjectName(QStringLiteral("action_Q"));
        QIcon icon14;
        icon14.addFile(QStringLiteral("../icon/edit-download.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_Q->setIcon(icon14);
        action_Y = new QAction(MainWindow);
        action_Y->setObjectName(QStringLiteral("action_Y"));
        QIcon icon15;
        icon15.addFile(QStringLiteral("../icon/text-x-generic.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_Y->setIcon(icon15);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(13, 9, 461, 511));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 987, 28));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu->menuAction());
        menu_F->addAction(action_N);
        menu_F->addAction(action_S);
        menu_F->addAction(action_B);
        menu_F->addAction(action_Y);
        menu_F->addAction(actionpdf);
        menu_F->addAction(action_Pdf);
        menu_F->addAction(action_O);
        menu_F->addAction(action_C);
        menu_F->addAction(action_X);
        menu_E->addAction(action_Z);
        menu_E->addAction(action);
        menu->addAction(action_L);
        menu->addAction(action_D);
        menu->addAction(action_Q);
        menu->addAction(action_T);
        mainToolBar->addAction(action_N);
        mainToolBar->addAction(action_S);
        mainToolBar->addAction(action_B);
        mainToolBar->addAction(action_Y);
        mainToolBar->addAction(actionpdf);
        mainToolBar->addAction(action_Pdf);
        mainToolBar->addAction(action_O);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Z);
        mainToolBar->addAction(action);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_L);
        mainToolBar->addAction(action_Q);
        mainToolBar->addAction(action_T);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action_N->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_N->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        action_N->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_S->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_S->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        action_S->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_B->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(&B)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        action_B->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        action_B->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_O->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_O->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_C->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255(&C)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_C->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_X->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&X)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_X->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_Z->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200(&Z)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_Z->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276(&F)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionpdf->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272Html(&H)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionpdf->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_Pdf->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272Pdf(&P)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_Pdf->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_L->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225\346\210\226\346\263\250\345\206\214(&L)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_L->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_D->setText(QApplication::translate("MainWindow", "\346\263\250\351\224\200(&D)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_D->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_T->setText(QApplication::translate("MainWindow", "\345\220\214\346\255\245(&T)", Q_NULLPTR));
        action_Q->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\344\272\221\347\253\257\346\226\207\344\273\266(&Q)", Q_NULLPTR));
        action_Y->setText(QApplication::translate("MainWindow", "\351\242\204\350\247\210(&Y)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_Y->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        menu_F->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", Q_NULLPTR));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\344\272\221\346\234\215\345\212\241(&Y)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
