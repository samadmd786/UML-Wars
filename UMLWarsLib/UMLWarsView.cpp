/**
 * @file UMLWarsView.cpp
 * @author hemke
 */

#include "pch.h"
#include "UMLWarsView.h"
#include <wx/dcbuffer.h>

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
    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();
}
