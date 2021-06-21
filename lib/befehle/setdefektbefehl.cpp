#include "setdefektbefehl.h"
#include <iostream>
#include "umlaute.h"
#include "ints.h"

SetDefektBefehl::SetDefektBefehl(const RegalController& rctrl)
    : m_rctrl(rctrl)
{
}

void SetDefektBefehl::exec(std::vector<std::string> &args)
{
    try
    {

        if (args.size() < 2)
        {
            std::cout << "Fehler: Falsche Anzahl an Argumenten. F" << c_ue << "hren sie `help set-defekt` f" << c_ue << "r eine ausf" << c_ue << "hrliche Benutzungshilfe aus." << std::endl;
        }
        else
        {

            // Bekomme alle Argumente
            szT index = std::stoull(args[0]);
            std::string& defekt_str = args[1];
            for (char& c : defekt_str) c = std::tolower(c);
            bool defekt;

            if (defekt_str == "true" || defekt_str == "wahr" || defekt_str == "ja" || defekt_str == "yes")
            {
                defekt = true;
            }
            else if (defekt_str == "false" || defekt_str == "falsch" || defekt_str == "nein" || defekt_str == "no")
            {
                defekt = false;
            }
            else
            {
                std::cout << "Fehler: \"" << defekt_str << "\" kann nicht als `true` oder `false` ermittelt werden." << std::endl;
                return;
            }

            // Suche die Palette.
            Palette* palette = m_rctrl[index];

            // Überprüfe, ob die Palette gültig ist.
            if (palette == nullptr)
            {

                // Gib Fehlermeldung aus.
                std::cout << "Fehler: Die Palette ist ung" << c_ue << "ltig. " << c_UE << "berpr" << c_ue << "fen Sie Ihre Angaben." << std::endl;

            }
            else
            {

                palette->setDefekt(defekt);

                if (defekt)
                {
                    std::cout << "Die Palette " << index << " wurde erfolgreich als defekt markiert!" << std::endl;
                }
                else
                {
                    std::cout << "Defekt-Markierung wurde von der Palette " << index << " erfolgreich entfernt!" << std::endl;
                }


            }

        }

    }
    catch (...)
    {
        std::cout << "Fehler: Entweder ID oder Anzahl ist keine g" << c_ue << "ltige Nummer!" << std::endl;
    }
}

void SetDefektBefehl::help()
{
    std::cout << "set-defekt <id> <defekt> @ Setzt/Entfernt die Defekt-Markierung." << std::endl
              << std::endl
              << "id: Die ID, welche {regal, reihe, zelle} repr" << c_ae << "sentiert." << std::endl
              << "defekt: `true` = defekt; `false` = nicht defekt" << std::endl;

}

static const std::string beschreibung = "Setzt die Defekt-Markierung der Palette.";
const std::string& SetDefektBefehl::desc() const
{
    return beschreibung;
}
