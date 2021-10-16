/**
 * @file ItemBox.h
 * @author hemke
 *
 *
 */

#ifndef UMLWARS_ITEMBOX_H
#define UMLWARS_ITEMBOX_H

#include "Item.h"

class ItemBox : public Item{
private:
    double mXDir = 0;
    double mYDir = 0;
    double mDirection = 1;

public:

    /// Default constructor (disabled)
    ItemBox() = delete;

    /// Copy constructor (disabled)
    ItemBox(const ItemBox &) = delete;

    /// Assignment operator
    void operator=(const ItemBox &) = delete;

    ItemBox(UMLWars* umlWars);

    virtual void Update(double elapsed) override;

    void Draw(wxGraphicsContext* graphics);
};

#endif //UMLWARS_ITEMBOX_H
