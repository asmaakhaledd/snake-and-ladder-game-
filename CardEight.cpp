#include "CardEight.h"
#include<fstream>

CardEight::CardEight(const CellPosition& pos): Card(pos)
{
	cardNumber = 8;
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Output * o = pGrid->GetOutput();
	Input* i = pGrid->GetInput();
	pGrid->AdvanceCurrentPlayer();
	pPlayer = pGrid->GetCurrentPlayer();
	int y = pPlayer->GetPlayerNumber();
	o->PrintMessage("Chose between 1- to pay The amount of coins needed to go out of the prison or 2- to stay 3 rounds in the prison --- write ( 1 ) if you chose 1 & write ( 2 ) if you chose 2");
	int x = i->GetInteger(o);
	while (x != 1 || x != 2)
	{
		o->PrintMessage("invalid values re enter the value : ");
		i->GetInteger(o);
	}
	if (x == 1)
	{
		pPlayer->SetWallet(pPlayer->GetWallet() - The_Amount_Of_Coins_Needed_To_Go_Out_Of_The_Prison);
	}
	else
	{
		pPlayer->setPNum(y);
		pPlayer->setCount(3);
	}
}

void CardEight::SetCardNumber(int cnum)
{
	Card::SetCardNumber(cnum);
}

int CardEight::GetCardNumber()
{
	int x = Card::GetCardNumber();
	return x;
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	Output* o = pGrid->GetOutput();
	o->PrintMessage("Please enter The amount of coins needed to go out of the prison: ");
	Input* i = pGrid->GetInput();
	The_Amount_Of_Coins_Needed_To_Go_Out_Of_The_Prison = i->GetInteger(o);
}

void CardEight::Draw(Output* pOut) const
{
	Card::Draw(pOut);
}

void CardEight::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << '\n';
}

void CardEight::Load(ifstream& Infile) {
	Card::Load(Infile);

}

bool CardEight::IsOverLapping(GameObject* pGO)
{
	bool x = Card::IsOverLapping(pGO);
	return x;
}