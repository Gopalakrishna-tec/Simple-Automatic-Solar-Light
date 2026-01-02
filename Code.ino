#define PIR_PIN 2
#define LED_PIN 7
#define LDR_PIN A0

int threshold = 500;   // adjust based on your room light

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int ldrValue = analogRead(LDR_PIN);
  int motion   = digitalRead(PIR_PIN);

  Serial.print("LDR = ");
  Serial.print(ldrValue);

  // ---------- NIGHT ----------
  if (ldrValue > threshold) {           // Dark → Night
    digitalWrite(LED_PIN, LOW);         // Disable LED completely
    Serial.println("  NIGHT — Light Disabled");
  }

  // ---------- DAY ----------
  else {                                // Bright → Day
    Serial.print("  DAY ");

    if (motion == HIGH) {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("🚨 Motion Detected → LED ON");
      delay(2000);
    }
    else {
      digitalWrite(LED_PIN, LOW);
      Serial.println("No motion → LED OFF");
    }
  }

  delay(300);
}
