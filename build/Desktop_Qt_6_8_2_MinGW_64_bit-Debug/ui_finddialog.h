/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *closeButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *constLabelIFIND;
    QLineEdit *lineEdit;
    QLabel *constLabelINCOLUMN;
    QComboBox *columnBox;

    void setupUi(QWidget *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName("FindDialog");
        FindDialog->resize(540, 189);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FindDialog->sizePolicy().hasHeightForWidth());
        FindDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(FindDialog);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        closeButton = new QPushButton(FindDialog);
        closeButton->setObjectName("closeButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(22);
        closeButton->setFont(font);

        horizontalLayout->addWidget(closeButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        constLabelIFIND = new QLabel(FindDialog);
        constLabelIFIND->setObjectName("constLabelIFIND");
        QFont font1;
        font1.setPointSize(28);
        constLabelIFIND->setFont(font1);

        horizontalLayout_2->addWidget(constLabelIFIND);

        lineEdit = new QLineEdit(FindDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setFont(font1);

        horizontalLayout_2->addWidget(lineEdit);

        constLabelINCOLUMN = new QLabel(FindDialog);
        constLabelINCOLUMN->setObjectName("constLabelINCOLUMN");
        constLabelINCOLUMN->setFont(font1);

        horizontalLayout_2->addWidget(constLabelINCOLUMN);

        columnBox = new QComboBox(FindDialog);
        columnBox->addItem(QString());
        columnBox->addItem(QString());
        columnBox->addItem(QString());
        columnBox->addItem(QString());
        columnBox->addItem(QString());
        columnBox->addItem(QString());
        columnBox->addItem(QString());
        columnBox->addItem(QString());
        columnBox->addItem(QString());
        columnBox->setObjectName("columnBox");
        columnBox->setFont(font1);

        horizontalLayout_2->addWidget(columnBox);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(FindDialog);

        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QWidget *FindDialog)
    {
        FindDialog->setWindowTitle(QCoreApplication::translate("FindDialog", "Find", nullptr));
        closeButton->setText(QCoreApplication::translate("FindDialog", "Close", nullptr));
        constLabelIFIND->setText(QCoreApplication::translate("FindDialog", "Find", nullptr));
        constLabelINCOLUMN->setText(QCoreApplication::translate("FindDialog", "in ", nullptr));
        columnBox->setItemText(0, QCoreApplication::translate("FindDialog", "Any", nullptr));
        columnBox->setItemText(1, QCoreApplication::translate("FindDialog", "Code", nullptr));
        columnBox->setItemText(2, QCoreApplication::translate("FindDialog", "Name", nullptr));
        columnBox->setItemText(3, QCoreApplication::translate("FindDialog", "Year of foundation", nullptr));
        columnBox->setItemText(4, QCoreApplication::translate("FindDialog", "Staff", nullptr));
        columnBox->setItemText(5, QCoreApplication::translate("FindDialog", "Products", nullptr));
        columnBox->setItemText(6, QCoreApplication::translate("FindDialog", "Region", nullptr));
        columnBox->setItemText(7, QCoreApplication::translate("FindDialog", "Production volume", nullptr));
        columnBox->setItemText(8, QCoreApplication::translate("FindDialog", "Rating", nullptr));

    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
