/**
 * @file ItemHarold.h
 * @author hemke
 */

#ifndef UMLWARS_ITEMHAROLD_H
#define UMLWARS_ITEMHAROLD_H

#include "GraphicsItem.h"

/**
 * Class for Harold item
 */
class ItemHarold : public GraphicsItem{

private:
    /// Tells whether Harold is sliding. zero is no slide, negative is left slide, positive is right slide.
    double mSliding = 0;

    /// whether harold is holding a fast pen. Zero is no, -1 is yes (and move down), 1 is yes (and move up)
    int mFastPen = 0;

public:
    /// Default constructor (disabled)
    ItemHarold() = delete;

    /// Copy constructor (disabled)
    ItemHarold(const ItemHarold &) = delete;

    /// Assignment operator
    void operator=(const ItemHarold &) = delete;

    /// Setter for Sliding
    void SetSliding(double slide) {mSliding = slide; }

    /// Getter for sliding
    double GetSliding() {return mSliding;}

    /// Setter for fast pen
    void SetFastPen(int fast) {mFastPen = fast; }

    /// Getter for fast pen
    int GetFastPen() {return mFastPen; }

    /// Default constructor
    ItemHarold(UMLWars* umlWars);

    ///Update function
    virtual void Update(double elapsed) override;

};

#endif //UMLWARS_ITEMHAROLD_H
