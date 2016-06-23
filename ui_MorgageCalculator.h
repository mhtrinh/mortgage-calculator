/********************************************************************************
** Form generated from reading UI file 'MorgageCalculator.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORGAGECALCULATOR_H
#define UI_MORGAGECALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MorgageCalculator
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *rateEdt;
    QLineEdit *amountEdt;
    QLabel *label_6;
    QLineEdit *durationEdt;
    QLabel *label_3;
    QRadioButton *durationRadio;
    QRadioButton *rateRadio;
    QRadioButton *morgageRadio;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLineEdit *paymentEdt;
    QLabel *label;
    QRadioButton *paymentRadio;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *weeklyRadio;
    QRadioButton *biweeklyRadio;
    QRadioButton *monthlyRadio;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *MorgageCalculator)
    {
        if (MorgageCalculator->objectName().isEmpty())
            MorgageCalculator->setObjectName(QStringLiteral("MorgageCalculator"));
        MorgageCalculator->resize(655, 422);
        verticalLayoutWidget = new QWidget(MorgageCalculator);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 30, 319, 331));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        rateEdt = new QLineEdit(verticalLayoutWidget);
        rateEdt->setObjectName(QStringLiteral("rateEdt"));

        gridLayout->addWidget(rateEdt, 1, 1, 1, 1);

        amountEdt = new QLineEdit(verticalLayoutWidget);
        amountEdt->setObjectName(QStringLiteral("amountEdt"));

        gridLayout->addWidget(amountEdt, 0, 1, 1, 1);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        durationEdt = new QLineEdit(verticalLayoutWidget);
        durationEdt->setObjectName(QStringLiteral("durationEdt"));

        gridLayout->addWidget(durationEdt, 2, 1, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        durationRadio = new QRadioButton(verticalLayoutWidget);
        durationRadio->setObjectName(QStringLiteral("durationRadio"));
        durationRadio->setChecked(true);

        gridLayout->addWidget(durationRadio, 2, 2, 1, 1);

        rateRadio = new QRadioButton(verticalLayoutWidget);
        rateRadio->setObjectName(QStringLiteral("rateRadio"));

        gridLayout->addWidget(rateRadio, 1, 2, 1, 1);

        morgageRadio = new QRadioButton(verticalLayoutWidget);
        morgageRadio->setObjectName(QStringLiteral("morgageRadio"));

        gridLayout->addWidget(morgageRadio, 0, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        paymentEdt = new QLineEdit(groupBox);
        paymentEdt->setObjectName(QStringLiteral("paymentEdt"));

        gridLayout_2->addWidget(paymentEdt, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        paymentRadio = new QRadioButton(groupBox);
        paymentRadio->setObjectName(QStringLiteral("paymentRadio"));

        gridLayout_2->addWidget(paymentRadio, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        weeklyRadio = new QRadioButton(groupBox_2);
        weeklyRadio->setObjectName(QStringLiteral("weeklyRadio"));

        verticalLayout_2->addWidget(weeklyRadio);

        biweeklyRadio = new QRadioButton(groupBox_2);
        biweeklyRadio->setObjectName(QStringLiteral("biweeklyRadio"));

        verticalLayout_2->addWidget(biweeklyRadio);

        monthlyRadio = new QRadioButton(groupBox_2);
        monthlyRadio->setObjectName(QStringLiteral("monthlyRadio"));
        monthlyRadio->setChecked(true);

        verticalLayout_2->addWidget(monthlyRadio);


        verticalLayout->addWidget(groupBox_2);


        verticalLayout_3->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        groupBox_3 = new QGroupBox(MorgageCalculator);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(380, 40, 231, 71));
        formLayout_3 = new QFormLayout(groupBox_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, label_5);

        QWidget::setTabOrder(amountEdt, rateEdt);
        QWidget::setTabOrder(rateEdt, durationEdt);
        QWidget::setTabOrder(durationEdt, paymentEdt);
        QWidget::setTabOrder(paymentEdt, weeklyRadio);
        QWidget::setTabOrder(weeklyRadio, biweeklyRadio);
        QWidget::setTabOrder(biweeklyRadio, monthlyRadio);
        QWidget::setTabOrder(monthlyRadio, morgageRadio);
        QWidget::setTabOrder(morgageRadio, rateRadio);
        QWidget::setTabOrder(rateRadio, durationRadio);
        QWidget::setTabOrder(durationRadio, paymentRadio);

        retranslateUi(MorgageCalculator);

        QMetaObject::connectSlotsByName(MorgageCalculator);
    } // setupUi

    void retranslateUi(QWidget *MorgageCalculator)
    {
        MorgageCalculator->setWindowTitle(QApplication::translate("MorgageCalculator", "MorgageCalculator", 0));
        label_2->setText(QApplication::translate("MorgageCalculator", "Annual rate (%)", 0));
        rateEdt->setText(QApplication::translate("MorgageCalculator", "5", 0));
        amountEdt->setText(QApplication::translate("MorgageCalculator", "300", 0));
        label_6->setText(QApplication::translate("MorgageCalculator", "Morgage Amount (crapload)", 0));
        durationEdt->setText(QApplication::translate("MorgageCalculator", "20", 0));
        label_3->setText(QApplication::translate("MorgageCalculator", "Morgage duration (years)", 0));
#ifndef QT_NO_TOOLTIP
        durationRadio->setToolTip(QApplication::translate("MorgageCalculator", "<html><head/><body><p>Select this field to make it to be calculated</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        durationRadio->setText(QString());
#ifndef QT_NO_TOOLTIP
        rateRadio->setToolTip(QApplication::translate("MorgageCalculator", "Select this field to make it to be calculated", 0));
#endif // QT_NO_TOOLTIP
        rateRadio->setText(QString());
#ifndef QT_NO_TOOLTIP
        morgageRadio->setToolTip(QApplication::translate("MorgageCalculator", "Select this field to make it to be calculated", 0));
#endif // QT_NO_TOOLTIP
        morgageRadio->setText(QString());
        groupBox->setTitle(QApplication::translate("MorgageCalculator", "Payment", 0));
        label->setText(QApplication::translate("MorgageCalculator", "Amount:", 0));
#ifndef QT_NO_TOOLTIP
        paymentRadio->setToolTip(QApplication::translate("MorgageCalculator", "Select this field to make it to be calculated", 0));
#endif // QT_NO_TOOLTIP
        paymentRadio->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MorgageCalculator", "Per", 0));
        weeklyRadio->setText(QApplication::translate("MorgageCalculator", "Week", 0));
        biweeklyRadio->setText(QApplication::translate("MorgageCalculator", "Bi-week", 0));
        monthlyRadio->setText(QApplication::translate("MorgageCalculator", "Month", 0));
        groupBox_3->setTitle(QApplication::translate("MorgageCalculator", "Morgage", 0));
        label_4->setText(QApplication::translate("MorgageCalculator", "Bank interest: ", 0));
        label_5->setText(QApplication::translate("MorgageCalculator", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MorgageCalculator: public Ui_MorgageCalculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORGAGECALCULATOR_H
