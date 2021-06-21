#ifndef PALETTE_H
#define PALETTE_H

#include <string>

/**
 * @brief Diese Klasse stellt eine Palette dar.
 */
class Palette
{
public:

    /**
     * @brief Dies ist eine leere Palette.
     */
    static const Palette EMPTY;

public:

    /**
     * @brief Dies ist der Standard-Konstruktor.
     * @param ware Die Ware, die eingelagert werden soll.
     * @param anzahl Die Anzahl der eingelagerten Ware auf der Palette.
     * @param lagerbedingungen Lagerbedingungen der Ware.
     */
    Palette(std::string ware = "", unsigned int anzahl = 0, std::string lagerbedingungen = "", bool defekt = false);

    /**
     * @brief Ein Standard Copy-Konstructor.
     * @param other Die andere Palette.
     */
    Palette(const Palette& other);

public:

    /**
     * @brief Gibt die Anzahl der eingelagerten Ware zurück.
     * @return Die Anzahl der Ware.
     */
    unsigned int anzahl() const noexcept;

    /**
     * @brief Setzt die Waren-Anzahl fest.
     * @param anzahl Die neue Anzahl.
     */
    void setAnzahl(unsigned int anzahl);

    /**
     * @brief Gibt die Ware zurück.
     * @return Der Name der Ware.
     */
    const std::string& ware() const noexcept;

    /**
     * @brief Setzt die Ware auf der Palette.
     * @param ware Die neue Ware. (Default = Keine Ware, d.h. "")
     */
    void setWare(const std::string& ware = "");

    /**
     * @brief Gibt die Lagerbedingungen der Ware zurück.
     * @return Die Lagerbedingungen.
     */
    const std::string& lagerbedingungen() const noexcept;

    /**
     * @brief Setzt die Lagerbedingungen der Ware.
     * @param lagerbedingungen Die neuen Lagerbedingungen.
     */
    void setLagerbedingungen(const std::string& lagerbedingungen = "");

    /**
     * @brief Gibt zurück, ob diese Palette Lagerbedingungen besitzt.
     * @return `true` oder `false` zurück, je nach dem, ob Lagerbedingungen gesetzt sind.
     */
    bool hasLagerbedingungen() const noexcept;

    /**
     * @brief Gibt zurück, ob die Palette leer ist.
     * @return `true` oder `false`, wenn die Anzahl = 0 oder die Ware leer ist.
     */
    bool empty() const noexcept;

    /**
     * @brief Setzt, dass die Palette defekt ist oder nicht.
     * @param defekt Ob die Palette defekt ist oder nicht. (Default = `true`)
     */
    void setDefekt(bool defekt = true);

    /**
     * @brief Prüft, ob die Palette defekt ist.
     * @return `true` oder `false`, wenn die Palette defekt ist.
     */
    bool defekt() const noexcept;

public:

    /**
     * @brief Ein einfacher Copy-Assign-Operator
     * @return Gibt die jetzige Instanz zurück.
     */
    Palette& operator=(const Palette&);

private:
    unsigned int m_anzahl;
    std::string m_ware;
    std::string m_lagerbedingungen;
    bool m_defekt;

};

#endif // PALETTE_H
