#include "signal_utils.h"
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fftw3.h>

// Read CSV
std::vector<float> readCSV(const std::string &filename) {
    std::vector<float> data;
    std::ifstream file(filename);
    if(!file.is_open()) {
        std::cerr << "Failed to open " << filename << std::endl;
        return data;
    }
    std::string line;
    while(std::getline(file, line)) {
        std::stringstream ss(line);
        float val;
        while(ss >> val) {
            data.push_back(val);
            if(ss.peek() == ',' || ss.peek() == ' ') ss.ignore();
        }
    }
    file.close();
    return data;
}

// Save CSV
void saveCSV(const std::string &filename, const std::vector<float> &data) {
    std::ofstream file(filename);
    if(!file.is_open()) {
        std::cerr << "Failed to open " << filename << " for writing" << std::endl;
        return;
    }
    for(const auto &val : data) {
        file << val << "\n";
    }
    file.close();
}

// Compute FFT using FFTW
std::vector<float> computeFFT(const std::vector<float> &signal) {
    int N = signal.size();
    std::vector<float> magnitude(N/2, 0.0f);

    float* in = (float*) fftwf_malloc(sizeof(float) * N);
    fftwf_complex* out = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * N);

    for(int i=0;i<N;i++) in[i] = signal[i];

    fftwf_plan plan = fftwf_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);
    fftwf_execute(plan);

    for(int k=0;k<N/2;k++)
        magnitude[k] = std::sqrt(out[k][0]*out[k][0] + out[k][1]*out[k][1]) / N;

    fftwf_destroy_plan(plan);
    fftwf_free(in);
    fftwf_free(out);

    return magnitude;
}
