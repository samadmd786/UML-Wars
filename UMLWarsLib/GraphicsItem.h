/**
 * @file GraphicsItem.h
 * @author hemke
 *
 *
 */

#ifndef UMLWARS_GRAPHICSITEM_H
#define UMLWARS_GRAPHICSITEM_H

#include "Item.h"
#include <memory>

class GraphicsItem : public Item{
protected:
    GraphicsItem(UMLWars* umlWars, const std::wstring &filename);
private:
    /// The underlying item image
    std::unique_ptr<wxImage> mItemImage;

    /// Bitmap for the item in question
    wxGraphicsBitmap mItemBitmap;

public:

    void Draw(wxGraphicsContext* graphics);
};

#endif //UMLWARS_GRAPHICSITEM_H
