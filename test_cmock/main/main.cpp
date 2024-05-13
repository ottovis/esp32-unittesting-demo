/*
 * SPDX-FileCopyrightText: 2015-2021 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include <unity.h>

#define STRX(x) #x
#ifndef __FUNCTION__
#define __FUNCTION__ "unknown"
#endif
#define TAG __FUNCTION__ ":" STRX(__LINE__)

static void print_banner(const char *text)
{
    printf("\n#### %s #####\n\n", text);
}

extern "C" void app_main(void)
{
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    print_banner("Running all the registered tests");
    UNITY_BEGIN();
    unity_run_all_tests();
    UNITY_END();

    print_banner("Starting interactive test menu");
    /* This function will not return, and will be busy waiting for UART input.
     * Make sure that task watchdog is disabled if you use this function.
     */
    unity_run_menu();

    return;
}