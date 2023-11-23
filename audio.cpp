#include <iostream>
#include "audio.h"

Audio::Audio(double sampleRate, unsigned long framesPerBuffer, PaStreamCallback streamCallback) : stream_(nullptr) {
    err_ = Pa_Initialize();
    if (err_ != paNoError) throw std::runtime_error(Pa_GetErrorText(err_));

    err_ = Pa_OpenDefaultStream(&stream_, 1, 1,
                                paFloat32, sampleRate, framesPerBuffer,
                                streamCallback, nullptr);
    if (err_ != paNoError) throw std::runtime_error(Pa_GetErrorText(err_));
}

Audio::~Audio() {
    Pa_Terminate();
    std::cout << "Finished." << std::endl;
}

void Audio::start() {
    err_ = Pa_StartStream(stream_);
    if (err_ != paNoError) throw std::runtime_error(Pa_GetErrorText(err_));

    std::cout << "Hit ENTER to stop program." << std::endl;
    std::cin.get();
    stop();
}

void Audio::stop() {
    err_ = Pa_CloseStream(stream_);
    if (err_ != paNoError) throw std::runtime_error(Pa_GetErrorText(err_));
}
