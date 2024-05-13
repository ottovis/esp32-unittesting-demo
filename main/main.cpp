/*
 * SPDX-FileCopyrightText: 2015-2021 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <gpio_hardware.h>
#include <status_led.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>

// define a TAG that holds the following __FILE__ __PRETTY_FUNCTION__ __LINE__
#define TAG() __FILE__, __LINE__, __PRETTY_FUNCTION__
#define TAGC "[%s:%d (%s)] %s"

extern "C" void app_main(void)
{
    gpio_interface &gpio_instance = gpio_hardware::Instance();
    status_led status_led_obj(gpio_instance, 0, 2, 42);

    ESP_LOGI("", TAGC, TAG(), "Setting status led to ERROR");
    status_led_obj.set_state(state_e::ERROR);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    ESP_LOGI(__FUNCTION__, "Setting status led to WARNING");
    status_led_obj.set_state(state_e::WARNING);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    ESP_LOGI(__FUNCTION__, "Setting status led to OK");
    status_led_obj.set_state(state_e::OK);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    ESP_LOGI(__FUNCTION__, "Setting status led to OFF");
    status_led_obj.set_state(state_e::OFF);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    return;
}