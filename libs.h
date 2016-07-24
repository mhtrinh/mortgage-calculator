#ifndef LIBS_H
#define LIBS_H

#include <QString>

void getBankInterest(double numPayment,double monthlyPayment,double mortgageAmout, double &totalPaid, double &bankInterest);
bool validate(const QString &text1, double &val1);
bool log_base(double base,double x, double &res);
QString printThousand(double val);

#endif // LIBS_H
