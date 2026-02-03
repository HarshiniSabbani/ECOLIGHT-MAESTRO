# ECOLIGHT MAESTRO  
### Time & Intensity Adaptive Street Light Automation

## 📌 Overview
**EcoLight Maestro** is an embedded system project designed to automatically control street lights based on **fixed time schedules** and **real-time ambient light intensity**.  
The system ensures energy efficiency by turning ON street lights only when required, reducing unnecessary power consumption.

---

## 🎯 Objective
To automatically control street light LEDs using:
- **Time-based control** (Night hours: 6 PM – 6 AM)
- **Intensity-based control** using an LDR sensor

---

## ⚙️ System Description
- The system reads **current time and date** from the on-chip RTC of LPC2148.
- If the time lies between **18:00 (6 PM) and 06:00 (6 AM)**:
  - Ambient light intensity is measured using an **LDR via ADC**.
  - If intensity is **below a threshold**, LEDs are turned **ON**.
  - Otherwise, LEDs remain **OFF**.
- During daytime, the system only displays real-time information on the LCD.

---

## 🔧 RTC Configuration Feature
- If RTC time is incorrect, the user can trigger an **external interrupt**.
- A menu is displayed on the LCD:
  1. **Edit RTC Info**
  2. **Exit**
- Users can modify:
  - Hours, Minutes, Seconds
  - Day, Date, Month, Year
- All inputs are validated before updating RTC registers.

---

## 🧩 Block Diagram
*(Add block diagram image here if available)*

---

## 🛠️ Hardware Requirements
- LPC2148 Microcontroller  
- LCD Display  
- Keypad  
- LEDs  
- LDR (Light Dependent Resistor)  
- Buzzer  

---

## 💻 Software Requirements
- Embedded C  
- Keil C Compiler  
- Flash Magic  

---

## 🔄 Project Workflow
1. Initialize LCD, LEDs, Keypad, RTC, ADC, and External Interrupt.
2. Continuously read and display time/date on LCD.
3. During night hours:
   - Read LDR intensity using ADC.
   - Control street light LEDs accordingly.
4. Allow RTC editing through interrupt-based menu.
5. Resume normal operation after RTC update.

---

## 🌱 Applications
- Smart street lighting systems  
- Energy-efficient city infrastructure  
- Automated outdoor lighting  

---

## 🚀 Future Enhancements
- Wireless monitoring using IoT
- Solar-powered operation
- Automatic fault detection
- Cloud-based data logging

---

## 👩‍💻 Author
**Harshini Sabbani**  
Embedded Systems | ECE  

---

