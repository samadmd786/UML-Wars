/**
 * @file ItemPen.cpp
 * @author Josh Erno
 */

#include "pch.h"
#include "ItemPen.h"
#include "UMLWars.h"
#include <cmath>

using namespace std;

/// Pen filename
const wstring PenImageName = L"images/redpen.png";

/// constant for pi
const double pi = 3.1415;

/**
 * Constructor
 * @param umlwars UML Wars game this pen is a member of
 */
ItemPen::ItemPen(UMLWars *umlWars) : GraphicsItem(umlWars, PenImageName)
{
}

/**
 * Updates Pen's Rotation Angle based on the mouse coordinates (and the pen's)
*/
void ItemPen::Update()
{
    double mouseX = GetUMLWars()->GetMouseX();
    double mouseY = GetUMLWars()->GetMouseY();
    SetRotation(pi + atan2(mouseY-GetY() , mouseX-GetX()));
}

/**
 * Draw this Pen
 * @param graphics - Device context to draw on
 */
void ItemPen::Draw(wxGraphicsContext* graphics)
{
    GraphicsItem::Draw(graphics);
    graphics->PushState();  // Save the graphics state
    graphics->Translate(GetX(), GetY());
    graphics->Rotate(GetRotation());
    //graphics->DrawBitmap(GetBitmap(), -GetImageWidth()/2, -GetImageHeight()/2, GetImageWidth(), GetImageHeight());
    graphics->DrawBitmap(GetBitmap(), 0, 0, GetImageWidth(), GetImageHeight());
    graphics->PopState();   // Restore the graphics state
}