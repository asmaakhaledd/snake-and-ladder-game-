#include "Card.h"
#include <fstream>

Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	cardNumber = cnum;
	// needs validation
	if (cnum>0 && cnum<15)
		cardNumber = cnum;
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(GameObject::position, cardNumber);

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

void Card::EditCard(Grid* pGrid)
{
}

void Card::setPosition(CellPosition poss)
{
	position = poss;
}

void Card::Save(ofstream& OutFile) {
	OutFile << cardNumber << " " << position.GetCellNum();
}

void Card::Load(ifstream& Infile) {
	int cellNum;
	
	Infile >> cellNum;
	position = CellPosition::GetCellPositionFromNum(cellNum);
}

Card::~Card()
{
}

bool Card::IsOverLapping(GameObject* pGO)
{
	CellPosition CP = pGO->GetPosition();
	Cell c(CP);
	if (c.HasCard())
		return true;
	return false;
}
