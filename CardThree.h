#pragma once
#include"Card.h"

class CardThree:public Card
{
public:
	CardThree(const CellPosition& pos);
	void Apply(Grid* pGrid, Player* pPlayer);              // apply
	void SetCardNumber(int cnum);                         // The setter of card number
	int GetCardNumber();                                 // The getter of card number

	void Draw(Output* pOut) const;                     // Draws the card number in the cell position of the card
									                  // It has the same implementation for all Card Types (Non-Virtual)

	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	bool IsOverLapping(GameObject* pGO);
};

