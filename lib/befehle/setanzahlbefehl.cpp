#include "setanzahlbefehl.h"
#include <iostream>
#include "umlaute.h"
#include "ints.h"

SetAnzahlBefehl::SetAnzahlBefehl(const RegalController& rctrl)
    : m_rctrl(rctrl)
{
}

void SetAnzahlBefehl::exec(std::vector<std::string> &args)
{
    try
    {

        if (args.size() < 2)
        {
            std::cout << "Fehler: Falsche Anzahl an Argumenten. F" << c_ue << "hren sie `help set-anzahl` f" << c_ue << "r eine ausf" << c_ue << "hrliche Benutzungshilfe aus." << std::endl;
        }
        else
        {

            // Bekomme alle Argumente
            szT index = std::stoull(args[0]);
            uiT anzahl = std::stoul(args[1]);

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
                std::cout << "Fehler: Die Palette ist leer. Kann nicht die Anzahl einer ung" << c_ue << "ltigen Ware festlegen!" << std::endl;

            }
            else
            {

                // Setze die Anzahl.
                palette->setAnzahl(anzahl);
                std::cout << "Die Palette " << index << " wurde erfolgreich auf " << anzahl << "x " << palette->ware() << " gesetzt!" << std::endl;

            }

        }

    }
    catch (...)
    {
        std::cout << "Fehler: Entweder ID oder Anzahl ist keine g" << c_ue << "ltige Nummer!" << std::endl;
    }
}

void SetAnzahlBefehl::help()
{
    std::cout << "set-anzahl <id> <anzahl> @ Setzt die Anzahl der Ware durch die ID." << std::endl
              << std::endl
              << "id: Die ID, welche {regal, reihe, zelle} repr" << c_ae << "sentiert." << std::endl
              << "anzahl: Die Anzahl der Ware, die sich auf der Palette befinden soll." << std::endl;
}

static const std::string beschreibung = "Setzt die Anzahl der Ware auf der Palette.";
const std::string& SetAnzahlBefehl::desc() const
{
    return beschreibung;
}
