/********************************************************************************
** Form generated from reading UI file 'authorAbout.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORABOUT_H
#define UI_AUTHORABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AuthorAbout
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *okButton;

    void setupUi(QDialog *AuthorAbout)
    {
        if (AuthorAbout->objectName().isEmpty())
            AuthorAbout->setObjectName("AuthorAbout");
        AuthorAbout->resize(800, 300);
        AuthorAbout->setMinimumSize(QSize(800, 0));
        AuthorAbout->setMaximumSize(QSize(800, 300));
        gridLayout = new QGridLayout(AuthorAbout);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_2 = new QSpacerItem(142, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(142, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        label = new QLabel(AuthorAbout);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 50));
        label->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setPointSize(18);
        font.setBold(false);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(AuthorAbout);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 50));
        QFont font1;
        font1.setPointSize(22);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 3);

        okButton = new QPushButton(AuthorAbout);
        okButton->setObjectName("okButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(250);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);
        okButton->setMinimumSize(QSize(0, 0));
        okButton->setMaximumSize(QSize(100, 50));
        QFont font2;
        font2.setPointSize(14);
        okButton->setFont(font2);

        gridLayout->addWidget(okButton, 1, 1, 1, 1);


        retranslateUi(AuthorAbout);

        QMetaObject::connectSlotsByName(AuthorAbout);
    } // setupUi

    void retranslateUi(QDialog *AuthorAbout)
    {
        AuthorAbout->setWindowTitle(QCoreApplication::translate("AuthorAbout", "About Author", nullptr));
        label->setText(QCoreApplication::translate("AuthorAbout", "Completed by", nullptr));
        label_2->setText(QCoreApplication::translate("AuthorAbout", "ICTMS 2-6 Bogatyirev Aleksandr Dmitryevich", nullptr));
        okButton->setText(QCoreApplication::translate("AuthorAbout", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthorAbout: public Ui_AuthorAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORABOUT_H
