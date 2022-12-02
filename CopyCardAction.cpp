#include "CopyCardAction.h"
#include "Grid.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{

}

void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn  = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();


	pOut->PrintMessage("Click on the cell");
	cardPosition = pIn->GetCellClicked();
	if (!cardPosition.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid Cell, operation cancelled");
		return;
	}
	pOut->ClearStatusBar();
}

void CopyCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (!(pGrid->GetCard(cardPosition)))
		return;
	pGrid->SetClipboard(pGrid->GetCard(cardPosition));
}

CopyCardAction::~CopyCardAction()
{

}