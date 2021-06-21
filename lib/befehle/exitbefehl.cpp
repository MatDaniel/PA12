#include "exitbefehl.h"
#include <iostream>
#include "umlaute.h"

ExitBefehl::ExitBefehl()
{
}

void ExitBefehl::exec(std::vector<std::string> &args)
{
    std::exit(0);
}

void ExitBefehl::help()
{
    std::cout << "exit @ Beendet das Programm." << std::endl;
}

static const std::string beschreibung = "Beendet das Programm.";
const std::string& ExitBefehl::desc() const
{
    return beschreibung;
}
