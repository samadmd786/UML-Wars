/**
 * @file UMLWarsView.cpp
 * @author hemke
 */

#include "pch.h"
#include "UMLWarsView.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>


/**
 * Initialize the uml wars view class.
 * @param parent The parent window for this class
 */
void UMLWarsView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &UMLWarsView::OnPaint, this);
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
}