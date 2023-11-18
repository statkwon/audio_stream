#include <iostream>
#include "fft.h"
#include "audio.h"

static int streamCallback(const void *input,
                          void *output,
                          unsigned long frameCount,
                          const PaStreamCallbackTimeInfo *timeInfo,
                          PaStreamCallbackFlags statusFlags,
                          void *userData) {
    std::vector<complex> cspec(frameCount / 2 + 1);
    auto in = reinterpret_cast<const float *>(input);
    auto out = reinterpret_cast<float *>(output);
    fft(frameCount, in, cspec.data());
    ifft(frameCount, cspec.data(), out);
    memcpy(output, input, sizeof(paFloat32) * frameCount);
    return 0;
}

int main() {
    Audio audio(48000, 480, streamCallback);
    audio.start();
}
