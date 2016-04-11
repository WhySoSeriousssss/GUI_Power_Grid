#ifndef G_BUILDINGDIALOG_H
#define G_BUILDINGDIALOG_H

#include <QDialog>

#include "c_gamedata.h"
#include "c_mapdata.h"
#include "c_playerdata.h"

#include "i_dialog.h"

namespace Ui {
class G_BuildingDialog;
}

class G_BuildingDialog : public QDialog, public I_Dialog
{
    Q_OBJECT

public:
    explicit G_BuildingDialog(QWidget *parent = 0);
    ~G_BuildingDialog();

    void Initialize(C_MapData *pMap, C_PlayerData* player);

    std::string GetPlayerLog();
    std::string GetPhaseLog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::G_BuildingDialog *ui;

    C_PlayerData* player;
    C_MapData* map;

    std::string player_log;
};

#endif // G_BUILDINGDIALOG_H
