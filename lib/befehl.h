#ifndef BEFEHL_H
#define BEFEHL_H

#include <string>
#include <vector>

/**
 * @brief Diese Klasse wird zur vereinfachung der Befehlsaufrufe verwendet.
 */
class Befehl
{
public:

    /**
     * @brief Ein Standard-Konsturktor.
     */
    Befehl();

    /**
     * @brief Ein Standard-Dekonstruktor.
     */
    virtual ~Befehl();

    /**
     * @brief Führt den jeweiligen Befehl aus.
     * @param args Die Argumente, mit denen der Befehl aufgerufen wurde.
     */
    virtual void exec(std::vector<std::string>& args) = 0;

    /**
     * @brief Gibt eine Benutzungsübersicht über sich selbst aus.
     */
    virtual void help() = 0;

    /**
     * @brief Eine kurze Beschreibung des Befehls. (Wird in der Hilfen-Auflistung verwendet)
     * @return Ein String, der die Beschreibung enthält.
     */
    virtual const std::string& desc() const = 0;

};

#endif // BEFEHL_H
