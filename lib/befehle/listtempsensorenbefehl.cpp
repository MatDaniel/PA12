#include "listtempsensorenbefehl.h"
#include <iostream>
#include "umlaute.h"
#include "ints.h"

ListTempSensorenBefehl::ListTempSensorenBefehl(const TemperaturController &tctrl)
    : m_tctrl(tctrl)
{
}

void ListTempSensorenBefehl::exec(std::vector<std::string> &args)
{
    std::cout << std::endl << "-- Temperatursensoren --" << std::endl << std::endl;

    for (szT i = 0; i < m_tctrl.size(); i++)
    {
        std::cout << '[' << i << "] ";
        if (m_tctrl[i].isInRange())
        {
            std::cout << "[OKAY]: ";
        }
        else
        {
            std::cout << "[WARN]: ";
        }
        std::cout << m_tctrl[i].current() << std::endl;
    }

    std::cout << std::endl << "-- Temperatursensoren --" << std::endl << std::endl;
}

void ListTempSensorenBefehl::help()
{
    std::cout << "list-temp @ Listet alle Temperatur-Sensoren mit dem jeweiligen Status auf." << std::endl;
}

static const std::string beschreibung = "Listet die Temperaturn an den Sensoren auf.";
const std::string &ListTempSensorenBefehl::desc() const
{
    return beschreibung;
}
