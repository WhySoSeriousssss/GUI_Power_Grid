#include "g_statingdialog.h"
#include "ui_g_statingdialog.h"

G_StatingDialog::G_StatingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G_StatingDialog)
{
    ui->setupUi(this);
}

G_StatingDialog::~G_StatingDialog()
{
    delete ui;
}

int G_StatingDialog::GetNumberOfPlayers() {
    return m_iPlayers;
}

void G_StatingDialog::on_pushButton_clicked()
{
    int num = ui->comboBox->currentIndex();
    m_iPlayers = num + 2;
    this->accept();
}
