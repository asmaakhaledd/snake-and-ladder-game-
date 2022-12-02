#pragma once
#include"Card.h"

class CardSix:public Card
{
	CellPosition CellToMoveTo;
public:
	CardSix(const CellPosition& pos);
	void Apply(Grid* pGrid, Player* pPlayer);
	void SetCardNumber(int cnum);   // The setter of card number
	int GetCardNumber();            // The getter of card number

	void Draw(Output* pOut) const;  // Draws the card number in the cell position of the card
	                               // It has the same implementation for all Card Types (Non-Virtual)
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	void ReadCardParameters(Grid* pGrid);
	bool IsOverLapping(GameObject* pGO);
};

