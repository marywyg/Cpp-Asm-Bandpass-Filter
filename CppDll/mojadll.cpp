#include <cstdint>
#include<array> 

extern "C" void ModifyBitsCpp(float* chunkPointer, size_t numElements) {

    float filterCoefficients[] = {
     -0.0059f,   0.0215f,    0.1756f,    0.3827f,    0.3827f,    0.1756f,    0.0215f, - 0.0059f

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