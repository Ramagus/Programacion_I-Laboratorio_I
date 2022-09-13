#include "Conversion.h"

float convertirCelsius_A_Fahrenheit(float tempCelsius)
{
    float tempFahrenheit;

    tempFahrenheit = (tempCelsius * 9/5) + 32;

    return tempFahrenheit;
}

float convertirFahrenheit_A_Celsius(float tempFahrenheit)
{
    float tempCelsius;

    tempCelsius = (tempFahrenheit - 32) * 5/9;

    return tempCelsius;
}
