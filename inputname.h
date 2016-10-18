#pragma once
#include "hs.h"
#include "game.h"


namespace Sudoku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class inputname : public System::Windows::Forms::Form
	{
	public:
		inputname(void)
		{
			InitializeComponent();
		}

	protected:
		~inputname()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  submit_but;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(inputname::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->submit_but = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 40);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(242, 20);
			this->textBox1->TabIndex = 1;
			// 
			// submit_but
			// 
			this->submit_but->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"submit_but.BackgroundImage")));
			this->submit_but->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->submit_but->Location = System::Drawing::Point(13, 66);
			this->submit_but->Name = L"submit_but";
			this->submit_but->Size = System::Drawing::Size(242, 44);
			this->submit_but->TabIndex = 2;
			this->submit_but->UseVisualStyleBackColor = true;
			this->submit_but->Click += gcnew System::EventHandler(this, &inputname::submit_but_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->Location = System::Drawing::Point(13, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(242, 31);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// inputname
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(267, 122);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->submit_but);
			this->Controls->Add(this->textBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(283, 160);
			this->MinimumSize = System::Drawing::Size(283, 160);
			this->Name = L"inputname";
			this->Text = L"SUDOKU";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void submit_but_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
