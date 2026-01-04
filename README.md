Developed by Andrew Primiano | UGA Electrical Engineering
This project implements an end-to-end TinyML solution for voice-controlled bedroom lighting. It utilizes a deep learning model trained on Edge Impulse and deployed to an Arduino Nano 33 BLE Sense to perform real-time keyword spotting with high precision and low latency.

🛠 Technical Overview
Hardware: Arduino Nano 33 BLE Sense (Cortex-M4F), 2-Channel Relay Module.

Microphone: Built-in MP34DT05 PDM Digital Microphone.

Inference Engine: Edge Impulse C++ SDK (EON Compiler optimized).

Programming: C++ (Arduino IDE).

Key Features & Engineering Challenges
1. Robust Dataset Engineering
To minimize False Acceptance Rates (FAR), I curated a custom dataset including:

Target Commands: "Light One On/Off" and "Light Two On/Off" recorded at varying distances and inflections.

"Unknown" Class: 120 seconds of conversational speech and environmental noise to prevent false triggers during normal activity.

Noise Augmentation: Integrated background hum and sharp transients (snaps/claps) into the training pipeline to ensure a True Positive rate of nearly 100%.

2. Signal Processing & Optimization
Post-Processing Logic: Implemented a Moving Average Filter in the inference loop to ensure the system only triggers when a command is identified with >80% confidence across multiple consecutive windows.

Memory Management: Leveraged the EON Compiler to minimize the model's RAM/Flash footprint, ensuring stable performance on the ARM Cortex-M4 microcontroller.

3. Hardware Implementation
Interfaced the 3.3V logic of the Nano 33 BLE Sense with a 2-channel relay module to safely switch high-voltage bedroom lighting circuits.

