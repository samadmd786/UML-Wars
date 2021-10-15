/**
 * @file ItemHarold.h
 * @author hemke
 *
 * Class for ItemHarold in UML Wars game
 */

#ifndef UMLWARS_ITEMHAROLD_H
#define UMLWARS_ITEMHAROLD_H

#include "GraphicsItem.h"

class ItemHarold : public GraphicsItem{

public:
    /// Default constructor (disabled)
    ItemHarold() = delete;

    /// Copy constructor (disabled)
    ItemHarold(const ItemHarold &) = delete;

    /// Assignment operator
    void operator=(const ItemHarold &) = delete;

    ItemHarold(UMLWars* umlWars);

    virtual void Draw(wxGraphicsContext* graphics) override;
    virtual void Update() override;

};

#endif //UMLWARS_ITEMHAROLD_H
