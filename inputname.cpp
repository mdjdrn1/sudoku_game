#include "stdafx.h"
#include "inputname.h"
#include <msclr\marshal_cppstd.h>

using namespace Sudoku;

System::Void Sudoku::inputname::submit_but_Click(System::Object ^ sender, System::EventArgs ^ e)
{

	if (textBox1->Text != "")
	{
		
		msclr::interop::marshal_context context;
		std::string standardString = context.marshal_as<std::string>(textBox1->Text);
		for (unsigned int k = 0;k < standardString.length(); k++)	//when user inputs name with space, space is changed to "_" sign 
		{
			if (standardString[k] == 32)	//ASCII 32 - SPACE
				standardString[k] = 95;		//ASCII 96 - "_" SIGN
		}
		game g;
		g.load_high_score(standardString);


		if (MessageBox::Show("Do you want to play again?",
			"New game?", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			this->Hide();
			Sudoku::menu^ Sudoku = gcnew Sudoku::menu();
			Sudoku->ShowDialog();
		}
		else
			Application::Exit();
	}
	else
	{
		MessageBox::Show("Text box is empty!\nInput your name.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
