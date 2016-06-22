#include "MorgageCalculator.h"
#include "ui_MorgageCalculator.h"
#include <QButtonGroup>


///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////
MorgageCalculator::MorgageCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MorgageCalculator)
{
    ui->setupUi(this);

    QButtonGroup *aGroup = new QButtonGroup(this);
    aGroup->addButton(ui->durationRadio);
    aGroup->addButton(ui->rateRadio);
    aGroup->addButton(ui->morgageRadio);
    aGroup->addButton(ui->paymentRadio);

    connect(aGroup, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonReleased),
        this,&MorgageCalculator::onTargetChanged);

    connect(ui->amountEdt,&QLineEdit::textChanged,this,&MorgageCalculator::updateResults);
    connect(ui->rateEdt,&QLineEdit::textChanged,this,&MorgageCalculator::updateResults);
    connect(ui->paymentEdt,&QLineEdit::textChanged,this,&MorgageCalculator::updateResults);
    connect(ui->durationEdt,&QLineEdit::textChanged,this,&MorgageCalculator::updateResults);
    connect(ui->weeklyRadio,&QRadioButton::clicked,this,&MorgageCalculator::updateResults);
    connect(ui->biweeklyRadio,&QRadioButton::clicked,this,&MorgageCalculator::updateResults);
    connect(ui->monthlyRadio,&QRadioButton::clicked,this,&MorgageCalculator::updateResults);

    dataValid = false;
    ui->paymentRadio->setChecked(true);
    onTargetChanged();
}

///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////
MorgageCalculator::~MorgageCalculator()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////
void MorgageCalculator::onTargetChanged()
{
    ui->amountEdt->setEnabled(true);
    ui->rateEdt->setEnabled(true);
    ui->durationEdt->setEnabled(true);
    ui->paymentEdt->setEnabled(true);

    if (ui->durationRadio->isChecked())
    {
        ui->durationEdt->setEnabled(false);
    }
    else if (ui->rateRadio->isChecked())
    {
        ui->rateEdt->setEnabled(false);
    }
    else if (ui->paymentRadio->isChecked())
        ui->paymentEdt->setEnabled(false);
    else
        ui->amountEdt->setEnabled(false);

    updateResults();
}

///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////
bool MorgageCalculator::validate(const QString &text1, double &val1)
{
    bool ok;
    val1 = text1.toDouble(&ok);
    dataValid = ok;
    return ok;
}


///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////
void MorgageCalculator::updateResults()
{
    if (ui->durationRadio->isChecked())
        processDuration();
    else if (ui->rateRadio->isChecked())
        processRate();
    else if (ui->paymentRadio->isChecked())
        processPayment();
    else
        processMorgage();
}

///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////
void MorgageCalculator::processDuration()
{
    double payment;
    if (!validate(ui->amountEdt->text(),morgageAmount)) return;
    else if (!validate(ui->rateEdt->text(),annualRate)) return;
    else if (!validate(ui->paymentEdt->text(),payment)) return;

    /*
    if (ui->weeklyRadio->isChecked())
        monthlyPayment
*/

}

///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////
void MorgageCalculator::processPayment()
{
    //double numYear;
    if (!validate(ui->amountEdt->text(),morgageAmount)) return;
    else if (!validate(ui->rateEdt->text(),annualRate)) return;
    else if (!validate(ui->durationEdt->text(),duration)) return;

    morgageAmount *= 1000;
    double payment;
    double monthRate = annualRate/1200;
    double numPayment = duration*12;
    monthlyPayment = morgageAmount*(monthRate*pow((1+monthRate),numPayment))/(pow(1+monthRate,numPayment)-1);

    if (ui->weeklyRadio->isChecked())
    {
        payment = monthlyPayment*12/52;
    }
    else if (ui->biweeklyRadio->isChecked())
    {
        payment = monthlyPayment*12/26;
    }
    else
        payment = monthlyPayment;

    ui->paymentEdt->setText(QString::number(payment,'f',2));
}

void MorgageCalculator::processRate()
{

}

void MorgageCalculator::processMorgage()
{

}
