#include "CompoundInterest.h"
#include "ui_CompoundInterest.h"

#include "libs.h"

CompoundInterest::CompoundInterest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompoundInterest)
{
    ui->setupUi(this);
    this->setLayout(ui->mainLayout);
    this->setWindowTitle("Saving");
    connect(ui->initialDepositEdt,&QLineEdit::textChanged,this,&CompoundInterest::updateSummary);
    connect(ui->weeklyDepositEdt,&QLineEdit::textChanged,this,&CompoundInterest::updateSummary);
    connect(ui->annualRateEdt,&QLineEdit::textChanged,this,&CompoundInterest::updateSummary);
    connect(ui->durationEdt,&QLineEdit::textChanged,this,&CompoundInterest::updateSummary);
}

CompoundInterest::~CompoundInterest()
{
    delete ui;
}

void CompoundInterest::updateSummary()
{
    double initDeposit,weeklyDeposit,annualRate,duration;
    if (validate(ui->initialDepositEdt->text(),initDeposit)
            && validate(ui->weeklyDepositEdt->text(),weeklyDeposit)
            && validate(ui->annualRateEdt->text(),annualRate)
            && validate(ui->durationEdt->text(),duration))
    {
        double monthlyPayment = weeklyDeposit*52/12;
        annualRate /= 100;
        double tot = initDeposit*pow((1+annualRate/12),12*duration) + monthlyPayment*(pow((1+annualRate/12),12*duration)-1)/annualRate*12*(1+annualRate/12);
        double totDeposit = monthlyPayment*12*duration;
        double interest = tot-totDeposit;
        ui->totalLbl->setText(printThousand(tot));
        ui->totInterestLbl->setText(printThousand(interest));
        ui->totInvestedLbl->setText(printThousand(totDeposit));
    }
    else
    {
        clearSummary();
    }
}

void CompoundInterest::clearSummary()
{
    ui->totInterestLbl->clear();
    ui->totInvestedLbl->clear();
    ui->totalLbl->clear();
}
