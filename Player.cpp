#include "Player.h"

#include "GameObject.h"
#include "ApplicationManager.h"
#include "RollDiceAction.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

void Player::SetTurnCount(int rturncount)
{
	if(rturncount < 0)
		turnCount=0;
	turnCount=rturncount;
}
void Player::SetStepCount(int rstepcount)
{
	if(rstepcount<=0)
		stepCount=1;
	else
		stepCount=rstepcount;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];
	
    pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,playerColor);

	///TODO use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,cellColor);
	
	///TODO use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{

	if (playerNum == PNum && i < count)
	{
		return;
	}

	CellPosition newcellnum;
	int updatedcellnum;
	int Move = 0;
	bool haswon=0;
	int Increment;

	///TODO Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

    Increment = turnCount++;
	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	int Check = 0;



    


	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	
	if (turnCount == 3)
	{
		wallet = wallet + (diceNumber * 10);   //if the third turn of the player came then the amount of money increase by adding the amount of money the player has with the dice number multiplying by 10 
		turnCount = 0;
		Check = 1;
		Move = 1;
	}

		

	// 3- Set the justRolledDiceNum with the passed diceNumber
	
	justRolledDiceNum = diceNumber;



	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"


    if( Move==1 && wallet==0 ){
        newcellnum = pCell->GetCellPosition();
	    updatedcellnum = newcellnum.GetCellNum();          //updatedcellnum is the new cell that the player is standing on 
	    updatedcellnum = updatedcellnum + justRolledDiceNum;  //the new cell that the player is standing on after rolling dice
	    if(updatedcellnum >= 99){                             //if the game ended the players should return to the beginning cell
		newcellnum.SetHCell(10);
		newcellnum.SetVCell(8);
		haswon=1;
	    }
		newcellnum = newcellnum.GetCellPositionFromNum(updatedcellnum);
		Cell updatedCell(newcellnum);
		pCell = &updatedCell;
	}
	



    

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
  
	pGrid->UpdatePlayerCell(this, newcellnum);

	// 6- Apply() the game object of the reached cell (if any)
    
	if (pCell->GetGameObject() != NULL) {
		(pCell->GetGameObject())->Apply(pGrid, this);
	}

	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
 if(haswon==1){
    pGrid->SetEndGame(1);
	}
}

int Player::GetPlayerNumber()
{
	return playerNum;
}

void Player::setPNum(int x)
{
	PNum = x;
}

int Player::GetPNum()
{
	return PNum;
}

void Player::setCount(int x)
{
	count = x;
}

void Player::seti(int x)
{
	i = x;
}

void Player::MakeExtraRollDice()
{
	ApplicationManager * A;
	RollDiceAction R(A);
	R.Execute();
}
void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}

//IMPLEMENTED <ESLAM>