#ifndef MORTGAGEPIECE_H
#define MORTGAGEPIECE_H

#include <QWidget>

namespace Ui {
class MortgagePiece;
}

class MortgagePiece : public QWidget
{
    Q_OBJECT

public:
    explicit MortgagePiece(QWidget *parent = 0);
    ~MortgagePiece();

    void setName(QString name);

    bool getFutureStateAfter(double numMonth, double &principalPaid, double &principalLeft, double &futurPaid);

signals:
    void sigNewData();

private slots:
    void updateSummary();

private:
    void clearSummary();

    Ui::MortgagePiece *ui;
    bool dataValid;
};

#endif // MORTGAGEPIECE_H
