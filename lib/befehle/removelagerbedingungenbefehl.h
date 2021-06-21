#ifndef REMOVELAGERBEDINGUNGENBEFEHL_H
#define REMOVELAGERBEDINGUNGENBEFEHL_H

#include "befehl.h"
#include "regalcontroller.h"

/**
 * @brief Dieser Befehl entfernt Lagerbedingungen von einer Ware/Palette.
 */
class RemoveLagerbedingungenBefehl : public Befehl
{
public:
    RemoveLagerbedingungenBefehl(const RegalController& rctrl);

    // Befehl interface
public:
    void exec(std::vector<std::string> &args) override;
    void help() override;
    const std::string& desc() const override;

private:
    const RegalController& m_rctrl;

};

#endif // REMOVELAGERBEDINGUNGENBEFEHL_H
