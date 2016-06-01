#pragma once

namespace Project1 {
	int i = 0;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;



	protected:

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
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(99, 170);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Do it!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(131, 80);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(10, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L" ";
			this->label1->MouseHover += gcnew System::EventHandler(this, &MyForm::label1_MouseHover);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(279, 354);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->Text = L"Shia Motivator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion		 
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		i++;
		if (i == 1)
			MessageBox::Show("Yes you can!");
		else if (i == 2)
			MessageBox::Show("Don't let your dreams be dreams.");
		else if (i == 3)
			MessageBox::Show("Yesterday you said tomorrow, so just do it!");
		else if (i == 4)
			MessageBox::Show("Make your dreams come true!");
		else if (i == 5)
			MessageBox::Show("Nothing is impossible!");
		else if (i == 6)
			MessageBox::Show("What are you waiting for?");
		else
		{
			MessageBox::Show("Stop giving up."); i = 0;
		}
	}
	
private: System::Void label1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("Написано же\nНЕтрогать!", "Fatal ERROR!");
}
};
}