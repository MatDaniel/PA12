#ifndef REGALCONTROLLER_H
#define REGALCONTROLLER_H

#include "palettenode.h"

/**
 * @brief Diese Klasse kümmert sich um die interne verlinkte Liste.
 */
class RegalController
{
public:

    /**
     * @brief Erstellt eine Instanz von RegalController und initializiert sie mit leeren Paletten.
     * @param regale Die Anzahl der Regale
     * @param reihen Die Anzahl der Reihen
     * @param zellen Die Anzahl der Zellen
     */
    RegalController(unsigned int regale, unsigned int reihen, unsigned int zellen);

public:

    /**
     * @brief Gibt die Palette zurück, gibt `nullptr` zurück, wenn der index außerhalb des gültigen Bereichts liegt.
     * @param index Der Index, an dem gesucht werden soll.
     * @return Ein Zeiger auf die Palette.
     */
    Palette* operator[](size_t index) const;

    /**
     * @brief Wandelt regal + zelle + reihe in ein index um.
     * @param regal Das Regal (fängt von 0 an)
     * @param reihe Die Reihe (fängt von 0 an)
     * @param zelle Die Zelle (fängt von 0 an)
     * @return Gibt den index zurück, der beim Subscript-Operator verwendet werden kann.
     */
    size_t index_of(unsigned int regal, unsigned int reihe, unsigned int zelle) const noexcept;

    /**
     * @brief Wandelt den Paletten-Index in ein Regal-Index um.
     * @param Der Paletten-Index.
     * @return Ein Regal-Index.
     */
    unsigned int regal_of(size_t id) const noexcept;

    /**
     * @brief Wandelt den Paletten-Index in ein Reihe-Index um.
     * @param Der Paletten-Index.
     * @return Ein Reihe-Index.
     */
    unsigned int reihe_of(size_t id) const noexcept;

    /**
     * @brief Wandelt den Paletten-Index in ein Zelle-Index um.
     * @param Der Paletten-Index.
     * @return Ein Zelle-Index.
     */
    unsigned int zelle_of(size_t id) const noexcept;

    /**
     * @brief Gibt die Anzahl der Einträge zurück.
     * @return Die Anzahl der Einträge.
     */
    size_t size() const noexcept;

private:
    size_t m_size;
    unsigned int m_regale, m_reihen, m_zellen;
    PaletteNode* m_begin;

private:

    /**
     * @brief Initialisiert die Liste mit leeren Einträgen.
     */
    void init();

};

#endif // REGALCONTROLLER_H
