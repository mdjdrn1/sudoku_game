#include "stdafx.h"
#include "Level.h"

using namespace Sudoku;

System::Void level::radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	lvl = '1';
}

System::Void level::radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	lvl = '2';
}

System::Void level::radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	lvl = '3';
}

System::Void level::start_but_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Hide();
	game^ Sudoku = gcnew game(lvl);
	Sudoku->ShowDialog();
}