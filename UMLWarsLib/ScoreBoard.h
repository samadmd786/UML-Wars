/**
 * @file ScoreBoard.h
 * @author Josh Erno
 *
 * Class to display the score on the scoreboard
 */

#ifndef UMLWARS_SCOREBOARD_H
#define UMLWARS_SCOREBOARD_H

#include "pch.h"
#include "Item.h"


/**
 * Class to display the score on the scoreboard
 */
class ScoreBoard : public Item{
    private:

        ///Unfair count
        int mUnfair = 0;

        /// Missed count
        int mMissed = 0;

        ///Correct count
        int mCorrect = 0;

    public:

        /// Default constructor (disabled)
        ScoreBoard() = delete;

        /// Copy constructor (disabled)
        ScoreBoard(const ScoreBoard &) = delete;

        /// Assignment operator
        void operator=(const ScoreBoard &) = delete;

        /// Copy constructor
        ScoreBoard(UMLWars* umlWars);

        /**
         * Draw function for scoreboard
         * @param graphics
         */
        virtual void Draw(wxGraphicsContext* graphics) override;

        /**
         * Increments mUnfair by one
         */
        void IncUnfair() { mUnfair++; }

        /**
         * Increments mMissed by one
         */
        void IncMissed() { mMissed++; }

        /**
         * Increments mCorrect by one
         */
        void IncCorrect() { mCorrect++; }

    };

#endif //UMLWARS_SCOREBOARD_H
