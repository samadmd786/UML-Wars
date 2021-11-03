/**
 * @file ItemBoxInheritance.cpp
 * @author Andrew Haas
 */

#include "pch.h"
#include <memory>
#include <random>
#include <wx/utils.h>
#include "ItemBoxInheritance.h"
#include "UMLWars.h"

using namespace std;

/// constant for pi
const double pi = 3.1415;

ItemBoxInheritance::ItemBoxInheritance(UMLWars* umlWars, bool good) : Item(umlWars)
{
    std::uniform_real_distribution<> distribution(-500, 500);
    double random = distribution(umlWars->GetRandom());
    SetX(random);

    LoadXML xml = umlWars->GetXML();

    ElementHolderInheritance inheritance = (xml.GetInheritance(good));

    mBClassName = inheritance.GetName();
    mDClassName = inheritance.GetDerivedName();
    mMsgString = !inheritance.GetBad().empty() ? inheritance.GetBad() : "Unfair!";
    mGood = good;

    // now we have to set up attributes for both base and derived
    mBaseAttributes = xml.GetAttributes();
    mBaseOperations = xml.GetOperations();
    mDerivedAttributes = xml.GetAttributes();
    mBaseAttributes = xml.GetOperations();

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
 * draw this inheritance structure
 * @param graphics - context to draw on
 */
void ItemBoxInheritance::Draw(wxGraphicsContext* graphics) {

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

    //
    // Set up for the base class box
    //
    //
    double bWid, bHit, bClassWidth;
    graphics->GetTextExtent(mBClassName, &bWid, &bHit);

    bClassWidth = bWid;

    for (auto attribute: mBaseAttributes) {
        /// Initial width and height according to the class name
        double width, height;
        graphics->GetTextExtent(attribute.GetName(), &width, &height);
        /// Set wid height to maximums
        if (width>=bWid) {
            bWid = width;
        }
        if (height>=bHit) {
            bHit = height;
        }
    }

    for (auto operation: mBaseOperations) {
        double width, height;
        graphics->GetTextExtent(operation.GetName(), &width, &height);
        /// Set wid height to maximums
        if (width>=bWid) {
            bWid = width;
        }
        if (height>=bHit) {
            bHit = height;
        }
    }

    mBWidth = bWid;
    mBHeight = bHit*(mBaseAttributes.size() + mBaseOperations.size() + 2);

    /// Rectangle setup
    wxBrush rectBrush(wxColour(255, 255, 193));
    graphics->SetBrush(rectBrush);
    graphics->SetPen(*wxBLACK_PEN);

    graphics->DrawRectangle(-mBWidth/2., -mBHeight/2., mBWidth, mBHeight);
    graphics->DrawText(mBClassName, (- bClassWidth) / 2., -mBHeight/2.);
    graphics->StrokeLine(-mBWidth/2., -mBHeight/2.+bHit, -mBWidth/2.+bWid, -mBHeight/2.+bHit);


    graphics->SetFont(font, wxColour(0, 0, 0));
    int i = 1;
    int j = 0;

    for (auto attribute: mBaseAttributes) {
        graphics->DrawText(attribute.GetName(), -mBWidth/2., -mBHeight/2.+bHit*i);
        i++;
    }

    if (!mBaseOperations.empty()) {
        graphics->StrokeLine(-mBWidth/2., -mBHeight/2.+bHit*i, -mBWidth/2.+bWid, -mBHeight/2.+bHit*i);
        for (auto operation: mBaseOperations) {
            graphics->DrawText(operation.GetName(), -mBWidth/2., -mBHeight/2.+bHit*i+bHit*j);
            j++;
        }
    }
    //
    // End base class rectangle setup
    //

    //
    //
    // Now set up derived class rectangle... yes, there is too much duplicate code... I know
    // I initially was going to derive this class from the normal boxes but the constructors didn't play well
    // together, and I didn't feel like thinking too hard about it
    //
    // Set up for derived class
    //
    graphics->SetFont(boldFont, wxColour(0, 0, 0));
    double dWid, dHit, dClassWidth;
    graphics->GetTextExtent(mDClassName, &dWid, &dHit);

    dClassWidth = dWid;

    for (auto attribute: mDerivedAttributes) {
        /// Initial width and height according to the class name
        double width, height;
        graphics->GetTextExtent(attribute.GetName(), &width, &height);
        /// Set wid height to maximums
        if (width>=dWid) {
            dWid = width;
        }
        if (height>=dHit) {
            dHit = height;
        }
    }

    for (auto operation: mDerivedOperations) {
        double width, height;
        graphics->GetTextExtent(operation.GetName(), &width, &height);
        /// Set wid height to maximums
        if (width>=dWid) {
            dWid = width;
        }
        if (height>=dHit) {
            dHit = height;
        }
    }

    mDWidth = dWid;
    mDHeight = dHit*(mDerivedAttributes.size() + mDerivedOperations.size() + 2);

    /// Rectangle setup
    wxBrush dRectBrush(wxColour(255, 255, 193));
    graphics->SetBrush(dRectBrush);
    graphics->SetPen(*wxBLACK_PEN);

    graphics->DrawRectangle(-mDWidth/2., -mDHeight/2. - mBHeight - 20, mDWidth, mDHeight);
    graphics->DrawText(mDClassName, (- dClassWidth) / 2., -mDHeight/2. - mBHeight - 20);
    graphics->StrokeLine(-mDWidth/2., -mDHeight/2.+dHit- mBHeight - 20, -mDWidth/2.+dWid, -mDHeight/2.+dHit - mBHeight - 20);


    graphics->SetFont(font, wxColour(0, 0, 0));
    i = 1;
    j = 0;

    for (auto attribute: mDerivedAttributes) {
        graphics->DrawText(attribute.GetName(), -mDWidth/2., -mDHeight/2.+bHit*i - mBHeight - 20);
        i++;
    }

    if (!mDerivedOperations.empty()) {
        graphics->StrokeLine(-mDWidth/2., -mDHeight/2.+dHit*i - mBHeight - 20, -mDWidth/2.+dWid, -mDHeight/2.+bHit*i - mBHeight - 20);
        for (auto operation: mDerivedOperations) {
            graphics->DrawText(operation.GetName(), -mDWidth/2., -mDHeight/2.+dHit*i+dHit*j - mBHeight - 20);
            j++;
        }
    }
    //
    // end derived setup
    //

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
        graphics->DrawText(mMsgString, (-mBWidth/2. + (mBWidth / 2)) - (msgWidth), -mBHeight/2. + (mBHeight - msgHeight) / 2. - mBHeight - 20);
    }

    graphics->PopState();   // Restore the graphics state

}

/**
* Handle updates for animation
* @param elapsed The time since the last update
*/
void ItemBoxInheritance::Update(double elapsed)
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
bool ItemBoxInheritance::HitTest(int x, int y)
{
    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to the image top corner
    double bTestX = x-GetX()+mBWidth/2;
    double bTestY = y-GetY()+mBHeight/2;

    // Test to see if x, y are in the image (and if the pen has been launched)
    if (bTestX<0 || bTestY<0 || bTestX>=mBWidth*2 || bTestY>=mBHeight || !GetUMLWars()->GetPen()->GetLaunch()) {
        // We are outside the image
        return false;
    }

    // now perform the same test for the derived rectangle
    // someone take a look at this
    return true;
}