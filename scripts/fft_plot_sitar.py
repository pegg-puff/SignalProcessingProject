import numpy as np
import matplotlib.pyplot as plt

# Load FFT output
fft_data = np.loadtxt("output/sitar.csv", delimiter=",")

# Plot
plt.figure(figsize=(12,6))
plt.plot(fft_data, color='blue')
plt.title("FFT Spectrum of sitar.wav")
plt.xlabel("Frequency Bin")
plt.ylabel("Magnitude")
plt.grid(True)
plt.tight_layout()
plt.show()

# Optional: Save the plot as an image for submission
plt.savefig("output/sitar_fft.png")