/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QSplitter *splitter_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSplitter *splitter;
    QLabel *label;
    QLineEdit *log;
    QLabel *label_2;
    QLineEdit *pass;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(172, 132);
        splitter_2 = new QSplitter(Login);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(10, 90, 150, 23));
        splitter_2->setOrientation(Qt::Horizontal);
        pushButton_2 = new QPushButton(splitter_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        splitter_2->addWidget(pushButton_2);
        pushButton = new QPushButton(splitter_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        splitter_2->addWidget(pushButton);
        splitter = new QSplitter(Login);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 10, 151, 71));
        splitter->setOrientation(Qt::Vertical);
        label = new QLabel(splitter);
        label->setObjectName(QString::fromUtf8("label"));
        splitter->addWidget(label);
        log = new QLineEdit(splitter);
        log->setObjectName(QString::fromUtf8("log"));
        log->setFrame(true);
        log->setClearButtonEnabled(false);
        splitter->addWidget(log);
        label_2 = new QLabel(splitter);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        splitter->addWidget(label_2);
        pass = new QLineEdit(splitter);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setEchoMode(QLineEdit::Password);
        pass->setReadOnly(false);
        splitter->addWidget(pass);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Login", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        pushButton->setText(QCoreApplication::translate("Login", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        label->setText(QCoreApplication::translate("Login", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        pass->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
