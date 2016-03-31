#ifndef G_WELCOMEDIALOG_H
#define G_WELCOMEDIALOG_H

#include <QDialog>
#include "c_menudata.h"

namespace Ui {
class G_WelcomeDialog;
}

class G_WelcomeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit G_WelcomeDialog(QWidget *parent = 0);
    ~G_WelcomeDialog();


    MENU_OPTION GetMenuOption();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::G_WelcomeDialog *ui;
    C_MenuData *menu;
};

#endif // G_WELCOMEDIALOG_H
