#include "exportbefehl.h"

#include <iostream>
#include <fstream>
#include "umlaute.h"
#include "ints.h"

ExportBefehl::ExportBefehl(const RegalController &rctrl)
    : m_rctrl(rctrl)
{
}

static bool cmp_ignore_case(const std::string& a, const std::string& b)
{
    if (a.size() == b.size())
    {
        for (szT i = 0; i < a.size(); i++)
        {
            if (std::tolower(a[i]) != std::tolower(b[i]))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

static bool cmp_free(Palette* pal)
{
    return pal->empty();
}

static bool cmp_empty(Palette* pal)
{
    return !pal->empty() && pal->anzahl() == 0;
}

static bool cmp_filled(Palette* pal)
{
    return !pal->empty() && pal->anzahl() > 0;
}

static bool cmp_defekt(Palette* pal)
{
    return pal->defekt();
}

void ExportBefehl::exec(std::vector<std::string> &args)
{
    if (args.size() == 0)
    {
        std::cout << "Fehler: Falsche Anzahl an Argumenten. F" << c_ue << "hren Sie `help export` f" << c_ue << "r eine ausf" << c_ue << "hrliche Benutzungshilfe aus." << std::endl;
    }

    bool(*cmp_func)(Palette*);
    if (cmp_ignore_case(args[0], "defekt"))
    {
        cmp_func = &cmp_defekt;
    }
    else if (cmp_ignore_case(args[0], "empty"))
    {
        cmp_func = &cmp_empty;
    }
    else if (cmp_ignore_case(args[0], "filled"))
    {
        cmp_func = &cmp_filled;
    }
    else if (cmp_ignore_case(args[0], "free"))
    {
        cmp_func = &cmp_free;
    }
    else
    {
        std::cout << "Fehler: Unerwarteter Parameter. F" << c_ue << "hre `help export` f" << c_ue << "r eine ausf" << c_ue << "hrliche Benutzungshilfe aus" << std::endl;
        return;
    }

    std::ofstream out(args[0] + ".csv");
    for (szT i = 0; i < m_rctrl.size(); i++)
    {
        Palette* pal = m_rctrl[i];
        if (cmp_func(pal))
        {
            out << '"' << i << "\";\"" << pal->anzahl() << "\";\"" << pal->ware() << "\";\"" << pal->lagerbedingungen() << "\";\"" << pal->defekt() << '"' << std::endl;
        }
    }

    out.close();
    std::string target_command = args[0] + ".csv";
    system(target_command.c_str());

}

void ExportBefehl::help()
{
    std::cout << "export free @ Speichert eine CSV-Datei `free.csv` im Arbeitsverzeichnis ab mit leeren Stellpl" << c_ae << "tzen" << std::endl
              << "export empty @ Speichert eine CSV-Datei `empty.csv` im Arbeitsverzeichnis ab mit leeren Paletten" << std::endl
              << "export filled @ Speichert eine CSV-Datei `filled.csv` im Arbeitsverzeichnis ab mit gef" << c_ue << "llten Paletten" << std::endl
              << "export defekt @ Speichert eine CSV-Datei `defekt.csv` im Arbeitsverzeichnis ab mit defekten Stellpl" << c_ae << "tzen" << std::endl;
}

static const std::string beschreibung = std::string("Speichert eine CSV-Datei mit den ausgew") + c_ae + "hlten Paletten ab.";
const std::string &ExportBefehl::desc() const
{
    return beschreibung;
}

