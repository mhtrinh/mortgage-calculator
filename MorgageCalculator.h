#ifndef MORGAGECALCULATOR_H
#define MORGAGECALCULATOR_H

#include <QWidget>

#include <QString>

namespace Ui {
class MorgageCalculator;
}

class MorgageCalculator : public QWidget
{
    Q_OBJECT

public:
    explicit MorgageCalculator(QWidget *parent = 0);
    ~MorgageCalculator();

private slots:
    void onTargetChanged();
    void updateResults();

    void on_afterEdt_textChanged(const QString &arg1);

private:
    void updateFuture();
    QString printThousand(double val);

    void updateCost();

    bool validate(const QString &text1, double &val1);

    bool dataValid;
    double morgageAmount;
    double annualRate;
    double monthlyRate;
    double monthlyPayment;
    double duration;


    void processDuration();
    void processPayment();
    void processRate();
    void processMorgage();

    bool log_base(double base,double x, double &res);

    Ui::MorgageCalculator *ui;

    bool changing;

};

#endif // MORGAGECALCULATOR_H
