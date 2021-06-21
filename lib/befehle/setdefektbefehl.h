#ifndef SETDEFEKTBEFEHL_H
#define SETDEFEKTBEFEHL_H

#include "befehl.h"
#include "regalcontroller.h"

/**
 * @brief Dieser Befehl schaltet die Defekt-Markierung.
 */
class SetDefektBefehl : public Befehl
{
public:
    SetDefektBefehl(const RegalController& rctrl);

    // Befehl interface
public:
    void exec(std::vector<std::string> &args) override;
    void help() override;
    const std::string& desc() const override;

private:
    const RegalController& m_rctrl;
};

#endif // SETDEFEKTBEFEHL_H
