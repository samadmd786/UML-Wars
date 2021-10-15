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

public:
    /// Default constructor (disabled)
    ItemPen() = delete;

    /// Copy constructor (disabled)
    ItemPen(const ItemPen &) = delete;

    /// Assignment operator
    void operator=(const ItemPen &) = delete;

    ItemPen(UMLWars* umlWars);

    virtual void Draw(wxGraphicsContext* graphics) override;
    virtual void Update() override;

};

#endif //UMLWARS_ITEMPEN_H
