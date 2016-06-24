#include "MainDialog.h"
#include "ui_MainDialog.h"

#include "MorgageCalculator.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    this->setLayout(ui->mainLayout);
    this->setWindowTitle("Morgage calculator");

}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_pushButton_clicked()
{
    this->close();
}
