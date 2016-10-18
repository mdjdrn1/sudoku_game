#include "stdafx.h"
#include <fstream>
#include "game.h"
#include "shlobj.h"
#include <sstream>
#include <tchar.h>
#include "inputname.h"
#pragma comment(lib, "shell32.lib")

using namespace Sudoku;

std::random_device rd;								//initializing random numbers generator
std::uniform_int_distribution<int> dist(1, 9);		//
std::mt19937 gen(rd());								//

int minute = 0, second = 0, time = 0;
bool hint = true;

int solution[9][9] = {};	//global variable with solution

bool game::findcell(int grid[9][9], int &x, int &y)	//finding empty cell in matrix
{
	for (x = 0; x < 9; x++)
		for (y = 0; y < 9; y++)
			if (grid[x][y] == 0)
				return true;
	return false;
}

bool game::check_col_row(int grid[9][9], int value, int x, int y)	//checking for collisions in columns/rows
{
	for (int k = 0; k < 9; k++)
	{
		if (grid[k][y] == value || grid[x][k] == value)
			return true;
	}
	return false;
}

bool game::check_box(int grid[9][9], int value, int x, int y)	//checking for collisions in box (3x3)
{
	x -= x % 3;
	y -= y % 3;
	for (int k = 0; k < 3; k++)
	{
		for (int j = 0; j < 3; j++)
			if (grid[k + x][j + y] == value)
				return true;
	}
	return false;
}

bool game::gensudo(int grid[9][9])	//main random solution generator
{
	int x, y, val;

	if (!findcell(grid, x, y))
		return true;

	for (int k = 1; k <= 9; k++)
	{
		val = dist(gen);
		if (!check_col_row(grid, val, x, y) && !check_box(grid, val, x, y))
		{
			grid[x][y] = val;
			if (gensudo(grid))
				return true;
			grid[x][y] = 0;
		}
	}
	return false;
}

System::Void game::start_but_Click(System::Object ^ sender, System::EventArgs ^ e) {
	gensudo(solution);	//generating solution
	int todisp;	//numbers to display
	switch (level)
	{
	case '1':
		todisp = 45;
		break;
	case '2':
		todisp = 38;
		break;
	case '3':
		todisp = 30;
		break;
	}
	int a, b;
	for (int k = 0; k < todisp; k++)	//writing into grid 30 values from solution in random cells
	{
		a = dist(gen);
		b = dist(gen);
		if (dataGridView1->Rows[b - 1]->Cells[a - 1]->Value == nullptr)
		{
			dataGridView1->Rows[b - 1]->Cells[a - 1]->Value = solution[a - 1][b - 1];
			dataGridView1->Rows[b - 1]->Cells[a - 1]->Style->ForeColor = System::Drawing::Color::Black;
			dataGridView1->Rows[b - 1]->Cells[a - 1]->ReadOnly = true;
		}
		else
			k--;
	}
	this->start_but->Enabled = 0;
	this->solve_but->Enabled = true;
	this->help_but->Enabled = true;
	this->timer1->Enabled = true;
}

System::Void game::solve_but_Click(System::Object^  sender, System::EventArgs^  e) {
	//checking if player's solution is correct
	int cell;
	bool finish = true;
	double wrongans = 0; //counter of wrong answers
	double corans = 0; //counter of correct answers
	for (int k = 0; k < 9; k++)
		for (int r = 0; r < 9; r++)
		{
			cell = Convert::ToInt32(dataGridView1->Rows[r]->Cells[k]->Value);
			if (dataGridView1->Rows[r]->Cells[k]->Style->ForeColor != System::Drawing::Color::Black)
			{
				if (cell == solution[k][r])
				{
					dataGridView1->Rows[r]->Cells[k]->Style->BackColor = System::Drawing::Color::LightGreen;
					corans++;
				}
				else if (dataGridView1->Rows[r]->Cells[k]->Value != nullptr)
				{		
					dataGridView1->Rows[r]->Cells[k]->Style->BackColor = System::Drawing::Color::Tomato;
					wrongans++;
				}
				if (dataGridView1->Rows[r]->Cells[k]->Value == nullptr)
					finish = false;
			}
		}
	if (finish == true)
	{
		timer1->Enabled = false;

		if (wrongans == 0)
		{
			if (MessageBox::Show("Congratulations!\n100% of correct answers.\nYou've won!\nDo you want to save your score to the highscores?",
				"WIN!!!", MessageBoxButtons::YesNo,
				MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			{
				this->Hide();
				Sudoku::inputname^ Sudoku = gcnew Sudoku::inputname();
				Sudoku->ShowDialog();
			}
			else
			{
				if (MessageBox::Show("Do you want to play again?",
					"", MessageBoxButtons::YesNo,
					MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
				{
					this->Hide();
					Sudoku::menu^ Sudoku = gcnew Sudoku::menu();
					Sudoku->ShowDialog();
				}
				else
					Application::Exit();
			}
		}
		else
		{
			int percents = static_cast<int>(corans / (corans + wrongans) * 100);
			if (MessageBox::Show("Your score: " + percents + "% of correct answers.\nDo you want to try again?",
				":(", MessageBoxButtons::YesNo,
				MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			{
				this->Hide();
				Sudoku::level^ Sudoku = gcnew Sudoku::level();
				Sudoku->ShowDialog();
			}
			else
				Application::Exit();
		}
	}
}

System::Void game::help_but_Click(System::Object^  sender, System::EventArgs^  e) {
	int x, y;
	bool insert = false;

	//inserting hint
	while (!insert)
	{
		x = dist(gen) - 1;
		y = dist(gen) - 1;
		if (dataGridView1->Rows[x]->Cells[y]->Style->ForeColor != System::Drawing::Color::Black)
		{
			dataGridView1->Rows[x]->Cells[y]->Value = solution[y][x];
			dataGridView1->Rows[x]->Cells[y]->Style->ForeColor = System::Drawing::Color::Green;
			dataGridView1->Rows[x]->Cells[y]->Style->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			dataGridView1->Rows[x]->Cells[y]->ReadOnly = true;
			insert = true;
			counter++;
		}
	}

	//how many times user can use hints
	if (level == '1' && counter == 5)
	{
		hint = false;
		help_but->Enabled = false;
	}
	else if (level == '2' && counter == 3)
	{
		hint = false;
		help_but->Enabled = false;
	}
	else if (level == '3' && counter == 1)
	{
		hint = false;
		help_but->Enabled = false;
	}
}

void game::load_high_score(std:: string name)
{
	std::ifstream inFile;

	//find path to appdata folder
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

	user t_users[11];
	int i = 0;

	//read from file 
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			inFile >> t_users[i].name;
			inFile >> t_users[i].score;
			i++;
		}

		inFile.close();
	}
	t_users[i].name = name;

	int points = 100000;

	if (level == '1')
	{
		points = 100000;

	}
	else if (level == '2')
	{
		points = 110000;

	}
	else if (level == '3')
	{
		points = 130000;
	}

	points -= (m + s);

	t_users[i].score = points ;


	//sort
	std::sort(t_users, t_users + i + 1);

	std::ofstream outFile;

	//find path to appdata folder
	if (SUCCEEDED(SHGetFolderPath(NULL,
		CSIDL_APPDATA | CSIDL_FLAG_CREATE,
		NULL,
		SHGFP_TYPE_CURRENT,
		appData)))
	{
		std::basic_ostringstream<TCHAR> file_path;
		file_path << appData << _TEXT("\\highscore.su");
		outFile.open(file_path.str().c_str());
	}
	int k = 0;
	if (i >= 10)
	{
		k = 10;
	}
	else
	{
		k = i + 1;
	}
	//save to file best scores
	for (int j = 0; j < k; j++)
	{
		outFile << t_users[j].name;
		outFile << " ";
		outFile << t_users[j].score;
		if (j != k - 1)
		{
			outFile << std::endl;
		}
	}

	outFile.close();
}

Void game::start_but_MouseHover(System::Object^  sender, System::EventArgs^  e)
{
	label1->Text = "Start game.";
}

Void game::start_but_MouseLeave(System::Object^  sender, System::EventArgs^  e)
{
	label1->Text = nullptr;
}

Void game::help_but_MouseHover(System::Object^  sender, System::EventArgs^  e)
{
	label1->Text = "Show hint.";
}

Void game::help_but_MouseLeave(System::Object^  sender, System::EventArgs^  e)
{
	label1->Text = nullptr;
}

Void game::solve_but_MouseHover(System::Object^  sender, System::EventArgs^  e)
{
	label1->Text = "Check the solution.";
}

Void game::solve_but_MouseLeave(System::Object^  sender, System::EventArgs^  e)
{
	label1->Text = nullptr;
}

Void game::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	String^ min;
	String^ sec;
	time++;
	second++;
	if (second == 60) {
		minute++;
		second = 0;
	}
	min = System::Convert::ToString(minute);
	sec = System::Convert::ToString(second);
	if (second < 10)
	{
		Timer->Text = min + ":0" + sec;
		m += minute;
		s += second;
	}
	else
	{
		Timer->Text = min + ":" + sec;
		m += minute;
		s += second;
	}
}


Void game::game_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	if (MessageBox::Show("Do you want to quit Sudoku?",
		"Sudoku", MessageBoxButtons::YesNo,
		MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No)
			e->Cancel = true;
}