#include "stdafx.h"
#include "hs.h"
#include "shlobj.h"
#include <sstream>
#include <tchar.h>
#include <fstream>
#pragma comment(lib, "shell32.lib")


using namespace Sudoku;

System::Void hs::menu_back_but_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Hide();
	menu^ Sudoku = gcnew menu();
	Sudoku->ShowDialog();
}

System::Void hs::hs_Load_1(System::Object^  sender, System::EventArgs^  e)
{
	std::ifstream inFile;

	TCHAR appData[MAX_PATH];
	if (SUCCEEDED(SHGetFolderPath(NULL,
		CSIDL_APPDATA,
		NULL,
		SHGFP_TYPE_CURRENT,
		appData)))
	{
		std::basic_ostringstream<TCHAR> file_path;
		file_path << appData << _TEXT("\\highscore.su");
		inFile.open(file_path.str().c_str());
	}
	int r = 0;
	user u;

	//read from file
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{

			inFile >> u.name;
			inFile >> u.score;
			dataGridView1->Rows->Add();
			String^ str2 = gcnew String(u.name.c_str());
			dataGridView1->Rows[r]->Cells[0]->Value = str2;
			dataGridView1->Rows[r]->Cells[1]->Value = u.score;
			r++;
		}
		inFile.close();
	}
	else
	{
		pictureBox2->Visible = true;
		dataGridView1->Visible = false;

	}

}