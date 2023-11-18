#ifndef AISE_FFT_H
#define AISE_FFT_H

#include "pocketfft_hdronly.h"

using complex = std::complex<float>;

void fft(size_t n_fft, const float *data_in, complex *data_out) {
    pocketfft::shape_t shape_in;
    shape_in.push_back(n_fft);

    pocketfft::stride_t stride_in, stride_out;
    stride_in.push_back(sizeof(float));
    stride_out.push_back(sizeof(complex));

    pocketfft::shape_t axes;
    axes.push_back(0);

    pocketfft::r2c(shape_in, stride_in, stride_out, axes, pocketfft::FORWARD, data_in, data_out, 1.0f);
}

void ifft(size_t n_fft, const complex *data_in, float *data_out) {
    pocketfft::shape_t shape_out;
    shape_out.push_back(n_fft);

    pocketfft::stride_t stride_in, stride_out;
    stride_in.push_back(sizeof(complex));
    stride_out.push_back(sizeof(float));

    pocketfft::shape_t axes;
    axes.push_back(0);

    pocketfft::c2r(shape_out, stride_in, stride_out, axes, pocketfft::BACKWARD, data_in, data_out, 1.0f);
}

#endif //AISE_FFT_H
