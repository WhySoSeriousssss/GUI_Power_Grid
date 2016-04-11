#ifndef G_BUREAUCRACYDIALOG_H
#define G_BUREAUCRACYDIALOG_H

#include <QDialog>

#include "c_playerdata.h"

namespace Ui {
class G_BureaucracyDialog;
}

class G_BureaucracyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit G_BureaucracyDialog(QWidget *parent = 0);
    ~G_BureaucracyDialog();

    void Initialize(C_PlayerData* p);

    void RealTimeUpdate(int cardIndex);

    void RealTimeClear(int cardIndex);

    bool TestEnoughFuel(int cardIndex);

private slots:

    void on_pushButton_clicked();

    void on_checkBox_toggled(bool checked);

    void on_checkBox_2_toggled(bool checked);

    void on_checkBox_3_toggled(bool checked);

private:
    Ui::G_BureaucracyDialog *ui;

    C_PlayerData* player;

    int coalDecrease;
    int oilDecrease;
    int garbageDecrease;
    int uraniumDecrease;

};

#endif // G_BUREAUCRACYDIALOG_H
