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

private:
    bool validate(const QString &text1, double &val1);

    bool dataValid;
    double morgageAmount;
    double annualRate;
    double monthlyPayment;
    double duration;


    void processDuration();
    void processPayment();
    void processRate();
    void processMorgage();


    Ui::MorgageCalculator *ui;

};

#endif // MORGAGECALCULATOR_H
