#include "MainDialog.h"
#include "ui_MainDialog.h"

#include "MorgageCalculator.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    this->setLayout(ui->mainLayout);
    this->setWindowTitle(QString("Morgage calculator - v%1").arg(VERSION));

}

MainDialog::~MainDialog()
{
    delete ui;
    for (int i=0; i<planners.size();i++)
    {
        planners[i]->close();
        delete planners[i];
    }
}

void MainDialog::on_pushButton_clicked()
{
    this->close();
}

void MainDialog::on_pushButton_2_clicked()
{
    Planner *planner = new Planner();
    planners.push_back(planner);
    planner->show();

}
