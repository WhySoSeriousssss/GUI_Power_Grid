#ifndef G_PLANTMARKETDIALOG_H
#define G_PLANTMARKETDIALOG_H

#include <QDialog>

#include "i_subject.h"

#include "c_deckdata.h"
#include "c_gamedata.h"

#include "g_biddingdialog.h"

namespace Ui {
class G_PlantMarketDialog;
}

class G_PlantMarketDialog : public QDialog
{
    Q_OBJECT

public:
    explicit G_PlantMarketDialog(QWidget *parent = 0);
    ~G_PlantMarketDialog();

    void Initialize(C_DeckData *pData);

    void Update();

    void SetDisplay(std::string name, int money);

    void Start();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::G_PlantMarketDialog *ui;

    std::vector<C_CardData*>* m_vPowerPlantMarket;
    C_DeckData* m_pDeck;

    int biddingPrice, index;

    std::vector<C_PlayerData *> biddersThisRound;
    std::vector<C_PlayerData *> bidderList;
};

#endif // G_PLANTMARKETDIALOG_H
