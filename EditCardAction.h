#pragma once

#include "Action.h"

class EditCardAction : public Action
{
	
	
	Card* editcard;
	int cardnum;
	Cell* pCell;

public:
	EditCardAction(ApplicationManager *pApp); 
	virtual void ReadActionParameters(); 

	virtual void Execute(); 
	virtual~EditCardAction();
};