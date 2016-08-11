#ifndef PLANNER_H
#define PLANNER_H

#include <QDialog>

namespace Ui {
class Planner;
}

#include <QHBoxLayout>
#include "MortgagePiece.h"

class Planner : public QDialog
{
    Q_OBJECT

public:
    explicit Planner(QWidget *parent = 0);
    ~Planner();

private slots:
    void on_pushButton_clicked();

    void slotNewData();

private:
    void addPiece();
    void clearFuture();
    Ui::Planner *ui;
    QHBoxLayout *plannerLayout;
    QVector<MortgagePiece*> pieces;
};

#endif // PLANNER_H
