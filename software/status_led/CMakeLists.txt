idf_component_register(
    SRCS
        "status_led.cpp"
    INCLUDE_DIRS
        "include"
    REQUIRES
        gpio_interface
)