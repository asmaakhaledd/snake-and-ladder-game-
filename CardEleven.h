#pragma once

#include "Card.h"
class CardEleven :	public Card
{
	int walletAmount;
	static int priceOfCard;
	static int fees;
	static int avaliable;
	static Player*ownership;
public:
	CardEleven( const CellPosition & pos); //a constructor that takes card positiion 
	
		virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardNine which is: walletAmount

    	virtual void Apply(Grid* pGrid, Player* pPlayer);
		
		void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

	virtual ~CardEleven(); //  destructor 
	bool IsOverLapping(GameObject* pGO);
};
