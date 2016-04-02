#include "g_biddingwindows.h"
#include "ui_g_biddingwindows.h"

G_BiddingWindows::G_BiddingWindows(QWidget *parent) :
    QMainWindow(parent),
    enter(0),
    ui(new Ui::G_BiddingWindows)
{
    ui->setupUi(this);
}

G_BiddingWindows::~G_BiddingWindows()
{
    delete ui;
}

void G_BiddingWindows::Initialize(C_DeckData *pData) {

    m_pDeck = pData;

    Update();

}

void G_BiddingWindows::Update() {
    m_vPowerPlantMarket = m_pDeck->GetMarket();
    ui->radioButton->setText(QString::number(m_vPowerPlantMarket[0].GetNumber()));
    ui->radioButton_2->setText(QString::number(m_vPowerPlantMarket[1].GetNumber()));
    ui->radioButton_3->setText(QString::number(m_vPowerPlantMarket[2].GetNumber()));
    ui->radioButton_4->setText(QString::number(m_vPowerPlantMarket[3].GetNumber()));
    ui->radioButton_5->setText(QString::number(m_vPowerPlantMarket[4].GetNumber()));
    ui->radioButton_6->setText(QString::number(m_vPowerPlantMarket[5].GetNumber()));
    ui->radioButton_7->setText(QString::number(m_vPowerPlantMarket[6].GetNumber()));
    ui->radioButton_8->setText(QString::number(m_vPowerPlantMarket[7].GetNumber()));
}

void G_BiddingWindows::SetDisplay(std::string name, int money) {
    ui->label_3->setText(QString::fromStdString(name));
    ui->label_4->setText(QString::number(money));
}

int G_BiddingWindows::GetEnter() {
    return enter;
}

int G_BiddingWindows::GetCardNum() {
    return index;
}

int G_BiddingWindows::GetPrice() {
    return m_vPowerPlantMarket[index].GetNumber();
}

void G_BiddingWindows::Start() {

    for (int i = 0; i < pGameData->playerList.size(); i++) {
        bidderList.push_back(&pGameData->playerList[i]);
    }

    SetDisplay(bidderList.front()->GetName(), bidderList.front()->GetMoney());
    /*
    while (bidderList.size() != 0) {


        SetDisplay(bidderList.front()->GetName(), bidderList.front()->GetMoney());

        biddersThisRound.clear();

        std::cout << "Please type in the index(From 1 to 4, 0 represents abandon):\n";


        if (GetEnter() == 2) {
            std::cout << "Player " << bidderList.front()->GetName() << " abandoned bidding!\n";
            bidderList.erase(bidderList.begin());
            round++;
            continue;
        }
        else {
            index = biddingWds->GetCardNum();
            biddingPrice = biddingWds->GetPrice();
            biddingDlg.SetInitialDisplay(bidderList.front()->GetName(), index, biddingPrice);
            biddingDlg.exec();
            biddersThisRound.push_back(bidderList.front());
        }


        for (int i = 1; i < bidderList.size(); i++) {
            biddingDlg.SetDisplay(bidderList[i]->GetName(), bidderList[i]->GetMoney(), biddingPrice);

            if (biddingDlg.GetAbandon() == true) {
                std::cout << "Player " << bidderList[i]->GetName() << " abandoned bidding!\n";
            }
            else {
                biddingPrice = temp;
                biddersThisRound.push_back(bidderList[i]);
            }
        }

        while (biddersThisRound.size() > 1) {
            for (int i = 0; i < biddersThisRound.size(); i++) {
                std::cout << "Player " << bidderList[i]->GetName() << "'s turn to bid.\n";
                std::cout << "Please type in your bidding price:\n";
                int temp;
                std::cin >> temp;
                if (temp == 0) {
                    std::cout << "Player " << bidderList[i]->GetName() << " abandoned bidding!\n";
                    biddersThisRound.erase(biddersThisRound.begin() + i);
                }
                else {
                    biddingPrice = temp;
                }
            }

        }

        std::cout << "Player " << biddersThisRound[0]->GetName() << " bought plant card finally!\n\n";
        biddersThisRound[0]->ConsumeMoney(biddingPrice);
        biddersThisRound[0]->BuyCard(pGameData->deck.PlayerBuysCard(index - 1));
        for (int i = 0; i < bidderList.size(); i++) {
            if (bidderList[i] == biddersThisRound[0]) {
                bidderList.erase(bidderList.begin() + i);
                break;
            }
        }
        round++;

    }
    */
}

void G_BiddingWindows::on_pushButton_clicked()
{

    G_BiddingDialog biddingDlg;

    if (ui->radioButton->isChecked())
        index = 0;
    else if (ui->radioButton_2->isChecked())
        index = 1;
    else if (ui->radioButton_3->isChecked())
        index = 2;
    else
        index = 3;

    for (int i = 0; i < bidderList.size(); i++)
        biddersThisRound.push_back(bidderList[i]);

    biddingDlg.Initialize(this->biddersThisRound, this->bidderList);

    biddingDlg.SetInitialDisplay(m_vPowerPlantMarket[index].GetNumber());
    biddingDlg.exec();

    if (biddingDlg.Accepted == 1) {
        round++;
    }
    if (bidderList.size() == 0)
        this->close();
}

void G_BiddingWindows::on_pushButton_2_clicked()
{
    std::cout << "Player " << bidderList.front()->GetName() << " abandoned bidding!\n";
    bidderList.erase(bidderList.begin());
    round++;
    if (bidderList.size() != 0)
        SetDisplay(bidderList.front()->GetName(), bidderList.front()->GetMoney());
    else
        this->close();
}
