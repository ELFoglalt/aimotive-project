#ifndef NEURALNET_H
#define NEURALNET_H

#include <vector>
#include <string>

namespace nn
{
    /**
     * Generic floating point number defined to allow swapping
     * single/double etc. precision if needed.
     */
    using Num = double;
    using Matrix = std::vector<std::vector<Num> >;

    /**
     * Represents a neural network as a vector of weight matrixes.
     * Given L hidden layers, the network consits of L + 1 matrixes.
     * If layer i has N neurons, and layer j has M neurons,
     * network[i] is expected to be an (M) x (N+1) matrix.
     * Row k of the matrix (weights[i][k]) represents the input weights
     * of neuron k in layer j.
     * The last element of each row is the bias term.
     */
    using Network = std::vector<Matrix>;
    
    class NeuralNet {
    public:
        NeuralNet(const Network& network) : network(network) {}

        /**
         * Calcualtes the output of the neural net for a given input.
         * \throws std::runtime_error If number of inputs does not matches
         *         the expectations of the network.
         */
        std::vector<Num> apply(const std::vector<Num>& input) const;
    
        int input_size() const;
        
        int output_size() const;

    private:
        const Network network;
    };

} // << nn

#endif