#ifndef NEURALNET_H
#define NEURALNET_H

#include <vector>
#include <string>

//TODO: Documentation

namespace nn
{
    /**
     * Arbitrary precision floating point number.
     * Declared explicitly to allow the use of implementation specific types.
     * ? Is this really necessary? Adds complexity.
     */
    using Number = double;
    using Matrix = std::vector<std::vector<Number> >;
    using Network = std::vector<Matrix>;
    
    class NeuralNet {
    public:
        NeuralNet(const Network& network) : network(network) {}

        /**
         * Calcualtes the output of the neural net for a given input.
         * \throws std::runtime_error If number of inputs does not matches
         *         the expectations of the network.
         */
        std::vector<Number> apply(const std::vector<Number>& input) const;
        
        std::string visualize() const; //TODO: Write as << operator?
    
        int input_size() const;
        int output_size() const;

    private:
        /**
         * Stores the neural net as a vector of weight matrixes.
         * Given L hidden layers, the weights vector is L + 1 long.
         * If layer i has N neurons, and layer j has M neurons,
         * weights[i] is expected to be an (M) x (N+1) matrix
         * where row k weights[i][k] represents the input weights
         * of neuron k in layer j.
         * The last element of each row is the bias term.
         */
        const Network network;
    };

} // << nn

#endif