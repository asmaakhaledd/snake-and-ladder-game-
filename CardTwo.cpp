#include <fstream>
#include "CardTwo.h"
#include "Ladder.h"
CardTwo::CardTwo(const CellPosition& pCell) : Card(pCell)
{
	cardNumber = 2;
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	Ladder * l;
	CellPosition  c;
	l = pGrid->GetNextLadder(GetPosition());
	c = l->GetEndPosition();
	if (l)
	{
		pGrid->UpdatePlayerCell(pPlayer, c);
	}

}

void CardTwo::SetCardNumber(int cnum)
{
	Card::SetCardNumber(cnum);
}

int CardTwo::GetCardNumber()
{
	int x = Card::GetCardNumber();
	return x;
}

void CardTwo::Draw(Output* pOut) const
{
	Card::Draw(pOut);
}

void CardTwo::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << " " << '\n';
}

void CardTwo::Load(ifstream& Infile) {
	Card::Load(Infile);
	

	
}


bool CardTwo::IsOverLapping(GameObject* pGO)
{
	bool x = Card::IsOverLapping(pGO);
	return x;
}