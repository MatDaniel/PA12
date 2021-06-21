#ifndef SWAPPALETTEBEFEHL_H
#define SWAPPALETTEBEFEHL_H

#include "befehl.h"
#include "regalcontroller.h"

/**
 * @brief Dieser Befehl tauscht die Plätze zweier Paletten.
 */
class SwapPaletteBefehl : public Befehl
{
public:
    SwapPaletteBefehl(const RegalController& rctrl);

    // Befehl interface
public:
    void exec(std::vector<std::string> &args) override;
    void help() override;
    const std::string &desc() const override;

private:
    const RegalController& m_rctrl;

};

#endif // SWAPPALETTEBEFEHL_H
