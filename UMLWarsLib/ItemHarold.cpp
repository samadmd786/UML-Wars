/**
 * @file ItemHarold.cpp
 * @author hemke
 */

#include "pch.h"
#include "ItemHarold.h"
#include "UMLWars.h"
#include <cmath>

using namespace std;

/// Harold filename
const wstring HaroldImageName = L"images/harold.png";

/// constant for pi
const double pi = 3.1415;

/**
 * Constructor
 * @param umlwars Aquarium this fish is a member of
 */
ItemHarold::ItemHarold(UMLWars *umlWars) : GraphicsItem(umlWars, HaroldImageName)
{

}

/**
 * Updates Harold's Rotation Angle based on the mouse coordinates (and his)
*/
void ItemHarold::Update()
{
    double mouseX = GetUMLWars()->GetMouseX();
    double mouseY = GetUMLWars()->GetMouseY();
    SetRotation(pi/2. + atan2(mouseY-GetY() , mouseX-GetX()));
}

/**
 * Draw this Harold
 * @param graphics - Device context to draw on
 */
void ItemHarold::Draw(wxGraphicsContext* graphics)
{
    GraphicsItem::Draw(graphics);
    graphics->PushState();  // Save the graphics state
    graphics->Translate(GetX(), GetY());
    graphics->Rotate(GetRotation());
    graphics->DrawBitmap(GetBitmap(), -GetImageWidth()/2, -GetImageHeight()/2, GetImageWidth(), GetImageHeight());
    //graphics->DrawBitmap(mItemBitmap, 0, 0, itemWidth, itemHeight);
    graphics->PopState();   // Restore the graphics state
}