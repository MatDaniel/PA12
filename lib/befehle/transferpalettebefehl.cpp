#include "transferpalettebefehl.h"

#include <iostream>
#include "umlaute.h"
#include "ints.h"

TransferPaletteBefehl::TransferPaletteBefehl(const RegalController& rctrl)
    : m_rctrl(rctrl)
{
}

void TransferPaletteBefehl::exec(std::vector<std::string> &args)
{
    try
    {

        if (args.size() < 2)
        {
            std::cout << "Fehler: Falsche Anzahl an Argumenten. F" << c_ue << "hren sie `help swap-palette` f" << c_ue << "r eine ausf" << c_ue << "hrliche Benutzungshilfe aus." << std::endl;
        }
        else
        {

            // Bekomme alle Argumente
            szT a_index = std::stoull(args[0]);
            szT b_index = std::stoull(args[1]);

            // Suche die Palette.
            Palette* a_palette = m_rctrl[a_index];
            Palette* b_palette = m_rctrl[b_index];

            // Überprüfe, ob die Palette gültig ist.
            if (a_palette == nullptr || b_palette == nullptr)
            {

                // Gib Fehlermeldung aus.
                std::cout << "Fehler: Einer der Paletten ist ung" << c_ue << "ltig. " << c_UE << "berpr" << c_ue << "fen Sie Ihre Angaben." << std::endl;

            }
            else
            {

                bool a_defekt = a_palette->defekt(),
                     b_defekt = b_palette->defekt();

                *b_palette = *a_palette;
                *a_palette = Palette::EMPTY;

                a_palette->setDefekt(a_defekt);
                b_palette->setDefekt(b_defekt);

                std::cout << "Die Palette " << a_index << " wurde erfolgreich nach " << b_index << " verschoben!" << std::endl;

            }

        }

    }
    catch (...)
    {
        std::cout << "Fehler: Einer der IDs ist keine g" << c_ue << "ltige Nummer!" << std::endl;
    }
}

void TransferPaletteBefehl::help()
{
    std::cout << "transfer-palette <src-id> <dst-id> @ Verschiebt eine Palette von `src` nach `dst`." << std::endl
              << std::endl
              << "*-id: Die ID, welche {regal, reihe, zelle} repr" << c_ae << "sentiert." << std::endl
              << "src-*: Die Palette, welche verschoben werden soll" << std::endl
              << "dst-*: Das Ziel, wohin die Palette verschoben wird.";
}

static const std::string beschreibung = "Verschiebt eine Palette.";
const std::string &TransferPaletteBefehl::desc() const
{
    return beschreibung;
}
