/**
 * @file ItemPen.h
 * @author Josh Erno
 *
 * Class for ItemPen in UML Wars game
 */

#ifndef UMLWARS_ITEMPEN_H
#define UMLWARS_ITEMPEN_H

#include "GraphicsItem.h"

/**
 * Class for ItemPen in UML Wars game
 */
class ItemPen : public GraphicsItem{
private:

    /// boolean indicator of whether the pen has been launched
    bool mLaunched = false;

    // if the pen has been launched, it must store has the direction it has been fired in
    double mDirX = 0; ///< indicator for the X velocity direction
    double mDirY = 0; ///< indicator for the Y velocity direction

public:
    /// Default constructor (disabled)
    ItemPen() = delete;

    /// Copy constructor (disabled)
    ItemPen(const ItemPen &) = delete;

    /// Assignment operator
    void operator=(const ItemPen &) = delete;

    ItemPen(UMLWars* umlWars);

    /**
     * Setter for mLaunched
     * @param launch - true if launched, false if not
     */
    void SetLaunch(bool launch) { mLaunched = launch; }

    void Launch();

    bool IsOffScreen();

    virtual void Update(double elapsed) override;

};

#endif //UMLWARS_ITEMPEN_H
