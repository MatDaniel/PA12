#ifndef TRANSFERPALETTEBEFEHL_H
#define TRANSFERPALETTEBEFEHL_H

#include "befehl.h"
#include "regalcontroller.h"

/**
 * @brief Dieser Befehl verschiebt eine Palette auf einen anderen Ort.
 * Beim Ziel, wird die alte Palette überschrieben.
 */
class TransferPaletteBefehl : public Befehl
{
public:
    TransferPaletteBefehl(const RegalController& rctrl);

    // Befehl interface
public:
    void exec(std::vector<std::string> &args) override;
    void help() override;
    const std::string &desc() const override;

private:
    const RegalController& m_rctrl;

};

#endif // TRANSFERPALETTEBEFEHL_H
