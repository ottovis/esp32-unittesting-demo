/* test_mean.c: Implementation of a testable component.

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include "unity.h"
#include "gpio_hardware.h"

extern "C"
{
#include <Mockgpio.h>
}

TEST_CASE("Gpio hardware interface", "")
{
    auto &gpio_instance = gpio_hardware::Instance();

    gpio_config_IgnoreAndReturn(0);
    TEST_ASSERT_EQUAL(0, gpio_instance.set_direction(10, gpio_direction_e::OUTPUT));
    TEST_ASSERT_EQUAL(0, gpio_instance.set_pin(10, true));
}
