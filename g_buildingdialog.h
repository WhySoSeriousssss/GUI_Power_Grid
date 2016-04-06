#ifndef G_BUILDINGDIALOG_H
#define G_BUILDINGDIALOG_H

#include <QDialog>

#include "c_mapdata.h"
#include "c_playerdata.h"

namespace Ui {
class G_BuildingDialog;
}

class G_BuildingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit G_BuildingDialog(QWidget *parent = 0);
    ~G_BuildingDialog();

    void Initialize(C_MapData *map, C_PlayerData* player);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::G_BuildingDialog *ui;

    C_MapData* map;
    C_PlayerData* player;

};

#endif // G_BUILDINGDIALOG_H
