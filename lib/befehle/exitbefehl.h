#ifndef EXITBEFEHL_H
#define EXITBEFEHL_H

#include "befehl.h"

/**
 * @brief Dieser Befehl beendet das Programm.
 */
class ExitBefehl : public Befehl
{
public:
    ExitBefehl();

    // Befehl interface
public:
    void exec(std::vector<std::string> &args) override;
    void help() override;
    const std::string &desc() const override;

};

#endif // EXITBEFEHL_H
