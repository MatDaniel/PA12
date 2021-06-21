#ifndef LAGERHALLE_H
#define LAGERHALLE_H

#include "temperaturcontroller.h"
#include "regalcontroller.h"

/**
 * @brief Das Hauptobjekt, welches alle wichtigen Controller lagert und so eine Lagerhalle darstellt.
 */
class Lagerhalle
{
public:
    Lagerhalle();

public:
    TemperaturController &temperaturController();
    RegalController &regalController();

    const TemperaturController &temperaturController() const;
    const RegalController &regalController() const;

private:
    TemperaturController m_temperaturController;
    RegalController m_regalController;

};

#endif // LAGERHALLE_H
