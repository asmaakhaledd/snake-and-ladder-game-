#pragma once

#include "Action.h"
class CutCardAction : public Action
{
	int cardNumber;            
	CellPosition cp; 
public:
	
	CutCardAction(ApplicationManager *pApp);
	
	virtual void ReadActionParameters(); 	
	
	virtual void Execute();
	
	~CutCardAction();
};
