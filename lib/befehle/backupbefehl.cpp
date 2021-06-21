#include "backupbefehl.h"
#include <iostream>
#include <fstream>
#include "umlaute.h"
#include "ints.h"

BackupBefehl::BackupBefehl(const RegalController &rctrl)
    : m_rctrl(rctrl)
{
}

void BackupBefehl::exec(std::vector<std::string> &args)
{
    std::ofstream out("paletten.csv");
    for (szT i = 0; i < m_rctrl.size(); i++)
    {
        Palette* pal = m_rctrl[i];
        if (!(*pal == Palette::EMPTY))
        {
            out << '"' << i << "\";\"" << pal->anzahl() << "\";\"" << pal->ware() << "\";\"" << pal->lagerbedingungen() << "\";\"" << pal->defekt() << '"' << std::endl;
        }
    }
}

void BackupBefehl::help()
{
    std::cout << "backup @ Speichert eine CSV-Datei als Backup ab." << std::endl;
}

static const std::string beschreibung = "Speichert eine CSV-Datei als Backup ab.";
const std::string &BackupBefehl::desc() const
{

}
