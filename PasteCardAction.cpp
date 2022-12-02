#include "PasteCardAction.h"
#include "Grid.h"
#include "Card.h"
#include "Cell.h"
PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{

}

void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
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

void PasteCardAction::Execute()
{

	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Card* pCard = pGrid->GetClipboard();
	if (!pCard)
		return;
	pCard->setPosition(cardPosition);
	pGrid->AddObjectToCell(pCard);


}

PasteCardAction::~PasteCardAction()
{

}