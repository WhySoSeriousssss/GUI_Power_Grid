#include "g_playerinfoinitdialog.h"
#include "ui_g_playerinfoinitdialog.h"

G_PlayerInfoInitDialog::G_PlayerInfoInitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G_PlayerInfoInitDialog)
{
    ui->setupUi(this);
}

G_PlayerInfoInitDialog::~G_PlayerInfoInitDialog()
{
    delete ui;
}

std::string G_PlayerInfoInitDialog::GetPlayerName() {
    return this->playerName;
}

void G_PlayerInfoInitDialog::on_pushButton_clicked()
{
    QString Qstr = ui->lineEdit->text();
    playerName = Qstr.toStdString();
    this->accept();
}
