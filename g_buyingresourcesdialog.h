#ifndef G_BUYINGRESOURCESDIALOG_H
#define G_BUYINGRESOURCESDIALOG_H

#include <QDialog>

#include "c_playerdata.h"
#include "c_resourcemarketdata.h"

namespace Ui {
class G_BuyingResourcesDialog;
}

class G_BuyingResourcesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit G_BuyingResourcesDialog(QWidget *parent = 0);
    ~G_BuyingResourcesDialog();

    void Initialize(C_PlayerData *p, C_ResourceMarket *m);

    int* GetBuyingQuantities();

private slots:
    void on_pushButton_clicked();

private:
    Ui::G_BuyingResourcesDialog *ui;

    C_PlayerData *player;
    C_ResourceMarket *market;

    int tempCost;
};

#endif // G_BUYINGRESOURCESDIALOG_H
