void setup()
{
    // USB Serial Monitor
    Serial.begin(9600);

    // UART from STM32
    // RX = GPIO16
    // TX = GPIO17
    Serial2.begin(9600, SERIAL_8N1, 16, 17);

    Serial.println("================================");
    Serial.println("ESP32 TRAFFIC MONITOR READY");
