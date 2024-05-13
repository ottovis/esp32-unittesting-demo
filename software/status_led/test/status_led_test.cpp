/* test_mean.c: Implementation of a testable component.

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include "unity.h"
#include "status_led.h"
#include "gpio_mock.h"

TEST_CASE("Status led interface host", "")
{
    gpio_interface &gpio_instance = gpio_mock::Instance();
    status_led status_led_obj(gpio_instance, 0, 2, 42);

    TEST_ASSERT_EQUAL(0, status_led_obj.set_state(state_e::ERROR));
    TEST_ASSERT_EQUAL(0, status_led_obj.set_state(state_e::WARNING));
    TEST_ASSERT_EQUAL(0, status_led_obj.set_state(state_e::OK));
    TEST_ASSERT_EQUAL(0, status_led_obj.set_state(state_e::OFF));
    TEST_ASSERT_EQUAL(-1, status_led_obj.set_state(static_cast<state_e>(-1)));
}
