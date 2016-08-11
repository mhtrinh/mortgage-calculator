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
    explicit MortgagePiece(int id, QWidget *parent = 0);
    ~MortgagePiece();

    void setName(QString name);

    bool getFutureStateAfter(double numMonth, double &principalPaid, double &principalLeft, double &futurPaid);

signals:
    void sigNewData();
    void sigDeleteMe(int id);

private slots:
    void updateSummary();

    void on_pushButton_clicked();

private:
    void clearSummary();

    Ui::MortgagePiece *ui;

    int id;
};

#endif // MORTGAGEPIECE_H
