#include <iostream>
#include <filesystem>
#include "signal_utils.h"

namespace fs = std::filesystem;

int main() {
    std::string input_folder = "data/";
    std::string output_folder = "output/";

    // Create output folder if it doesn't exist
    if(!fs::exists(output_folder)) {
        fs::create_directory(output_folder);
    }

    // Iterate over all CSV files in data folder
    for (const auto & entry : fs::directory_iterator(input_folder)) {
        std::string path = entry.path().string();
        if(entry.path().filename().string()[0] == '.') continue; // skip hidden files

        std::vector<float> signal = readCSV(path);
        if(signal.empty()) continue;

        std::vector<float> fft_mag = computeFFT(signal);

        // Save FFT magnitude to output folder
        std::string filename = output_folder + entry.path().filename().string();
        saveCSV(filename, fft_mag);

        std::cout << "Processed " << path << std::endl;
    }

    std::cout << "All signals processed." << std::endl;
    return 0;
}
