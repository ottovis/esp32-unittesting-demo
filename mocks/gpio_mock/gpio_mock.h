#pragma once

#include <singleton.h>
#include "gpio_interface.h"

class gpio_mock : public gpio_interface, public Singleton<gpio_mock>{
public:
    int set_pin(int32_t pin, bool value) override;
    int set_direction(int pin, gpio_direction_e direction) override;
};