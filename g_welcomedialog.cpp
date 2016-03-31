#include "g_welcomedialog.h"
#include "ui_g_welcomedialog.h"

//#include "c_menudata.h"

G_WelcomeDialog::G_WelcomeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G_WelcomeDialog),
    menu(new C_MenuData)
{
    ui->setupUi(this);

}

G_WelcomeDialog::~G_WelcomeDialog()
{
    delete ui;
    delete menu;
}

MENU_OPTION G_WelcomeDialog::GetMenuOption() {
    return this->menu->GetOption();
}

void G_WelcomeDialog::on_pushButton_clicked()
{
    menu->SetChoice(MENU_NEW_GAME);
    this->accept();
}

void G_WelcomeDialog::on_pushButton_2_clicked()
{
    menu->SetChoice(MENU_LOAD_GAME);
    this->accept();
}
