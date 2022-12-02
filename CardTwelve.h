#pragma once
#include "Card.h"

class CardTwelve : public Card
{
private:
/*This card moves the ownership of the most expensive station that the
	current user owns from the current user to the player that has
	the least amount of coins in his wallet*/
	int walletAmount;
	static int priceOfCard;
	static int fees;
	static int avaliable;
	static Player*ownership;

public:
	//both default and non default constructors.
	CardTwelve(const CellPosition & pos);
	

	virtual void ReadCardParameters(Grid*);
	virtual void Apply(Grid* pGrid, Player* pPlayer);

	static int getavaliabilty();
	static void setavaliabilty();
	static Player*GetClipboardOwner();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

	// destructor.
	~CardTwelve();
	bool IsOverLapping(GameObject* pGO);
};