#ifndef G_BIDDINGDIALOG_H
#define G_BIDDINGDIALOG_H

#include "c_playerdata.h"

#include <QDialog>

namespace Ui {
class G_BiddingDialog;
}

class G_BiddingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit G_BiddingDialog(QWidget *parent = 0);
    ~G_BiddingDialog();

    void Initialize(std::vector<C_PlayerData *>* pBidders, std::vector<C_PlayerData *>* pBList);

    void SetInitialDisplay(int cardNum);

    int GetBiddingPrice();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::G_BiddingDialog *ui;

    std::vector<C_PlayerData *>* biddersThisRound;
    std::vector<C_PlayerData *>* bidderList;

    int currentBidder;

    int biddingPrice;
};

#endif // G_BIDDINGDIALOG_H
