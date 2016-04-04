#include "g_buyingresourcesdialog.h"
#include "ui_g_buyingresourcesdialog.h"

G_BuyingResourcesDialog::G_BuyingResourcesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G_BuyingResourcesDialog)
{
    ui->setupUi(this);
    tempCost = 0;
}

G_BuyingResourcesDialog::~G_BuyingResourcesDialog()
{
    delete ui;
}

void G_BuyingResourcesDialog::Initialize(C_PlayerData *p, C_ResourceMarket *m) {
    player = p;
    market = m;

    //set amount of resources
    ui->label_16->setText(QString::number(market->GetCoal()));
    ui->label_17->setText(QString::number(market->GetOil()));
    ui->label_18->setText(QString::number(market->GetGarbage()));
    ui->label_19->setText(QString::number(market->GetUranium()));

    //set price of resources
    ui->label_8->setText(QString::number(market->GetCostOfCoal()));
    ui->label_9->setText(QString::number(market->GetCostOfOil()));
    ui->label_10->setText(QString::number(market->GetCostOfGarbage()));
    ui->label_11->setText(QString::number(market->GetCostOfUranium()));

    //set player info
    ui->label_12->setText(QString::fromStdString(player->GetName()));
    ui->label_13->setText(QString::number(player->GetMoney()));

    //set quantity limits
    ui->spinBox->setMaximum(player->GetMaxCoal());
    ui->spinBox_2->setMaximum(player->GetMaxOil());
    ui->spinBox_3->setMaximum(player->GetMaxGarbage());
    ui->spinBox_4->setMaximum(player->GetMaxUranium());
}

int* G_BuyingResourcesDialog::GetBuyingQuantities() {
    int* qt = new int[4];
    qt[0] = ui->spinBox->value();
    qt[1] = ui->spinBox_2->value();
    qt[2] = ui->spinBox_3->value();
    qt[3] = ui->spinBox_4->value();
    return qt;
}

void G_BuyingResourcesDialog::on_pushButton_clicked()
{
    this->accept();
}
