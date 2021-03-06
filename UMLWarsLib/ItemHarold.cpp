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
 * @param umlWars game this item is a member of
 */
ItemHarold::ItemHarold(UMLWars *umlWars) : GraphicsItem(umlWars, HaroldImageName)
{

}

/**
 * Updates Harold's Rotation Angle based on the mouse coordinates (and his)
 * @param elapsed The time since the last update
*/

void ItemHarold::Update(double elapsed)
{
    double mouseX = GetUMLWars()->GetMouseX();
    double mouseY = GetUMLWars()->GetMouseY();
    SetRotation(pi/2. + atan2(mouseY-GetY() , mouseX-GetX()));
    SetX(GetX() + mSliding*5);
    if (GetX() < -500 || GetX() > 525)
    {
        mSliding = -1*mSliding;
    }

    // fast pen
    SetY(GetY() + mFastPen*5);
    mFastPen = -1*mFastPen;
}

