#include <status_led.h>

#define RETURN_IF_ERROR(x) \
    if (x != 0)             \
    {                       \
        return x;           \
    }

status_led::status_led(gpio_interface &gpio, int red_pin, int green_pin, int blue_pin) : gpio(gpio), red_pin(red_pin), green_pin(green_pin), blue_pin(blue_pin)
{
    gpio.set_direction(red_pin, gpio_direction_e::OUTPUT);
    gpio.set_direction(green_pin, gpio_direction_e::OUTPUT);
    gpio.set_direction(blue_pin, gpio_direction_e::OUTPUT);
}

int status_led::set_state(state_e state)
{
    switch (state)
    {
    case state_e::ERROR:
        RETURN_IF_ERROR(gpio.set_pin(red_pin, true));
        RETURN_IF_ERROR(gpio.set_pin(green_pin, false));
        RETURN_IF_ERROR(gpio.set_pin(blue_pin, false));
        break;
    case state_e::WARNING:
        RETURN_IF_ERROR(gpio.set_pin(red_pin, true));
        RETURN_IF_ERROR(gpio.set_pin(green_pin, true));
        RETURN_IF_ERROR(gpio.set_pin(blue_pin, false));
        break;
    case state_e::OK:
        RETURN_IF_ERROR(gpio.set_pin(red_pin, false));
        RETURN_IF_ERROR(gpio.set_pin(green_pin, true));
        RETURN_IF_ERROR(gpio.set_pin(blue_pin, false));
        break;
    case state_e::OFF:
        RETURN_IF_ERROR(gpio.set_pin(red_pin, false));
        RETURN_IF_ERROR(gpio.set_pin(green_pin, false));
        RETURN_IF_ERROR(gpio.set_pin(blue_pin, false));
        break;
    default:
        return -1;
        break;
    }
    return 0;
}