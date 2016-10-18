#pragma once
#include "hs.h"
#include "level.h"

namespace Sudoku {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class menu : public System::Windows::Forms::Form
	{
	public:
		menu(void)
		{
			InitializeComponent();
		}

	protected:
		~menu()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Button^  hs_but;
	private: System::Windows::Forms::Button^  exit_but;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  start_but;

	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(menu::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->hs_but = (gcnew System::Windows::Forms::Button());
			this->exit_but = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->start_but = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(-3, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 0;
			// 
			// hs_but
			// 
			this->hs_but->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"hs_but.BackgroundImage")));
			this->hs_but->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->hs_but->Location = System::Drawing::Point(12, 150);
			this->hs_but->Name = L"hs_but";
			this->hs_but->Size = System::Drawing::Size(247, 45);
			this->hs_but->TabIndex = 2;
			this->hs_but->UseVisualStyleBackColor = true;
			this->hs_but->Click += gcnew System::EventHandler(this, &menu::hs_but_Click);
			// 
			// exit_but
			// 
			this->exit_but->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exit_but.BackgroundImage")));
			this->exit_but->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->exit_but->Location = System::Drawing::Point(12, 201);
			this->exit_but->Name = L"exit_but";
			this->exit_but->Size = System::Drawing::Size(247, 46);
			this->exit_but->TabIndex = 3;
			this->exit_but->UseVisualStyleBackColor = true;
			this->exit_but->Click += gcnew System::EventHandler(this, &menu::exit_but_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(247, 81);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// start_but
			// 
			this->start_but->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"start_but.BackgroundImage")));
			this->start_but->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->start_but->Location = System::Drawing::Point(13, 99);
			this->start_but->Name = L"start_but";
			this->start_but->Size = System::Drawing::Size(246, 45);
			this->start_but->TabIndex = 7;
			this->start_but->UseVisualStyleBackColor = true;
			this->start_but->Click += gcnew System::EventHandler(this, &menu::start_but_Click);
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(272, 262);
			this->Controls->Add(this->start_but);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->exit_but);
			this->Controls->Add(this->hs_but);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(288, 300);
			this->MinimumSize = System::Drawing::Size(288, 300);
			this->Name = L"menu";
			this->Text = L"SUDOKU";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void start_but_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void hs_but_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void exit_but_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void contextMenuStrip1_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
};
}
