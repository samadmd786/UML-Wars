/**
 * @file UMLWarsApp.cpp
 * @author hemke
 */
#include "pch.h"
#include "UMLWarsApp.h"
#include <MainFrame.h>

/**
 * Initialize the application.
 * @return
 */
bool UMLWarsApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show(true);

    return true;
}