struct PinData {
  uint8_t pin;           
  uint32_t inter;      
  volatile uint32_t time; 
  bool state;             
};

PinData pins[] = {
  {3,  10000, 0, LOW}, 
  {5,   1000, 0, LOW}, 
  {6,    500, 0, LOW}, 
  {9,    100, 0, LOW}, 
  {10,    50, 0, LOW}  
};
const uint8_t numPins = sizeof(pins)/sizeof(PinData);

void setup() {
  for (uint8_t i = 0; i < numPins; i++) {
    pinMode(pins[i].pin, OUTPUT);
  }
}

void loop() {
  uint32_t currentTime = micros();

  for (uint8_t i = 0; i < numPins; i++) {
    if (currentTime - pins[i].time >= pins[i].inter) {
      pins[i].time = currentTime;
      
      pins[i].state = !pins[i].state;
      digitalWrite(pins[i].pin, pins[i].state);
    }
  }
}
