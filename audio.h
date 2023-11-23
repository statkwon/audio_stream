#ifndef AISE_AUDIO_H
#define AISE_AUDIO_H

#include "portaudio.h"

class Audio {
    PaError err_;
    PaStream *stream_;

public:
    Audio(double sampleRate, unsigned long framesPerBuffer, PaStreamCallback streamCallback);

    ~Audio();

    void start();

    void stop();
};

#endif //AISE_AUDIO_H
