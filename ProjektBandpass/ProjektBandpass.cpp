#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <iomanip>
#include <cstdint>
#include <chrono>
#include <vector>

extern "C" void ModifyBitsAsm(float* chunkPointer, size_t numElements);
extern "C" void ModifyBitsCpp(float* chunkPointer, size_t numElements);

void static processChunkAsm(float* chunkPointer, size_t numElements) {
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
        std::cerr << "Could not open input file!" << std::endl;
        return;
    }
    
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

    std::vector<size_t> chunkSizes = divideIntoChunks(audioData.size(), numThreads);

    std::vector<std::thread> threads;
    size_t offset = 0;

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
        std::cout << "Assembly processing time: " << durationAsm.count() << " seconds" << std::endl;//wysweitlanie czasu

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
        std::cout << "C++ processing time: " << durationCpp.count() << " seconds" << std::endl;//wyswietlenie czasu cpp
    }
    else {
        std::cout << "Blad!" << std::endl;
    }
   

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

    std::cout << "Processed WAV file saved as: " << outputFilePath << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input_wav_file> <output_wav_file>" << std::endl;
        return 1;
    }

    size_t numThreads;
    int choice;
    std::cout << "Enter the number of threads for processing: ";
    std::cin >> numThreads;
    std::cout << std::endl << "1. Assembly 2. C++" << std::endl;
    std::cin >> choice;

    processWavFile(argv[1], argv[2], numThreads, choice);

    return 0;
}