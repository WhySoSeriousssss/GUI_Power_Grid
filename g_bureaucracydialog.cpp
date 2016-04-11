#include "g_bureaucracydialog.h"
#include "ui_g_bureaucracydialog.h"

G_BureaucracyDialog::G_BureaucracyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G_BureaucracyDialog)
{
    ui->setupUi(this);

    coalDecrease = 0;
    oilDecrease = 0;
    garbageDecrease = 0;
    uraniumDecrease = 0;
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
        ui->checkBox_3->setCheckable(TestEnoughFuel(2));

    case 2:
        ui->checkBox_2->setText("Card #" + QString::number(player->GetCard()[1]->GetNumber()));
        ui->checkBox_2->setVisible(true);
        ui->checkBox_2->setCheckable(TestEnoughFuel(1));

    case 1:
        ui->checkBox->setText("Card #" + QString::number(player->GetCard()[0]->GetNumber()));
        ui->checkBox->setVisible(true);
        ui->checkBox->setCheckable(TestEnoughFuel(0));

    default:
        break;
    }

}

void G_BureaucracyDialog::RealTimeUpdate(int cardIndex) {
    int fuel = player->GetCard()[cardIndex]->GetResources();
    int cost = player->GetCard()[cardIndex]->GetCost();

    switch (fuel) {
    case 1:
        coalDecrease += cost;
        ui->label_14->setText("(- " + QString::number(coalDecrease) + ")");
        break;

    case 10:
        oilDecrease += cost;
        ui->label_15->setText("(- " + QString::number(oilDecrease) + ")");
        break;

    case 11:
        if (coalDecrease > cost) {
            coalDecrease += cost;
            ui->label_14->setText("(- " + QString::number(coalDecrease) + ")");
        }
        else {
            oilDecrease += cost;
            ui->label_15->setText("(- " + QString::number(oilDecrease) + ")");
        }
        break;

    case 100:
        garbageDecrease += cost;
        ui->label_16->setText("(- " + QString::number(garbageDecrease) + ")");
        break;

    case 1000:
        uraniumDecrease += cost;
        ui->label_17->setText("(- " + QString::number(uraniumDecrease) + ")");
        break;

    default:
        break;
    }

}

void G_BureaucracyDialog::RealTimeClear(int cardIndex) {
    int fuel = player->GetCard()[cardIndex]->GetResources();
    int cost = player->GetCard()[cardIndex]->GetCost();

    switch (fuel) {
    case 1:
        coalDecrease -= cost;
        if (coalDecrease == 0)
            ui->label_14->setText("");
        ui->label_14->setText("(- " + QString::number(coalDecrease) + ")");
        break;

    case 10:
        oilDecrease -= cost;
        if (oilDecrease == 0)
            ui->label_15->setText("");
        ui->label_15->setText("(- " + QString::number(oilDecrease) + ")");
        break;

    case 11:
        //haven't figured out a good way here
        break;

    case 100:
        garbageDecrease -= cost;
        if (garbageDecrease == 0)
            ui->label_16->setText("");
        ui->label_16->setText("(- " + QString::number(garbageDecrease) + ")");
        break;

    case 1000:
        uraniumDecrease -= cost;
        if (uraniumDecrease == 0)
            ui->label_17->setText("");
        ui->label_17->setText("(- " + QString::number(uraniumDecrease) + ")");
        break;

    default:
        break;
    }
}

bool G_BureaucracyDialog::TestEnoughFuel(int cardIndex) {
    int fuel = player->GetCard()[cardIndex]->GetResources();
    int cost = player->GetCard()[cardIndex]->GetCost();

    int coal = player->GetCoal();
    int oil = player->GetOil();
    int garbage = player->GetGarbage();
    int uranium = player->GetUranium();

    switch (fuel) {
    case 1:
        if (coal < cost)
            return false;
        break;
    case 10:
        if (oil < cost)
            return false;
        break;
    case 11:
        if (coal < cost)
            if (oil < cost)
                return false;
        break;
    case 100:
        if (garbage < cost)
            return false;
        break;
    case 1000:
        if (uranium < cost)
            return false;
        break;
    default:
        break;
    }
    return true;
}

void G_BureaucracyDialog::on_pushButton_clicked()
{
    if (ui->checkBox->isChecked())
        player->GenerateElectricity(0);
    if (ui->checkBox_2->isChecked())
        player->GenerateElectricity(1);
    if (ui->checkBox_3->isChecked())
        player->GenerateElectricity(2);
    int income = player->GetIncome();
    std::cout<<"Player "<<player->GetName()<<" gets $" <<income << " this turn.\n";
    this->accept();
}

void G_BureaucracyDialog::on_checkBox_toggled(bool checked)
{
    if (checked == true)
        RealTimeUpdate(0);
    else {
        RealTimeClear(0);
    }

    switch ((int)player->GetCard().size()) {
    case 3:
        ui->checkBox_3->setCheckable(TestEnoughFuel(2));

    case 2:
        ui->checkBox_2->setCheckable(TestEnoughFuel(1));

    default:
        break;
    }
}

void G_BureaucracyDialog::on_checkBox_2_toggled(bool checked)
{
    if (checked == true)
        RealTimeUpdate(1);
    else {
        RealTimeClear(1);
    }

    switch ((int)player->GetCard().size()) {
    case 3:
        ui->checkBox_3->setCheckable(TestEnoughFuel(2));

    case 2:
        ui->checkBox->setCheckable(TestEnoughFuel(0));

    default:
        break;
    }
}

void G_BureaucracyDialog::on_checkBox_3_toggled(bool checked)
{
    if (checked == true) {
        RealTimeUpdate(2);
    }
    else {
        RealTimeClear(2);
    }
    ui->checkBox->setCheckable(TestEnoughFuel(0));
    ui->checkBox_2->setCheckable(TestEnoughFuel(1));
}
