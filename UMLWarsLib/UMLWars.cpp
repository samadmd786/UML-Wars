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
void UMLWars::OnDraw(wxGraphicsContext* graphics, int width, int height)
{
    //
    // Automatic Scaling
    //
    auto scaleX = double(width)/double(Width);
    auto scaleY = double(height)/double(Height);
    mScale = min(scaleX, scaleY);

    mXOffset = width/2.;
    mYOffset = 0;
    if (height>Height*mScale) {
        mYOffset = (float) ((height-Height*mScale)/2);
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
    graphics->DrawRectangle(-Width, 0, Width*2, Height);

    for (auto item: mItems) {
        item->Draw(graphics);
    }
    GetScoreBoard()->Draw(graphics);

    wxBrush rectBrushBlack(*wxBLACK);
    graphics->SetBrush(rectBrushBlack);
    graphics->SetPen(*wxBLACK_PEN);
    graphics->DrawRectangle(-Width, 0, Width/2., Height);
    graphics->DrawRectangle(Width/2., 0, Width/2., Height);


    //
    // Draw in virtual pixels on the graphics context
    //

    graphics->PopState();
}

/**
 * Updates items in the game for animation purposes
 * @param elapsed time since last update
 */
void UMLWars::Update(double elapsed)
{
    for (auto item: mItems) {
        item->Update(elapsed);

    }
    if (!mToRemove.empty()) {
        DeleteBox();
    }

}

/**
 * Launches the pen Harold is holding, if one exists.
 * @return boolean indicator of whether a pen was launched
 */
void UMLWars::LaunchPen()
{
    if (mPen) {
        mPen->Launch();
    }
}

/**
 * Resets a launched pen once it hits a box
 * or goes off screen
 */
void UMLWars::ResetPen()
{
    mPen->Reset();
}

void UMLWars::DeleteBox()
{

    for (auto item: mToRemove) {
        Remove(item);
    }

}

UMLWars::UMLWars()
{
}

/**
 * Add an item to the remove vector
 * @param item - New item to add
 */
void UMLWars::AddToRemove(std::shared_ptr<Item> item)
{
    mToRemove.push_back(item);
    ResetPen();
}

void UMLWars::Remove(std::shared_ptr<Item> item)
{
    auto loc = find(begin(mItems), end(mItems), item);
    if (loc!=end(mItems)) {
        mItems.erase(loc);
    }
}




