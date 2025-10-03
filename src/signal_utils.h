#ifndef SIGNAL_UTILS_H
#define SIGNAL_UTILS_H

#include <vector>
#include <string>

// Read a CSV file into a vector of floats
std::vector<float> readCSV(const std::string &filename);

// Compute magnitude of FFT
std::vector<float> computeFFT(const std::vector<float> &signal);

// Save a vector to CSV
void saveCSV(const std::string &filename, const std::vector<float> &data);

#endif
