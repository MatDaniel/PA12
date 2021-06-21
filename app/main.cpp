#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "ints.h"
#include "lagerhalle.h"

// Befehle
#include "befehl.h"
#include "befehle/getpalettebefehl.h"
#include "befehle/setwarebefehl.h"
#include "befehle/removewarebefehl.h"
#include "befehle/exitbefehl.h"
#include "befehle/setdefektbefehl.h"
#include "befehle/setanzahlbefehl.h"
#include "befehle/listtempsensorenbefehl.h"
#include "befehle/updatetempsensorbefehl.h"
#include "befehle/swappalettebefehl.h"
#include "befehle/transferpalettebefehl.h"
#include "befehle/setlagerbedingungenbefehl.h"
#include "befehle/removelagerbedingungenbefehl.h"
#include "befehle/backupbefehl.h"

// Typen Shortcuts
typedef std::map<std::string, Befehl*> BefehlMap;
typedef std::pair<std::string, Befehl*> BefehlPair;

// Eine Liste an Befehlen.
static BefehlMap befehle;

/**
 * @brief Sucht den Befehl über seinen Namne.
 * @param name Der Name des Befehls.
 * @return Gibt einen Zeiger des Befehls zurück. Wenn der Befehl nicht gefunden wurde, dann ist der Zeiger null.
 */
Befehl* finde_befehl(const std::string& name)
{

    // Wandelt den Namen des Befehls in Kleinbuchstaben um.
    std::string lname = name;
    for (char& c : lname) c = std::tolower(c);

    // Sucht den Befehl über den Namen.
    BefehlMap::const_iterator iter = befehle.find(lname);

    // Gibt das Ergebnis zurück.
    return iter == befehle.end() ? nullptr : iter->second;

}

int main(int argc, char *argv[])
{

    // Die Lagerhalle, die alle wichtigen Daten speichert.
    Lagerhalle halle;

    // Füllt die Map mit Befehlen auf.
    befehle["get-palette"] = new GetPaletteBefehl(halle.regalController());
    befehle["set-ware"] = new SetWareBefehl(halle.regalController());
    befehle["remove-ware"] = new RemoveWareBefehl(halle.regalController());
    befehle["set-defekt"] = new SetDefektBefehl(halle.regalController());
    befehle["set-anzahl"] = new SetAnzahlBefehl(halle.regalController());
    befehle["exit"] = new ExitBefehl();
    befehle["list-temp"] = new ListTempSensorenBefehl(halle.temperaturController());
    befehle["update-temp"] = new UpdateTempSensorBefehl(halle.temperaturController());
    befehle["swap-palette"] = new SwapPaletteBefehl(halle.regalController());
    befehle["transfer-palette"] = new TransferPaletteBefehl(halle.regalController());
    befehle["set-lagerbedingungen"] = new SetLagerbedingungenBefehl(halle.regalController());
    befehle["remove-lagerbedingungen"] = new RemoveLagerbedingungenBefehl(halle.regalController());
    befehle["backup"] = new BackupBefehl(halle.regalController());


    // Hier wird der rohe, unverarbeitete Befehl abgespeichert.
    std::string raw_command;

    // Hier wird der eigentliche Befehl abgespeichert.
    std::string command;

    // Hier werden die Argumente abgespeichert
    std::vector<std::string> args;

    while (true)
    {

        // Bereitet die Argumenteliste vor.
        args.clear();

        // Gib ein Befehls-Prefix aus, damit der Benutzer weiß,
        // wann er in der Lage ist Befehle einzugeben.
        std::cout << "> ";

        // Lese den eingegebenen Befehl ein.
        std::getline(std::cin, raw_command);

        // Finde den ersten Abstand, um daraus den Befehlsnamen zu schließen.
        szT pos = raw_command.find(' ');

        // Speichert den eigentlichen Befehl ab.
        command = raw_command.substr(0, pos);

        // Geht die übrigen Abstände durch und teilt diese in Argumente auf.
        while (pos != std::string::npos)
        {

            // Die alte Position wird hier abgespeichert.
            szT opos = pos + 1;

            // Versucht die nächste Position zu bekommen.
            pos = raw_command.find(' ', opos);

            // Fügt das Ergebnis zu den Argumenten hinzu.
            args.push_back(raw_command.substr(opos, pos - opos));

        }

        // Überprüfe, ob der Befehl ein Spezial-Befehl ist.
        if (command == "help")
        {

            // Prüft, ob der Befehl mitangegeben wurde.
            if (args.size() > 0)
            {

                // Sucht den Befehl
                Befehl* befehl = finde_befehl(args[0]);

                // Überprüft, ob der Befehl gefunden wurde.
                if (befehl != nullptr)
                {

                    // Gibt die Hilfe über den Befehl aus.
                    befehl->help();

                }
                else
                {

                    // Gibt eine Fehlermeldung zurück.
                    std::cout << "Fehler: Der Befehl \"" << args[0] << "\" konnte nicht gefunden werden!" << std::endl;

                }

            }
            else
            {

                // Gibt den Header der Auflistung aus.
                std::cout << std::endl << "-- Hilfe / Alle Befehle --" << std::endl << std::endl;

                // Gibt eine allgemeine Liste mit allen Befehlen zurück.
                for (const BefehlPair pair : befehle)
                {

                    // Gibt einen Befehl aus.
                    std::cout << pair.first << " @ " << pair.second->desc() << std::endl;

                }

                // Gibt den Footer der Auflistung aus.
                std::cout << std::endl << "-- Hilfe / Alle Befehle --" << std::endl << std::endl;

            }

        }
        else
        {

            // Sucht den Befehl
            Befehl* befehl = finde_befehl(command);

            // Überprüft, ob der Befehl gefunden wurde.
            if (befehl != nullptr)
            {

                // Führt den Befehl aus!
                befehl->exec(args);

            }
            else
            {

                // Gibt eine Fehlermeldung zurück.
                std::cout << "Fehler: Der Befehl \"" << command << "\" konnte nicht gefunden werden!" << std::endl;

            }

        }

    }

}
