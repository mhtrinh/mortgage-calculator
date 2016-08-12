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
    for (int i =0; i < savings.size(); i++)
    {
        savings[i]->close();
        delete savings[i];
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

void MainDialog::on_pushButton_3_clicked()
{
    CompoundInterest *saving = new CompoundInterest();
    savings.push_back(saving);
    saving->show();
}

void MainDialog::closeAll()
{
    for (int i=0; i<planners.size();i++)
    {
        planners[i]->close();
    }
    for (int i =0; i < savings.size(); i++)
    {
        savings[i]->close();
    }
}

void MainDialog::closeEvent(QCloseEvent *ev)
{
    closeAll();
    QDialog::closeEvent(ev);
}
