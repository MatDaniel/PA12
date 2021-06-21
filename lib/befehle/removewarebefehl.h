#ifndef REMOVEWAREBEFEHL_H
#define REMOVEWAREBEFEHL_H

#include "befehl.h"
#include "regalcontroller.h"

/**
 * @brief Dieser Befehl entfernt die Ware von einer Palette.
 */
class RemoveWareBefehl : public Befehl
{
public:
    RemoveWareBefehl(const RegalController& rctrl);

    // Befehl interface
public:
    void exec(std::vector<std::string> &args) override;
    void help() override;
    const std::string& desc() const override;

private:
    const RegalController& m_rctrl;

};

#endif // REMOVEWAREBEFEHL_H
