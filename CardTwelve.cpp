
#include "CardTwelve.h"
#include <fstream>

CardTwelve::CardTwelve(const CellPosition & pos) : Card(pos) // seting the cell position of the card
{
	cardNumber = 12; // seting the inherited cardNumber data member with the card number (12 here)
}
int CardTwelve:: fees=0;
int CardTwelve:: priceOfCard=0;
int CardTwelve:: avaliable=0;
Player* CardTwelve:: ownership=NULL;

void CardTwelve::ReadCardParameters(Grid * pGrid)
{
	if (avaliable==0);
	{
		Input * pIn = (pGrid)->GetInput(); Output * pOut = (pGrid)->GetOutput();

		pOut->PrintMessage("enter a price"); //reading the card price from the user
		do
		{
			priceOfCard= pIn->GetInteger(pOut);

		}while(priceOfCard<=0);
		
		pOut->PrintMessage("now please Enter Fees");
		do
		{
		fees= pIn->GetInteger(pOut); // reading fees from the user
		}while(fees<=0);
		avaliable=1;
	}
}



void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	Card::Apply(pGrid,pPlayer) ;
	Input * pIn = (pGrid)->GetInput();
	Output * pOut = (pGrid)->GetOutput();

	// checking if no one owns the card
	if(ownership==NULL) 
	{
		pOut->PrintMessage("if you want to buy this card enter Y else N");
		// reading the answer from the user 
		string reply= pIn->GetSrting(pOut);
		if(reply=="Y" && pPlayer->GetWallet() >= priceOfCard)
		{
			
			ownership=pPlayer;
			ownership->SetWallet( pPlayer->GetWallet() - priceOfCard);
		}
		else if(reply=="Y" &&pPlayer->GetWallet()<priceOfCard)
		{
			pOut->PrintMessage("no enough money in your wallet ");
		}
	
	}
	 // if another player (not the owner og teh card) 
	else if(ownership!=pPlayer) 
	{
		pPlayer->SetWallet( pPlayer->GetWallet()-fees);
	}
	 
}

void CardTwelve::Save(ofstream &OutFile) {
	static bool has_been_saved_with_parameters = false ;
	Card::Save(OutFile);

	if(!has_been_saved_with_parameters){
	OutFile << " " << priceOfCard<<" "<< fees << '\n';
	has_been_saved_with_parameters = true ;
	}
	else OutFile<<"\n";
}
void CardTwelve::Load(ifstream &Infile){
	static bool has_been_loaded_with_parameters = false ;
	Card::Load(Infile);

	if(!has_been_loaded_with_parameters){
	Infile >> priceOfCard >> fees    ;
	has_been_loaded_with_parameters = true ;
	}


}
CardTwelve::~CardTwelve(void)
{
}

bool CardTwelve::IsOverLapping(GameObject* pGO)
{
	bool x = Card::IsOverLapping(pGO);
	return x;
}