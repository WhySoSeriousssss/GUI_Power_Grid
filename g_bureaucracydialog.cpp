#include "g_bureaucracydialog.h"
#include "ui_g_bureaucracydialog.h"

G_BureaucracyDialog::G_BureaucracyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G_BureaucracyDialog)
{
    ui->setupUi(this);
}

G_BureaucracyDialog::~G_BureaucracyDialog()
{
    delete ui;
}

void G_BureaucracyDialog::Initialize(C_PlayerData *p) {
    this->player = p;
    ui->label_2->setText(QString::fromStdString(player->GetName()));
    ui->label_13->setText(QString::number(player->GetMoney()));
    ui->label_8->setText(QString::number(player->GetCoal()));
    ui->label_9->setText(QString::number(player->GetOil()));
    ui->label_10->setText(QString::number(player->GetGarbage()));
    ui->label_11->setText(QString::number(player->GetUranium()));

    int numberOfCards = (int)player->GetCard().size();

    ui->checkBox->setVisible(false);
    ui->checkBox_2->setVisible(false);
    ui->checkBox_3->setVisible(false);

    switch (numberOfCards) {
    case 3:
        ui->checkBox_3->setText("Card #" + QString::number(player->GetCard()[2]->GetNumber()));
        ui->checkBox_3->setVisible(true);
    case 2:
        ui->checkBox_2->setText("Card #" + QString::number(player->GetCard()[1]->GetNumber()));
        ui->checkBox_2->setVisible(true);
    case 1:
        ui->checkBox->setText("Card #" + QString::number(player->GetCard()[0]->GetNumber()));
        ui->checkBox->setVisible(true);
    default:
        break;
    }

}
