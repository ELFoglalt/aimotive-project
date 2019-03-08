# Aimotive C++ test

> A simple neral network implementation.

> This is the user readme. For documentation on the source code, see the `README.md` in the root directory of the project source.


## Usage

```sh
> neuralnet input1 input2 ... inputn
```

With the default network:
```sh
> neuralnet 0.2 -0.4 0.6
Inputs =======================================
    +0.2000000     -0.4000000     +0.6000000
Results ======================================
    +0.0011591     +0.0007003
===============================================
```

## Network

The default configuration implements a neural network described by the following structure:
```
Layers:
    Input (3 nodes)
    Hidden 1 (3 neurons)
    Output (2 nodes)

Weights:
    Input -> Hidden 1
    0.1200, 0.0500, 0.0300, 0.0000 
    0.3200, 0.0100, 0.0135, 0.0000 
    0.0450, 0.0200, 0.0230, 0.0000 

    Hidden 1 -> Output
    0.0370, 0.0230, 0.0610, 0.0000
    0.0420, 0.0510, 0.0100, 0.0000
```

The weights above are in a matrix format where the `i`th row's `j`th column represents the input weight that maps the `j`th neuron of the first layer to the `i-1`th neuron of the second. The last element of each row is the bias term.