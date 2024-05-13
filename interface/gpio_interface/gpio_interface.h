#pragma once

#include <stdint.h>

enum class gpio_direction_e{
    INPUT,
    OUTPUT
};

class gpio_interface{
public:
    virtual int set_pin(int32_t pin, bool value);
    virtual int get_pin(int pin);
    virtual int set_direction(int pin, gpio_direction_e direction);
};