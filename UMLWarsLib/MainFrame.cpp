/**
 * @file MainFrame.cpp
 * @author hemkesh
 */

#include "pch.h"
#include "MainFrame.h"
#include "UMLWarsView.h"
#include "ids.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"UML Wars", wxDefaultPosition, wxSize(1000, 800));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer(wxHORIZONTAL);

    // Create the view class object as a child of MainFrame
    auto mainView = new UMLWarsView();
    mainView->Initialize(this);

    // Add it to the sizer
    sizer->Add(mainView, 1, wxEXPAND | wxALL);

    // Set the sizer for this frame
    SetSizer(sizer);

    // Layout (place) the child windows.
    Layout();

    auto menuBar = new wxMenuBar();

    CreateStatusBar(1, wxSTB_SIZEGRIP, wxID_ANY);

    auto fileMenu = new wxMenu();
    auto variantMenu = new wxMenu();
    auto helpMenu = new wxMenu();

    fileMenu->Append(wxID_EXIT, "&Exit\tAlt-X", "Quit this program");
    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");

    menuBar->Append(fileMenu, L"&File");
    menuBar->Append(variantMenu, L"&Variant");
    menuBar->Append(helpMenu, L"&Help");
    variantMenu->AppendRadioItem(IDM_STANDARD, L"&Standard", L"Standard");
    variantMenu->AppendRadioItem(IDM_CUSTOM, L"&Custom", L"Custom");

    SetMenuBar(menuBar);

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnVariantStandard, this, IDM_STANDARD);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnVariantCustom, this, IDM_CUSTOM);

    mUMLWarsView = mainView;
}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
    mUMLWarsView->SetCustom(false);
    Close(true);
}

/**
 * Application about box menu handler
 * @param event
 */
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(L"Welcome to UML Wars",
            L"About UMlWars",
            wxOK,
            this);
}

/**
 * Application about box menu handler
 * @param event
 */
void MainFrame::OnVariantStandard(wxCommandEvent& event)
{
    mUMLWarsView->SetCustom(false);
}

/**
 * Application about box menu handler
 * @param event
 */
void MainFrame::OnVariantCustom(wxCommandEvent& event)
{
    mUMLWarsView->SetCustom(true);
}
