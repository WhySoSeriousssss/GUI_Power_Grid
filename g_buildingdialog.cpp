#include "g_buildingdialog.h"
#include "ui_g_buildingdialog.h"

G_BuildingDialog::G_BuildingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G_BuildingDialog)
{
    ui->setupUi(this);
}

G_BuildingDialog::~G_BuildingDialog()
{
    delete ui;
}

void G_BuildingDialog::Initialize(C_MapData *pMap, C_PlayerData* player) {
    this->map = pMap;
    this->player = player;

    ui->label_2->setText(QString::fromStdString(player->GetName()));
    ui->label_4->setText(QString::number(player->GetMoney()));

    for (int i = 0; i < map->GetCities()->size(); i++) {
        ui->comboBox->addItem(QString::fromStdString((*map->GetCities())[i]->GetName()), i);
    }

}

std::string G_BuildingDialog::GetPlayerLog() {
    return player_log;
}

std::string G_BuildingDialog::GetPhaseLog() {
    return "Building Phase";
}

void G_BuildingDialog::on_comboBox_currentIndexChanged(int index)
{
    ui->label_7->setText(QString::number((*map->GetCities())[index]->GetCost()));
}

void G_BuildingDialog::on_pushButton_clicked()
{
    int i = ui->comboBox->currentIndex();
    player_log = "Player " + player->GetName() + " bought " + (*map->GetCities())[i]->GetName() + "\n";
    player->BuyCity((*map->GetCities())[i]);   
    Notify();
    this->accept();
}

void G_BuildingDialog::on_pushButton_2_clicked()
{
    this->accept();
}
