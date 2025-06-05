/********************************************************************************
** Form generated from reading UI file 'grapfdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPFDIALOG_H
#define UI_GRAPFDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_GrapfDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *GrapfDialog)
    {
        if (GrapfDialog->objectName().isEmpty())
            GrapfDialog->setObjectName("GrapfDialog");
        GrapfDialog->resize(749, 300);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GrapfDialog->sizePolicy().hasHeightForWidth());
        GrapfDialog->setSizePolicy(sizePolicy);
        GrapfDialog->setMinimumSize(QSize(400, 300));
        gridLayout = new QGridLayout(GrapfDialog);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        closeButton = new QPushButton(GrapfDialog);
        closeButton->setObjectName("closeButton");
        QFont font;
        font.setPointSize(16);
        closeButton->setFont(font);

        gridLayout->addWidget(closeButton, 2, 0, 1, 1);


        retranslateUi(GrapfDialog);

        QMetaObject::connectSlotsByName(GrapfDialog);
    } // setupUi

    void retranslateUi(QDialog *GrapfDialog)
    {
        GrapfDialog->setWindowTitle(QCoreApplication::translate("GrapfDialog", "Dependence of length on type", nullptr));
        closeButton->setText(QCoreApplication::translate("GrapfDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GrapfDialog: public Ui_GrapfDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPFDIALOG_H
