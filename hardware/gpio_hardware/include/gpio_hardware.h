#pragma once

#include <singleton.h>
#include "gpio_interface.h"

class gpio_hardware : public gpio_interface, public Singleton<gpio_hardware>{
public:
    int set_pin(int32_t pin, bool value) override;
    int set_direction(int pin, gpio_direction_e direction) override;
};