#include <iostream>
#include "fft.h"
#include "audio.h"

static int streamCallback(const void *input,
                          void *output,
                          unsigned long frameCount,
                          const PaStreamCallbackTimeInfo *timeInfo,
                          PaStreamCallbackFlags statusFlags,
                          void *userData) {
    memcpy(output, input, sizeof(paFloat32) * frameCount);
    return 0;
}

int main() {
    try {
        Audio audio(48000, 480, streamCallback);
        audio.start();
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}
