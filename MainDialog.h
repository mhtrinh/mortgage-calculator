#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#define VERSION "1.0.0"

#include <QDialog>
#include "Planner.h"

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainDialog *ui;
    QVector<Planner*> planners;
};

#endif // MAINDIALOG_H
