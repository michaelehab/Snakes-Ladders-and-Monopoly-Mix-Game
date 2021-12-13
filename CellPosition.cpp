#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	if (v >= 0 && v <= 8) {
		vCell = v;
		return true;
	}

	return false;
}

bool CellPosition::SetHCell(int h) 
{
	if (h >= 0 && h <= 10) {
		hCell = h;
		return true;
	}

	return false;
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	if (vCell >= 0 && vCell <= 8 && hCell >= 0 && hCell <= 10) {
		return true;
	}

	return false;
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	if (cellPosition.IsValidCell()) {
		return (cellPosition.HCell() + 1) + (8 - cellPosition.VCell()) * NumHorizontalCells;
	}
	return 0; //Invalid CellPosition
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	CellPosition position;
	if (cellNum >= 1 && cellNum <= NumHorizontalCells * NumVerticalCells) {
		position.SetHCell((cellNum % NumHorizontalCells == 0)?(NumHorizontalCells - 1):(cellNum % NumHorizontalCells - 1));
		position.SetVCell((cellNum % NumHorizontalCells == 0)?(NumVerticalCells - cellNum/NumHorizontalCells):(NumVerticalCells - 1 - cellNum/NumHorizontalCells));
	}
	//If the function takes an invalid cellNum it uses Default Constructor, vCell = -1 and hCell = -1
	return position;
}

void CellPosition::AddCellNum(int addedNum)
{
	//Makes sure that it'll handle the case when the dice gives a value making the new cell num > 99
	//For Example : Current Position = 98 and the dice gives us 5, the new num will be 103 which is invalid
	//In this case the player already won because he reached the end of the grid (99)
	int new_num = min(GetCellNum() + addedNum, NumHorizontalCells * NumVerticalCells);
	CellPosition new_position = GetCellPositionFromNum(new_num);
	//If the new position is invalid, the new vCell and hCell will be -1 (invalid cell)
	SetVCell(new_position.VCell());
	SetHCell(new_position.HCell());
}