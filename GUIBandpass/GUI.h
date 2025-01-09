#pragma once
#include "C:\Users\marwy\source\repos\SolBandpass\ProjektBandpass\ProjektBandpass.h"
namespace GUIBandpass {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ProgressBar^ progressBar;
	protected:

	private: System::Windows::Forms::Label^ progressBarLabel;
	private: System::Windows::Forms::Label^ titleLabel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ threadsText;

	private: System::Windows::Forms::Button^ assemblyButton;
	private: System::Windows::Forms::Button^ cppButton;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ repeatsText;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ fileButton;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;


	protected:


	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBarLabel = (gcnew System::Windows::Forms::Label());
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->threadsText = (gcnew System::Windows::Forms::TextBox());
			this->assemblyButton = (gcnew System::Windows::Forms::Button());
			this->cppButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->repeatsText = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->fileButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// progressBar
			// 
			this->progressBar->Location = System::Drawing::Point(12, 304);
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(479, 23);
			this->progressBar->TabIndex = 0;
			this->progressBar->Minimum = 0;   // Minimalna wartoœæ
			this->progressBar->Maximum = 100; // Maksymalna wartoœæ
			this->progressBar->Value = 0;     // Wartoœæ pocz¹tkowa
			// 
			// progressBarLabel
			// 
			this->progressBarLabel->AutoSize = true;
			this->progressBarLabel->Location = System::Drawing::Point(12, 285);
			this->progressBarLabel->Name = L"progressBarLabel";
			this->progressBarLabel->Size = System::Drawing::Size(65, 16);
			this->progressBarLabel->TabIndex = 1;
			this->progressBarLabel->Text = L"Progress:";
			this->progressBarLabel->Click += gcnew System::EventHandler(this, &GUI::label1_Click);
			// 
			// titleLabel
			// 
			this->titleLabel->AutoSize = true;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->titleLabel->Location = System::Drawing::Point(116, 9);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(246, 29);
			this->titleLabel->TabIndex = 2;
			this->titleLabel->Text = L"BANDPASS FILTER";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(429, 48);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Please select how many threads shall be used and the amount of times \r\nthe algori"
				L"thm is to be repeated.\r\nWhen everything is set, please select which algorithm to"
				L" use.";
			// 
			// threadsText
			// 
			this->threadsText->Location = System::Drawing::Point(150, 117);
			this->threadsText->Name = L"threadsText";
			this->threadsText->Size = System::Drawing::Size(100, 22);
			this->threadsText->TabIndex = 4;
			// 
			// assemblyButton
			// 
			this->assemblyButton->Location = System::Drawing::Point(54, 221);
			this->assemblyButton->Name = L"assemblyButton";
			this->assemblyButton->Size = System::Drawing::Size(134, 48);
			this->assemblyButton->TabIndex = 5;
			this->assemblyButton->Text = L"Assembly";
			this->assemblyButton->UseVisualStyleBackColor = true;
			this->assemblyButton->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
			// 
			// cppButton
			// 
			this->cppButton->Location = System::Drawing::Point(289, 221);
			this->cppButton->Name = L"cppButton";
			this->cppButton->Size = System::Drawing::Size(134, 48);
			this->cppButton->TabIndex = 6;
			this->cppButton->Text = L"C++";
			this->cppButton->UseVisualStyleBackColor = true;
			this->cppButton->Click += gcnew System::EventHandler(this, &GUI::cppButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 120);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(120, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Number of threads:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(24, 159);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 16);
			this->label3->TabIndex = 9;
			this->label3->Click += gcnew System::EventHandler(this, &GUI::label3_Click);
			// 
			// repeatsText
			// 
			this->repeatsText->Location = System::Drawing::Point(150, 156);
			this->repeatsText->Name = L"repeatsText";
			this->repeatsText->Size = System::Drawing::Size(100, 22);
			this->repeatsText->TabIndex = 8;
			this->repeatsText->TextChanged += gcnew System::EventHandler(this, &GUI::textBox2_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(24, 159);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(121, 16);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Number of repeats:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(256, 137);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(116, 16);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Select another file:";
			// 
			// fileButton
			// 
			this->fileButton->Location = System::Drawing::Point(378, 134);
			this->fileButton->Name = L"fileButton";
			this->fileButton->Size = System::Drawing::Size(99, 23);
			this->fileButton->TabIndex = 12;
			this->fileButton->Text = L"Select file...";
			this->fileButton->UseVisualStyleBackColor = true;
			this->fileButton->Click += gcnew System::EventHandler(this, &GUI::button3_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(513, 339);
			this->Controls->Add(this->fileButton);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->repeatsText);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cppButton);
			this->Controls->Add(this->assemblyButton);
			this->Controls->Add(this->threadsText);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->titleLabel);
			this->Controls->Add(this->progressBarLabel);
			this->Controls->Add(this->progressBar);
			this->Name = L"GUI";
			this->Text = L"Bandpass filter";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {

	}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->ShowDialog();
	openFileDialog1->Filter = "WAV files (*.wav)|*.wav";
	openFileDialog1->FilterIndex = 1;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	/*std::string inputFilePath = "C:\\Users\\marwy\\source\\repos\\SolBandpass\\ProjektBandpass\\ProjektBandpass\\input.wav";
	std::string outputFilePath = "C:\\Users\\marwy\\source\\repos\\SolBandpass\\ProjektBandpass\\ProjektBandpass\\output.wav";
	size_t numThreads = 1;
	int choice = 1;
	processWavFile(inputFilePath, outputFilePath, numThreads, choice);*/
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	
	
}
private: System::Void cppButton_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Processing...");
	label1->Text = "Processing...";
	std::string inputFilePath = "C:\\Users\\marwy\\source\\repos\\SolBandpass\\ProjektBandpass\\ProjektBandpass\\input.wav";
	std::string outputFilePath = "C:\\Users\\marwy\\source\\repos\\SolBandpass\\ProjektBandpass\\ProjektBandpass\\output.wav";
	size_t numThreads = 1;
	int choice = 2;
	processWavFile(inputFilePath, outputFilePath, numThreads, choice);
}
};
}
