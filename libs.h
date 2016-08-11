#ifndef LIBS_H
#define LIBS_H

#include <QString>

bool getFuture(double mortgageAmount, double monthlyRate, double monthlyPayment, double numMonth, double &paid, double &left, double &futur);
bool getSummary(double mortgageAmount, double monthlyRate, double monthlyPayment, double &numMonth, double &totalPaid, double &bankInterest);
void getBankInterest(double numPayment,double monthlyPayment,double mortgageAmout, double &totalPaid, double &bankInterest);
bool validate(const QString &text1, double &val1);
bool log_base(double base,double x, double &res);
QString printThousand(double val);

#endif // LIBS_H
