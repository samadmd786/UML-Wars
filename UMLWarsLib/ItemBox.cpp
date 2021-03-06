/**
 * @file ItemBox.cpp
 * @author hemke
 */

#include "pch.h"
#include "ItemBox.h"
#include "ItemPen.h"
#include <memory>
#include <random>
#include "UMLWars.h"
#include "Item.h"
#include <wx/utils.h>

using namespace std;

/// constant for pi
const double pi = 3.1415;

/**
 * Constructor
 * @param umlWars, good UMLWars this block is a member of
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
        mMsgString = "Unfair!";
    } else {
        std::uniform_int_distribution<int> badDistribution(0,2);
        int badType = badDistribution(umlWars->GetRandom());
        ElementHolder className = xml.GetClassName(badType != 0);
        mClassName = className.GetName();
        mAttributes = xml.GetAttributes(badType != 1);
        mOperations = xml.GetOperations(badType != 2);
        mMsgString = className.GetBad();
        for (auto attr : mAttributes) {
            mMsgString += attr.GetBad();
        }
        for (auto op : mOperations) {
            mMsgString += op.GetBad();
        }
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
    graphics->PushState();  // Save the graphics state
    graphics->Translate(GetX(), GetY());
    graphics->Rotate(GetRotation());


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


    mWidth = wid;
    mHeight = hit*(mAttributes.size() + mOperations.size() + 2);

    /// Rectangle setup
    wxBrush rectBrush(wxColour(255, 255, 193));
    graphics->SetBrush(rectBrush);
    graphics->SetPen(*wxBLACK_PEN);

    graphics->DrawRectangle(-mWidth/2., -mHeight/2., mWidth, mHeight);
    graphics->DrawText(mClassName, (- classWidth) / 2., -mHeight/2.);
    graphics->StrokeLine(-mWidth/2., -mHeight/2.+hit, -mWidth/2.+wid, -mHeight/2.+hit);


    graphics->SetFont(font, wxColour(0, 0, 0));
    int i = 1;
    int j = 0;

    for (auto attribute: mAttributes) {
        graphics->DrawText(attribute.GetName(), -mWidth/2., -mHeight/2.+hit*i);
        i++;
    }

    if (!mOperations.empty()) {
        graphics->StrokeLine(-mWidth/2., -mHeight/2.+hit*i, -mWidth/2.+wid, -mHeight/2.+hit*i);
        for (auto operation: mOperations) {
            graphics->DrawText(operation.GetName(), -mWidth/2., -mHeight/2.+hit*i+hit*j);
            j++;
        }
    }


    if (mError) {
        wxFont errorFont(wxSize(0, 50),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_BOLD);
        double msgWidth, msgHeight;
        graphics->GetTextExtent(mMsgString, &msgWidth, &msgHeight);
        if (!mGood) {
            graphics->SetFont(errorFont, wxColour(0, 176, 80));
        } else {
            graphics->SetFont(errorFont, wxColour(192, 0, 0));
        }
        graphics->DrawText(mMsgString, (-mWidth/2. + (mWidth / 2)) - (msgWidth), -mHeight/2. + (mHeight - msgHeight) / 2.);
    }

        graphics->PopState();   // Restore the graphics state
}

/**
* Handle updates for animation
* @param elapsed The time since the last update
*/
void ItemBox::Update(double elapsed)
{
    if(!mError) {
        SetX(GetX()+(GetSpeed()*mDirection*mXDir));
        SetY(GetY()+(GetSpeed()*mYDir));
        if (GetRotateVariant()){
            SetRotation(GetRotation() + GetUMLWars()->GetRotationSpeed()*elapsed/2.);
        }
        double penX = GetUMLWars()->GetPen()->GetX();
        double penY = GetUMLWars()->GetPen()->GetY();
        bool hitPen = HitTest(penX, penY);
        if (IsOffScreen() || hitPen) {
            if(hitPen) {
                mError = true;
                auto UMLWars = GetUMLWars();
                UMLWars->ResetPen();

                if(!mGood) {
                    GetUMLWars()->GetScoreBoard()->IncCorrect();

                    // harold slows down, and boxes rotate more slowly
                    auto harold = UMLWars->GetHarold();
                    harold->SetSliding(.90*harold->GetSliding());
                    UMLWars->SetRotationSpeed(.98*UMLWars->GetRotationSpeed());
                } else {
                    GetUMLWars()->GetScoreBoard()->IncUnfair();

                    // harold speeds up, and boxes rotate more quickly
                    auto harold = GetUMLWars()->GetHarold();
                    harold->SetSliding(1.05*harold->GetSliding());
                    UMLWars->SetRotationSpeed(1.15*UMLWars->GetRotationSpeed());
                }
            } else {
                GetUMLWars()->AddToRemove(this->GetID());
                if(!mGood || IsOffScreen()) {
                    GetUMLWars()->GetScoreBoard()->IncMissed();
                }
            }
        }
        mDestroyTime += elapsed;
    } else if (mError && mCurrentTime - mDestroyTime > 2) {
        GetUMLWars()->AddToRemove(this->GetID());
    }
    mCurrentTime += elapsed;
}

/**
* Test an x,y click location to see if it clicked
* on some item in the game
* @param x X location in pixels
* @param y Y location in pixels
* @returns Pointer to item we clicked on or nullptr if none
*/
bool ItemBox::HitTest(int x, int y)
{
    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to the image top corner
    double testX = x-GetX()+mWidth/2;
    double testY = y-GetY()+mHeight/2;

    // Test to see if x, y are in the image (and if the pen has been launched)
    if (testX<0 || testY<0 || testX>=mWidth*2 || testY>=mHeight || !GetUMLWars()->GetPen()->GetLaunch()) {
        // We are outside the image
        return false;
    }

    return true;
}
