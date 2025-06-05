/********************************************************************************
** Form generated from reading UI file 'autoraboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTORABOUTDIALOG_H
#define UI_AUTORABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AutorAboutDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okButton;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *AutorAboutDialog)
    {
        if (AutorAboutDialog->objectName().isEmpty())
            AutorAboutDialog->setObjectName("AutorAboutDialog");
        AutorAboutDialog->resize(615, 184);
        gridLayout = new QGridLayout(AutorAboutDialog);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_2 = new QSpacerItem(142, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        okButton = new QPushButton(AutorAboutDialog);
        okButton->setObjectName("okButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        okButton->setFont(font);

        gridLayout->addWidget(okButton, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(142, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(AutorAboutDialog);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(false);
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(AutorAboutDialog);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setPointSize(22);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 3);


        retranslateUi(AutorAboutDialog);

        QMetaObject::connectSlotsByName(AutorAboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AutorAboutDialog)
    {
        AutorAboutDialog->setWindowTitle(QCoreApplication::translate("AutorAboutDialog", "About Autor", nullptr));
        okButton->setText(QCoreApplication::translate("AutorAboutDialog", "OK", nullptr));
        label->setText(QCoreApplication::translate("AutorAboutDialog", "Created by", nullptr));
        label_2->setText(QCoreApplication::translate("AutorAboutDialog", "Bogatyirev Aleksandr Dmitryevich ICTMS 2-6", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AutorAboutDialog: public Ui_AutorAboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTORABOUTDIALOG_H
