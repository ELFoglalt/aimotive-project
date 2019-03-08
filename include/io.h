#ifndef IO_H
#define IO_H

#include <neuralnet.h>
#include <vector>
#include <string>

namespace nn {
    
    /**
     * Parses command line arguments (neural net input values) into a vector of nn::Nums.
     * \throws std::runtime_error If input does not match floating point literal format.
     */
    std::vector<nn::Num> ParseInput(const int& argc, const char** argv);

    std::string FormatOutput(const std::vector<nn::Num>& inputs, const std::vector<nn::Num>& results);

} // << nn

#endif