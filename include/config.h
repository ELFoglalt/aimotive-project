#ifndef CONFIG_H
#define CONFIG_H

#include <neuralnet.h>

// A namespace for compile time configuration constants.
namespace config
{

    // The neural net used by the compiled executible.
    nn::Network network({
        // In -> Hidden 1
        {
            { 0.0120, 0.0500, 0.0300, 0.0000 },
            { 0.0320, 0.0100, 0.0135, 0.0000 },
            { 0.0450, 0.0200, 0.0230, 0.0000 }
        },
        // Hidden 1 -> Out
        {
            { 0.0370, 0.0230, 0.0610, 0.0000 },
            { 0.0420, 0.0510, 0.0100, 0.0000 }
        }
    });
}

#endif