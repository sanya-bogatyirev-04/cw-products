/********************************************************************************
** Form generated from reading UI file 'grapf.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPF_H
#define UI_GRAPF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Grapf
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Grapf)
    {
        if (Grapf->objectName().isEmpty())
            Grapf->setObjectName("Grapf");
        Grapf->resize(749, 338);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Grapf->sizePolicy().hasHeightForWidth());
        Grapf->setSizePolicy(sizePolicy);
        Grapf->setMinimumSize(QSize(400, 300));
        gridLayout = new QGridLayout(Grapf);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 0, 2, 1);


        retranslateUi(Grapf);

        QMetaObject::connectSlotsByName(Grapf);
    } // setupUi

    void retranslateUi(QDialog *Grapf)
    {
        Grapf->setWindowTitle(QCoreApplication::translate("Grapf", "Dependence of length on type", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Grapf: public Ui_Grapf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPF_H
