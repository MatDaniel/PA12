#ifndef PALETTENODE_H
#define PALETTENODE_H

#include "palette.h"

/**
 * @brief Diese Klasse stellt einen Eintrag in der verlinkten Liste dar.
 */
class PaletteNode : public Palette
{
public:

    /**
     * @brief Dies ist der Standard-Konstruktor.
     * @param palette Die Palette, die dieser Eintrag beinhalten soll.
     * @param next Der nächste Eintrag in der verlinkten Liste.
     */
    PaletteNode(const Palette& palette = { }, PaletteNode* next = nullptr);

    /**
     * @brief Der Standard-Dekonstruktor. Achtung: Löscht alle folgenden Einträge!
     */
    ~PaletteNode();

    /**
     * @brief Ein gelöschter Copy-Konstructor.
     * @param other Der andere Eintrag.
     */
    PaletteNode(const PaletteNode& other) = delete;

    /**
     * @brief Der Standard Move-Konstruktor.
     * @param other Der andere Eintrag.
     */
    PaletteNode(PaletteNode&& other);

public:
    PaletteNode *next();
    void setNext(PaletteNode* = nullptr);

private:
    PaletteNode *m_next;

};

#endif // PALETTENODE_H
