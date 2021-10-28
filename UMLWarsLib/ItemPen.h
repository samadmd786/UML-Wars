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
class ItemPen : public GraphicsItem {
private:

    /// boolean indicator of whether the pen has been launched
    bool mLaunched = false;

public:
    /// Default constructor (disabled)
    ItemPen() = delete;

    /// Copy constructor (disabled)
    ItemPen(const ItemPen&) = delete;

    /// Assignment operator
    void operator=(const ItemPen&) = delete;

    /// Copy constructor
    ItemPen(UMLWars* umlWars);

    /**
     * Getter for launch state
     * @param mLaunched
     * @return bool indicating if pen is launched
     */
     bool GetLaunch() { return mLaunched; }

     /// Launch pen
    void Launch();

    /// Reset pen back in hand
    void Reset();

    ///Update pen
    virtual void Update(double elapsed) override;

};

#endif //UMLWARS_ITEMPEN_H
