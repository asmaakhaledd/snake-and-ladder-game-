#pragma once
#include"Card.h"
class CardSeven : public Card
{
public:
	CardSeven(const CellPosition& pos); 


	void Apply(Grid* pGrid, Player* pPlayer); 
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	bool IsOverLapping(GameObject* pGO);
};
