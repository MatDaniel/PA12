#ifndef TEMPERATURCONTROLLER_H
#define TEMPERATURCONTROLLER_H

#include <vector>
#include "temperatursensor.h"

/**
 * @brief Diese Klasse kümmert sich um die Temperatur-Sensoren.
 */
class TemperaturController
{
public:
    TemperaturController(size_t size);

public:
    TemperaturSensor& operator[](size_t index);
    const TemperaturSensor& operator[](size_t index) const;
    size_t size() const noexcept;

private:
    std::vector<TemperaturSensor> m_sensoren;

};

#endif // TEMPERATURCONTROLLER_H
