#include "getpalettebefehl.h"

#include <iostream>
#include "umlaute.h"
#include "ints.h"

GetPaletteBefehl::GetPaletteBefehl(const RegalController &rctrl)
    : m_rctrl(rctrl)
{
}

static void printPaletteInfo(const Palette* palette, szT index, uiT regal, uiT reihe, uiT zelle)
{

    // Überprüfe, ob die Palette gültig ist.
    if (palette == nullptr)
    {

        // Gib Fehlermeldung aus.
        std::cout << "Fehler: Die Palette ist ung" << c_ue << "ltig. " << c_UE << "berpr" << c_ue << "fen Sie Ihre Angaben." << std::endl;

    }
    else
    {

        std::cout << "-- Informationen zur Palette " << index << " { " << regal << ", " << reihe << ", " << zelle << " } --" << std::endl;

        if (palette->empty())
        {
            std::cout << "Inhalt: Die Palette ist leer." << std::endl;
        }
        else
        {
            std::cout << "Inhalt: " << palette->anzahl() << "x " << palette->ware() << std::endl;
        }

        if (palette->hasLagerbedingungen())
        {
            std::cout << "Lagerbedingungen: " << palette->lagerbedingungen() << std::endl;
        }

        if (palette->defekt())
        {
            std::cout << "Warnung: Die Palette ist als `defekt` gekennzeichnet!" << std::endl;
        }

    }

}

void GetPaletteBefehl::exec(std::vector<std::string> &args)
{
    try
    {

        if (args.size() == 0 || args.size() == 2)
        {

            std::cout << "Fehler: Falsche Anzahl an Argumenten. F" << c_ue << "hren sie `help get-palette` f" << c_ue << "r eine ausf" << c_ue << "hrliche Benutzungshilfe aus." << std::endl;

        }
        else if (args.size() == 1)
        {

            // Konvertiere das Argument in ein Index.
            szT index = std::stoull(args[0]);

            // Suche die Palette.
            Palette* palette = m_rctrl[index];

            // Gibt Informationen über die Palette aus.
            printPaletteInfo(palette, index, m_rctrl.regal_of(index), m_rctrl.reihe_of(index), m_rctrl.zelle_of(index));

        }
        else
        {

            // Die Variabeln werden übersichtlich hier eingesetzt.
            uiT regal = std::stoul(args[0]),
                reihe = std::stoul(args[1]),
                zelle = std::stoul(args[2]);

            // Berechne den Index der Palette.
            szT index = m_rctrl.index_of(regal, reihe, zelle);

            // Suche die Palette.
            Palette* palette = m_rctrl[index];

            // Gibt Informationen über die Palette aus.
            printPaletteInfo(palette, index, regal, reihe, zelle);

        }

    }
    catch (...)
    {
        std::cout << "Fehler: Eins oder mehrere Ihrer Argumente scheinen keine Nummern zu sein!" << std::endl;
    }
}

void GetPaletteBefehl::help()
{
    std::cout << "get-palette <id> @ Bekommt die Palette durch die ID." << std::endl
              << "get-palette <regal> <reihe> <zelle> @ Bekommt die Palette durch's Konstrukt" << std::endl
              << std::endl
              << "id: Die ID, welche {regal, reihe, zelle} repr" << c_ae << "sentiert." << std::endl
              << "regal: Das Regal, auf dem sich die Palette befindet." << std::endl
              << "reihe: Die Reihe, in der sich die Palette befindet." << std::endl
              << "zelle: Die Zelle, in der sich die Palette befindet." << std::endl;

}

static const std::string beschreibung = "Gibt Informationen zur Palette aus.";
const std::string& GetPaletteBefehl::desc() const
{
    return beschreibung;
}
