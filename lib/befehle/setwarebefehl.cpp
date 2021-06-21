#include "setwarebefehl.h"
#include <iostream>
#include "umlaute.h"
#include "ints.h"

SetWareBefehl::SetWareBefehl(const RegalController& rctrl)
    : m_rctrl(rctrl)
{
}

void SetWareBefehl::exec(std::vector<std::string> &args)
{
    try
    {

        if (args.size() < 2)
        {
            std::cout << "Fehler: Falsche Anzahl an Argumenten. F" << c_ue << "hren sie `help set-ware` f" << c_ue << "r eine ausf" << c_ue << "hrliche Benutzungshilfe aus." << std::endl;
        }
        else
        {

            // Bekomme alle Argumente
            szT index = std::stoull(args[0]);
            std::string& ware = args[1];
            uiT anzahl = args.size() > 2 ? std::stoul(args[2]) : 1;

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

                // Ersetze Gänsefüßchen durch Abstände
                for (char& c : ware) if (c == '"') c = ' ';

                // Setze Sachen
                palette->setWare(ware);
                palette->setAnzahl(anzahl);
                palette->setLagerbedingungen();
                std::cout << "Auf die Palette " << index << " wurde erfolgreich " << anzahl << "x " << ware << " eingelagert!" << std::endl;

            }

        }

    }
    catch (...)
    {
        std::cout << "Fehler: Entweder ID oder Anzahl ist keine g" << c_ue << "ltige Nummer!" << std::endl;
    }
}

void SetWareBefehl::help()
{
    std::cout << "set-ware <id> <ware> [anzahl = 1] @ " << c_UE << "berschreibt die jetzige Ware." << std::endl
              << std::endl
              << "id: Die ID, welche {regal, reihe, zelle} repr" << c_ae << "sentiert." << std::endl
              << "ware: Die Ware, die eingelagert werden soll." << std::endl
              << "anzahl: Die Anzahl der Ware, die sich auf der Palette befindet." << std::endl;

}

static const std::string beschreibung = "Setzt die Ware auf der Palette.";
const std::string& SetWareBefehl::desc() const
{
    return beschreibung;
}
