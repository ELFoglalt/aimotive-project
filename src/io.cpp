#include <io.h>

#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <regex>

namespace nn
{

    // File locals
    namespace
    {
        const std::regex rx_standard("[+-]?(?:\\d*\\.?\\d+)|(?:\\d+)");
        const std::regex rx_scientific("[+-]?\\d*\\.?\\d*[eE][+-]?\\d+");
    }


    std::vector<Num> ParseInput(const int& argc, const char* argv[])
    {
        std::vector<Num> input(argc - 1, 0);

        for (int i = 1; i < argc; i++) {
            std::stringstream ss;
            ss << argv[i];
            if (! (std::regex_match(ss.str(), rx_standard) || std::regex_match(ss.str(), rx_scientific)))
            {
                throw std::runtime_error("Unknown input parameter \"" + ss.str() + "\"");
            }

            ss >> input[i - 1];
        }

        return input;
    }


    std::string FormatOutput(
        const std::vector<Num>& inputs,
        const std::vector<Num>& results)
    {
        std::string format = "%+14.7f";
        std::ostringstream inputs_stream;
        for (auto& input : inputs) {
            char buffer[16];
            snprintf(buffer, sizeof(buffer), format.c_str(), input);
            inputs_stream << buffer << ' ';
        }
        inputs_stream << "\n";
        std::string inputs_srt = inputs_stream.str();

        std::ostringstream results_stream;
        for (auto& result : results) {
            char buffer[16];
            snprintf(buffer, sizeof(buffer), format.c_str(), result);
            results_stream << buffer << ' ';
        }
        results_stream << "\n";
        std::string results_srt = results_stream.str();

        int len = std::max(inputs_srt.size(), results_srt.size()) + 2;
        
        std::string header = "Inputs ";
        header += std::string(std::max(0, (int)(len - 2 - header.size())), '=') + "\n";
        
        std::string divider = "Results ";
        divider += std::string(std::max(0, (int)(len - 2 - divider.size())), '=') + "\n";
        
        std::string footer = std::string(std::max(header.size(), divider.size()), '=') + "\n";

        return header + inputs_srt + divider + results_srt + footer;
    }

} // << nn