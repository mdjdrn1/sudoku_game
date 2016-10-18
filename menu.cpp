#include "stdafx.h"
#include "menu.h"

using namespace Sudoku;

System::Void menu::start_but_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Hide();
	level^ Sudoku = gcnew level();
	Sudoku->ShowDialog();
}
System::Void menu::hs_but_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Hide();
	hs^ Sudoku = gcnew hs();
	Sudoku->ShowDialog();
}

System::Void menu::exit_but_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Hide();
	Application::Exit();
}