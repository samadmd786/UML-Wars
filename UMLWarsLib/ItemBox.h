/**
 * @file ItemBox.h
 * @author hemke
 *
 *
 */

#ifndef UMLWARS_ITEMBOX_H
#define UMLWARS_ITEMBOX_H

#include "Item.h"
#include "ElementHolder.h"
#include <vector>

class ItemBox : public Item{
private:

    double mXDir = 0;
    double mYDir = 0;
    double mDirection = 1;
    std::vector<ElementHolder> mAttributes;
    wxString mClassName;
    double mHeight = 0;
    double mWidth = 0;

public:

    /// Default constructor (disabled)
    ItemBox() = delete;

    /// Copy constructor (disabled)
    ItemBox(const ItemBox &) = delete;

    /// Assignment operator
    void operator=(const ItemBox &) = delete;

    ItemBox(UMLWars* umlWars, std::vector<ElementHolder> attributes, wxString className);

    virtual void Update(double elapsed) override;

    void Draw(wxGraphicsContext* graphics);

    /**
    * The width of the item
    * @return width in pixels
    */
    double GetWidth() const { return mWidth; }

    /**
     * The height of the item
     * @return height in pixels
     */
    double GetHeight() const { return mHeight; }

    virtual bool HitTest(int x, int y);
};

#endif //UMLWARS_ITEMBOX_H
