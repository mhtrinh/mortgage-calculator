#include "Planner.h"
#include "ui_Planner.h"


#include "libs.h"

Planner::Planner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Planner)
{
    ui->setupUi(this);
    this->setLayout(ui->mainLayout);
    plannerLayout = new QHBoxLayout();
    ui->groupBox->setLayout(plannerLayout);
    //ui->gridLayout->setColumnStretch(99,100);
    connect(ui->afterYearEdt,&QLineEdit::textChanged,this,&Planner::slotNewData);

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

void Planner::slotNewData()
{
    double numYear;
    if (!validate(ui->afterYearEdt->text(),numYear))
    {
        clearFuture();
        return;
    }
    double numMonth = numYear*12;
    double totPaid=0,totLeft=0,totFuture=0;


    for (int i=0; i < pieces.size(); i++)
    {
        double paid,left,future;
        if (pieces[i]->getFutureStateAfter(numMonth,paid,left,future))
        {
            totPaid += paid;
            totLeft += left;
            totFuture += future;
        }
        else
        {
            clearFuture();
            break;
        }
    }

    ui->futurLbl->setText(printThousand(totFuture));
    ui->paidLbl->setText(printThousand(totPaid));
    ui->leftLbl->setText(printThousand(totLeft));

}

void Planner::addPiece()
{
    MortgagePiece *piece = new MortgagePiece();
    plannerLayout->addWidget(piece);
    pieces.push_back(piece);
    piece->setName(QString("Part %1 :").arg(pieces.size()));
    connect(piece,&MortgagePiece::sigNewData,this,&Planner::slotNewData);
}

void Planner::clearFuture()
{
    ui->paidLbl->clear();
    ui->futurLbl->clear();
    ui->leftLbl->clear();
}
