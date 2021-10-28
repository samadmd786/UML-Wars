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
#include <wx/graphics.h>

/**
 * Class for graphics items
 */
class GraphicsItem : public Item{
protected:
    GraphicsItem(UMLWars* umlWars, const std::wstring &filename);
private:
    /// The underlying item image
    std::unique_ptr<wxImage> mItemImage;

    /// Bitmap for the item in question
    wxGraphicsBitmap mItemBitmap;

public:
    /**
     * Getter for graphics item's image width
     * @return image width
     */
    double GetImageWidth() {return mItemImage->GetWidth(); }
    /**
     * Getter for graphics item image's height
     * @return image height
     */
    double GetImageHeight() {return mItemImage->GetHeight(); }
    /**
     * Getter for graphics item's bitmap
     * @return bitmap
     */
    wxGraphicsBitmap GetBitmap() {return mItemBitmap; }

    /**
     * Draw function for graphics item
     * @return void
     */
    virtual void Draw(wxGraphicsContext* graphics);
};

#endif //UMLWARS_GRAPHICSITEM_H
