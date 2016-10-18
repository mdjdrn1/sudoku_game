// Sudoku.cpp : main project file.

#include "stdafx.h"
#include "menu.h"

using namespace Sudoku;

[STAThread]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew menu());
	return 0;
}

