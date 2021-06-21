#include "regalcontroller.h"

RegalController::RegalController(unsigned int regale, unsigned int reihen, unsigned int zellen)
    : m_size(regale * zellen * reihen)
    , m_regale(regale)
    , m_reihen(reihen)
    , m_zellen(zellen)
{
    init();
}

size_t RegalController::index_of(unsigned int regal, unsigned int reihe, unsigned int zelle) const noexcept
{

    // Überprüfe, ob die Angaben korrekt sind.
    if (regal < m_regale && reihe < m_reihen && zelle < m_zellen)
    {

        // Die Angeben sind korrekt, wandle sie in ein Index um.
        return (regal * m_reihen * m_zellen)
                + (reihe * m_zellen)
                + (zelle);

    }
    else
    {

        // Die Angeben sind ungültig!
        return -1;

    }

}

unsigned int RegalController::regal_of(size_t id) const noexcept
{
    return id / (m_reihen * m_zellen);
}

unsigned int RegalController::reihe_of(size_t id) const noexcept
{
    return (id % (m_reihen * m_zellen)) / m_zellen;
}

unsigned int RegalController::zelle_of(size_t id) const noexcept
{
    return id % m_zellen;
}

size_t RegalController::size() const noexcept
{
    return m_size;
}

Palette* RegalController::operator[](size_t index) const
{

    // Stelle sicher, dass die angeforderte Palette verfügbar ist.
    if (index >= size())
    {
        return nullptr;
    }

    // Nimm die erste Palette.
    PaletteNode* node = m_begin;

    // Gehe durch die Liste und nimm immer die nächste Palette bis `index`.
    for (size_t i = 0; i < index; i++)
    {
        node = node->next();
    }

    // Gib die Palette aus.
    return node;

}

void RegalController::init()
{

    // Erstelle den ersten Eintrag, falls mind. einer angefordert ist.
    // Setze diesen anschließend auf `prev` (Vorheriger) und `m_begin` (Anfang).
    PaletteNode *current, *prev = m_begin = size() > 0 ? new PaletteNode : nullptr;

    // Erstelle Einträge, bis alle erstellt sind.
    for (size_t i = 1; i < size(); i++) {

        // Erstelle Eintrag und setz ihn zum nächsten vom letzten.
        prev->setNext(current = new PaletteNode);

        // Setze den letzten Eintrag zum neuen letzten.
        prev = current;

    }

}
