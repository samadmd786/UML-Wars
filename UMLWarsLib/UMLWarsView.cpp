/**
 * @file UMLWarsView.cpp
 * @author hemke
 */

#include "pch.h"
#include "UMLWarsView.h"
#include "ItemHarold.h"
#include "BoxClass.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include <memory>

using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
 * Constructor
 */
UMLWarsView::UMLWarsView() {
    auto Harold = make_shared<ItemHarold>(&mUMLWars);
    Harold->SetLocation(0, 900);
    mUMLWars.Add(Harold);

    auto Box = make_shared<BoxClass>(&mUMLWars, 50, 100);
    mUMLWars.Add(Box);
}

/**
 * Initialize the uml wars view class.
 * @param parent The parent window for this class
 */
void UMLWarsView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &UMLWarsView::OnPaint, this);
    Bind(wxEVT_MOTION, &UMLWarsView::OnMouseMove, this);

    Bind(wxEVT_TIMER, &UMLWarsView::OnTimer, this);

    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    mStopWatch.Start();
}


/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void UMLWarsView::OnPaint(wxPaintEvent& event)
{
    // Create a double-buffered display context
    wxAutoBufferedPaintDC dc(this);

    // Clear the image to black
    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    std::shared_ptr<wxGraphicsContext> gc;
    gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

    // Tell the game class to draw
    wxRect rect = GetRect();
    mUMLWars.OnDraw(gc.get(), rect.GetWidth(), rect.GetHeight());
    dc.DrawText(L"Missed",100,100);
}

/**
 * Handler for a mouse movement event
 */
void UMLWarsView::OnMouseMove(wxMouseEvent& event)
{
    mUMLWars.SetMouseX(event.GetX());
    mUMLWars.SetMouseY(event.GetY());
}

/**
 * Handle timer events
 * @param event timer event
 */
void UMLWarsView::OnTimer(wxTimerEvent& event)
{
    Refresh();
}
