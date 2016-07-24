#include "Planner.h"
#include "ui_Planner.h"


Planner::Planner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Planner)
{
    ui->setupUi(this);
    this->setLayout(ui->mainLayout);
    plannerLayout = new QHBoxLayout();
    ui->groupBox->setLayout(plannerLayout);
    //ui->gridLayout->setColumnStretch(99,100);
    addPiece();
}

Planner::~Planner()
{
    delete ui;
}

void Planner::on_pushButton_clicked()
{
    addPiece();
}

void Planner::addPiece()
{
    MortgagePiece *piece = new MortgagePiece();
    plannerLayout->addWidget(piece);
    pieces.push_back(piece);
    piece->setName(QString("Part %1 :").arg(pieces.size()));
}
