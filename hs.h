#pragma once
#include "menu.h"
#include "user.h"


namespace Sudoku {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class hs : public System::Windows::Forms::Form
	{
	public:
		hs(void)
		{
			InitializeComponent();
		}

	protected:
		~hs()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  menu_back_but;

	private: System::Windows::Forms::DataGridView^  dataGridView1;


	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Nick;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Score;
	private: System::Windows::Forms::PictureBox^  pictureBox2;





	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(hs::typeid));
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->menu_back_but = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Nick = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Score = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// menu_back_but
			// 
			this->menu_back_but->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_back_but.Image")));
			this->menu_back_but->Location = System::Drawing::Point(43, 274);
			this->menu_back_but->Name = L"menu_back_but";
			this->menu_back_but->Size = System::Drawing::Size(246, 46);
			this->menu_back_but->TabIndex = 1;
			this->menu_back_but->UseVisualStyleBackColor = true;
			this->menu_back_but->Click += gcnew System::EventHandler(this, &hs::menu_back_but_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Nick, this->Score });
			this->dataGridView1->Location = System::Drawing::Point(12, 39);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(310, 229);
			this->dataGridView1->TabIndex = 14;
			// 
			// Nick
			// 
			dataGridViewCellStyle7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			dataGridViewCellStyle7->ForeColor = System::Drawing::Color::SteelBlue;
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::Color::White;
			dataGridViewCellStyle7->SelectionForeColor = System::Drawing::Color::Black;
			this->Nick->DefaultCellStyle = dataGridViewCellStyle7;
			this->Nick->HeaderText = L"Nick";
			this->Nick->Name = L"Nick";
			this->Nick->ReadOnly = true;
			this->Nick->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Nick->Width = 200;
			// 
			// Score
			// 
			dataGridViewCellStyle8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			dataGridViewCellStyle8->ForeColor = System::Drawing::Color::SteelBlue;
			dataGridViewCellStyle8->SelectionBackColor = System::Drawing::Color::White;
			dataGridViewCellStyle8->SelectionForeColor = System::Drawing::Color::Black;
			this->Score->DefaultCellStyle = dataGridViewCellStyle8;
			this->Score->HeaderText = L"Score";
			this->Score->Name = L"Score";
			this->Score->ReadOnly = true;
			this->Score->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Score->Width = 108;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->Location = System::Drawing::Point(109, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(114, 29);
			this->pictureBox1->TabIndex = 15;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox2->Location = System::Drawing::Point(43, 112);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(246, 67);
			this->pictureBox2->TabIndex = 16;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			// 
			// hs
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(334, 332);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menu_back_but);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(350, 370);
			this->MinimumSize = System::Drawing::Size(350, 370);
			this->Name = L"hs";
			this->Text = L"SUDOKU";
			this->Load += gcnew System::EventHandler(this, &hs::hs_Load_1);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void menu_back_but_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void hs_Load_1(System::Object^  sender, System::EventArgs^  e);
	};
}
