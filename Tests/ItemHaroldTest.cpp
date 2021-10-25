/**
 * @file ItemHaroldTest.cpp
 * @author Md Samad
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <ItemHarold.h>
#include <UMLWars.h>

/**
* Mock class for testing the class ItemHarold
*/
class ItemHaroldMock : public ItemHarold {
public:
    ItemHaroldMock(UMLWars* umlWars)
            :ItemHarold(umlWars) { }

    void Draw(wxGraphicsContext* graphics) override { }
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


}















