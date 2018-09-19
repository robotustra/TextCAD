/********************************************************************************
** Form generated from reading UI file 'TextCAD.ui'
**
** Created: Mon Feb 25 23:31:27 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTCAD_H
#define UI_TEXTCAD_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#ifdef _QT_4_8_
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#else
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPlainTextEdit>
#include <QSpacerItem>
#include <QSplitter>
#include <QStatusBar>
#include <QTextBrowser>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#endif

#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionClose;
    QAction *actionExit;
    QAction *actionBuild;
    QAction *actionRebuild_All;
    QAction *actionBuild_File;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_2;
    QTextEdit *textEdit;
    QPlainTextEdit *plainTextEdit;
    QTextBrowser *textBrowser;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    GLWidget *widget_3;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuBuild;
    QMenu *menuView;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::Canada));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionBuild = new QAction(MainWindow);
        actionBuild->setObjectName(QString::fromUtf8("actionBuild"));
        actionRebuild_All = new QAction(MainWindow);
        actionRebuild_All->setObjectName(QString::fromUtf8("actionRebuild_All"));
        actionBuild_File = new QAction(MainWindow);
        actionBuild_File->setObjectName(QString::fromUtf8("actionBuild_File"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Serif"));
        font.setPointSize(10);
        widget->setFont(font);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        splitter_2 = new QSplitter(widget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter_2->sizePolicy().hasHeightForWidth());
        splitter_2->setSizePolicy(sizePolicy);
        splitter_2->setMinimumSize(QSize(0, 0));
        splitter_2->setAutoFillBackground(false);
        splitter_2->setFrameShape(QFrame::NoFrame);
        splitter_2->setFrameShadow(QFrame::Plain);
        splitter_2->setLineWidth(2);
        splitter_2->setOrientation(Qt::Vertical);
        textEdit = new QTextEdit(splitter_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setMinimumSize(QSize(0, 300));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Lucida Sans Typewriter"));
        font1.setPointSize(10);
        textEdit->setFont(font1);
        splitter_2->addWidget(textEdit);
        plainTextEdit = new QPlainTextEdit(splitter_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy2);
        plainTextEdit->setMinimumSize(QSize(0, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Courier New"));
        font2.setPointSize(10);
        plainTextEdit->setFont(font2);
        plainTextEdit->setUndoRedoEnabled(false);
        plainTextEdit->setReadOnly(true);
        plainTextEdit->setBackgroundVisible(false);
        splitter_2->addWidget(plainTextEdit);

        verticalLayout->addWidget(splitter_2);

        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        sizePolicy2.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy2);
        textBrowser->setMinimumSize(QSize(0, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Lucida Sans"));
        font3.setPointSize(10);
        textBrowser->setFont(font3);

        verticalLayout->addWidget(textBrowser);

        verticalLayout->setStretch(0, 90);
        verticalLayout->setStretch(1, 10);
        splitter->addWidget(widget);
        widget_2 = new QWidget(splitter);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_3 = new GLWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));

        verticalLayout_2->addWidget(widget_3);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Ignored);

        verticalLayout_2->addItem(verticalSpacer);

        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Lucida Console"));
        font4.setPointSize(10);
        lineEdit->setFont(font4);

        verticalLayout_2->addWidget(lineEdit);


        verticalLayout_3->addLayout(verticalLayout_2);

        splitter->addWidget(widget_2);

        horizontalLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuBuild = new QMenu(menubar);
        menuBuild->setObjectName(QString::fromUtf8("menuBuild"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuBuild->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuBuild->addAction(actionBuild_File);
        menuBuild->addAction(actionRebuild_All);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(activated()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
#ifdef _QT_4_8_
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TextCAD", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionBuild->setText(QApplication::translate("MainWindow", "Build ", 0, QApplication::UnicodeUTF8));
        actionRebuild_All->setText(QApplication::translate("MainWindow", "Rebuild All", 0, QApplication::UnicodeUTF8));
        actionBuild_File->setText(QApplication::translate("MainWindow", "Build File", 0, QApplication::UnicodeUTF8));
        plainTextEdit->setDocumentTitle(QApplication::translate("MainWindow", "Console Output", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuBuild->setTitle(QApplication::translate("MainWindow", "Build", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
#else
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TextCAD", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionBuild->setText(QApplication::translate("MainWindow", "Build ", 0));
        actionRebuild_All->setText(QApplication::translate("MainWindow", "Rebuild All", 0));
        actionBuild_File->setText(QApplication::translate("MainWindow", "Build File", 0));
        plainTextEdit->setDocumentTitle(QApplication::translate("MainWindow", "Console Output", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuBuild->setTitle(QApplication::translate("MainWindow", "Build", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
#endif

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTCAD_H
