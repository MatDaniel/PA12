#include "temperatursensor.h"

TemperaturSensor::TemperaturSensor(float minTemp, float maxTemp)
    : m_min(minTemp)
    , m_max(maxTemp)
    , m_cur(0.0F)
{
}

bool TemperaturSensor::isInRange(float temp) const noexcept
{
    return temp >= m_min && temp <= m_max;
}

bool TemperaturSensor::isInRange() const noexcept
{
    return isInRange(m_cur);
}

void TemperaturSensor::setMin(float value) noexcept
{
    m_min = value;
}

float TemperaturSensor::min() const noexcept
{
    return m_min;
}

void TemperaturSensor::setMax(float value) noexcept
{
    m_max = value;
}

float TemperaturSensor::max() const noexcept
{
    return m_max;
}

void TemperaturSensor::setCurrent(float value) noexcept
{
    m_cur = value;
}

float TemperaturSensor::current() const noexcept
{
    return m_cur;
}
