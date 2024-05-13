#include "gpio_mock.h"


int gpio_mock::set_pin(int32_t pin, bool value)
{
    return 0;
}

int gpio_mock::set_direction(int pin, gpio_direction_e direction)
{
    return 0;
}
