# 🌞 Automatic Solar Street Light using PIR & LDR (Arduino)

An automatic solar street light system that intelligently turns **ON at night when motion is detected** and remains **OFF during daytime**. This project uses an **LDR** to detect light intensity and a **PIR sensor** to detect motion, controlled by an **Arduino**.

---

## 📌 Features

* Automatic **day/night detection** using LDR
* **Motion-based lighting** using PIR sensor
* Saves power by turning OFF when no motion
* Simple, low-cost, and efficient design

---

## 🛠 Components Used

* Arduino Uno
* LDR (Light Dependent Resistor)
* PIR Motion Sensor
* Relay Module
* LED / Street Light
* Resistors & Connecting Wires

---

## 🔌 Pin Connections

| Component  | Arduino Pin |
| ---------- | ----------- |
| LDR        | A0          |
| PIR Sensor | D2          |
| Relay IN   | D9          |
| Relay VCC  | 5V          |
| Relay GND  | GND         |

---

## ⚙️ Working Principle

1. **LDR** checks ambient light level
2. If it is **night (low light)**:

   * PIR detects motion → Light turns **ON**
   * No motion → Light remains **OFF**
3. If it is **daytime**:

   * Light remains **OFF** regardless of motion

---

## 💻 Arduino Code

```cpp
// Solar Street Light using PIR and LDR

int ldrPin = A0;
int pirPin = 2;
int relayPin = 9;

int ldrThreshold = 500;

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);

  digitalWrite(relayPin, LOW);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  int motion = digitalRead(pirPin);

  if (ldrValue < ldrThreshold) {
    if (motion == HIGH) {
      digitalWrite(relayPin, HIGH);
    } else {
      digitalWrite(relayPin, LOW);
    }
  } else {
    digitalWrite(relayPin, LOW);
  }

  delay(200);
}
```

---

## 📷 Output

* **Daytime** → Light OFF
* **Night + Motion** → Light ON
* **Night + No Motion** → Light OFF

---

## 🚀 Applications

* Solar street lighting
* Smart campus lighting
* Garden & pathway lights
* Energy-efficient outdoor lighting



