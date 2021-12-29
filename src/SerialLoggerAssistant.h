#pragma once

#include <Assistant.h>
#include <Logger.h>

class SerialLoggerAssistant : public Logger, public Assistant {
    HardwareSerial &serial;
    unsigned int setup_serial;
   public:
    /**
     * @brief Construct a new Serial Logger Assistant object
     * 
     * @param serial serial port to use
     * @param setup_serial if >0, then serial.begin(setup_serial) is called on setup
     * @param set_default if true, then deflogger is set to this object
     */
    SerialLoggerAssistant(HardwareSerial &serial, unsigned int setup_serial = 0, bool set_default = true);
    void _setup();
    void _loop();
};
