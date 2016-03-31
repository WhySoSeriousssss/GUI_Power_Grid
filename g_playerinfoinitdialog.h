#ifndef PLAYERINFOINITDIALOG_H
#define PLAYERINFOINITDIALOG_H

#include <QDialog>

namespace Ui {
class G_PlayerInfoInitDialog;
}

class G_PlayerInfoInitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit G_PlayerInfoInitDialog(QWidget *parent = 0);
    ~G_PlayerInfoInitDialog();

    std::string GetPlayerName();

private slots:
    void on_pushButton_clicked();

private:
    Ui::G_PlayerInfoInitDialog *ui;\
    std::string playerName;
};

#endif // PLAYERINFOINITDIALOG_H
