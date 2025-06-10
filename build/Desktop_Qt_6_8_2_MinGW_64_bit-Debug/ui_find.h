/********************************************************************************
** Form generated from reading UI file 'find.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIND_H
#define UI_FIND_H

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

class Ui_Find
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

    void setupUi(QWidget *Find)
    {
        if (Find->objectName().isEmpty())
            Find->setObjectName("Find");
        Find->resize(789, 189);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Find->sizePolicy().hasHeightForWidth());
        Find->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Find);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        closeButton = new QPushButton(Find);
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
        constLabelIFIND = new QLabel(Find);
        constLabelIFIND->setObjectName("constLabelIFIND");
        QFont font1;
        font1.setPointSize(28);
        constLabelIFIND->setFont(font1);

        horizontalLayout_2->addWidget(constLabelIFIND);

        lineEdit = new QLineEdit(Find);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setFont(font1);

        horizontalLayout_2->addWidget(lineEdit);

        constLabelINCOLUMN = new QLabel(Find);
        constLabelINCOLUMN->setObjectName("constLabelINCOLUMN");
        constLabelINCOLUMN->setFont(font1);

        horizontalLayout_2->addWidget(constLabelINCOLUMN);

        columnBox = new QComboBox(Find);
        columnBox->setObjectName("columnBox");
        columnBox->setFont(font1);
        columnBox->setInsertPolicy(QComboBox::InsertPolicy::InsertAtBottom);

        horizontalLayout_2->addWidget(columnBox);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Find);

        QMetaObject::connectSlotsByName(Find);
    } // setupUi

    void retranslateUi(QWidget *Find)
    {
        Find->setWindowTitle(QCoreApplication::translate("Find", "Find", nullptr));
        closeButton->setText(QCoreApplication::translate("Find", "Close", nullptr));
        constLabelIFIND->setText(QCoreApplication::translate("Find", "Find", nullptr));
        constLabelINCOLUMN->setText(QCoreApplication::translate("Find", "in ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Find: public Ui_Find {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIND_H
