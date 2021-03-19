/********************************************************************************
** Form generated from reading UI file 'admin_form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_FORM_H
#define UI_ADMIN_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_7;
    QGroupBox *groupBox_2;
    QSplitter *splitter_4;
    QSplitter *splitter;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QSplitter *splitter_2;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QSplitter *splitter_3;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QGroupBox *groupBox_3;
    QTableWidget *tableWidget;
    QSplitter *splitter_6;
    QSplitter *splitter_5;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(813, 587);
        comboBox_2 = new QComboBox(Form);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(270, 40, 59, 20));
        comboBox_3 = new QComboBox(Form);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(220, 230, 40, 20));
        comboBox_4 = new QComboBox(Form);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(360, 30, 131, 20));
        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 330, 331, 171));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 20, 131, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 80, 47, 16));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 50, 64, 20));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 100, 51, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 50, 125, 16));
        groupBox_2 = new QGroupBox(Form);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(420, 330, 311, 171));
        splitter_4 = new QSplitter(groupBox_2);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setGeometry(QRect(30, 30, 241, 33));
        splitter_4->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_4);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        label_4 = new QLabel(splitter);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        splitter->addWidget(label_4);
        lineEdit_4 = new QLineEdit(splitter);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        splitter->addWidget(lineEdit_4);
        splitter_4->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_4);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        label_5 = new QLabel(splitter_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        splitter_2->addWidget(label_5);
        lineEdit_5 = new QLineEdit(splitter_2);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        splitter_2->addWidget(lineEdit_5);
        splitter_4->addWidget(splitter_2);
        splitter_3 = new QSplitter(splitter_4);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        label_6 = new QLabel(splitter_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        splitter_3->addWidget(label_6);
        lineEdit_6 = new QLineEdit(splitter_3);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        splitter_3->addWidget(lineEdit_6);
        splitter_4->addWidget(splitter_3);
        groupBox_3 = new QGroupBox(Form);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 221, 201));
        tableWidget = new QTableWidget(groupBox_3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 60, 201, 131));
        splitter_6 = new QSplitter(groupBox_3);
        splitter_6->setObjectName(QString::fromUtf8("splitter_6"));
        splitter_6->setGeometry(QRect(10, 20, 201, 33));
        splitter_6->setOrientation(Qt::Horizontal);
        splitter_5 = new QSplitter(splitter_6);
        splitter_5->setObjectName(QString::fromUtf8("splitter_5"));
        splitter_5->setOrientation(Qt::Vertical);
        label = new QLabel(splitter_5);
        label->setObjectName(QString::fromUtf8("label"));
        splitter_5->addWidget(label);
        lineEdit = new QLineEdit(splitter_5);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        splitter_5->addWidget(lineEdit);
        splitter_6->addWidget(splitter_5);
        pushButton = new QPushButton(splitter_6);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        splitter_6->addWidget(pushButton);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Form", "1 \320\277\320\260\321\200\320\260", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Form", "2 \320\277\320\260\321\200\320\260", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("Form", "3 \320\277\320\260\321\200\320\260", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("Form", "4 \320\277\320\260\321\200\320\260", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("Form", "5 \320\277\320\260\321\200\320\260", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("Form", "6 \320\277\320\260\321\200\320\260", nullptr));

        comboBox_3->setItemText(0, QCoreApplication::translate("Form", "\320\233", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("Form", "\320\233\320\240", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("Form", "\320\237\320\240", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("Form", "\320\232\320\240", nullptr));
        comboBox_3->setItemText(4, QCoreApplication::translate("Form", "\320\232\320\237", nullptr));

        comboBox_4->setItemText(0, QCoreApplication::translate("Form", "\320\221\320\276\320\273\321\214\321\210\320\260\321\217 \320\274\320\276\321\200\321\201\320\272\320\260\321\217 67", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("Form", "\320\223\320\260\321\201\321\202\320\265\320\273\320\273\320\276 15", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("Form", "\320\233\320\265\320\275\321\201\320\276\320\262\320\265\321\202\320\260 14\320\262", nullptr));

        groupBox->setTitle(QCoreApplication::translate("Form", "\320\243\321\207\320\265\320\261\320\275\321\213\320\265 \320\277\320\273\320\260\320\275\321\213", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "\320\232\320\276\320\273. \320\273\320\265\320\272\321\206\320\270\320\276\320\275\320\275\321\213\321\205 \321\207\320\260\321\201\320\276\320\262", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "\320\235\320\260\320\263\321\200\321\203\320\267\320\272\320\260", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_3->setText(QString());
        label_7->setText(QCoreApplication::translate("Form", "\320\272\320\276\320\264 \320\264\320\270\321\201\321\206\320\270\320\277\320\273\320\270\320\275\321\213", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Form", "\320\223\321\200\321\203\320\277\320\277\321\213", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "\320\235\320\276\320\274\320\265\321\200 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        lineEdit_4->setText(QString());
        label_5->setText(QCoreApplication::translate("Form", "\320\235\320\276\320\274\320\265\321\200 \320\277\320\276\321\202\320\276\320\272\320\260", nullptr));
        lineEdit_5->setText(QString());
        label_6->setText(QCoreApplication::translate("Form", "\320\232\320\276\320\273. \320\241\321\202\321\203\320\264\320\265\320\275\321\202\320\276\320\262", nullptr));
        lineEdit_6->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("Form", "\320\224\320\270\321\201\321\206\320\270\320\277\320\276\320\273\320\270\320\275\320\260", nullptr));
        label->setText(QCoreApplication::translate("Form", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\264\320\270\321\201\321\206\320\270\320\277\320\273\320\270\320\275\321\213", nullptr));
        lineEdit->setText(QString());
        pushButton->setText(QCoreApplication::translate("Form", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_FORM_H
