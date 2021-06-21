#include "lagerhalle.h"

Lagerhalle::Lagerhalle()
    : m_temperaturController(10)
    , m_regalController(20, 20, 50)
{
}

TemperaturController &Lagerhalle::temperaturController()
{
    return m_temperaturController;
}

RegalController &Lagerhalle::regalController()
{
    return m_regalController;
}

const TemperaturController &Lagerhalle::temperaturController() const
{
    return m_temperaturController;
}

const RegalController &Lagerhalle::regalController() const
{
    return m_regalController;
}
