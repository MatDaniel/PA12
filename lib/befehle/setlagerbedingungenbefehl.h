#ifndef SETLAGERBEDINGUNGENBEFEHL_H
#define SETLAGERBEDINGUNGENBEFEHL_H

#include "befehl.h"
#include "regalcontroller.h"

/**
 * @brief Dieser Befehl setzt die Lagerbedingungen einer Ware fest.
 */
class SetLagerbedingungenBefehl : public Befehl
{
public:
    SetLagerbedingungenBefehl(const RegalController& rctrl);

    // Befehl interface
public:
    void exec(std::vector<std::string> &args) override;
    void help() override;
    const std::string& desc() const override;

private:
    const RegalController& m_rctrl;

};

#endif // SETLAGERBEDINGUNGENBEFEHL_H
