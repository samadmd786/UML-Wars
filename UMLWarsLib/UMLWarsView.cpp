/**
 * @file UMLWarsView.cpp
 * @author hemke
 */

#include "pch.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include <memory>
#include "UMLWarsView.h"
#include "ItemHarold.h"
#include "ItemBox.h"
#include "ItemBoxInheritance.h"
#include "ItemPen.h"

using namespace std;


/// Frame duration in milliseconds
const int FrameDuration = 25;

/// constant for emission variable
const int emission = 1;

/**
 * Constructor
 */
UMLWarsView::UMLWarsView()
{
    auto Harold = make_shared<ItemHarold>(&mUMLWars);
    Harold->SetX(0);
    Harold->SetY(900);
    mUMLWars.Add(Harold);
    mUMLWars.SetHarold(Harold);

    auto Pen = make_shared<ItemPen>(&mUMLWars);
    Pen->SetX(29);
    Pen->SetY(846);
    mUMLWars.Add(Pen);
    mUMLWars.SetPen(Pen);

    auto Board = make_shared<ScoreBoard>(&mUMLWars);
    mUMLWars.Add(Board);
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
    Bind(wxEVT_LEFT_DOWN, &UMLWarsView::OnLeftDown, this);
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

    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;
    mUMLWars.Update(elapsed);

    // Tell the game class to draw
    wxRect rect = GetRect();
    mUMLWars.OnDraw(gc.get(), rect.GetWidth(), rect.GetHeight());
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
 * Handler for a mouse left-click event
 */
void UMLWarsView::OnLeftDown(wxMouseEvent& event)
{
    mUMLWars.LaunchPen();
}

/**
 * Handle timer events
 * @param event timer event
 */
void UMLWarsView::OnTimer(wxTimerEvent& event)
{
    if ((mStopWatch.Time() - mLastBox) > 2000) {

        std::uniform_int_distribution<int> badDistribution(0,10);
        bool goodOrBad = badDistribution(mUMLWars.GetRandom()) % 2 == 1;
        bool isInherited = badDistribution(mUMLWars.GetRandom()) > 7;
        if (isInherited){
            auto Box = make_shared<ItemBoxInheritance>(&mUMLWars, goodOrBad);
            Box->SetSpeed(mCurrentSpeed);

            // variant stuff
            if (mStopWatch.Time() > 25000) {
                std::uniform_real_distribution<> distribution(0, 100);
                double random = distribution(mUMLWars.GetRandom());
                if (random >= 75)
                {
                    Box->SetRotationVariant(true);
                }
            }
            if (mStopWatch.Time() > 10000){
                auto harold = mUMLWars.GetHarold();
                if (harold->GetSliding() == 0){
                    harold->SetSliding(1);
                }
                else{
                    harold->SetSliding(1.04*harold->GetSliding());
                }
            }
            mUMLWars.Add(Box);
        }
        else{
            auto Box = make_shared<ItemBox>(&mUMLWars, goodOrBad);
            Box->SetSpeed(mCurrentSpeed);

            // variant stuff
            if (mStopWatch.Time() > 25000) {
                std::uniform_real_distribution<> distribution(0, 100);
                double random = distribution(mUMLWars.GetRandom());
                if (random >= 75)
                {
                    Box->SetRotationVariant(true);
                }
            }
            if (mStopWatch.Time() > 10000){
                auto harold = mUMLWars.GetHarold();
                if (harold->GetSliding() == 0){
                    harold->SetSliding(1);
                }
                else{
                    harold->SetSliding(1.04*harold->GetSliding());
                }
            }
            mUMLWars.Add(Box);
        }
        mLastBox = mStopWatch.Time();
    }
    if (mStopWatch.Time()%10000<=30) {
        mCurrentSpeed += 1;
    }
    Refresh();
}