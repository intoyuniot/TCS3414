// Connection for TCS3414 sensor
// Connect sensor GND to Core GND
// Connect sensor VDD to 3.3V
// Connect sensor SCL to D9
// Connect sensor SDA to D8
// Connect a 10K resistor from SCL (clock) to 3.3V (power)
// Connect a 10K resistor from SDA (clock) to 3.3V (power)

#include <TCS3414.h>

TCS3414 sensor;

void setup()
{
    Serial.begin(115200);
    Serial.println("TCS3414 Sensor Example");

    if (!sensor.begin())
    {
        Serial.println("No TCS3414 detected...");
        while (1);
    }

    Serial.print("Part number: ");
    Serial.println(sensor.getPartNumber());
    Serial.print("Revision number: ");
    Serial.println(sensor.getRevisionNumber());
}

void loop()
{
    uint32_t lux = sensor.getLux();
    Serial.print("Lux: ");
    Serial.println(lux);
    delay(1000);
}
