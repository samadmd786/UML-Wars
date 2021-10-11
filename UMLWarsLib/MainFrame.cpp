/**
 * @file MainFrame.cpp
 * @author hemkesh
 */

#include "pch.h"
#include "MainFrame.h"
#include "UMLWarsView.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"UML Wars", wxDefaultPosition,  wxSize( 1000,800 ));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxHORIZONTAL );

    // Create the view class object as a child of MainFrame
    auto mainView = new UMLWarsView();
    mainView->Initialize(this);

    // Add it to the sizer
    sizer->Add(mainView,1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();
}