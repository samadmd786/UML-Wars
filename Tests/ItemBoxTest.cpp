/**
 * @file ItemBoxTest.cpp
 * @author Md Samad
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <ItemBox.h>
#include <UMLWars.h>

/**
* Mock class for testing the class ItemHarold
*/
class ItemBoxMock : public ItemBox {
public:
    ItemBoxMock(UMLWars* umlWars)
            :ItemBox(umlWars) { }

    void Draw(wxGraphicsContext* graphics) override { }
};

TEST(ItemBoxTest, Construct)
{
    UMLWars umlWars;
    ItemBoxMock box(&umlWars);
}

TEST(ItemBoxTest, Positon)
{
    UMLWars umlWars;
    ItemBoxMock box(&umlWars);

    ASSERT_NEAR(-364.522, box.GetX(), 0.001);
    ASSERT_NEAR(0, box.GetY(), 0.001);

    box.SetX(0);
    box.SetY(10);

    ASSERT_NEAR(0, box.GetX(), 0.001);
    ASSERT_NEAR(10, box.GetY(), 0.001);

    box.SetX(100);
    box.SetY(500);

    ASSERT_NEAR(100, box.GetX(), 0.001);
    ASSERT_NEAR(500, box.GetY(), 0.001);
}

TEST(ItemBoxTest, Size)
{
    UMLWars umlWars;
    ItemBoxMock box(&umlWars);

    ASSERT_NEAR(0, box.GetWidth(), 0.001);
    ASSERT_NEAR(0, box.GetHeight(), 0.001);



}

TEST(ItemBoxTest, Speed)
{
    UMLWars umlWars;
    ItemBoxMock box(&umlWars);

    ASSERT_EQ(1, box.GetSpeed());

    box.SetSpeed(5);

    ASSERT_EQ(5, box.GetSpeed());

}

TEST(ItemBoxTest, Rotate)
{
    UMLWars umlWars;
    ItemBoxMock box(&umlWars);

    ASSERT_NEAR(0, box.GetRotation(), 0.001);

    box.SetRotation(5);

    ASSERT_NEAR(5, box.GetRotation(), 0.001);

    ASSERT_FALSE(box.GetRotateVariant());

    box.SetRotationVariant(true);

    ASSERT_TRUE(box.GetRotateVariant());

    box.SetRotationVariant(false);

    ASSERT_FALSE(box.GetRotateVariant());

}


