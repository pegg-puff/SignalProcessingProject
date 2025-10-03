#include "signal_utils.h"
#include <fstream>
#include <sstream>
#include <cmath>
#include <complex>
#include <iostream>

// Simple DFT (for demonstration, can be replaced with FFT library)
std::vector<float> computeFFT(const std::vector<float> &signal) {
    int N = signal.size();
    std::vector<float> magnitude(N/2, 0.0f);

    for(int k = 0; k < N/2; k++) {
        std::complex<float> sum(0.0f,0.0f);
        for(int n = 0; n < N; n++) {
            float angle = -2.0f * M_PI * k * n / N;
            sum += std::complex<float>(signal[n]*cos(angle), signal[n]*sin(angle));
        }
        magnitude[k] = std::abs(sum)/N;
    }
    return magnitude;
}

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
