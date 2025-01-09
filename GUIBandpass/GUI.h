#pragma once
#include "C:\Users\marwy\source\repos\SolBandpass\ProjektBandpass\ProjektBandpass.h"
#include <string>
#include <msclr\marshal_cppstd.h>
namespace GUIBandpass {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	extern "C" void ModifyBitsAsm(float* chunkPointer, size_t numElements);
	extern "C" void ModifyBitsCpp(float* chunkPointer, size_t numElements);
	/// <summary>
	/// Podsumowanie informacji o GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		int numThreads;
		int numRepeats = 1;
		System::String^ inputFilePath;
		System::String^ outputFilePath;
	private: System::Windows::Forms::Label^ statusLabel;
	public:
		int languageChoice;
		GUI(void)
		{
			InitializeComponent();
			progressBar->Maximum = 100;
			progressBar->Minimum = 0;
			progressBar->Value = 0;
		}
		
	protected:
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
	private: System::Windows::Forms::Button^ startButton;






	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ repeatsText;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ fileButton;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;


	private: System::Windows::Forms::Label^ timeTextLabel;
	private: System::Windows::Forms::Label^ actualTimeLabel;
	private: System::Windows::Forms::CheckedListBox^ checkedListBoxLanguage;




	protected:


	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GUI::typeid));
			this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBarLabel = (gcnew System::Windows::Forms::Label());
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->threadsText = (gcnew System::Windows::Forms::TextBox());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->repeatsText = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->fileButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->timeTextLabel = (gcnew System::Windows::Forms::Label());
			this->actualTimeLabel = (gcnew System::Windows::Forms::Label());
			this->checkedListBoxLanguage = (gcnew System::Windows::Forms::CheckedListBox());
			this->statusLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// progressBar
			// 
			this->progressBar->BackColor = System::Drawing::Color::White;
			this->progressBar->Location = System::Drawing::Point(12, 304);
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(479, 23);
			this->progressBar->TabIndex = 0;
			// 
			// progressBarLabel
			// 
			this->progressBarLabel->AutoSize = true;
			this->progressBarLabel->Location = System::Drawing::Point(12, 285);
			this->progressBarLabel->Name = L"progressBarLabel";
			this->progressBarLabel->Size = System::Drawing::Size(65, 16);
			this->progressBarLabel->TabIndex = 1;
			this->progressBarLabel->Text = L"Progress:";
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
			this->label1->Size = System::Drawing::Size(406, 48);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Please select how many threads shall be used, the amount of times \r\nthe algorithm"
				L" is to be repeated and the input file.\r\nWhen everything is set, please select wh"
				L"ich algorithm to use.";
			// 
			// threadsText
			// 
			this->threadsText->Location = System::Drawing::Point(150, 117);
			this->threadsText->Name = L"threadsText";
			this->threadsText->Size = System::Drawing::Size(100, 22);
			this->threadsText->TabIndex = 4;
			this->threadsText->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GUI::threadsText_KeyDown);
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(163, 207);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(134, 48);
			this->startButton->TabIndex = 5;
			this->startButton->Text = L"Start program";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
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
			// 
			// repeatsText
			// 
			this->repeatsText->Location = System::Drawing::Point(150, 156);
			this->repeatsText->Name = L"repeatsText";
			this->repeatsText->Size = System::Drawing::Size(100, 22);
			this->repeatsText->TabIndex = 8;
			this->repeatsText->Text = L"1";
			this->repeatsText->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GUI::repeatsText_KeyDown);
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
			this->label5->Location = System::Drawing::Point(263, 137);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(99, 16);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Select input file:";
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
			// timeTextLabel
			// 
			this->timeTextLabel->AutoSize = true;
			this->timeTextLabel->Location = System::Drawing::Point(328, 223);
			this->timeTextLabel->Name = L"timeTextLabel";
			this->timeTextLabel->Size = System::Drawing::Size(41, 16);
			this->timeTextLabel->TabIndex = 15;
			this->timeTextLabel->Text = L"Time:";
			// 
			// actualTimeLabel
			// 
			this->actualTimeLabel->AutoSize = true;
			this->actualTimeLabel->Location = System::Drawing::Point(409, 223);
			this->actualTimeLabel->Name = L"actualTimeLabel";
			this->actualTimeLabel->Size = System::Drawing::Size(24, 16);
			this->actualTimeLabel->TabIndex = 16;
			this->actualTimeLabel->Text = L"0 s";
			// 
			// checkedListBoxLanguage
			// 
			this->checkedListBoxLanguage->CheckOnClick = true;
			this->checkedListBoxLanguage->FormattingEnabled = true;
			this->checkedListBoxLanguage->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Assembly", L"C++" });
			this->checkedListBoxLanguage->Location = System::Drawing::Point(24, 207);
			this->checkedListBoxLanguage->Name = L"checkedListBoxLanguage";
			this->checkedListBoxLanguage->Size = System::Drawing::Size(99, 55);
			this->checkedListBoxLanguage->TabIndex = 17;
			this->checkedListBoxLanguage->SelectedIndexChanged += gcnew System::EventHandler(this, &GUI::checkedListBoxLanguage_SelectedIndexChanged);
			// 
			// statusLabel
			// 
			this->statusLabel->AutoSize = true;
			this->statusLabel->Location = System::Drawing::Point(79, 285);
			this->statusLabel->Name = L"statusLabel";
			this->statusLabel->Size = System::Drawing::Size(0, 16);
			this->statusLabel->TabIndex = 18;
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LavenderBlush;
			this->ClientSize = System::Drawing::Size(513, 339);
			this->Controls->Add(this->statusLabel);
			this->Controls->Add(this->checkedListBoxLanguage);
			this->Controls->Add(this->actualTimeLabel);
			this->Controls->Add(this->timeTextLabel);
			this->Controls->Add(this->fileButton);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->repeatsText);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->startButton);
			this->Controls->Add(this->threadsText);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->titleLabel);
			this->Controls->Add(this->progressBarLabel);
			this->Controls->Add(this->progressBar);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GUI";
			this->Text = L"Bandpass filter";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	numRepeats = Convert::ToInt32(repeatsText->Text);
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->Filter = "WAV files (*.wav)|*.wav";
	openFileDialog1->ShowDialog();
	inputFilePath = openFileDialog1->FileName;

}
private: System::Void threadsText_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == System::Windows::Forms::Keys::Enter) {
		int numberInText;
		if (repeatsText->Text == "") {
			MessageBox::Show("Please enter a valid number");
			repeatsText->Text = "";
		}
		else {
			try {
				numberInText = Convert::ToInt32(threadsText->Text);
			}
			catch (System::FormatException^ e) {
				MessageBox::Show("Please enter a valid number");
				threadsText->Text = "";
			}

			if (numberInText > 64 || numberInText < 0) {
				MessageBox::Show("Number of threads must be between 0 and 64");
				threadsText->Text = "";
			}
			else {
				numThreads = numberInText;
			}
		}
	}
}
	   private: System::Void repeatsText_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		   if (e->KeyCode == System::Windows::Forms::Keys::Enter) {
			   int numberInText;
			   if (repeatsText->Text == "") {
				   MessageBox::Show("Please enter a valid number");
				   repeatsText->Text = "";
			   }
			   else{
				   try {
					   numberInText = Convert::ToInt32(repeatsText->Text);
				   }
				   catch (System::FormatException^ e) {
					   MessageBox::Show("Please enter a valid number");
					   repeatsText->Text = "";
				   }

				   if (numberInText > 100 || numberInText < 0) {
					   MessageBox::Show("Number of repeats must be between 0 and 100");
					   repeatsText->Text = "";
				   }
				   else {
					   numRepeats = numberInText;
				   }
			   }
			   
		   }
	   }
private: System::Void checkedListBoxLanguage_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkedListBoxLanguage->SelectedIndex != -1) {
		
		for (int i = 0; i < checkedListBoxLanguage->Items->Count; i++) {
			checkedListBoxLanguage->SetItemChecked(i, false);
		}

		
		checkedListBoxLanguage->SetItemChecked(checkedListBoxLanguage->SelectedIndex, true);

		
		if (checkedListBoxLanguage->SelectedIndex == 0) {
			languageChoice = 1;
		}
		else if (checkedListBoxLanguage->SelectedIndex == 1) {
			languageChoice = 2;
		}
	}
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	progressBar->Value = 0;
    std::string inputFilePath = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
	std::string outputFilePath = "C:\\Users\\marwy\\source\\repos\\SolBandpass\\output.wav";
	std::ifstream checkFile(inputFilePath, std::ios::binary);
	if (!checkFile) {
		MessageBox::Show("Input file not found at: " + gcnew String(inputFilePath.c_str()));
		return;
	}
	if (threadsText->Text == "") {
		MessageBox::Show("Please enter a valid number");
		threadsText->Text = "";
		return;
	}
	if (repeatsText->Text == "") {
		MessageBox::Show("Please enter a valid number");
		repeatsText->Text = "";
		return;
	}
	checkFile.close();
	try {
		processWavFile(inputFilePath, outputFilePath, numThreads, languageChoice);
	}
	catch (const std::exception& e) {
		MessageBox::Show(gcnew String(e.what()));
	}
}
	   private: void static processChunkAsm(float* chunkPointer, size_t numElements) {
		   ModifyBitsAsm(chunkPointer, numElements);
	   }
				void static processChunkCpp(float* chunkPointer, size_t chunkSize) {
				  ModifyBitsCpp(chunkPointer, chunkSize);
			  }

			  std::vector<size_t> divideIntoChunks(size_t totalSize, size_t numChunks) {
				  std::vector<size_t> chunkSizes(numChunks, totalSize / numChunks);
				  size_t remainder = totalSize % numChunks;

				  for (size_t i = 0; i < remainder; ++i) {
					  chunkSizes[i]++;
				  }

				  return chunkSizes;
			  }

			  void processWavFile(const std::string& inputFilePath, const std::string& outputFilePath, size_t numThreads, int choice) {
				 
				  std::ifstream inputFile(inputFilePath, std::ios::binary);
				  if (!inputFile) {
					  MessageBox::Show("Could not open input file!"); 
					  return;
				  }
				  progressBar->Step = 10;
				  progressBar->PerformStep();
				  char header[44];
				  inputFile.read(header, 44);

				  int bitDepth = *reinterpret_cast<int16_t*>(&header[34]);

				  inputFile.seekg(0, std::ios::end);
				  std::streamoff fileSize = inputFile.tellg();
				  size_t dataSize = static_cast<size_t>(fileSize) - 44;
				  inputFile.seekg(44, std::ios::beg);

				  std::vector<float> audioData;
				  if (bitDepth == 16) {
					  std::vector<int16_t> rawAudioData(dataSize / sizeof(int16_t));
					  inputFile.read(reinterpret_cast<char*>(rawAudioData.data()), dataSize);
					  audioData.reserve(rawAudioData.size());
					  for (int16_t sample : rawAudioData) {
						  audioData.push_back(static_cast<float>(sample));
					  }
				  }
				  else if (bitDepth == 32) {
					  std::vector<int32_t> rawAudioData(dataSize / sizeof(int32_t));
					  inputFile.read(reinterpret_cast<char*>(rawAudioData.data()), dataSize);
					  audioData.reserve(rawAudioData.size());
					  for (int32_t sample : rawAudioData) {
						  audioData.push_back(static_cast<float>(sample));
					  }
				  }
				  else {
					  std::cerr << "Unsupported bit depth: " << bitDepth << std::endl;
					  return;
				  }
				  inputFile.close();
				  progressBar->Step = 20;
				  progressBar->PerformStep();
				  std::vector<size_t> chunkSizes = divideIntoChunks(audioData.size(), numThreads);
				  std::vector<std::thread> threads;
				  size_t offset = 0;
				  progressBar->PerformStep();
				  if (choice == 1) {
					  auto startAsm = std::chrono::high_resolution_clock::now(); //   POCZATEK CZASU DLA ASM
					  for (size_t i = 0; i < numThreads; ++i) {
						  float* chunkStart = &audioData[offset];
						  threads.emplace_back(processChunkAsm, chunkStart, chunkSizes[i]);
						  offset += chunkSizes[i];
					  }

					  for (auto& thread : threads) {
						  thread.join();
					  }
					  auto endAsm = std::chrono::high_resolution_clock::now(); //     KONIEC CZASU DLA ASM
					  std::chrono::duration<float> durationAsm = endAsm - startAsm;//obliczenia czasu
					  actualTimeLabel->Text = durationAsm.count() + " s";//wyswietlenie czasu
					  threads.clear();
				  }
				  else if (choice == 2) {

					  auto startCpp = std::chrono::high_resolution_clock::now(); //    START CZASU CPP
					  for (size_t i = 0; i < numThreads; ++i) {
						  float* chunkStart = &audioData[offset];
						  threads.emplace_back(processChunkCpp, chunkStart, chunkSizes[i]);
						  offset += chunkSizes[i];
					  }
					  for (auto& thread : threads) {
						  thread.join();
					  }
					  auto endCpp = std::chrono::high_resolution_clock::now(); // KONIEC CZASU CPP
					  std::chrono::duration<double> durationCpp = endCpp - startCpp;//obliczenie czasu cpp
					  actualTimeLabel->Text = durationCpp.count() + " s";//wyswietlenie czasu
				  }
				  else {
					  std::cout << "Blad!" << std::endl;
				  }
				  progressBar->Step = 40;
				  progressBar->PerformStep();

				  std::ofstream outputFile(outputFilePath, std::ios::binary);
				  if (!outputFile) {
					  std::cerr << "Could not open output file!" << std::endl;
					  return;
				  }

				  outputFile.write(header, 44);

				  if (bitDepth == 16) {
					  for (float sample : audioData) {
						  int16_t intSample = static_cast<int16_t>(sample);
						  outputFile.write(reinterpret_cast<const char*>(&intSample), sizeof(int16_t));
					  }
				  }
				  else if (bitDepth == 32) {
					  for (float sample : audioData) {
						  int32_t intSample = static_cast<int32_t>(sample);
						  outputFile.write(reinterpret_cast<const char*>(&intSample), sizeof(int32_t));
					  }
				  }
				  outputFile.close();
				  progressBar->Step = 10;
				  progressBar->PerformStep();
				  statusLabel->Text = "Finished and saved!";
				  std::cout << "Processed WAV file saved as: " << outputFilePath << std::endl;
			  }
};
}
