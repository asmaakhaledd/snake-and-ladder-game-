#include "CardThree.h"
#include<fstream>

CardThree::CardThree(const CellPosition& pos) : Card(pos)
{
	cardNumber = 3;
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	pPlayer = pGrid->GetCurrentPlayer();
	pPlayer->MakeExtraRollDice();
}

void CardThree::SetCardNumber(int cnum)
{
	Card::SetCardNumber(cnum);
}

int CardThree::GetCardNumber()
{
	int x = Card::GetCardNumber();
	return x;
}

void CardThree::Draw(Output* pOut) const
{
	Card::Draw(pOut);
}

void CardThree::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << '\n';
}

void CardThree::Load(ifstream& Infile) {
	Card::Load(Infile);

}

bool CardThree::IsOverLapping(GameObject* pGO)
{
	bool x = Card::IsOverLapping(pGO);
	return x;
}