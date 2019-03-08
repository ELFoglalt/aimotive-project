#ifndef IO_H
#define IO_H

#include <neuralnet.h>
#include <vector>
#include <string>

namespace nn {
    
    /**
     * Parses command line arguments (neural net input values) into a vector of nn::Nums.
     * ! Non floating point parsable inputs parse to zeros.
     */
    std::vector<nn::Num> ParseInput(const int& argc, const char** argv);

    std::string FormatOutput(const std::vector<nn::Num>& inputs, const std::vector<nn::Num>& results);

} // << nn

#endif