

#include <gpio_interface.h>

enum class state_e {
    ERROR,
    WARNING,
    OK,
    OFF
};

class status_led {
private:
    gpio_interface &gpio;
    int red_pin;
    int green_pin;
    int blue_pin;
public:
    status_led(gpio_interface &gpio, int red_pin, int green_pin, int blue_pin);

    /// @brief Set the state of the status led
    /// @attention error will be red, warning will be yellow, ok will be green
    /// @param state 
    /// @return int 0 if success, -1 if invalid state
    int set_state(state_e state);
};