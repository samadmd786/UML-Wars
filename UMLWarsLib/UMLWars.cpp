/**
 * @file UMLWars.cpp
 * @author hemke
 */

#include "pch.h"
#include "UMLWars.h"
#include <wx/graphics.h>
#include <algorithm>

using namespace std;

/// Game area in virtual pixels
const static int Width = 1250;

/// Game area height in virtual pixels
const static int Height = 1000;


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

    mXOffset = width / 2;
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
    graphics->DrawRectangle(-Width/2, 0, Width, Height);

    //
    // Draw in virtual pixels on the graphics context
    //
    // INSERT YOUR DRAWING CODE HERE

    graphics->PopState();
}