#include <iostream>
#include "audio.h"

Audio::Audio(double sampleRate, unsigned long framesPerBuffer, PaStreamCallback streamCallback) : stream_(nullptr) {
    err_ = Pa_Initialize();
    if (err_ != paNoError) {
        handle_error();
        return;
    }

    err_ = Pa_OpenDefaultStream(&stream_, 1, 1,
                                paFloat32, sampleRate, framesPerBuffer,
                                streamCallback, nullptr);
    if (err_ != paNoError) handle_error();
}

Audio::~Audio() {
    Pa_Terminate();
    std::cout << "Finished." << std::endl;
}

void Audio::start() {
    err_ = Pa_StartStream(stream_);
    if (err_ != paNoError) {
        handle_error();
        return;
    }

    std::cout << "Hit ENTER to stop program." << std::endl;
    std::cin.get();
    stop();
}

void Audio::stop() {
    err_ = Pa_CloseStream(stream_);
    if (err_ != paNoError) handle_error();
}

void Audio::handle_error() const {
    Pa_Terminate();
    std::cerr << "An error occurred while using the portaudio stream" << std::endl;
    std::cerr << "Error number: " << err_ << std::endl;
    std::cerr << "Error message: " << Pa_GetErrorText(err_) << std::endl;
}
