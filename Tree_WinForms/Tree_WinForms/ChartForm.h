#pragma once

#include "Forest.h"
#include <time.h>
#include <fstream>

namespace TreeWinForms {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace Forest_nspace;

	int n = 0;
	vector<double> x;
	vector<double> y;

	Forest Taiga = Forest();

	public ref class ChartForm : public System::Windows::Forms::Form {
	public: ChartForm(void)	{ 
			InitializeComponent(); 
			srand((unsigned int)time(NULL));
		}
	protected: ~ChartForm() { if (components) { delete components; } }
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  Chart;
	private: System::Windows::Forms::SplitContainer^  splitContainer;
	private: System::Windows::Forms::MenuStrip^  menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::Button^  ����������;
	private: System::Windows::Forms::TextBox^  �����������1;

	private: System::Windows::Forms::Button^  ��������;
	private: System::Windows::Forms::StatusStrip^  statusStrip2;
	private: System::Windows::Forms::Button^  �����������;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  �������;
	private: System::Windows::Forms::ToolStripStatusLabel^  �������2;
	private: System::Windows::Forms::Button^  �������;
	private: System::Windows::Forms::Button^  �������;
	private: System::Windows::Forms::TextBox^  �����������2;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->Chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->splitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->������� = (gcnew System::Windows::Forms::Button());
			this->������� = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->������� = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->����������� = (gcnew System::Windows::Forms::Button());
			this->statusStrip2 = (gcnew System::Windows::Forms::StatusStrip());
			this->�������2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->�������� = (gcnew System::Windows::Forms::Button());
			this->�����������1 = (gcnew System::Windows::Forms::TextBox());
			this->���������� = (gcnew System::Windows::Forms::Button());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������2 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Chart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer))->BeginInit();
			this->splitContainer->Panel1->SuspendLayout();
			this->splitContainer->Panel2->SuspendLayout();
			this->splitContainer->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->statusStrip2->SuspendLayout();
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// Chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->Chart->ChartAreas->Add(chartArea1);
			this->Chart->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->Chart->Legends->Add(legend1);
			this->Chart->Location = System::Drawing::Point(0, 0);
			this->Chart->Name = L"Chart";
			series1->BorderWidth = 5;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::Black;
			series1->EmptyPointStyle->Color = System::Drawing::Color::White;
			series1->Legend = L"Legend1";
			series1->MarkerColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			series1->MarkerSize = 50;
			series1->Name = L"��������";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series2->BorderWidth = 5;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::Red;
			series2->Legend = L"Legend1";
			series2->Name = L"������1";
			series3->BorderWidth = 5;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Color = System::Drawing::Color::Blue;
			series3->Legend = L"Legend1";
			series3->Name = L"������2";
			this->Chart->Series->Add(series1);
			this->Chart->Series->Add(series2);
			this->Chart->Series->Add(series3);
			this->Chart->Size = System::Drawing::Size(567, 534);
			this->Chart->TabIndex = 0;
			this->Chart->Text = L"Chart";
			// 
			// splitContainer
			// 
			this->splitContainer->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->splitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer->Location = System::Drawing::Point(0, 24);
			this->splitContainer->Name = L"splitContainer";
			// 
			// splitContainer.Panel1
			// 
			this->splitContainer->Panel1->Controls->Add(this->Chart);
			// 
			// splitContainer.Panel2
			// 
			this->splitContainer->Panel2->Controls->Add(this->�����������2);
			this->splitContainer->Panel2->Controls->Add(this->�������);
			this->splitContainer->Panel2->Controls->Add(this->�������);
			this->splitContainer->Panel2->Controls->Add(this->statusStrip1);
			this->splitContainer->Panel2->Controls->Add(this->�����������);
			this->splitContainer->Panel2->Controls->Add(this->statusStrip2);
			this->splitContainer->Panel2->Controls->Add(this->��������);
			this->splitContainer->Panel2->Controls->Add(this->�����������1);
			this->splitContainer->Panel2->Controls->Add(this->����������);
			this->splitContainer->Size = System::Drawing::Size(822, 538);
			this->splitContainer->SplitterDistance = 571;
			this->splitContainer->TabIndex = 1;
			// 
			// �������
			// 
			this->�������->Location = System::Drawing::Point(22, 136);
			this->�������->Name = L"�������";
			this->�������->Size = System::Drawing::Size(129, 23);
			this->�������->TabIndex = 8;
			this->�������->Text = L"�������";
			this->�������->UseVisualStyleBackColor = true;
			this->�������->Click += gcnew System::EventHandler(this, &ChartForm::�������_Click);
			// 
			// �������
			// 
			this->�������->Location = System::Drawing::Point(22, 48);
			this->�������->Name = L"�������";
			this->�������->Size = System::Drawing::Size(129, 23);
			this->�������->TabIndex = 7;
			this->�������->Text = L"/roll";
			this->�������->UseVisualStyleBackColor = true;
			this->�������->Click += gcnew System::EventHandler(this, &ChartForm::�������_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->������� });
			this->statusStrip1->Location = System::Drawing::Point(0, 490);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(243, 22);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 6;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// �������
			// 
			this->�������->Name = L"�������";
			this->�������->Size = System::Drawing::Size(58, 17);
			this->�������->Text = L"�������";
			// 
			// �����������
			// 
			this->�����������->Location = System::Drawing::Point(22, 106);
			this->�����������->Name = L"�����������";
			this->�����������->Size = System::Drawing::Size(129, 23);
			this->�����������->TabIndex = 5;
			this->�����������->Text = L"�����������";
			this->�����������->UseVisualStyleBackColor = true;
			this->�����������->Click += gcnew System::EventHandler(this, &ChartForm::�����������_Click);
			// 
			// statusStrip2
			// 
			this->statusStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->�������2 });
			this->statusStrip2->Location = System::Drawing::Point(0, 512);
			this->statusStrip2->Name = L"statusStrip2";
			this->statusStrip2->Size = System::Drawing::Size(243, 22);
			this->statusStrip2->SizingGrip = false;
			this->statusStrip2->TabIndex = 4;
			this->statusStrip2->Text = L"statusStrip2";
			// 
			// �������2
			// 
			this->�������2->Name = L"�������2";
			this->�������2->Size = System::Drawing::Size(64, 17);
			this->�������2->Text = L"�������2";
			// 
			// ��������
			// 
			this->��������->Location = System::Drawing::Point(22, 19);
			this->��������->Name = L"��������";
			this->��������->Size = System::Drawing::Size(129, 23);
			this->��������->TabIndex = 3;
			this->��������->Text = L"�������� ��������";
			this->��������->UseVisualStyleBackColor = true;
			this->��������->Click += gcnew System::EventHandler(this, &ChartForm::��������_Click);
			// 
			// �����������1
			// 
			this->�����������1->Location = System::Drawing::Point(22, 170);
			this->�����������1->Name = L"�����������1";
			this->�����������1->Size = System::Drawing::Size(129, 20);
			this->�����������1->TabIndex = 1;
			// 
			// ����������
			// 
			this->����������->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->����������->Location = System::Drawing::Point(22, 77);
			this->����������->Name = L"����������";
			this->����������->Size = System::Drawing::Size(129, 23);
			this->����������->TabIndex = 0;
			this->����������->Text = L"����������";
			this->����������->UseVisualStyleBackColor = true;
			this->����������->Click += gcnew System::EventHandler(this, &ChartForm::����������_Click);
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->����ToolStripMenuItem });
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(822, 24);
			this->menuStrip->TabIndex = 2;
			this->menuStrip->Text = L"menuStrip";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �����������2
			// 
			this->�����������2->Location = System::Drawing::Point(22, 196);
			this->�����������2->Name = L"�����������2";
			this->�����������2->Size = System::Drawing::Size(129, 20);
			this->�����������2->TabIndex = 9;
			// 
			// ChartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(822, 562);
			this->Controls->Add(this->splitContainer);
			this->Controls->Add(this->menuStrip);
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"ChartForm";
			this->Text = L"ChartForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Chart))->EndInit();
			this->splitContainer->Panel1->ResumeLayout(false);
			this->splitContainer->Panel2->ResumeLayout(false);
			this->splitContainer->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer))->EndInit();
			this->splitContainer->ResumeLayout(false);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->statusStrip2->ResumeLayout(false);
			this->statusStrip2->PerformLayout();
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: void Read_File(string file1, string file2) {
		ifstream fin;

		fin.open(file1);
		fin >> n;
		x.resize(n);
		for (int i = 0; i < n; i++) fin >> x[i];
		fin.close();

		fin.open(file2);
		fin >> n;
		y.resize(n);
		for (int i = 0; i < n; i++) fin >> y[i];
		fin.close();
	}
	private: System::Void ��������_Click	(System::Object^  sender, System::EventArgs^  e) {
		Read_File("res/sin/2x.txt", "res/sin/2y.txt");

		Chart->Series["��������"]->Points->Clear();
		for (int i = 0; i < n; i++) Chart->Series["��������"]->Points->AddXY(x[i], y[i]);
	}
	private: System::Void �������_Click		(System::Object^  sender, System::EventArgs^  e) {
		Taiga = Forest(2, 2, -10, 20);

	}
	private: System::Void ����������_Click	(System::Object^  sender, System::EventArgs^  e) {
		�������->Text = "y = " + gcnew System::String(Taiga.Population[0].Print().c_str());
		�������2->Text = "y = " + gcnew System::String(Taiga.Population[1].Print().c_str());

		Chart->Series["������1"]->Points->Clear();
		Chart->Series["������2"]->Points->Clear();
		for (int i = 0; i < 100; i++) {
			Chart->Series["������1"]->Points->AddXY(x[i], Taiga.Population[0].GetY(x[i]));
			Chart->Series["������2"]->Points->AddXY(x[i], Taiga.Population[1].GetY(x[i]));
		}

		Taiga.Population[0].Fitness(n, x, y);
		Taiga.Population[1].Fitness(n, x, y);
		�����������1->Text = Convert::ToString(Taiga.Population[0].GetFitness());
		�����������2->Text = Convert::ToString(Taiga.Population[1].GetFitness());
	}
	private: System::Void �����������_Click	(System::Object^  sender, System::EventArgs^  e) {
		vector<int> Order(Taiga.GetSize() * 2);
		for (int i = 0; i < Taiga.GetSize(); i++) {
			int a = 0, b = 0;
			while (a == b) {
				a = rand() % Taiga.GetSize();
				b = rand() % Taiga.GetSize();
			}
			Order[i * 2] = a;
			Order[i * 2 + 1] = b;
		}
		Taiga.CrossOver(Order);
	}
	private: System::Void �������_Click		(System::Object^  sender, System::EventArgs^  e) { Taiga.TreeMutation(1, -10, 20); }
};
}
