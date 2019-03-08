#include <neuralnet.h>
#include <stdexcept>

namespace nn
{

    //TODO: Explain or fix: Since the neural network is defined at compile time, no run-time checks are made for it's validity.
    std::vector<Number> NeuralNet::apply(const std::vector<Number>& input) const
    {
        if ((int)input.size() != input_size()) {
            throw std::runtime_error("Invalid input parameters.");
        }

        std::vector<Number> previous = input;
        std::vector<Number> next;

        for (auto& weight_matrix : network) {
            const int n_outputs = weight_matrix.size();
            next = std::vector<Number>(n_outputs, 0);

            for (int i = 0; i < n_outputs; ++i) {
                const std::vector<Number>& input_weights = weight_matrix[i];
                const int n_inputs = input_weights.size() - 1;

                // Connections
                for (int j = 0; j < n_inputs; ++j) {
                    next[i] += previous[j] * input_weights[j];
                }
                // Bias
                next[i] += previous[n_inputs];

                // ReLU
                next[i] = std::max(0.0, next[i]);
            }

            previous = next;
        }        

        return next;
    }

    int NeuralNet::input_size() const {
        return network.front().front().size() - 1; // -1 due to bias term
    }

    int NeuralNet::output_size() const {
        return network.back().size();
    }

    std::string NeuralNet::visualize() const
    {
        throw std::logic_error("Implement me.");
    }

} // << nn