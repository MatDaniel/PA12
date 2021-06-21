#include "swappalettebefehl.h"
#include <iostream>
#include "umlaute.h"
#include "ints.h"

SwapPaletteBefehl::SwapPaletteBefehl(const RegalController& rctrl)
    : m_rctrl(rctrl)
{
}

void SwapPaletteBefehl::exec(std::vector<std::string> &args)
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

                bool a_defekt = a_palette->defekt(), b_defekt = b_palette->defekt();
                std::swap(*a_palette, *b_palette);

                a_palette->setDefekt(a_defekt);
                b_palette->setDefekt(b_defekt);

                std::cout << "Die Palette " << a_index << " und " << b_index << " wurden erfolgreich getauscht!" << std::endl;

            }

        }

    }
    catch (...)
    {
        std::cout << "Fehler: Einer der IDs ist keine g" << c_ue << "ltige Nummer!" << std::endl;
    }
}

void SwapPaletteBefehl::help()
{
    std::cout << "swap-palette <a-id> <b-id> @ Wechselt die Position der zwei Paletten." << std::endl
              << std::endl
              << "a/b-id: Die ID, welche {regal, reihe, zelle} repr" << c_ae << "sentiert." << std::endl;
}

static const std::string beschreibung = "Wechselt die Position zweier Paletten.";
const std::string &SwapPaletteBefehl::desc() const
{
    return beschreibung;
}
