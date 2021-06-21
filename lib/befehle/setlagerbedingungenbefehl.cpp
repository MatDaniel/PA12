#include "setlagerbedingungenbefehl.h"
#include <iostream>
#include <sstream>
#include "umlaute.h"
#include "ints.h"

SetLagerbedingungenBefehl::SetLagerbedingungenBefehl(const RegalController& rctrl)
    : m_rctrl(rctrl)
{
}

void SetLagerbedingungenBefehl::exec(std::vector<std::string> &args)
{
    try
    {

        if (args.size() < 2)
        {
            std::cout << "Fehler: Falsche Anzahl an Argumenten. F" << c_ue << "hren sie `help set-lagerbedingungen` f" << c_ue << "r eine ausf" << c_ue << "hrliche Benutzungshilfe aus." << std::endl;
        }
        else
        {

            // Bekomme alle Argumente
            szT index = std::stoull(args[0]);

            // Erstelle den Bedingungs-String durch's Zusammenfügen der Argumente mit Abständen.
            std::stringstream sbedingungen;
            if (args.size() > 1)
            {
                sbedingungen << args[1];
                for (szT i = 2; i < args.size(); i++)
                {
                    sbedingungen << ' ' << args[i];
                }
            }
            const std::string bedingungen = sbedingungen.str();

            // Suche die Palette.
            Palette* palette = m_rctrl[index];

            // Überprüfe, ob die Palette gültig ist.
            if (palette == nullptr)
            {

                // Gib Fehlermeldung aus.
                std::cout << "Fehler: Die Palette ist ung" << c_ue << "ltig. " << c_UE << "berpr" << c_ue << "fen Sie Ihre Angaben." << std::endl;

            }
            // Überprüfe, ob die Palette leer ist.
            else if (palette->empty())
            {

                // Gib Fehlermeldung aus.
                std::cout << "Fehler: Die Palette ist leer. Kann keine Lagerbedingung auf eine ung" << c_ue << "ltigen Ware festlegen!" << std::endl;

            }
            else
            {

                // Setze die Bedingungen.
                palette->setLagerbedingungen(bedingungen);
                std::cout << "Die Lagerbedingungen \"" << bedingungen << "\" wurde erfolgreich der Palette " << index << " zugewiesen!" << std::endl;

            }

        }

    }
    catch (...)
    {
        std::cout << "Fehler: Entweder ID oder Anzahl ist keine g" << c_ue << "ltige Nummer!" << std::endl;
    }
}

void SetLagerbedingungenBefehl::help()
{
    std::cout << "set-lagerbedingungen <id> <bedingungen> @ Setzt die Lagerbedingungen durch die ID." << std::endl
              << std::endl
              << "id: Die ID, welche {regal, reihe, zelle} repr" << c_ae << "sentiert." << std::endl
              << "bedingungen: Die Lagerbedingungen der Palette." << std::endl;
}

static const std::string beschreibung = "Setzt die Lagerbedingungen der Ware auf der Palette.";
const std::string& SetLagerbedingungenBefehl::desc() const
{
    return beschreibung;
}

