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

/// constant for radial offset from Harold
const double offsetRadial = 61.3;

/// constant for angular offset from Harold
const double offsetAngular = -1.078;

/**
 * Constructor
 * @param umlwars UML Wars game this pen is a member of
 */
ItemPen::ItemPen(UMLWars *umlWars) : GraphicsItem(umlWars, PenImageName)
{

}

/**
 * Launches the pen
 */
void ItemPen::Launch()
{
    mLaunched = true;
    SetSpeed(20.);
}
/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */

void ItemPen::Update(double elapsed)
{
    if (!mLaunched)
    {
        // Fetch Harold, we'll need info about him
        std::shared_ptr<ItemHarold> harold = GetUMLWars()->GetHarold();

        // The pen should be rotated 45 degrees further than harold
        SetRotation(harold->GetRotation()+pi/4.);

        // Now, we need to get the position of Harold's hand and use it to set the pen location
        SetX(offsetRadial*cos(harold->GetRotation()+offsetAngular));
        SetY(harold->GetY() + offsetRadial*sin(harold->GetRotation()+offsetAngular));
    }
    else
    {
        // in this case, the pen has been launched. Its movement is no longer tied to Harold.
        double firingAngle = GetRotation() - 3.*pi/4.;
        SetX(GetX() + GetSpeed()*cos(firingAngle));
        SetY(GetY() + GetSpeed()*sin(firingAngle));

        if (IsOffScreen())
        {
            Reset();
        }

    }
}

/**
 * Resets the pen's location to Harold's hand
 */
void ItemPen::Reset()
{
    mLaunched = false;
    // Fetch Harold, we'll need info about him
    std::shared_ptr<ItemHarold> harold = GetUMLWars()->GetHarold();

    // The pen should be rotated 45 degrees further than harold
    SetRotation(harold->GetRotation()+pi/4.);

    // Now, we need to get the position of Harold's hand and use it to set the pen location
    SetX(offsetRadial*cos(harold->GetRotation()+offsetAngular));
    SetY(harold->GetY() + offsetRadial*sin(harold->GetRotation()+offsetAngular));

}

