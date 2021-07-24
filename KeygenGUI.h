/*********************************************************************
* Project:   WinRAR-Keygen-GUI
* Author:     Pranjal (https://github.com/pran-jal)
*********************************************************************/

#pragma once

#include <msclr/marshal.h>
#include <Windows.h>
#include "tmain.h"

namespace KeygenGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>  Summary for KeygenGUI </summary>
	public ref class KeygenGUI : public System::Windows::Forms::Form {
		public:
			KeygenGUI(void) {
				InitializeComponent();
				// TODO: Add the constructor code here
			}
		protected:
		/// <summary> Clean up any resources being used. </summary>
			~KeygenGUI() {
				if (components) {
					delete components;
				}
			}

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ProgressBar^ progressBar1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->AccessibleName = L"";
			this->textBox1->BackColor = System::Drawing::Color::PaleGreen;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBox1->Location = System::Drawing::Point(154, 46);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(252, 41);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &KeygenGUI::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->AccessibleRole = System::Windows::Forms::AccessibleRole::Dialog;
			this->button1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->button1->Location = System::Drawing::Point(120, 269);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(221, 81);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Generate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &KeygenGUI::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label1->Location = System::Drawing::Point(53, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 31);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Name";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(59, 182);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(347, 23);
			this->progressBar1->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->ClientSize = System::Drawing::Size(473, 392);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"WinRAR Keygen";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	String^ str;

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		str = textBox1->Text;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//button1->Visible = false;
		progressBar1->Value = 25;
		button1->Text = L"Generating";
		Update();
		pin_ptr<const wchar_t> name = PtrToStringChars(str);
		size_t name_size = wcslen(name) + 1, convertedChars = 0;
		const size_t new_name_size = name_size * 2;
		char* new_name = new char[new_name_size];
		wcstombs_s(&convertedChars, new_name, new_name_size, name, _TRUNCATE);
		char* company = "Free Individual Licence";
		progressBar1->Value = 50;
		Update();

		//   old method to call tmain 

		if (tmain(new_name, company) == 2) {
			progressBar1->Value = 0;
			MessageBox::Show("Failed to open File");
		}
		else if (tmain(new_name, company) == 3) {
			progressBar1->Value = 0;
			MessageBox::Show("Failed to generate key. Retry using different name");
		}
		else {
			progressBar1->Value = 100;
			MessageBox::Show("Key generated successfully");
		}

		button1->Text = L"Generate";
		Update();
		progressBar1->Value = 0;
	}
	};
}
