/**
 * @file GraphicsItem.cpp
 * @author hemke
 */

#include "pch.h"
#include "GraphicsItem.h"
#include <memory>

using namespace std;

/**
 * Constructor
 * @param umlWars - The UML Wars game this item is a member of
 * @param filename - The name of the file to display for this item
 */
GraphicsItem::GraphicsItem(UMLWars* umlWars, const std::wstring &filename) : Item(umlWars)
{
    mItemImage = make_unique<wxImage>(filename);
}


/**
 * Draw this item
 * @param graphics - graphics item to draw
 */
void GraphicsItem::Draw(wxGraphicsContext* graphics)
{
    double itemWidth = mItemImage->GetWidth();
    double itemHeight = mItemImage->GetHeight();
    if (mItemBitmap.IsNull())
    {
        mItemBitmap = graphics->CreateBitmapFromImage(*mItemImage);
    }
    graphics->PushState();  // Save the graphics state
    graphics->Translate(GetX(), GetY());
    graphics->Rotate(GetRotation());
    graphics->DrawBitmap(mItemBitmap, -itemWidth/2, -itemHeight/2, itemWidth, itemHeight);
    graphics->PopState();   // Restore the graphics state
}

