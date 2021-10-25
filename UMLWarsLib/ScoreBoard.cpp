/**
 * @file ScoreBoard.cpp
 * @author Josh Erno
 */
#include "pch.h"
#include "ScoreBoard.h"

using namespace std;

/**
 * Constructor
 * @param umlwars UMLWars this block is a member of
 */
ScoreBoard::ScoreBoard(UMLWars* umlWars)
        :Item(umlWars)
{
}

void ScoreBoard::Draw(wxGraphicsContext* graphics)
{
    // Draw the scoreboard
    wxFont font(wxSize(0, 45),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, wxColour(0, 139, 139));
    graphics->DrawText(L"Correct", -300, 200);
    graphics->DrawText(L"Missed", 0, 200);
    graphics->DrawText(L"Unfair", 300, 200);

    // Draw the score

    wxFont fontNum(wxSize(0, 100),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);
    graphics->SetFont(fontNum, wxColour(0, 139, 139));
    graphics->DrawText(to_string(mCorrect), -250, 50);
    graphics->DrawText(to_string(mMissed), 50, 50);
    graphics->DrawText(to_string(mUnfair), 350, 50);
}


