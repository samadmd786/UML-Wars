/**
 * @file ItemBox.cpp
 * @author hemke
 */

#include "ItemBox.h"
#include <memory>
#include <random>
#include "UMLWars.h"

using namespace std;


/**
 * Constructor
 * @param umlwars Aquarium this fish is a member of
 */
ItemBox::ItemBox(UMLWars *umlWars) : Item(umlWars)
{
    std::uniform_real_distribution<> distribution(-500, 500);
    double random = distribution(umlWars->GetRandom());
    SetX(random);

    if(random >= 0){
        mDirection = -1;
    }

    std::uniform_real_distribution<> xDistribution(0.1,0.5);
    mXDir = xDistribution(umlWars->GetRandom());

    std::uniform_real_distribution<> yDistribution(0.1,0.5);
    mYDir = yDistribution(umlWars->GetRandom());

    SetSpeed(1);
}

/**
 * Draw this item
 * @param dc - Device context to draw on
 */
void ItemBox::Draw(wxGraphicsContext* graphics)
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
void ItemBox::Update(double elapsed)
{
    SetX(GetX() + (GetSpeed() * mDirection * mXDir));
    SetY(GetY() + (GetSpeed() * mYDir));
}