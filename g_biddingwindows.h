#ifndef G_BIDDINGWINDOWS_H
#define G_BIDDINGWINDOWS_H

#include <QMainWindow>

#include "i_subject.h"

#include "c_deckdata.h"
#include "c_gamedata.h"

#include "g_biddingdialog.h"

namespace Ui {
class G_BiddingWindows;
}

class G_BiddingWindows : public QMainWindow, public I_Subject
{
    Q_OBJECT

public:
    explicit G_BiddingWindows(QWidget *parent = 0);
    ~G_BiddingWindows();

    void Initialize(C_DeckData *pData);

    void Update();

    void SetDisplay(std::string name, int money);

    void Start();

    int GetEnter();
    int GetCardNum();
    int GetPrice();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::G_BiddingWindows *ui;

    int enter;

    std::vector<C_CardData> m_vPowerPlantMarket;
    C_DeckData* m_pDeck;

    int round = 1;
    int biddingPrice, index;

    std::vector<C_PlayerData *> biddersThisRound;
    std::vector<C_PlayerData *> bidderList;
};

#endif // G_BIDDINGWINDOWS_H
