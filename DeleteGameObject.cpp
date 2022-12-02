#include "DeleteGameObject.h"
#include "Action.h"
#include"Grid.h"
#include"Input.h"
#include"Output.h"



	

DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) : Action(pApp)
{
	
}

void DeleteGameObject::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn;
	Output* pOut;
	pIn = pGrid->GetInput();
	pOut = pGrid->GetOutput();
	
	pOut->PrintMessage("Enter the Game Object to Delete");
	DeleteCell = pIn->GetCellClicked();

}



void DeleteGameObject::Execute()
{
	
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();

	Input* I = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	Cell cc = I->GetCellClicked();
	DeleteCell=I->GetCellClicked();

	if (cc.HasLadder() || cc.HasSnake() || cc.HasCard())
	{
		pOut->PrintMessage("No Game Object was found");
	}
	else
	{
		pOut->PrintMessage("Game Object Removed");
		pGrid->RemoveObjectFromCell(DeleteCell);
	}

	
}