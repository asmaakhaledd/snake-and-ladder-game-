#include "CutCardAction.h"
#include "Grid.h"
CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{

}

void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the  cell");
	cp = pIn->GetCellClicked();
	if (!cp.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid Cell, operation cancelled");
		return;
	}
	pOut->ClearStatusBar();
}

void CutCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (!(pGrid->GetCard(cp)))
		return;
	pGrid->SetClipboard(pGrid->GetCard(cp));
	pGrid->RemoveObjectFromCell(cp);
}

CutCardAction::~CutCardAction()
{

}