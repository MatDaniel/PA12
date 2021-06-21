#include "removelagerbedingungenbefehl.h"
#include <iostream>
#include "umlaute.h"
#include "ints.h"

RemoveLagerbedingungenBefehl::RemoveLagerbedingungenBefehl(const RegalController &rctrl)
    : m_rctrl(rctrl)
{
}

void RemoveLagerbedingungenBefehl::exec(std::vector<std::string> &args)
{
    try
    {

        if (args.size() == 0)
        {
            std::cout << "Fehler: Falsche Anzahl an Argumenten. F" << c_ue << "hren sie `help remove-lagerbedinungen` f" << c_ue << "r eine ausf" << c_ue << "hrliche Benutzungshilfe aus." << std::endl;
        }
        else
        {

            // Konvertiere das Argument in ein Index.
            szT index = std::stoull(args[0]);

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

                palette->setLagerbedingungen();
                std::cout << "Die Lagederbedingungen wurden erfolgreich von der Palette " << index << " entfernt!" << std::endl;

            }

        }

    }
    catch (...)
    {
        std::cout << "Fehler: Die ID ist keine g" << c_ue << "ltige Nummer!" << std::endl;
    }
}

void RemoveLagerbedingungenBefehl::help()
{
    std::cout << "remove-lagerbedinungen <id> @ Entfernt die Lagerbedingungen durch die ID." << std::endl
              << std::endl
              << "id: Die ID, welche {regal, reihe, zelle} repr" << c_ae << "sentiert." << std::endl;
}

static const std::string beschreibung = "Entfernt die Lagerbedinungen von der Palette.";
const std::string &RemoveLagerbedingungenBefehl::desc() const
{
    return beschreibung;
}
