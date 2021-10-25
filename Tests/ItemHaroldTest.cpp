/**
 * @file ItemHaroldTest.cpp
 * @author Md Samad
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <ItemHarold.h>
#include <UMLWars.h>

/// constant for pi
const double pi = 3.1415;

/// constant for radial offset from Harold
const double offsetRadial = 61.3;

/// constant for angular offset from Harold
const double offsetAngular = -1.078;

/**
* Mock class for testing the class ItemHarold
*/
class ItemHaroldMock : public ItemHarold
{
public:
    ItemHaroldMock(UMLWars* umlWars) : ItemHarold(umlWars) {}

    void Draw(wxGraphicsContext* graphics) override {}
};

TEST(ItemHaroldTest, Construct)
{
UMLWars umlWars;
ItemHaroldMock Harold(&umlWars);
}

TEST(ItemHaroldTest, Reset)
{
UMLWars umlWars;
ItemHaroldMock Harold(&umlWars);

ASSERT_NEAR(0, Harold.GetX(), 0.0001);
ASSERT_NEAR(0, Harold.GetY(), 0.0001);

Harold.SetX(100.0);
Harold.SetY(100.0);

ASSERT_NEAR(100.0, Harold.GetX(), 0.0001);
ASSERT_NEAR(100.0, Harold.GetY(), 0.0001);


//    Harold.Reset();
//
//    ASSERT_NEAR(29, Harold.GetX(), 0.0001);
//    ASSERT_NEAR(846, Harold.GetY(), 0.0001);





}















