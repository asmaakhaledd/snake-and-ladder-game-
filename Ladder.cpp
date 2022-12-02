#include "Ladder.h"
#include <fstream>
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	if (endCellPos.VCell() >= startCellPos.VCell() || endCellPos.HCell() != startCellPos.HCell())
	{
		return;
	}
	///TODO: Do the needed validation
	this->endCellPos = endCellPos;
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	
	Input* pIn  = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pPlayer = pGrid->GetCurrentPlayer();
	pGrid->UpdatePlayerCell(pPlayer, GetEndPosition());
}

void Ladder::Save(ofstream& file) {
	file<<this->position.GetCellNum()<<"  "<<this->endCellPos.GetCellNum()<<'\n' ;
}

void Ladder::Load(ifstream& file){
	int startCellNum, endCellNum ;
	file >> startCellNum >> endCellNum;
	endCellPos = CellPosition::GetCellPositionFromNum(endCellNum);
	position = CellPosition::GetCellPositionFromNum(startCellNum);
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}

bool Ladder::IsOverLapping(GameObject* pGO)
{
	CellPosition CP = pGO->GetPosition();
	Cell C(CP);
	if (C.HasLadder())
	{
		return true;
	}
	return false;
}