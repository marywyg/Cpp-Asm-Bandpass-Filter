#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <iomanip>
#include <cstdint>  

extern "C" void ModifyBitsAsm(double* chunkPointer);

void processChunk(double* chunkPointer) {
    std::cout << "Processing chunk at address: " << chunkPointer << std::endl;
    ModifyBitsAsm(chunkPointer);
}

void printRawData(const std::vector<double>& data, const std::string& message, size_t numSamples = 10) {
    std::cout << message << std::endl;
    std::cout << "First " << numSamples << " samples:" << std::endl;
    for (size_t i = 0; i < std::min(numSamples, data.size()); ++i) {
        std::cout << std::hexfloat << data[i] << " ";
    }
    std::cout << std::endl;

    if (data.size() > numSamples) {
        std::cout << "Last " << numSamples << " samples:" << std::endl;
        for (size_t i = data.size() - numSamples; i < data.size(); ++i) {
            std::cout << std::hexfloat << data[i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void processWavFile(const std::string& inputFilePath, const std::string& outputFilePath) {
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

    std::vector<double> audioData;
    if (bitDepth == 16) {
        
        std::vector<int16_t> rawAudioData(dataSize / sizeof(int16_t));
        inputFile.read(reinterpret_cast<char*>(rawAudioData.data()), dataSize);

        
        audioData.reserve(rawAudioData.size());
        for (int16_t sample : rawAudioData) {
            audioData.push_back(static_cast<double>(sample));
        }
    }
    else if (bitDepth == 32) {
        
        std::vector<int32_t> rawAudioData(dataSize / sizeof(int32_t));
        inputFile.read(reinterpret_cast<char*>(rawAudioData.data()), dataSize);

        
        audioData.reserve(rawAudioData.size());
        for (int32_t sample : rawAudioData) {
            audioData.push_back(static_cast<double>(sample));
        }
    }
    else {
        std::cerr << "Unsupported bit depth: " << bitDepth << std::endl;
        return;
    }
    inputFile.close();

    
    printRawData(audioData, "Raw Data Before Processing:", 10);

    size_t chunkSize = audioData.size() / 3;
    size_t numChunks = 3;
    std::vector<std::thread> threads;

    for (size_t i = 0; i < numChunks; ++i) {
        double* chunkStart = &audioData[i * chunkSize];
        std::cout << "Creating thread for chunk " << i << " at address: " << chunkStart << std::endl; 
        threads.emplace_back(processChunk, chunkStart);
    }

    for (auto& thread : threads) {
        thread.join();
        std::cout << "Thread joined." << std::endl; 
    }

    
    printRawData(audioData, "Raw Data After Processing:", 10);

    
    std::ofstream outputFile(outputFilePath, std::ios::binary);
    if (!outputFile) {
        std::cerr << "Could not open output file!" << std::endl;
        return;
    }

    outputFile.write(header, 44); 

    if (bitDepth == 16) {
        
        for (double sample : audioData) {
            int16_t intSample = static_cast<int16_t>(sample);
            outputFile.write(reinterpret_cast<const char*>(&intSample), sizeof(int16_t));
        }
    }
    else if (bitDepth == 32) {
        
        for (double sample : audioData) {
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

    processWavFile(argv[1], argv[2]);
    return 0;
}
