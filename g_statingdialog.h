#ifndef G_STATINGDIALOG_H
#define G_STATINGDIALOG_H

#include <QDialog>

namespace Ui {
class G_StatingDialog;
}

class G_StatingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit G_StatingDialog(QWidget *parent = 0);
    ~G_StatingDialog();

    int GetNumberOfPlayers();

private slots:
    void on_pushButton_clicked();

private:
    Ui::G_StatingDialog *ui;
    int m_iPlayers;
};

#endif // G_STATINGDIALOG_H
