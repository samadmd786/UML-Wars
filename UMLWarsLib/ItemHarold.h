/**
 * @file ItemHarold.h
 * @author hemke
 */

#ifndef UMLWARS_ITEMHAROLD_H
#define UMLWARS_ITEMHAROLD_H

#include "GraphicsItem.h"

/**
 * Class for Harold item
 */
class ItemHarold : public GraphicsItem{

public:
    /// Default constructor (disabled)
    ItemHarold() = delete;

    /// Copy constructor (disabled)
    ItemHarold(const ItemHarold &) = delete;

    /// Assignment operator
    void operator=(const ItemHarold &) = delete;

    /// Default constructor
    ItemHarold(UMLWars* umlWars);

    ///Update function
    virtual void Update(double elapsed) override;

};

#endif //UMLWARS_ITEMHAROLD_H
