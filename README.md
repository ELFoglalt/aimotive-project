# Aimotive C++ test
> A simple neral network implementation by Máté Kerekes.

## Configuration
To modify the neural net, edit the `network` definition in `config.h`. For details about the representation and structure of the network constant, see the definition of `Network` in `neuralnet.h`.

> If your project does not have `config.h`, make a manual copy of `example.config.h` and name it accordingly, or alternatively, run `./script/build` to automatically generate it. `config.h` is not tracked in git to allow you changing the network without causing merge conflicts.

## Design notes
This is a straightforward network implementation that favours readable code and convienience over both performance and generality. 


### Improvement directions

### Network data structure

### Botlenecks




## Scripts
### Build
```sh
# Build in debug mode and run tests
> ./script/build debug
# Run the executable
> ./build/debug/neuralnet 0.2 -0.4 0.6
```

```sh
# Build in release mode and run tests
> ./script/build release
# Run the executable
> ./build/release/neuralnet 0.2 -0.4 0.6
```

```sh
# Clean buld directories
> ./script/build clean
```

### Distribution
```sh
# Create dist folder with release mode executible and docs
> ./script/dist
```