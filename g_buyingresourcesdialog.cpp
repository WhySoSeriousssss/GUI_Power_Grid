#include "g_buyingresourcesdialog.h"
#include "ui_g_buyingresourcesdialog.h"

G_BuyingResourcesDialog::G_BuyingResourcesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G_BuyingResourcesDialog)
{
    ui->setupUi(this);
}

G_BuyingResourcesDialog::~G_BuyingResourcesDialog()
{
    delete ui;
}

void G_BuyingResourcesDialog::SetResourceMarket(int coal, int oil, int garbage, int uranium, int coalPrice, int oilPrice, int garbagePrice, int uraniumPrice) {
    for (int i = 0; i <= coal; i++) {
        ui->comboBox->addItem(QString::number(i), i);
    }
    for (int i = 0; i <= oil; i++) {
        ui->comboBox_2->addItem(QString::number(i), i);
    }
    for (int i = 0; i <= garbage; i++) {
        ui->comboBox_3->addItem(QString::number(i), i);
    }
    for (int i = 0; i <= uranium; i++) {
        ui->comboBox_4->addItem(QString::number(i), i);
    }

    ui->label_8->setText(QString::number(coalPrice));
    ui->label_9->setText(QString::number(oilPrice));
    ui->label_10->setText(QString::number(garbagePrice));
    ui->label_11->setText(QString::number(uraniumPrice));
}

void G_BuyingResourcesDialog::SetDisplay(std::string name, int money) {
    QString name_qstr = QString::fromStdString(name);
    QString money_qstr = QString::number(money);

    ui->label_12->setText(name_qstr);
    ui->label_13->setText(money_qstr);
}

int* G_BuyingResourcesDialog::GetBuyingQuantities() {
    int* qt = new int[4];
    qt[0] = ui->comboBox->currentIndex();
    qt[1] = ui->comboBox_2->currentIndex();
    qt[2] = ui->comboBox_3->currentIndex();
    qt[3] = ui->comboBox_4->currentIndex();

    return qt;
}

void G_BuyingResourcesDialog::on_pushButton_clicked()
{
    this->accept();
}
