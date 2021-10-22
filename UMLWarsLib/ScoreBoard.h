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

    int mUnfair = 0;
    int mMissed = 0;
    int mCorrect = 0;

    public:

        /// Default constructor (disabled)
        ScoreBoard() = delete;

        /// Copy constructor (disabled)
        ScoreBoard(const ScoreBoard &) = delete;

        /// Assignment operator
        void operator=(const ScoreBoard &) = delete;

        ScoreBoard(UMLWars* umlWars);

        //virtual void Update(double elapsed) override;

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
