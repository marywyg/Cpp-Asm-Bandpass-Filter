#include <cstdint>
#include<array> 

extern "C" void ModifyBitsCpp(float* chunkPointer, size_t numElements) {

    float filterCoefficients[] = {
     -0.0059,   0.0215,    0.1756,    0.3827,    0.3827,    0.1756,    0.0215, - 0.0059

    };


    for (size_t i = 0; i < numElements; ++i) {
        float result = 0.f;
        for (size_t j = 0; j < std::size(filterCoefficients); ++j) {
            if (i + j < numElements) {
                result += chunkPointer[i + j] * filterCoefficients[j];
            }
        }
        chunkPointer[i] = result;
    }
}