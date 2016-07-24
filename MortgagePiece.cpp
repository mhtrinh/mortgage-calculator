#include "MortgagePiece.h"
#include "ui_MortgagePiece.h"

#include "libs.h"

MortgagePiece::MortgagePiece(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MortgagePiece)
{
    ui->setupUi(this);
    this->setLayout(ui->mainLayout);
    connect(ui->amountEdt,&QLineEdit::textChanged,this,&MortgagePiece::updateSummary);
    connect(ui->paymentEdt,&QLineEdit::textChanged,this,&MortgagePiece::updateSummary);
    connect(ui->rateEdt,&QLineEdit::textChanged,this,&MortgagePiece::updateSummary);

}

MortgagePiece::~MortgagePiece()
{
    delete ui;
}

void MortgagePiece::setName(QString name)
{
    ui->groupBox->setTitle(name);
}

///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////
void MortgagePiece::updateSummary()
{
    double mortgageAmount,annualRate,monthlyPayment,weeklyPayment;
    if (validate(ui->amountEdt->text(),mortgageAmount)
            && validate(ui->rateEdt->text(),annualRate)
            && validate(ui->paymentEdt->text(),weeklyPayment))
    {

        mortgageAmount *= 1000;
        monthlyPayment = weeklyPayment*52/12;
        double numPayment;
        double monthlyRate = annualRate/1200;
        double dividend = monthlyPayment-mortgageAmount*monthlyRate;

        if ((dividend !=0) && log_base((1+monthlyRate),(monthlyPayment/(dividend)),numPayment))
        {
            double bankInterest,totalPaid;
            getBankInterest(numPayment,monthlyPayment,mortgageAmount,totalPaid,bankInterest);

            ui->durationLbl->setText(QString::number(numPayment/12,'f',2));
            ui->bankLbl->setText(printThousand(bankInterest));
            ui->totPaymentLbl->setText(printThousand(totalPaid));
            return;
        }
    }
    clearSummary();

}

///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////
void MortgagePiece::clearSummary()
{
    ui->totPaymentLbl->clear();
    ui->bankLbl->clear();
    ui->durationLbl->clear();
}
