#ifndef LISTTEMPSENSORENBEFEHL_H
#define LISTTEMPSENSORENBEFEHL_H

#include "befehl.h"
#include "temperaturcontroller.h"

/**
 * @brief Dieser Befehl listet alle Temperatur-Sensoren.
 */
class ListTempSensorenBefehl : public Befehl
{
public:
    ListTempSensorenBefehl(const TemperaturController& tctrl);

    // Befehl interface
public:
    void exec(std::vector<std::string> &args) override;
    void help() override;
    const std::string &desc() const override;

private:
    const TemperaturController& m_tctrl;

};

#endif // LISTTEMPSENSORENBEFEHL_H
