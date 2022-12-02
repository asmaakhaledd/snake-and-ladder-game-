#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}
void GameObject::setposition(CellPosition& pos)
{
	position =pos;
}
CellPosition GameObject::GetPosition() const
{
	return position;
}

GameObject::~GameObject()
{
}
