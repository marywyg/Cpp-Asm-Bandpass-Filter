#ifndef PROJEKT_BANDPASS_H
#define PROJEKT_BANDPASS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <iomanip>
#include <cstdint>
#include <chrono>
#include <vector>
#include <string>

// Deklaracje funkcji ASM i C++ do przetwarzania danych audio
extern "C" void ModifyBitsAsm(float* chunkPointer, size_t numElements);
extern "C" void ModifyBitsCpp(float* chunkPointer, size_t numElements);

// Funkcje pomocnicze
std::vector<size_t> divideIntoChunks(size_t totalSize, size_t numChunks);
void printData(const std::vector<float>& data, const std::string& label);

// G³ówna funkcja do przetwarzania pliku WAV
void processWavFile(const std::string& inputFilePath, const std::string& outputFilePath, size_t numThreads, int choice);

// Funkcje do przetwarzania poszczególnych fragmentów danych audio
void processChunkAsm(float* chunkPointer, size_t numElements);
void processChunkCpp(float* chunkPointer, size_t chunkSize);
void logToFile(const std::string& message);
#endif // PROJEKT_BANDPASS_H