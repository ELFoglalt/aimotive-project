# Aimotive C++ test
> A simple neral network implementation by Máté Kerekes.

## Configuration
To modify the neural net, edit the `network` definition in `config.h`. For details about the representation and structure of the network constant, see the definition of `Network` in `neuralnet.h`.

## Design notes
This is a straightforward network implementation that favours readable code and convienience over both performance and generality. 


### Improvement directions

### Network data structure

### Botlenecks




## Scripts
### Build
```sh
# Build in debug mode and run tests
> ./scripts/build debug
# Run the executable
> ./build/debug/neuralnet 0.2 -0.4 0.6
```

```sh
# Build in release mode and run tests
> ./scripts/build release
# Run the executable
> ./build/release/neuralnet 0.2 -0.4 0.6
```

```sh
# Clean buld directories
> ./scripts/build clean
```

### Distribution
```sh
# Create dist folder with release mode executible and docs
> ./scripts/dist
```