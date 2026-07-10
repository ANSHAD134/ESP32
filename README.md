<div align="center">

# 📡 ESP32

### ESP-IDF based ESP32 Projects — GPIO, Sensors, Wi-Fi & Cloud Connectivity

![ESP32](https://img.shields.io/badge/MCU-ESP32-E7352C?style=for-the-badge&logo=espressif&logoColor=white)
![ESP--IDF](https://img.shields.io/badge/Framework-ESP--IDF-000000?style=for-the-badge&logo=espressif&logoColor=white)
![C](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![IoT](https://img.shields.io/badge/IoT-Cloud%20Connected-4CAF50?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge)

*A hands-on collection of ESP32 firmware projects built with ESP-IDF — from basic GPIO to Wi-Fi & cloud data upload.*

</div>

---

## 🖼️ Preview

<div align="center">

**Wi-Fi Connection Output**

<img src="https://raw.githubusercontent.com/ANSHAD134/ESP32/main/Codes/Wifi_connect/Screenshot%202026-04-18%20205050.png" width="600"/>

</div>

---

## 📂 Projects

| Project | Description |
|---|---|
| 💡 **Blink** | Basic GPIO blink program — the classic "Hello World" of embedded systems |
| 💡 **Blink_LED** | Extended LED blinking with configurable GPIO control |
| 🔘 **Switch** | Push-button input handling with debounce logic *(includes working demo video)* |
| 🌡️ **Temp_LM35** | Reads analog temperature data from an **LM35** sensor |
| 📶 **Wifi_connect** | Connects the ESP32 to a Wi-Fi network *(with output screenshot)* |
| 📊 **adc** | Reads ADC values and converts them to temperature *(includes working demo video)* |
| ☁️ **cloud_upload** | Uploads sensor data to the cloud over Wi-Fi *(includes working demo video)* |

---

## 🛠️ Tech Stack

- **MCU**: ESP32 (Dual-core Xtensa LX6)
- **Framework**: [ESP-IDF](https://github.com/espressif/esp-idf) (FreeRTOS-based)
- **Language**: C
- **Build System**: CMake
- **IDE**: VS Code with ESP-IDF extension
- **Connectivity**: Wi-Fi (Station mode), HTTP/Cloud data upload
- **Sensors**: LM35 (analog temperature)

---

## 🎯 Highlights

- ✅ Progressive learning path — starts from **GPIO basics** and builds up to **cloud connectivity**
- ✅ Real **ADC-to-temperature conversion** with sensor interfacing
- ✅ **Wi-Fi station mode** connection example with proof-of-output
- ✅ **Cloud data upload** pipeline over Wi-Fi
- ✅ Working demo **videos** included for hardware-level verification

---

## ⚙️ Getting Started

1. Install **[ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html)** and set up the toolchain (VS Code ESP-IDF extension recommended).
2. Clone the repository:
   ```bash
   git clone https://github.com/ANSHAD134/ESP32.git
   cd ESP32/Codes
   ```
3. Open any project folder (e.g. `Wifi_connect`) in VS Code.
4. Set the target chip and build:
   ```bash
   idf.py set-target esp32
   idf.py build
   ```
5. Flash to your ESP32 board and monitor output:
   ```bash
   idf.py -p (PORT) flash monitor
   ```

---

## 📄 License

Open for personal and educational use. Feel free to fork and learn from these examples. Add a `LICENSE` file (e.g. MIT) if you'd like to make the terms official.

---

<div align="center">

### 🙋 Author
**ANSHAD134** — [GitHub Profile](https://github.com/ANSHAD134)

</div>
