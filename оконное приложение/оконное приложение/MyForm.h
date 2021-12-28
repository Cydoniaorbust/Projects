#pragma once

namespace оконноеприложение {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;

	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ColumnHeader^  Product;
	private: System::Windows::Forms::ColumnHeader^  ProductType;
	private: System::Windows::Forms::ColumnHeader^  ValuePer100Cal;

	private: System::Windows::Forms::ColumnHeader^  Prots;
	private: System::Windows::Forms::ColumnHeader^  Carbs;
	private: System::Windows::Forms::ColumnHeader^  Fats;
	private: System::Windows::Forms::ColumnHeader^  Weight;
	private: System::Windows::Forms::ColumnHeader^  SleepHours;









	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(L"123"));
			System::Windows::Forms::ListViewItem^  listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(L"456"));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->Product = (gcnew System::Windows::Forms::ColumnHeader());
			this->ProductType = (gcnew System::Windows::Forms::ColumnHeader());
			this->ValuePer100Cal = (gcnew System::Windows::Forms::ColumnHeader());
			this->Prots = (gcnew System::Windows::Forms::ColumnHeader());
			this->Carbs = (gcnew System::Windows::Forms::ColumnHeader());
			this->Fats = (gcnew System::Windows::Forms::ColumnHeader());
			this->Weight = (gcnew System::Windows::Forms::ColumnHeader());
			this->SleepHours = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(938, 541);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->listView1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(930, 515);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(769, 366);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(8) {
				this->Product, this->ProductType,
					this->ValuePer100Cal, this->Prots, this->Carbs, this->Fats, this->Weight, this->SleepHours
			});
			this->listView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView1->HideSelection = false;
			this->listView1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(2) { listViewItem1, listViewItem2 });
			this->listView1->Location = System::Drawing::Point(3, 3);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(924, 509);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// Product
			// 
			this->Product->Text = L"Продукт";
			this->Product->Width = 63;
			// 
			// ProductType
			// 
			this->ProductType->Text = L"Наименование";
			this->ProductType->Width = 93;
			// 
			// ValuePer100Cal
			// 
			this->ValuePer100Cal->Text = L"Ценность, ккал/100г";
			this->ValuePer100Cal->Width = 127;
			// 
			// Prots
			// 
			this->Prots->Text = L"Белки";
			this->Prots->Width = 48;
			// 
			// Carbs
			// 
			this->Carbs->Text = L"Углеводы";
			this->Carbs->Width = 67;
			// 
			// Fats
			// 
			this->Fats->Text = L"Жиры";
			this->Fats->Width = 51;
			// 
			// Weight
			// 
			this->Weight->Text = L"Вес";
			this->Weight->Width = 82;
			// 
			// SleepHours
			// 
			this->SleepHours->Text = L"Часов сна";
			this->SleepHours->Width = 82;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(938, 541);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
