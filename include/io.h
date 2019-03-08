#ifndef IO_H
#define IO_H

#include <neuralnet.h>
#include <vector>
#include <string>

namespace nn {
    
    /**
     *  Parses command line arguments (neural net input values) into a vector of doubles.
     *  ! Non double-parsable values parse with undefined behaviour.
     *  \param IN argc The number of command line arguments.
     *  \param IN argv Command line arguments.
     *  \return Vector of doubles as parsed from argv.
     */
    std::vector<Number> ParseInput(const int& argc, const char** argv);
    
    /**
     *  Formats a vector of doubles as neural network results.
     *  \param IN A vector containing the results of the neural network.
     *  \return A multiline formatted string containing the results.
     */
    std::string FormatOutput(const std::vector<Number>& results);

} // << nn

#endif