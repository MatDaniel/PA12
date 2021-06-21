#include "updatetempsensorbefehl.h"
#include <iostream>
#include "umlaute.h"
#include "ints.h"

UpdateTempSensorBefehl::UpdateTempSensorBefehl(TemperaturController &tctrl)
    : m_tctrl(tctrl)
{
}

void UpdateTempSensorBefehl::exec(std::vector<std::string> &args)
{
    try
    {

        if (args.size() < 2)
        {
            std::cout << "Fehler: Falsche Anzahl an Argumenten. F" << c_ue << "hren sie `help update-temp` f" << c_ue << "r eine ausf" << c_ue << "hrliche Benutzungshilfe aus." << std::endl;
        }
        else
        {

            // Bekomme alle Argumente
            szT index = std::stoull(args[0]);
            float temp = std::stof(args[1]);

            // Überprüfe, ob der Sensor gültig ist.
            if (index >= m_tctrl.size())
            {

                // Gib Fehlermeldung aus.
                std::cout << "Fehler: Der Sensor ist ung" << c_ue << "ltig. " << c_UE << "berpr" << c_ue << "fen Sie Ihre Angaben." << std::endl;

            }
            else
            {

                // Lege Temperatur fest.
                m_tctrl[index].setCurrent(temp);
                std::cout << "Die Temperatur " << temp << " wurde erfolgreich im Sensor " << index << " eingestellt!" << std::endl;

            }

        }

    }
    catch (...)
    {
        std::cout << "Fehler: Sensor-ID ist keine g" << c_ue << "ltige Nummer!" << std::endl;
    }
}

void UpdateTempSensorBefehl::help()
{
    std::cout << "update-temp <tid> <temp> @ Setzt die jetzige Temperatur am Sensor fest." << std::endl
              << std::endl
              << "tid: Die ID des Sensors." << std::endl
              << "temp: Die Temperatur, die am Sensor gemessen wurde." << std::endl;
}

static const std::string beschreibung = "Aktualisiert die jetzige Temperatur am Sensor.";
const std::string& UpdateTempSensorBefehl::desc() const
{
    return beschreibung;
}
