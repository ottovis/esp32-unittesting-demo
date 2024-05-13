#include "gpio_hardware.h"
#include <driver/gpio.h>


int gpio_hardware::set_pin(int32_t pin, bool value)
{
    return gpio_set_level((gpio_num_t)pin, value);
}

int gpio_hardware::set_direction(int pin, gpio_direction_e direction)
{
    gpio_config_t io_conf;
    io_conf.pin_bit_mask = (1ULL << pin);
    io_conf.mode = (direction == gpio_direction_e::INPUT) ? GPIO_MODE_INPUT : GPIO_MODE_OUTPUT;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    return gpio_config(&io_conf);
}
