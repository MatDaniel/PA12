#ifndef TEMPERATURSENSOR_H
#define TEMPERATURSENSOR_H

#include <string>
#include <limits>

/**
 * @brief Diese Klasse stellt einen Temperatursensor dar.
 *
 * Der Temperatursensor beinhaltet einen zulässigen Temperatur-Bereich.
 * Er kann prüfen, ob die Temperatur innerhalb oder außerhalb diesem Bereich liegt.
 */
class TemperaturSensor
{
public:

    /**
     * @brief Die kleinstmögliche Temperatur (d.h. kein Limit)
     */
    static constexpr float MIN_TEMPERATURE = -274.0F; // 0 Kelvin, actual -273.15...

    /**
     * @brief Die größtmögliche Temperatur (d.h. kein Limit)
     */
    static constexpr float MAX_TEMPERATURE = std::numeric_limits<float>::max();

    /**
     * @brief Erstellt eine Insatanz von TemperaturSensor
     * @param name Der Name des Temperatursensors.
     * @param minTemp Die minimale Temperatur.
     * @param maxTemp Die maximale Temperatur.
     */
    TemperaturSensor(float minTemp = MIN_TEMPERATURE, float maxTemp = MAX_TEMPERATURE);

    /**
     * @brief Prüft, ob `temp` innerhalb der zulässigen Parameter liegt.
     * @param temp Die Temperatur, die getestet werden soll.
     * @return Gibt `true` zurück, wenn die Temperatur gut ist, ansonsten `false`.
     */
    bool isInRange(float temp) const noexcept;

    /**
     * @brief Prüft, ob die jetzige Temperatur innerhalb der zulässigen Parameter liegt.
     * @return Gibt `true` zurück, wenn die Temperatur gut ist, ansonsten `false`.
     */
    bool isInRange() const noexcept;

    /**
     * @brief Setzt die minimale Temperatur.
     * @param value Die minimale Temperatur in Celsius.
     */
    void setMin(float value) noexcept;

    /**
     * @brief Gibt die minimale Temperatur zurück.
     * @return Die minimale Temperatur in Celsius.
     */
    float min() const noexcept;

    /**
     * @brief Setzt die maximale Temperatur.
     * @param value Die maximale Temperatur in Celsius.
     */
    void setMax(float value) noexcept;

    /**
     * @brief Gibt die maximale Temperatur zurück.
     * @return Die maximale Temperatur in Celsius.
     */
    float max() const noexcept;

    /**
     * @brief Setzt die jetzige Temperatur.
     * @param value Die jetzige Temperatur in Celsius.
     */
    void setCurrent(float value) noexcept;

    /**
     * @brief Gibt die jetzige Temperatur zurück.
     * @return Die jetzige Temperatur in Celsius.
     */
    float current() const noexcept;

private:
    float m_min, m_max, m_cur;

};

#endif // TEMPERATURSENSOR_H
