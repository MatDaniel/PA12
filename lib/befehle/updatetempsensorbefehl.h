#ifndef UPDATETEMPSENSORBEFEHL_H
#define UPDATETEMPSENSORBEFEHL_H

#include "befehl.h"
#include "temperaturcontroller.h"

/**
 * @brief Dieser Befehl aktualisiert die aktuelle Temperatur an einem Sensor.
 */
class UpdateTempSensorBefehl : public Befehl
{
public:
    UpdateTempSensorBefehl(TemperaturController& tctrl);

    // Befehl interface
public:
    void exec(std::vector<std::string> &args) override;
    void help() override;
    const std::string &desc() const override;

private:
    TemperaturController& m_tctrl;

};

#endif // UPDATETEMPSENSORBEFEHL_H
