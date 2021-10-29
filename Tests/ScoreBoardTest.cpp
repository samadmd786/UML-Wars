/**
 * @file ScoreBoardTest.cpp
 * @author hemke
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <ScoreBoard.h>
#include <UMLWars.h>

/**
* Mock class for testing the class ItemPen
*/
class ScoreboardMock : public ScoreBoard
{
public:
    ScoreboardMock(UMLWars* umlWars) : ScoreBoard(umlWars) {}

    void Draw(wxGraphicsContext* graphics) override {}
};

TEST(ScoreBoardTest, Construct)
{
    UMLWars umlWars;
    ScoreboardMock scoreboard(&umlWars);
}

TEST(ScoreboardValTest, Reset)
{
    UMLWars umlWars;
    ScoreboardMock scoreboard(&umlWars);

    scoreboard.IncCorrect();
    scoreboard.IncCorrect();
    ASSERT_TRUE(scoreboard.RetCorrect() == 2);

    scoreboard.IncMissed();
    scoreboard.IncMissed();
    ASSERT_TRUE(scoreboard.RetMissed() == 2);

    scoreboard.IncUnfair();
    scoreboard.IncUnfair();
    ASSERT_TRUE(scoreboard.RetUnfair() == 2);
}