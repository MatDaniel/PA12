#include "temperaturcontroller.h"

TemperaturController::TemperaturController(size_t size)
    : m_sensoren(size)
{

    // Setze die Temperatursensoren auf die vereinbarten Messwerte.

    for (TemperaturSensor& sensor : m_sensoren)
    {

        // Siehe: Pflichtenheft
        // Versprechen: Die Temperatursensoren auf 18°C zu begerenzen.
        sensor.setMax(18.0F);

    }

}

TemperaturSensor &TemperaturController::operator[](size_t index)
{
    return m_sensoren[index];
}

const TemperaturSensor &TemperaturController::operator[](size_t index) const
{
    return m_sensoren[index];
}

size_t TemperaturController::size() const noexcept
{
    return m_sensoren.size();
}
