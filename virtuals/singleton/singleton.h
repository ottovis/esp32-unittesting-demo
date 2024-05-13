#pragma once

/// @brief Wrapper class for the singleton pattern
/// @details The wrapped class will be static and only one instance of the class can be created.
/// This helps to prevent multiple instances of the same class where that does not make sense.
/// This should be used for classes that are used as a interface for a hardware component.
/// @tparam T The class that will be wrapped.
/// @warning The wrapped class must be instantiated before usage in a interupt context.
template <typename T> class Singleton
{
protected:
    Singleton() = default;

public:
    static T &Instance()
    {
        static T instance;
        return instance;
    }
};
