#include <io.h>

#include <stdexcept>
#include <stdlib.h>
#include <sstream>

std::vector<double> nn::ParseInput(const int& argc, const char* argv[])
    {
        std::vector<double> input(argc - 1, 0);

        for(int i = 1; i < argc; i++) {
            input[i - 1] = std::atof(argv[i]);
        }

        return input;
    }


std::string nn::FormatOutput(const std::vector<double>& results)
{
    std::ostringstream output;

    for (auto& result : results) {
        char buffer[16];
        snprintf(buffer, sizeof(buffer), "%+14.4f", result);
        output << buffer << ' ';
    }
    output << "\n";

    return output.str();
}