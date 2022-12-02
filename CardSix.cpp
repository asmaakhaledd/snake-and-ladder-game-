#include "CardSix.h"
#include<fstream>
#include<string>

CardSix::CardSix(const CellPosition& pos) : Card(pos)
{
	cardNumber = 6;
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer = pGrid->GetCurrentPlayer();
	pGrid->UpdatePlayerCell(pPlayer, CellToMoveTo);
}

void CardSix::SetCardNumber(int cnum)
{
	Card::SetCardNumber(cnum);
}

int CardSix::GetCardNumber()
{
	int x = Card::GetCardNumber();
	return x;
}

void CardSix::Draw(Output* pOut) const
{
	Card::Draw(pOut);
}

void CardSix::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << '\n';
}

void CardSix::Load(ifstream& Infile) {
	Card::Load(Infile);

	
}
void CardSix::ReadCardParameters(Grid* pGrid)
{
	Input * I = pGrid->GetInput();
	CellToMoveTo = I->GetCellClicked();
}


bool CardSix::IsOverLapping(GameObject* pGO)
{
	bool x = Card::IsOverLapping(pGO);
	return x;
}