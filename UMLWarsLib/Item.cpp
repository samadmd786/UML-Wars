/**
 * @file Item.cpp
 * @author Josh Erno
 */

#include "pch.h"
#include "Item.h"
#include "UMLWars.h"
#include <memory>

using namespace std;


///**
// * Test to see if we hit this object with a mouse
// * @param x - X position to test
// * @param y - Y position to test
// * @return true if hit
// */
//bool Item::HitTest(int x, int y)
//{
//    double wid = mItemBitmap->GetWidth();
//    double hit = mItemBitmap->GetHeight();
//
//    // Make x and y relative to the top-left corner of the bitmap image
//    // Subtracting the center makes x, y relative to the image center
//    // Adding half the size makes x, y relative to the image top corner
//    double testX = x - GetX() + wid / 2;
//    double testY = y - GetY() + hit / 2;
//
//    // Test to see if x, y are in the image
//    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
//    {
//        // We are outside the image
//        return false;
//    }
//
//    // Test to see if x, y are in the drawn part of the image
//    // If the location is transparent, we are not in the drawn
//    // part of the image
//    return !mItemImage->IsTransparent((int)testX, (int)testY);
//}

/**
 * Draw this item
 * @param dc - Device context to draw on
 */
void Item::Draw(wxGraphicsContext* graphics)
{
//    double itemWidth = mItemImage->GetWidth();
//    double itemHeight = mItemImage->GetHeight();
//    if (mItemBitmap.IsNull())
//    {
//        mItemBitmap = graphics->CreateBitmapFromImage(*mItemImage);
//    }
//    graphics->PushState();  // Save the graphics state
//    graphics->Translate(GetX(), GetY());
//    graphics->Rotate(mRotation);
//    graphics->DrawBitmap(mItemBitmap, -itemWidth/2, -itemHeight/2, itemWidth, itemHeight);
//    graphics->PopState();   // Restore the graphics state
//    //graphics->DrawBitmap(mItemBitmap, GetX() - itemWidth/2, GetY() - itemHeight/2, itemWidth, itemHeight);
}

/**
 * Destructor
 */
Item::~Item()
{
}

/**
 * Constructor
 * @param umlWars - The UML Wars game this item is a member of
 */
Item::Item(UMLWars* umlWars) : mUMLWars(umlWars)
{
}





