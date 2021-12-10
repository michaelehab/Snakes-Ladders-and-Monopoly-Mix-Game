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
	int pos = (cellPosition.HCell() + 1) + (8 - cellPosition.VCell())*11;
	
	return pos;
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	CellPosition position;
	position.SetHCell((cellNum % 11 == 0)?(10):(cellNum % 11 - 1));
	position.SetVCell((cellNum % 11 == 0)?(9 - cellNum/11):(8 - cellNum/11));

	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	int new_num = GetCellNum() + addedNum;
	CellPosition new_position = GetCellPositionFromNum(new_num);
	SetVCell(new_position.VCell());
	SetHCell(new_position.HCell());
}