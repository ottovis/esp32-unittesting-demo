idf_component_register(
    SRCS
        "status_led_test.cpp"
    INCLUDE_DIRS
        "."
    REQUIRES
        gpio_interface
    PRIV_REQUIRES
        unity
        status_led
        gpio_mock
)
