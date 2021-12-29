#include <Arduino.h>
#include <SerialLoggerAssistant.h>

// -------------------------------------------------------------------------------- SerialLoggerAssistant
SerialLoggerAssistant::SerialLoggerAssistant(HardwareSerial &serial, unsigned int setup_serial, bool set_default)
    : serial(serial), setup_serial(setup_serial) {
    if (set_default) deflogger = *this;
}

void SerialLoggerAssistant::_setup() {
    if (setup_serial)
        serial.begin(setup_serial);
    _loop();
}

void SerialLoggerAssistant::_loop() {
    if (!buffer_empty() && serial.available()) {
        if (serial.print(logger_buffer))
            if (buffer_full())
                create_overflow_message();
            else
                clear_buffer();
        else
            WARN("Serial send failed");
    }
}
