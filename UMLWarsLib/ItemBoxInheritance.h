/**
 * @file ItemBoxInheritance.h
 * @author Andrew Haas
 *
 *
 */

#ifndef UMLWARS_ITEMBOXINHERITANCE_H
#define UMLWARS_ITEMBOXINHERITANCE_H

#include "Item.h"
#include "ElementHolder.h"
#include <vector>

class ItemBoxInheritance : public Item{
private:

    /// holds attributes for the base class
    std::vector<ElementHolder> mBaseAttributes;

    /// holds attributes in the derived class
    std::vector<ElementHolder> mDerivedAttributes;

    /// holds operations for the base class
    std::vector<ElementHolder> mBaseOperations;

    /// holds operations in the derived class
    std::vector<ElementHolder> mDerivedOperations;

    /// name for base class
    wxString mBClassName;

    /// name for derived class
    wxString mDClassName;

    /// bad string
    wxString mBad;

    // we'll need height and width members for the base and derived box
    /// base height
    double mBHeight = 0;

    /// base width
    double mBWidth = 0;

    /// derived height
    double mDHeight = 0;

    /// derived width
    double mDWidth = 0;

    /// x direction
    double mXDir = 0;

    /// y direction
    double mYDir = 0;

    /// movement direction
    double mDirection = 1;

    /// Indicate if box class is good
    bool mGood = true;

    /// Indicate if box class is bad
    bool mError = false;

    /// wxString holding error message
    wxString mMsgString;

    /// Destroy time
    double mDestroyTime = 0;

    /// Current time
    double mCurrentTime = 0;

    /// If true boxes will rotate while falling down
    bool mRotateVariant = false;

public:

    /// Default constructor (disabled)
    ItemBoxInheritance() = delete;

    /// Copy constructor (disabled)
    ItemBoxInheritance(const ItemBoxInheritance &) = delete;

    /// Assignment operator (disabled)
    void operator=(const ItemBoxInheritance &) = delete;

    /// Default constructor
    ItemBoxInheritance(UMLWars* umlWars, bool good = true);

    /// update function
    virtual void Update(double elapsed) override;

    /// drawing
    void Draw(wxGraphicsContext* graphics);

    /**
     * The base width of the item
     * @return width in pixels
     */
    double GetBWidth() const { return mBWidth; }

    /**
     * The base height of the item
     * @return height in pixels
     */
    double GetBHeight() const { return mBHeight; }

    /**
     * The derived width of the item
     * @return width in pixels
     */
    double GetDWidth() const { return mDWidth; }

    /**
     * The derived height of the item
     * @return height in pixels
     */
    double GetDHeight() const { return mDHeight; }

    /**
     * Getter for rotation variant
     * @return true if box rotation is set, false otherwise
     */
    bool GetRotateVariant() { return mRotateVariant; }

    /**
     * Setter for rotation variant
     * @param rotate - true if box is being set to rotate
     */
    void SetRotationVariant(bool rotate) { mRotateVariant = rotate; }

    /// Function to detect if box is hit
    virtual bool HitTest(int x, int y);

};

#endif //UMLWARS_ITEMBOXINHERITANCE_H
