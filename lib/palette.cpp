#include "palette.h"

const Palette Palette::EMPTY;

Palette::Palette(std::string ware, unsigned int anzahl, std::string lagerbedingungen, bool defekt)
    : m_anzahl(anzahl)
    , m_ware(ware)
    , m_lagerbedingungen(lagerbedingungen)
    , m_defekt(defekt)
{
}

Palette::Palette(const Palette &other) = default;

unsigned int Palette::anzahl() const noexcept
{
    return m_anzahl;
}

const std::string& Palette::ware() const noexcept
{
    return m_ware;
}

const std::string& Palette::lagerbedingungen() const noexcept
{
    return m_lagerbedingungen;
}

void Palette::setAnzahl(unsigned int anzahl)
{
    m_anzahl = anzahl;
}

void Palette::setWare(const std::string& ware)
{
    m_ware = ware;
}

void Palette::setLagerbedingungen(const std::string& lagerbedingungen)
{
    m_lagerbedingungen = lagerbedingungen;
}

bool Palette::hasLagerbedingungen() const noexcept
{
    return !m_lagerbedingungen.empty();
}

bool Palette::empty() const noexcept
{
    return m_ware.empty();
}

void Palette::setDefekt(bool defekt)
{
    m_defekt = defekt;
}

bool Palette::defekt() const noexcept
{
    return m_defekt;
}

Palette &Palette::operator=(const Palette& other)
{
    m_ware = other.m_ware;
    m_anzahl = other.m_anzahl;
    m_lagerbedingungen = other.m_lagerbedingungen;
    m_defekt = other.m_defekt;
    return *this;
}
