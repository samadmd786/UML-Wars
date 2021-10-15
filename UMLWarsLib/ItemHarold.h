/**
 * @file ItemHarold.h
 * @author hemke
 *
 *
 */

#ifndef UMLWARS_ITEMHAROLD_H
#define UMLWARS_ITEMHAROLD_H

#include "Item.h"

class ItemHarold : public Item{

public:
    /// Default constructor (disabled)
    ItemHarold() = delete;

    /// Copy constructor (disabled)
    ItemHarold(const ItemHarold &) = delete;

    /// Assignment operator
    void operator=(const ItemHarold &) = delete;

    ItemHarold(UMLWars* umlWars);

    virtual void Update() override;

};

#endif //UMLWARS_ITEMHAROLD_H
