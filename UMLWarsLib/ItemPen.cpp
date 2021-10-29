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
 * @param umlWars UML Wars game this pen is a member of
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
    mFiringAngle = GetRotation() - 3.*pi/4.;
    auto harold = GetUMLWars()->GetHarold();
    if (mFastPen){
        SetSpeed(75.);
    }
    else{
        SetSpeed(20.);
    }
    harold->SetFastPen(0);
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
        SetX(harold->GetX() + offsetRadial*cos(harold->GetRotation()+offsetAngular));
        SetY(harold->GetY() + offsetRadial*sin(harold->GetRotation()+offsetAngular));
    }
    else
    {
        // in this case, the pen has been launched. Its movement is no longer tied to Harold.
        SetX(GetX() + GetSpeed()*cos(mFiringAngle));
        SetY(GetY() + GetSpeed()*sin(mFiringAngle));
        if (mFastPen){
            SetRotation(GetRotation() + 20*elapsed);
        }

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
    mFastPen = false;

    // Fetch Harold, we'll need info about him
    std::shared_ptr<ItemHarold> harold = GetUMLWars()->GetHarold();

    // The pen should be rotated 45 degrees further than harold
    SetRotation(harold->GetRotation()+pi/4.);

    // Now, we need to get the position of Harold's hand and use it to set the pen location
    SetX(harold->GetX() + offsetRadial*cos(harold->GetRotation()+offsetAngular));
    SetY(harold->GetY() + offsetRadial*sin(harold->GetRotation()+offsetAngular));

    // check for fast pen event
    std::uniform_int_distribution<int> fastPenDist(0,5);
    int fast = fastPenDist(GetUMLWars()->GetRandom());
    if (fast > 3){
        // fast pen event!
        harold->SetFastPen(1);
        mFastPen = true;
    }

}

