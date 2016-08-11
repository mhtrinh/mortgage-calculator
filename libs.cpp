#include "libs.h"
#include <math.h>


///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////
bool getFuture(double mortgageAmount, double monthlyRate, double monthlyPayment, double numMonth, double &paid, double &left, double &futur)
{
    double numMonthRequired,interest;
    if (getSummary(mortgageAmount,monthlyRate,monthlyPayment,numMonthRequired,paid,interest))
    {
        if (numMonthRequired < numMonth)
        {
            futur = paid;
            left = 0;
            paid = mortgageAmount;
        }
        else
        {
            paid = (monthlyPayment/monthlyRate - mortgageAmount)*(pow(1+monthlyRate,numMonth)-1);
            left = mortgageAmount-paid;
            futur = numMonth*monthlyPayment;
        }
        return true;
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////
bool getSummary(double mortgageAmount, double monthlyRate, double monthlyPayment, double &numMonth, double &totalPaid, double &bankInterest)
{
    double dividend = monthlyPayment-mortgageAmount*monthlyRate;
    if ((dividend !=0) && log_base((1+monthlyRate),(monthlyPayment/(dividend)),numMonth))
    {
        getBankInterest(numMonth,monthlyPayment,mortgageAmount,totalPaid,bankInterest);
        return true;
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////
void getBankInterest(double numPayment,double monthlyPayment,double mortgageAmout, double &totalPaid, double &bankInterest)
{
    totalPaid = numPayment*monthlyPayment;

    bankInterest = totalPaid - mortgageAmout;

}

///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////
bool validate(const QString &text1, double &val1)
{
    bool ok;
    val1 = text1.toDouble(&ok);
    return ok;
}

///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////
bool log_base(double base, double x, double &res)
{
    if (x == 1) return false;
    if (x == 0) return false;
    if (x < 0) return false;

    res = log(x)/log(base);
    return true;
}

///////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////
QString printThousand(double val)
{
    QString word = QString::number(val,'f',0);
    int w_size = word.size();
    if (w_size > 3) {
        word.insert(word.size() - 3, " ");
    }
    if (w_size > 6) {
        word.insert(word.size() - 7, " ");
    }
    return word;
}
