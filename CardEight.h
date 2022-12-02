#pragma once
#include"Card.h"

class CardEight:public Card
{
	int The_Amount_Of_Coins_Needed_To_Go_Out_Of_The_Prison;
public:
	CardEight(const CellPosition& pos);
	void Apply(Grid* pGrid, Player* pPlayer);
	void SetCardNumber(int cnum);   // The setter of card number
	int GetCardNumber();            // The getter of card number
	void ReadCardParameters(Grid* pGrid);
	void Draw(Output* pOut) const;  // Draws the card number in the cell position of the card
									// It has the same implementation for all Card Types (Non-Virtual)
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	bool IsOverLapping(GameObject* pGO);
};

