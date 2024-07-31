import numpy as np
import matplotlib.pyplot as plt
import pandas as pd


filename = 'landmark_MOV_0265annotated_video.csv'
data = pd.read_csv(filename)

signal = data['pose_0_x'].values
print(signal)

dft = np.fft.fft(signal)
frequencies = np.fft.fftfreq(len(signal))

real_part = dft.real
imaginary_part = dft.imag

amplitude_spectrum = np.abs(dft)
phase_spectrum = np.angle(dft)

idft = np.fft.ifft(dft)
reconstructed_signal = idft.real

fig, axs = plt.subplots(3, 1, figsize=(10, 15))

axs[0].plot(signal)
axs[0].set_title('Original Signal')
axs[0].set_xlabel('Sample')
axs[0].set_ylabel('x position')

axs[1].plot(real_part)
axs[1].set_title('Real Part')
axs[1].set_xlabel('Frequency')
axs[1].set_ylabel('Amplitude')

axs[2].plot(imaginary_part)
axs[2].set_title('Imaginary Part')
axs[2].set_xlabel('Frequency')
axs[2].set_ylabel('Amplitude')
plt.tight_layout()
fig.savefig('DFT1.pdf')
plt.show()
fig, axs = plt.subplots(3, 1, figsize=(10, 15))

axs[0].plot(frequencies, amplitude_spectrum)
axs[0].set_title('Amplitude Spectrum')
axs[0].set_xlabel('Frequency')
axs[0].set_ylabel('Amplitude')

axs[1].plot(frequencies, phase_spectrum)
axs[1].set_title('Phase Spectrum')
axs[1].set_xlabel('Frequency')
axs[1].set_ylabel('Phase')

axs[2].plot(reconstructed_signal)
axs[2].set_title('IDFT')
axs[2].set_xlabel('Sample')
axs[2].set_ylabel('x position')
plt.tight_layout()
fig.savefig('DFT2.pdf')
plt.show()

plt.figure(figsize=(10, 15))
plt.plot(reconstructed_signal, label='IDFT')
plt.savefig('IDFT.pdf')
plt.title('IDFT')
plt.xlabel('Sample')
plt.ylabel('Amplitude')
plt.legend()
plt.show()