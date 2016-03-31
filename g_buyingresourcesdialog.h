#ifndef G_BUYINGRESOURCESDIALOG_H
#define G_BUYINGRESOURCESDIALOG_H

#include <QDialog>

namespace Ui {
class G_BuyingResourcesDialog;
}

class G_BuyingResourcesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit G_BuyingResourcesDialog(QWidget *parent = 0);
    ~G_BuyingResourcesDialog();

    void SetResourceMarket(int coal, int oil, int garbage, int uranium, int coalPrice, int oilPrice, int garbagePrice, int uraniumPrice);

    void SetDisplay(std::string name, int money);

    int* GetBuyingQuantities();

private slots:
    void on_pushButton_clicked();

private:
    Ui::G_BuyingResourcesDialog *ui;
};

#endif // G_BUYINGRESOURCESDIALOG_H
