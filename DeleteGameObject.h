#pragma once
#include"Action.h"
class DeleteGameObject:public Action
{
	CellPosition DeleteCell;
public:
	DeleteGameObject(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();


};
