/**
 * @file Item.cpp
 * @author Josh Erno
 */

#include "pch.h"
#include "Item.h"
#include "UMLWars.h"
#include <memory>

using namespace std;

/// constant for x-value at right of the screen
const int rightOfScreen = 625;

/// constant for x-value at left of the screen
const int leftOfScreen = -1000;

/// constant for y-value at top of screen
const int topOfScreen = 0;

/// constant for y-value at bottom of screen
const int bottomOfScreen = 1000;

/**
 * Test to see if we hit this object with a mouse
 * @param x - X position to test
 * @param y - Y position to test
 * @return true if hit
 */
bool Item::HitTest(int x, int y)
{
    return false;
}


/**
 * Detects if item is off the screen
 * @return true- if pen is off screen
 */
bool Item::IsOffScreen()
{
    // checks if pen is off-screen
    if (GetX()>rightOfScreen || GetX()<leftOfScreen || GetY()>bottomOfScreen || GetY()<topOfScreen) {
        return true;
    }

    return false;
}

/**
 * Destructor
 */
Item::~Item()
{
}

/**
 * Constructor
 * @param umlWars - The UML Wars game this item is a member of
 */
Item::Item(UMLWars* umlWars)
        :mUMLWars(umlWars)
{
}





