#ifndef SETWAREBEFEHL_H
#define SETWAREBEFEHL_H

#include "befehl.h"
#include "regalcontroller.h"

/**
 * @brief Dieser Befehl setzt die Ware auf eine Palette.
 */
class SetWareBefehl : public Befehl
{
public:
    SetWareBefehl(const RegalController& rctrl);

    // Befehl interface
public:
    void exec(std::vector<std::string> &args) override;
    void help() override;
    const std::string& desc() const override;

private:
    const RegalController& m_rctrl;

};

#endif // SETWAREBEFEHL_H
