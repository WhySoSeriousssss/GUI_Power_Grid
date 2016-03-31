#include "g_gamewindow.h"
#include "ui_g_gamewindow.h"

g_GameWindow::g_GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::g_GameWindow)
{
    ui->setupUi(this);
    setFixedSize(1280, 720);
}

g_GameWindow::~g_GameWindow()
{
    delete ui;
}
