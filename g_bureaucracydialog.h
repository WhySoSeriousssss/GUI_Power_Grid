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

private:
    Ui::G_BureaucracyDialog *ui;

    C_PlayerData* player;
};

#endif // G_BUREAUCRACYDIALOG_H
