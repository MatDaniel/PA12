#include "removewarebefehl.h"
#include <iostream>
#include "umlaute.h"
#include "ints.h"

RemoveWareBefehl::RemoveWareBefehl(const RegalController& rctrl)
    : m_rctrl(rctrl)
{
}

void RemoveWareBefehl::exec(std::vector<std::string> &args)
{
    try
    {

        if (args.size() == 0)
        {
            std::cout << "Fehler: Falsche Anzahl an Argumenten. F" << c_ue << "hren sie `help remove-ware` f" << c_ue << "r eine ausf" << c_ue << "hrliche Benutzungshilfe aus." << std::endl;
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

                palette->setWare();
                palette->setAnzahl(0);
                palette->setLagerbedingungen();
                std::cout << "Die Palette " << index << " wurde erfolgreich geleert!" << std::endl;

            }

        }

    }
    catch (...)
    {
        std::cout << "Fehler: Die ID ist keine g" << c_ue << "ltige Nummer!" << std::endl;
    }
}

void RemoveWareBefehl::help()
{
    std::cout << "remove-ware <id> @ Entfernt die Ware durch die ID." << std::endl
              << std::endl
              << "id: Die ID, welche {regal, reihe, zelle} repr" << c_ae << "sentiert." << std::endl;
}

static const std::string beschreibung = "Entfernt die Ware von der Palette.";
const std::string& RemoveWareBefehl::desc() const
{
    return beschreibung;
}
