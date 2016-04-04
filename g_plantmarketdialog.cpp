#include "g_plantmarketdialog.h"
#include "ui_g_plantmarketdialog.h"

G_PlantMarketDialog::G_PlantMarketDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G_PlantMarketDialog)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(true);
}

G_PlantMarketDialog::~G_PlantMarketDialog()
{
    delete ui;
}

void G_PlantMarketDialog::Initialize(C_DeckData *pData) {

    m_pDeck = pData;

    Update();

}

void G_PlantMarketDialog::Update() {
    m_vPowerPlantMarket = m_pDeck->GetMarket();

    ui->radioButton->setText(QString::number((*m_vPowerPlantMarket)[0]->GetNumber()));
    ui->radioButton_2->setText(QString::number((*m_vPowerPlantMarket)[1]->GetNumber()));
    ui->radioButton_3->setText(QString::number((*m_vPowerPlantMarket)[2]->GetNumber()));
    ui->radioButton_4->setText(QString::number((*m_vPowerPlantMarket)[3]->GetNumber()));
    ui->radioButton_5->setText(QString::number((*m_vPowerPlantMarket)[4]->GetNumber()));
    ui->radioButton_6->setText(QString::number((*m_vPowerPlantMarket)[5]->GetNumber()));
    ui->radioButton_7->setText(QString::number((*m_vPowerPlantMarket)[6]->GetNumber()));
    ui->radioButton_8->setText(QString::number((*m_vPowerPlantMarket)[7]->GetNumber()));
}

void G_PlantMarketDialog::SetDisplay(std::string name, int money) {
    ui->label_3->setText(QString::fromStdString(name));
    ui->label_4->setText(QString::number(money));
}

void G_PlantMarketDialog::Start() {

    for (int i = 0; i < pGameData->playerList.size(); i++) {
        bidderList.push_back(&pGameData->playerList[i]);
    }

    SetDisplay(bidderList.front()->GetName(), bidderList.front()->GetMoney());

}
void G_PlantMarketDialog::on_pushButton_clicked()
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

    if (bidderList.size() == 1) {
        std::cout << "Player " << bidderList[0]->GetName() << " bought the card #" << (*m_vPowerPlantMarket)[index]->GetNumber() << "\n";
        bidderList[0]->ConsumeMoney((*m_vPowerPlantMarket)[index]->GetNumber());
        bidderList[0]->BuyCard(pGameData->deck.PlayerBuysCard(index));
        bidderList.clear();
        this->accept();
    }
    else {
        for (int i = 0; i < bidderList.size(); i++)
            biddersThisRound.push_back(bidderList[i]);

        biddingDlg.Initialize(&this->biddersThisRound, &this->bidderList);

        biddingDlg.SetInitialDisplay((*m_vPowerPlantMarket)[index]->GetNumber());
        biddingDlg.exec();

        if (biddingDlg.Accepted == 1) {
            std::cout << "Player " << biddersThisRound[0]->GetName() << " bought the card #" << (*m_vPowerPlantMarket)[index]->GetNumber() << "\n";

            biddersThisRound[0]->BuyCard(pGameData->deck.PlayerBuysCard(index));
            for (int i = 0; i < bidderList.size(); i++) {
                if (bidderList[i] == biddersThisRound[0]) {
                    bidderList.erase(bidderList.begin() + i);
                    break;
                }
            }
            biddersThisRound.clear();
        }

        Update();
        SetDisplay(bidderList.front()->GetName(), bidderList.front()->GetMoney());
    }
}

void G_PlantMarketDialog::on_pushButton_2_clicked()
{
    std::cout << "Player " << bidderList.front()->GetName() << " abandoned bidding!\n";
    bidderList.erase(bidderList.begin());

    if (bidderList.size() != 0)
        SetDisplay(bidderList.front()->GetName(), bidderList.front()->GetMoney());
    else {
        this->accept();
    }
}
