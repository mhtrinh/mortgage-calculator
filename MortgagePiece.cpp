#include "MortgagePiece.h"
#include "ui_MortgagePiece.h"

#include "libs.h"

MortgagePiece::MortgagePiece(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MortgagePiece)
{
    dataValid = false;
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

bool MortgagePiece::getFutureStateAfter(double numMonth, double &principalPaid, double &principalLeft, double &futurPaid)
{
    double mortgageAmount,annualRate,monthlyPayment,weeklyPayment;
    if (validate(ui->amountEdt->text(),mortgageAmount)
            && validate(ui->rateEdt->text(),annualRate)
            && validate(ui->paymentEdt->text(),weeklyPayment))
    {
        mortgageAmount *= 1000;
        monthlyPayment = weeklyPayment*52/12;
        double monthlyRate = annualRate/1200;

        return getFuture(mortgageAmount,monthlyRate,monthlyPayment,numMonth,principalPaid,principalLeft,futurPaid);
    }
    return false;
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

        double monthlyRate = annualRate/1200;
        double numPayment,bankInterest,totalPaid;
        if (getSummary(mortgageAmount,monthlyRate,monthlyPayment,numPayment,totalPaid,bankInterest))
        {
            ui->durationLbl->setText(QString::number(numPayment/12,'f',2));
            ui->bankLbl->setText(printThousand(bankInterest));
            ui->totPaymentLbl->setText(printThousand(totalPaid));
            emit sigNewData();
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
