\# LDR Light Sensor with Real-time Graph



ESP32 project đọc cảm biến ánh sáng LDR và hiển thị đồ thị real-time bằng Teleplot extension.



\## 🎯 Mục tiêu dự án



\- Đọc giá trị độ sáng từ quang trở (LDR) qua chân ADC

\- Xuất dữ liệu ra UART định dạng số nguyên (0-4095)

\- Sử dụng Teleplot extension để vẽ đồ thị real-time

\- Điều khiển LED theo ngưỡng ánh sáng



\## 🔌 Hardware Setup



\### Linh kiện cần thiết:

\- \*\*ESP32 DevKit v1\*\*

\- \*\*LDR (Light Dependent Resistor)\*\*

\- \*\*LED\*\* + điện trở 220Ω

\- \*\*Điện trở 10kΩ\*\* (pull-down cho LDR)

\- \*\*Breadboard và dây jumper\*\*



\### Sơ đồ kết nối:

```

ESP32 Pin  | Component        | Notes

-----------|------------------|------------------

GPIO 36    | LDR              | ADC1\_CH0 (Analog input)

GPIO 5     | LED              | Through 220Ω resistor

3.3V       | LDR + LED        | Power supply

GND        | Pull-down + LED  | Common ground

```



\### Circuit Diagram:

```

3.3V ──── LDR ──── GPIO 36 ──── 1kΩ ──── GND

&nbsp;                   

GPIO 5 ──── 1K ──── LED(+)

&nbsp;                      │

GND ───────────────────┘

```



\## 📊 Real-time Graph với Teleplot



\### Screenshot đồ thị ánh sáng:

!\[LDR Light Graph](screenshots/ldr\_graph.png)



\*Đồ thị hiển thị sự thay đổi cường độ ánh sáng theo thời gian thực\*



\## 💻 Software Features



\### Chức năng chính:

\- \*\*ADC Reading\*\*: Đọc 12-bit resolution (0-4095)

\- \*\*UART Output\*\*: Format `>light:value` cho Teleplot

\- \*\*LED Control\*\*: Tự động bật/tắt theo ngưỡng ánh sáng

\- \*\*Real-time Plot\*\*: Đồ thị smooth updates mỗi 100ms



\### Ngưỡng điều khiển:

| Điều kiện | ADC Value | LED Status | Mô tả |

|-----------|-----------|------------|-------|

| \*\*Tối\*\* | 0 - 1499 | OFF | Ánh sáng yếu |

| \*\*Sáng\*\* | 1500 - 4095 | ON | Đủ ánh sáng |



\## 🚀 Getting Started



\### Prerequisites:

\- \*\*PlatformIO IDE\*\* với ESP32 platform

\- \*\*Teleplot Extension\*\* cho VS Code

\- \*\*Hardware setup\*\* theo sơ đồ trên



\### Installation:

```bash

\# Clone repository

git clone https://github.com/Dao-Anh-Phuc/LDR\_Test.git

cd LDR\_Test



\# Build project

pio run



\# Upload to ESP32

pio run --target upload



\# Monitor serial output

pio device monitor

```



\### Sử dụng Teleplot:

1\. \*\*Install Teleplot extension\*\* trong VS Code

2\. \*\*Start serial monitor\*\*: `pio device monitor`

3\. \*\*Mở Teleplot\*\*: Ctrl+Shift+P → "Teleplot: Open"

4\. \*\*Select COM port\*\* của ESP32

5\. \*\*Xem đồ thị real-time!\*\*



\## 📈 Expected Output



\### Serial Monitor:

```

LDR Light Sensor - Real-time Plot Ready

Format: >light:value

>light:2345

>light:2356

>light:1234   <- Che tay lên LDR

>light:987    <- Tối hơn

>light:3456   <- Sáng trở lại

```



\### Teleplot Graph:

\- \*\*X-axis\*\*: Time (seconds)

\- \*\*Y-axis\*\*: Light intensity (0-4095)

\- \*\*Real-time updates\*\* mỗi 100ms

\- \*\*Smooth line chart\*\* với grid



\## 📊 Project Structure



```

LDR\_Test/

├── src/

│   └── main.cpp          # Main application code

├── screenshots/

│   └── ldr\_graph.png     # Teleplot screenshot

├── platformio.ini        # PlatformIO configuration

├── README.md            # Project documentation

└── .gitignore           # Git ignore rules

```



\## 🔧 Configuration



\### ADC Settings:

```cpp

\#define LDR\_PIN 36        // GPIO 36 (ADC1\_CH0)

analogReadResolution(12); // 12-bit ADC (0-4095)

```



\### Teleplot Format:

```cpp

Serial.print(">light:");  // Variable name cho Teleplot

Serial.println(ldrValue); // ADC value (0-4095)

```



\### LED Threshold:

```cpp

if (ldrValue < 1500) {    // Adjustable threshold

&nbsp;   digitalWrite(LED\_PIN, LOW);   // Dark condition

} else {

&nbsp;   digitalWrite(LED\_PIN, HIGH);  // Light condition

}

```



\## 🎓 Learning Objectives



Dự án này demo:

\- \*\*ESP32 ADC\*\* programming với 12-bit resolution

\- \*\*LDR sensor\*\* interfacing và voltage divider

\- \*\*Real-time data visualization\*\* với Teleplot

\- \*\*Serial communication\*\* cho debugging

\- \*\*Conditional LED control\*\* based on sensor input



\## 🔍 Technical Notes



\- \*\*GPIO 36\*\* là input-only pin, perfect cho analog reading

\- \*\*10kΩ pull-down\*\* tạo voltage divider với LDR

\- \*\*100ms sampling rate\*\* balance giữa responsiveness và stability

\- \*\*Teleplot format\*\* requires `>variable\_name:value`



\## 📄 License



This project is open source and available under the \[MIT License](LICENSE).



\## 👨‍💻 Author



Created by \*\*Dao Anh Phuc\*\* - ESP32 IoT Learning Series



---



\### 🔗 Related Projects

\- \[ESP32 Dual LED Controller](https://github.com/Dao-Anh-Phuc/B2\_Blink\_2\_led)

\- \[ESP32 OneButton Demo](https://github.com/Dao-Anh-Phuc/Test\_IOT)

