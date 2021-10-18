/**
 * @file UMLWars.cpp
 * @author hemke
 */

#include "pch.h"
#include "UMLWars.h"
#include "Item.h"
#include "ItemHarold.h"
#include <wx/dcbuffer.h>
#include <algorithm>
#include <memory>

using namespace std;

/// Game area in virtual pixels
const static int Width = 1250;

/// Game area height in virtual pixels
const static int Height = 1000;


/**
 * Add an item to the UML Wars game
 * @param item - New item to add
 */
void UMLWars::Add(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}

/**
 * Draw the game area
 * @param graphics The graphics context to draw on
 * @param width Width of the client window
 * @param height Height of the client window
 */
void UMLWars::OnDraw(wxGraphicsContext *graphics, int width, int height)
{
    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(Width);
    auto scaleY = double(height) / double(Height);
    mScale = min(scaleX, scaleY);

    mXOffset = width / 2.;
    mYOffset = 0;
    if (height > Height * mScale) {
        mYOffset = (float)((height - Height * mScale) / 2);
    }


    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);

    //
    // A rectangle for the virtual area we are drawing on
    //
    wxBrush rectBrush(*wxWHITE);
    graphics->SetBrush(rectBrush);
    graphics->SetPen(*wxWHITE_PEN);
    graphics->DrawRectangle(-Width/2., 0, Width, Height);

    for(auto item : mItems)
    {
        item->Draw(graphics);
    }


    //
    // Draw in virtual pixels on the graphics context
    //
    // INSERT YOUR DRAWING CODE HERE
    // Draw the scoreboard
    wxFont font(wxSize(0, 45),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, wxColour(0, 139, 139));
    graphics->DrawText(L"Correct", -300, 200);
    graphics->DrawText(L"Missed", 0, 200);
    graphics->DrawText(L"Unfair", 300, 200);

    // Draw the score
    int correctNum = 0;
    int missedNum = 0;
    int unfairNum = 0;
    wxFont fontNum(wxSize(0, 100),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);
    graphics->SetFont(fontNum, wxColour(0, 139, 139));
    graphics->DrawText(to_string(correctNum), -250, 50);
    graphics->DrawText(to_string(missedNum), 50, 50);
    graphics->DrawText(to_string(unfairNum), 350, 50);


    graphics->PopState();
}

/**
 * Updates items in the game for animation purposes
 * @param elapsed time since last update
 */
void UMLWars::Update(double elapsed)
{
    for(auto item : mItems)
    {
        item->Update(elapsed);
    }
}

/**
 * Launches the pen Harold is holding, if one exists.
 * @return boolean indicator of whether a pen was launched
 */
bool UMLWars::LaunchPen()
{
    if (mPen)
    {
        mPen->Launch();
        //mPen = nullptr;
        return true;
    }
    return false;
}

/**
 * Resets a launched pen once it hits a box
 * or goes off screen
 */
void UMLWars::ResetPen()
{
    mPen->SetX(29);
    mPen->SetY(846);
    mPen->SetLaunch(false);
}

UMLWars::UMLWars()
{
    wxString file("data/uml.xml");
    LoadXML(file);
}

/**
 * Load XML file
 * @param fileXML file directory
 */
void UMLWars::LoadXML(wxString fileXML)
{
    wxXmlDocument xmlDocument;
    xmlDocument.Load(fileXML);

    auto root = xmlDocument.GetRoot();
    auto classInherit = root->GetChildren();
    for(; classInherit; classInherit=classInherit->GetNext()) {
        auto name = classInherit->GetName();
        for (auto child = classInherit->GetChildren(); child; child = child->GetNext()) {
            auto nameNext = child->GetName();
            if (name == "class") {
                if (child->GetAttribute("bad") == wxEmptyString) {
                    const wxString goodClassItem = child->GetNodeContent();
                    if (nameNext == "name") {
                        mNames.push_back(goodClassItem);
                    }
                    else if (nameNext == "attribute") {
                        mAttributes.push_back(goodClassItem);
                    }
                    else if (nameNext == "operation") {
                        mOperations.push_back(goodClassItem);
                    }
                }else{
                    const wxString badClassItem = child->GetNodeContent();
                    if (nameNext == "name") {
                        mBadNames.push_back(badClassItem);
                    }
                    else if (nameNext == "attribute") {
                        mBadAttributes.push_back(badClassItem);
                    }
                    else if (nameNext == "operation") {
                        mBadOperations.push_back(badClassItem);
                    }
                }
            }else if(name == "inheritance"){
                if (child->GetAttribute("bad") == wxEmptyString){
                    const wxString inheritedClassItem = child->GetNodeContent();
                    mInherited.push_back(inheritedClassItem);
                }else{
                    const wxString badInheritedClassItem = child->GetNodeContent();
                    mBadInherited.push_back(badInheritedClassItem);
                }
            }
        }
    }
}
