# 🚧 IoT-Based Manhole Monitoring System

An Internet of Things (IoT) project designed to monitor the environmental conditions inside urban manholes in real time. This system detects harmful gases, smoke, abnormal pressure, and temperature levels using multiple sensors connected to a NodeMCU microcontroller. The collected data is transmitted to the cloud via Wi-Fi using **ThingSpeak**, enabling authorities to prevent hazards and ensure worker safety.

---

## 📦 Project Features

- Real-time gas and smoke detection
- Pressure and temperature monitoring
- Cloud data visualization using **ThingSpeak**
- Alerts for abnormal conditions
- Low-cost and scalable hardware setup

---

## 🧰 Hardware Components Used

| Component               | Description                                   |
|-------------------------|-----------------------------------------------|
| **NodeMCU CP2102**      | ESP8266-based microcontroller with Wi-Fi      |
| **BMP180**              | Barometric pressure sensor                    |
| **DHT11**               | Digital temperature and humidity sensor       |
| **MQ-7**                | Gas sensor (Carbon Monoxide detection)        |
| **MQ-3**                | Smoke sensor (alcohol, methane, benzene)      |
| Breadboard & Jumpers    | For prototyping connections                   |
| USB Type-B Cable        | For powering and programming the NodeMCU      |

---

## 🔌 Circuit Connections

| Sensor      | VCC      | GND      | Signal Pin (NodeMCU) |
|-------------|----------|----------|------------------------|
| **DHT11**   | 3.3V     | GND      | D3 (GPIO 0)            |
| **BMP180**  | 3.3V     | GND      | SDA → D2, SCL → D1     |
| **MQ-7**    | 3.3V     | GND      | A0 (Analog input)      |
| **MQ-3**    | 3.3V     | GND      | D5 (GPIO 14) or A0     |

> ⚠️ **Note:** NodeMCU has only one analog input (A0). Use digital mode or a multiplexer if needed.

---

## ☁️ ThingSpeak Integration

The NodeMCU uses its built-in Wi-Fi to send data to **ThingSpeak**, an IoT analytics platform.

### 📋 Steps:
1. Create a free account on [ThingSpeak](https://thingspeak.com/)
2. Create a new **Channel**
3. Add 4 fields:
   - Field 1: Gas Level (MQ-7)
   - Field 2: Smoke Level (MQ-3)
   - Field 3: Temperature (DHT11)
   - Field 4: Pressure (BMP180)
4. Copy the **Write API Key**
5. In the Arduino code, replace `"YOUR_API_KEY"` with your actual key.
   ![Screenshot 2024-09-30 213628](https://github.com/user-attachments/assets/1b253121-39f4-48e4-99ae-726bc1e8e3c2)


---

## 🔁 How It Works

1. **Sensor Data Collection**
   - The sensors collect real-time data on gas, smoke, temperature, and pressure.

2. **Microcontroller Processing**
   - NodeMCU reads the values, processes thresholds, and prepares data.

3. **Wi-Fi Connectivity**
   - NodeMCU connects to the Wi-Fi and transmits data to **ThingSpeak** every 15 seconds.

4. **Cloud Visualization**
   - On the ThingSpeak dashboard, the user can monitor live charts of sensor data.

5. **Alerts (Future Enhancement)**
   - Thresholds can trigger email/SMS alerts using IFTTT or ThingSpeak alerts.

---

## 📊 Sample Output on ThingSpeak

- Line chart showing gas concentration
- Temperature vs. Time graph
- Pressure changes indicating flooding or blockage
- Smoke level spikes

![image](https://github.com/user-attachments/assets/90070a5b-1988-460c-833d-cf4af99045f8)


---

## 🧪 Future Improvements

- Add liveness alert via buzzer or mobile notifications
- Integrate with municipal safety dashboards
- Implement solar power for outdoor deployment
- Waterproof sensor housing

---

🙋 Developed By
Lokesh Varan
|Final Year B.Tech IT | Sathyabama University
💻 GitHub: LOKI-DOKI
📫 Email: *lokeshvaranlokeshvaran98@example.com*

