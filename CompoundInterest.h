#ifndef COMPOUNDINTEREST_H
#define COMPOUNDINTEREST_H

#include <QDialog>

namespace Ui {
class CompoundInterest;
}

class CompoundInterest : public QDialog
{
    Q_OBJECT

public:
    explicit CompoundInterest(QWidget *parent = 0);
    ~CompoundInterest();

private slots:
    void updateSummary();

private:
    void clearSummary();

    Ui::CompoundInterest *ui;
};

#endif // COMPOUNDINTEREST_H
