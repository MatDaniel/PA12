#ifndef GETPALETTEBEFEHL_H
#define GETPALETTEBEFEHL_H

#include "befehl.h"
#include "regalcontroller.h"

/**
 * @brief Dieser Befehl gibt Informationen über eine Palette aus.
 */
class GetPaletteBefehl : public Befehl
{
public:
    GetPaletteBefehl(const RegalController& rctrl);

    // Befehl interface
public:
    void exec(std::vector<std::string> &args) override;
    void help() override;
    const std::string& desc() const override;

private:
    const RegalController& m_rctrl;

};

#endif // GETPALETTEBEFEHL_H
