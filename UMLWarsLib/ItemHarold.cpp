/**
 * @file ItemHarold.cpp
 * @author hemke
 */

#include "ItemHarold.h"

using namespace std;

/// Harold filename
const wstring HaroldImageName = L"images/harold.png";

/**
 * Constructor
 * @param umlwars Aquarium this fish is a member of
 */
ItemHarold::ItemHarold(UMLWars *umlWars) : Item(umlWars, HaroldImageName)
{

}
