#pragma once
#include "user.h"
#include "level.h"
#include "inputname.h"
#include <string>
#include <random>
#include <algorithm>

namespace Sudoku {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class game : public System::Windows::Forms::Form
	{
	public:
		game()
		{
		}
		game(char selected_level)
		{
			InitializeComponent();

			for (int k = 0;k < 9;k++)
				this->dataGridView1->Rows->Add();
			for (int i = 0; i < 9; i++)
			{
				for (int t = 0; t < 9; t++)
				{
					if (((i < 3 || i>5) && (t < 3 || t>5)) || ((i>2 && i<6) && (t>2 && t<6)))
						dataGridView1->Rows[i]->Cells[t]->Style->BackColor = System::Drawing::Color::LightGray;
				}
			}
			counter = 0;
			level = selected_level;
		}
		

		static int counter, m, s;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  Timer;

	public:
		static char level;
		bool gensudo(int grid[9][9]);
		bool findcell(int grid[9][9], int &row, int &col);
		bool check_col_row(int grid[9][9], int value, int x, int y);
		bool check_box(int grid[9][9], int value, int x, int y);

		void load_high_score(std::string name);
	protected:
		~game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  start_but;

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;

	private: System::Windows::Forms::Button^  solve_but;
	private: System::Windows::Forms::Button^  help_but;
	private: System::ComponentModel::IContainer^  components;

	protected:

	private:


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(game::typeid));
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->start_but = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->solve_but = (gcnew System::Windows::Forms::Button());
			this->help_but = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Timer = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// start_but
			// 
			this->start_but->BackColor = System::Drawing::Color::White;
			this->start_but->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"start_but.BackgroundImage")));
			this->start_but->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->start_but->Location = System::Drawing::Point(378, 53);
			this->start_but->Name = L"start_but";
			this->start_but->Size = System::Drawing::Size(103, 54);
			this->start_but->TabIndex = 0;
			this->start_but->UseVisualStyleBackColor = false;
			this->start_but->Click += gcnew System::EventHandler(this, &game::start_but_Click);
			this->start_but->MouseLeave += gcnew System::EventHandler(this, &game::start_but_MouseLeave);
			this->start_but->MouseHover += gcnew System::EventHandler(this, &game::start_but_MouseHover);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeight = 5;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8, this->Column9
			});
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnKeystroke;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 10;
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::Navy;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::White;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView1->RowTemplate->Height = 40;
			this->dataGridView1->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView1->Size = System::Drawing::Size(360, 363);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &game::dataGridView1_CellContentClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Column1";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Column2";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Column3";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Column4";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Column5";
			this->Column5->Name = L"Column5";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Column6";
			this->Column6->Name = L"Column6";
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Column7";
			this->Column7->Name = L"Column7";
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Column8";
			this->Column8->Name = L"Column8";
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"Column9";
			this->Column9->Name = L"Column9";
			// 
			// solve_but
			// 
			this->solve_but->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"solve_but.BackgroundImage")));
			this->solve_but->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->solve_but->Enabled = false;
			this->solve_but->Location = System::Drawing::Point(378, 342);
			this->solve_but->Name = L"solve_but";
			this->solve_but->Size = System::Drawing::Size(103, 35);
			this->solve_but->TabIndex = 4;
			this->solve_but->UseVisualStyleBackColor = true;
			this->solve_but->Click += gcnew System::EventHandler(this, &game::solve_but_Click);
			this->solve_but->MouseLeave += gcnew System::EventHandler(this, &game::solve_but_MouseLeave);
			this->solve_but->MouseHover += gcnew System::EventHandler(this, &game::solve_but_MouseHover);
			// 
			// help_but
			// 
			this->help_but->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"help_but.BackgroundImage")));
			this->help_but->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->help_but->Enabled = false;
			this->help_but->Location = System::Drawing::Point(378, 113);
			this->help_but->Name = L"help_but";
			this->help_but->Size = System::Drawing::Size(103, 35);
			this->help_but->TabIndex = 5;
			this->help_but->UseVisualStyleBackColor = false;
			this->help_but->Click += gcnew System::EventHandler(this, &game::help_but_Click);
			this->help_but->MouseLeave += gcnew System::EventHandler(this, &game::help_but_MouseLeave);
			this->help_but->MouseHover += gcnew System::EventHandler(this, &game::help_but_MouseHover);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(378, 151);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 179);
			this->label1->TabIndex = 6;
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &game::timer1_Tick);
			// 
			// Timer
			// 
			this->Timer->BackColor = System::Drawing::Color::Black;
			this->Timer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Timer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Timer->ForeColor = System::Drawing::Color::White;
			this->Timer->Location = System::Drawing::Point(394, 12);
			this->Timer->Name = L"Timer";
			this->Timer->Size = System::Drawing::Size(70, 30);
			this->Timer->TabIndex = 7;
			this->Timer->Text = L"0:00";
			this->Timer->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(483, 389);
			this->Controls->Add(this->Timer);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->help_but);
			this->Controls->Add(this->solve_but);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->start_but);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(499, 427);
			this->MinimumSize = System::Drawing::Size(499, 427);
			this->Name = L"game";
			this->Text = L"SUDOKU";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &game::game_FormClosing);
			this->Load += gcnew System::EventHandler(this, &game::game_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void start_but_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {}
	private: System::Void solve_but_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void help_but_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void start_but_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void start_but_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void help_but_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void help_but_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void solve_but_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void solve_but_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void game_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	private: System::Void game_Load(System::Object^  sender, System::EventArgs^  e) {
	}
};
}