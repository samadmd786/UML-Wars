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
 * @param umlwars UMLWars this block is a member of
 */
ItemBox::ItemBox(UMLWars* umlWars, vector<ElementHolder> attributes, wxString className)
        :Item(umlWars)
{
    std::uniform_real_distribution<> distribution(-500, 500);
    double random = distribution(umlWars->GetRandom());
    SetX(random);

    mClassName = className;
    mAttributes = attributes;

    if (random>=0) {
        mDirection = -1;
    }

    std::uniform_real_distribution<> xDistribution(0.1, 0.5);
    mXDir = xDistribution(umlWars->GetRandom());

    std::uniform_real_distribution<> yDistribution(0.1, 0.5);
    mYDir = yDistribution(umlWars->GetRandom());

    SetSpeed(1);
}

/**
 * Draw this item
 * @param graphics - Device context to draw on
 */
void ItemBox::Draw(wxGraphicsContext* graphics)
{
    ///
    /// Measuring text
    ///
    wxFont font(wxSize(0, 20),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font, wxColour(0, 0, 0));

    /// Initial width and height according to the class name
    double wid, hit;
    graphics->GetTextExtent(mClassName, &wid, &hit);

    for (auto attribute: mAttributes) {
        /// Initial width and height according to the class name
        double width, height;
        graphics->GetTextExtent(attribute.GetName(), &width, &height);
        /// Set wid height to maximums
        if (width>=wid) {
            wid = width;
        }
        if (height>=hit) {
            hit = height;
        }
    }

    /// Rectangle setup
    wxBrush rectBrush(wxColour(255, 255, 193));
    graphics->SetBrush(rectBrush);
    graphics->SetPen(*wxBLACK_PEN);
    graphics->DrawRectangle(GetX(), GetY(), wid, hit*(mAttributes.size()+2));
    graphics->DrawText(mClassName, GetX(), GetY());
    graphics->StrokeLine(GetX(), GetY()+hit, GetX()+wid, GetY()+hit);

    int i = 1;
    for (auto attribute: mAttributes) {
        graphics->DrawText(attribute.GetName(), GetX(), GetY()+hit*i);
        i++;
    }

    mWidth = wid;
    mHeight = hit*(mAttributes.size()+2);
}

/**
 * Updates Box
*/
void ItemBox::Update(double elapsed)
{
    SetX(GetX()+(GetSpeed()*mDirection*mXDir));
    SetY(GetY()+(GetSpeed()*mYDir));

    if (IsOffScreen()) {
      GetUMLWars()->DeleteBox();
    }
}
