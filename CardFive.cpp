#include "CardFive.h"
#include<fstream>

CardFive::CardFive(const CellPosition& pos) : Card(pos)
{
	cardNumber = 5;
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->AdvanceCurrentPlayer();
	pPlayer = pGrid->GetCurrentPlayer();
	Cell* cell = pPlayer->GetCell();
	CellPosition c = cell->GetCellPosition();
	int x = c.GetCellNumFromPosition(c);
	pGrid->UpdatePlayerCell(pPlayer, x);
}

void CardFive::SetCardNumber(int cnum)
{
	Card::SetCardNumber(cnum);
}

int CardFive::GetCardNumber()
{
	int x = Card::GetCardNumber();
	return x;
}

void CardFive::Draw(Output* pOut) const
{
	Card::Draw(pOut);
}
void CardFive::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << '\n';
}

void CardFive::Load(ifstream& Infile) {
	Card::Load(Infile);

}

bool CardFive::IsOverLapping(GameObject* pGO)
{
	bool x = Card::IsOverLapping(pGO);
	return x;
}