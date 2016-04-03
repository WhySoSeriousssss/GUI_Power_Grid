#include "g_biddingdialog.h"
#include "ui_g_biddingdialog.h"
#include <QTimer>

G_BiddingDialog::G_BiddingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G_BiddingDialog)
{
    ui->setupUi(this);
}

G_BiddingDialog::~G_BiddingDialog()
{
    delete ui;
}

void G_BiddingDialog::Initialize(std::vector<C_PlayerData *>* pBidders, std::vector<C_PlayerData *>* pBList) {
    biddersThisRound = pBidders;
    bidderList = pBList;
    currentBidder = 1;
}

void G_BiddingDialog::SetInitialDisplay(int cardNum) {
    ui->label_2->setText(QString::fromStdString((*biddersThisRound)[1]->GetName()));
    ui->label_5->setText(QString::number((*biddersThisRound)[1]->GetMoney()));
    ui->spinBox->setMinimum(cardNum + 1);
    ui->spinBox->setMaximum((*biddersThisRound)[1]->GetMoney());

    biddingPrice = cardNum;

    QString info1, info2;
    info1 = "Player " + QString::fromStdString((*biddersThisRound)[0]->GetName()) + " started a bid on card #" + QString::number(cardNum);
    info2 = "Starting bidding price is $" + QString::number(cardNum);
    ui->textBrowser->append(info1);
    ui->textBrowser->append(info2);
}

int G_BiddingDialog::GetBiddingPrice() {
    return biddingPrice;
}

void G_BiddingDialog::on_pushButton_clicked()
{
    QString info;
    info = "Player " + QString::fromStdString((*biddersThisRound)[currentBidder]->GetName()) + " named $" + QString::number(ui->spinBox->value());
    biddingPrice = ui->spinBox->value();
    ui->textBrowser->append(info);

    currentBidder = (currentBidder + 1) % (int)(*biddersThisRound).size();
    ui->label_2->setText(QString::fromStdString((*biddersThisRound)[currentBidder]->GetName()));
    ui->label_5->setText(QString::number((*biddersThisRound)[currentBidder]->GetMoney()));
    ui->spinBox->setMinimum(biddingPrice + 1);
    ui->spinBox->setMaximum((*biddersThisRound)[currentBidder]->GetMoney());

    if ((*biddersThisRound).size() == 1) {
        info = "Player " + QString::fromStdString((*biddersThisRound)[0]->GetName()) + " bought this card.";
        ui->textBrowser->append(info);
        // for clearly seeing the test result, you can commend line the following code
        this->accept();
    }
}

void G_BiddingDialog::on_pushButton_2_clicked()
{
    QString info;
    info = "Player " + QString::fromStdString((*biddersThisRound)[currentBidder]->GetName()) + " abandoned bidding.";
    ui->textBrowser->append(info);
    (*biddersThisRound).erase((*biddersThisRound).begin() + currentBidder);

    currentBidder = currentBidder % (int)(*biddersThisRound).size();

    if ((*biddersThisRound).size() == 1) {
        info = "Player " + QString::fromStdString((*biddersThisRound)[0]->GetName()) + " bought this card.";
        ui->textBrowser->append(info);

        // for clearly seeing the test result, you can commend line the following code
     //   this->accept();
    }

    ui->label_2->setText(QString::fromStdString((*biddersThisRound)[currentBidder]->GetName()));
    ui->label_5->setText(QString::number((*biddersThisRound)[currentBidder]->GetMoney()));
    ui->spinBox->setMinimum(biddingPrice + 1);
    ui->spinBox->setMaximum((*biddersThisRound)[currentBidder]->GetMoney());
}
