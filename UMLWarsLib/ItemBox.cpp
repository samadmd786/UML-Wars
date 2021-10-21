/**
 * @file ItemBox.cpp
 * @author hemke
 */

#include "pch.h"
#include "ItemBox.h"
#include <memory>
#include <random>
#include "UMLWars.h"

using namespace std;

/**
 * Constructor
 * @param umlwars UMLWars this block is a member of
 */
ItemBox::ItemBox(UMLWars* umlWars, bool good)
        :Item(umlWars)
{
    std::uniform_real_distribution<> distribution(-500, 500);
    double random = distribution(umlWars->GetRandom());
    SetX(random);

    LoadXML xml = umlWars->GetXML();

    if(good) {
        mClassName = xml.GetClassName().GetName();
        mAttributes = xml.GetAttributes();
        mOperations = xml.GetOperations();
    } else {
        std::uniform_int_distribution<int> badDistribution(0,2);
        int badType = badDistribution(umlWars->GetRandom());
        mClassName = xml.GetClassName(badType != 0).GetName();
        mAttributes = xml.GetAttributes(badType != 1);
        mOperations = xml.GetOperations(badType != 2);
    }

    if (random>=0) {
        mDirection = -1;
    }

    std::uniform_real_distribution<> xDistribution(0.1, 0.5);
    mXDir = xDistribution(umlWars->GetRandom());

    std::uniform_real_distribution<> yDistribution(0.1, 0.5);
    mYDir = yDistribution(umlWars->GetRandom());

    SetSpeed(1);

    mGood = good;
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
    wxFont boldFont(wxSize(0, 20),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);
    graphics->SetFont(boldFont, wxColour(0, 0, 0));

    /// Initial width and height according to the class name
    double wid, hit, classWidth;
    graphics->GetTextExtent(mClassName, &wid, &hit);

    classWidth = wid;

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

    for (auto operation: mOperations) {
        double width, height;
        graphics->GetTextExtent(operation.GetName(), &width, &height);
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
    graphics->DrawRectangle(GetX(), GetY(), wid, hit*(mAttributes.size() + mOperations.size() +2));
    graphics->DrawText(mClassName, GetX() + (wid - classWidth) / 2., GetY());
    graphics->StrokeLine(GetX(), GetY()+hit, GetX()+wid, GetY()+hit);
    graphics->SetFont(font, wxColour(0, 0, 0));
    int i = 1;
    int j = 0;

    for (auto attribute: mAttributes) {
        graphics->DrawText(attribute.GetName(), GetX(), GetY()+hit*i);
        i++;
    }

    if (mOperations.size() != 0) {
        graphics->StrokeLine(GetX(), GetY()+hit*i, GetX()+wid, GetY()+hit*i);
        for (auto operation: mOperations) {
            graphics->DrawText(operation.GetName(), GetX(), GetY()+hit*i+hit*j);
            j++;
        }
    }

    mWidth = wid;
    mHeight = hit*(mAttributes.size() + mOperations.size() +2);
}

/**
* Handle updates for animation
* @param elapsed The time since the last update
*/
void ItemBox::Update(double elapsed)
{
    SetX(GetX()+(GetSpeed()*mDirection*mXDir));
    SetY(GetY()+(GetSpeed()*mYDir));
    double penX = GetUMLWars()->GetPen()->GetX();
    double penY = GetUMLWars()->GetPen()->GetY();
    if (IsOffScreen() || HitTest(penX, penY)) {
        GetUMLWars()->AddToRemove(static_cast<shared_ptr<Item>>(this));
    }
}

/**
* Test an x,y click location to see if it clicked
* on some item in the aquarium
* @param x X location in pixels
* @param y Y location in pixels
* @returns Pointer to item we clicked on or nullptr if none
*/
bool ItemBox::HitTest(int x, int y)
{

    double wid = GetWidth();
    double hit = GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to the image top corner
    double testX = x-GetX()+wid/2;
    double testY = y-GetY()+hit/2;

    // Test to see if x, y are in the image
    if (testX<0 || testY<0 || testX>=wid || testY>=hit) {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    // If the location is transparent, we are not in the drawn
    // part of the image
    return true;
}
