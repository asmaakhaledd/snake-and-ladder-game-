#include "CardSeven.h"
#include<fstream>
   CardSeven::CardSeven(const CellPosition& pos):Card(pos)
   {
	   cardNumber = 7;
   }



  
   void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
   {
	   int Gap = 1000;  // the gap between the leading player and the 2nd player
	   int index;


	   for (int i = 0; i < MaxPlayerCount; i++) {

		   Cell* sCell = pPlayer->GetCell();                    //gets a cell object
		   CellPosition sCellPos = sCell->GetCellPosition();   //gets the cell position of a cell object
		   int a = sCellPos.GetCellNum();                       //gets the cell number that the first player is currently standing on
		   Player* P = pGrid->GetCurrentPlayer();               //gets a pointer to the current player
		   Cell* sCell2 = P->GetCell();                         //gets a second cell object
		   CellPosition sCellPos2 = sCell->GetCellPosition();  //gets the cell position of the second cell object
		   int b = sCellPos2.GetCellNum();                      //gets the cell number that the second player is currently standing on

		   if (a > b) {
			   Gap = a - b;
			   index = i;
		   }

	   }
	   if (Gap != 1000) {
		   Cell startCell(8, 0);  //the leading player returns to the first cell
		   Cell* ptrToStartCell = &startCell;
		   pPlayer[index].SetCell(ptrToStartCell);
	   }
   }

   void CardSeven::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << '\n';
}

void CardSeven::Load(ifstream& Infile) 
{
	Card::Load(Infile);

}


bool CardSeven::IsOverLapping(GameObject* pGO)
{
	bool x = Card::IsOverLapping(pGO);
	return x;
}