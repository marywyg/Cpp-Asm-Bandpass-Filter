#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <iomanip>
#include <cstdint>
#include <chrono>
#include <vector>



void printData(const std::vector<float>& data, const std::string& label) {
    std::cout << label << ": ";
    for (size_t i = 0; i < std::min(data.size(), size_t(10)); ++i) { 
        std::cout << std::fixed << std::setprecision(6) << data[i] << " ";
    }
    std::cout << std::endl;
}
int main(int argc, char* argv[]) {
    //if (argc < 3) {
    //    std::cerr << "Usage: " << argv[0] << " <input_wav_file> <output_wav_file>" << std::endl;
    //    return 1;
    //}
    //size_t numThreads;
    //int choice;
    //std::cout << "Enter the number of threads for processing: ";
    //std::cin >> numThreads;
    //std::cout << std::endl << "1. Assembly 2. C++" << std::endl;
    //std::cin >> choice;
    ////processWavFile(argv[1], argv[2], numThreads, choice);
    //alignas(16) std::vector<float> audioData = { 1.0f, 2.0f, 3.0f, 4.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f };
    //std::cout << "Przed przetworzeniem w asm:" << std::endl;
    //printData(audioData, "Audio Data");
    //size_t numElements = audioData.size();
    //std::cout << "PRozmiar: " << numElements << std::endl;
    //ModifyBitsAsm(audioData.data(), numElements);
    //std::cout << "Po przetworzeniu w asm:" << std::endl;
    //printData(audioData, "Audio Data");
    //alignas(16) std::vector<float> audioData2 = { 1.0f, 2.0f, 3.0f, 4.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f };
    //std::cout << "Przed przetworzeniem w cpp:" << std::endl;
    //printData(audioData2, "Audio Data");
    //size_t numElements2 = audioData2.size();
    //ModifyBitsCpp(audioData2.data(), numElements2);
    //std::cout << "Po przetworzeniu w cpp:" << std::endl;
    //printData(audioData2, "Audio Data");

    return 0;
}