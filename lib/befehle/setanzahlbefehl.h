#ifndef SETANZAHLBEFEHL_H
#define SETANZAHLBEFEHL_H

#include "befehl.h"
#include "regalcontroller.h"

/**
 * @brief Dieser Befehl setzt die Anzahl der Ware auf der Palette.
 */
class SetAnzahlBefehl : public Befehl
{
public:
    SetAnzahlBefehl(const RegalController& rctrl);

    // Befehl interface
public:
    void exec(std::vector<std::string> &args) override;
    void help() override;
    const std::string& desc() const override;

private:
    const RegalController& m_rctrl;

};

#endif // SETANZAHLBEFEHL_H
