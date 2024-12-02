# Synthesizer

## Overview

**Synthesizer** is a powerful and flexible audio synthesizer built using the [JUCE library](https://juce.com/). Whether you're a beginner or a professional musician, this project aims to provide you with high-quality sound synthesis and an intuitive user interface.

## Features

- **Multiple Oscillators**: Generate rich and complex sounds with multiple types of oscillators.
- **Envelopes**: Control the attack, decay, sustain, and release of your sounds.
- **Filters**: Shape your sound with various types of filters.
- **MIDI Input**: Play your synthesizer using any MIDI keyboard or controller.
- **Real-Time Audio Processing**: Experience low-latency, high-performance audio processing.

## Installation

### Prerequisites

- **JUCE Library**: Download and install the JUCE library from [juce.com](https://juce.com/).
- **Visual Studio**: Ensure you have Visual Studio installed on your system.

### Building the Project

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/Synthesizer.git
    cd Synthesizer
    ```

2. Open the project in Projucer:
    ```sh
    Projucer --resave Synthesizer.jucer
    ```

3. Export the project to Visual Studio:
    - Open Projucer.
    - Click on the "Exporters" section.
    - Select "Visual Studio" as the export target.
    - Click "Save Project."

4. Build and run the project in Visual Studio:
    - Open the generated `.sln` file in Visual Studio.
    - Set the build configuration to "Debug" or "Release."
    - Build the project by selecting "Build Solution."
    - Run the project by selecting "Start Debugging" or "Start Without Debugging."

## Usage

- **Oscillator**: Choose different types of waveforms (sine, square, triangle, sawtooth) to generate sound.
- **Envelope Controls**: Adjust the ADSR (Attack, Decay, Sustain, Release) settings to shape your sound.
- **Filter**: Apply low-pass, high-pass, and band-pass filters to modulate your audio output.
- **MIDI Input**: Connect your MIDI keyboard/controller to start playing.
