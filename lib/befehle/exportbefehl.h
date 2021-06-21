#ifndef EXPORTBEFEHL_H
#define EXPORTBEFEHL_H

#include "befehl.h"
#include "regalcontroller.h"

/**
 * @brief Dieser Befehl speichert die belegten oder defekten Paletten in eine CSV-Datei als Backup ab.
 */
class ExportBefehl : public Befehl
{
public:
    ExportBefehl(const RegalController& rctrl);

    // Befehl interface
public:
    void exec(std::vector<std::string> &args) override;
    void help() override;
    const std::string &desc() const override;

private:
    const RegalController& m_rctrl;
};

#endif // EXPORTBEFEHL_H
