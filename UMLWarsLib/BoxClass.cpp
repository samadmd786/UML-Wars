/**
 * @file BoxClass.cpp
 * @author hemke
 */

#include "BoxClass.h"

using namespace std;

/**
 * Constructor
 * @param umlwars Aquarium this fish is a member of
 */
BoxClass::BoxClass(UMLWars *umlWars, double x, double y) : Item(umlWars)
{
    SetX(x);
    SetY(y);
}

/**
 * Draw this item
 * @param dc - Device context to draw on
 */
void BoxClass::Draw(wxGraphicsContext* graphics)
{
    /// Draw a filled rectangle
    wxBrush rectBrush(wxColour(255, 255, 193));
    graphics->SetBrush(rectBrush);
    graphics->SetPen(*wxBLACK_PEN);
    graphics->DrawRectangle(GetX(), GetY(), 100, 50);
}

/**
 * Updates Box
*/
void BoxClass::Update()
{
    SetX(GetX() + 5);
    SetY(GetY() + 5);
}