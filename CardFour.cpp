#include "CardFour.h"
#include<fstream>
CardFour::CardFour(const CellPosition& pos) : Card(pos)
{
	cardNumber = 4;
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->AdvanceCurrentPlayer();
	pPlayer = pGrid->GetCurrentPlayer();
	int x = pPlayer->GetPlayerNumber();
	pPlayer->setPNum(x);
	pPlayer->setCount(1);
}

void CardFour::SetCardNumber(int cnum)
{
	Card::SetCardNumber(cnum);
}

int CardFour::GetCardNumber()
{
	int x = Card::GetCardNumber();
	return x;
}

void CardFour::Draw(Output* pOut) const
{
	Card::Draw(pOut);
}

void CardFour::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << '\n';
}

void CardFour::Load(ifstream& Infile) {
	Card::Load(Infile);

	
}

bool CardFour::IsOverLapping(GameObject* pGO)
{
	bool x = Card::IsOverLapping(pGO);
	return x;
}