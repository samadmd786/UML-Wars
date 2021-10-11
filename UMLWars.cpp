/**
 * @file UMLWars.cpp
 * @author hemke
 */
#include "pch.h"
#include "UMLWars.h"
#include <MainFrame.h>

/**
 * Initialize the application.
 * @return
 */
bool UMLWars::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show(true);

    return true;
}