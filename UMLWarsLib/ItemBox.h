/**
 * @file ItemBox.h
 * @author hemke
 *
 *
 */

#ifndef UMLWARS_ITEMBOX_H
#define UMLWARS_ITEMBOX_H

#include "Item.h"
#include "ElementHolder.h"
#include <vector>

/**
 * Class for box item
 */
class ItemBox : public Item{
private:

    /// Variable with x direction
    double mXDir = 0;

    /// Variable with y direction
    double mYDir = 0;

    /// Variable holding direction
    double mDirection = 1;

    /// Vector holding all attributes
    std::vector<ElementHolder> mAttributes;

    /// Vector holding all operations
    std::vector<ElementHolder> mOperations;

    /// wxString holding class names
    wxString mClassName;

    /// Variable holding height of box
    double mHeight = 0;

    /// Width of box
    double mWidth = 0;

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
    ItemBox() = delete;

    /// Copy constructor (disabled)
    ItemBox(const ItemBox &) = delete;

    /// Assignment operator
    void operator=(const ItemBox &) = delete;

    /// Default constructor
    ItemBox(UMLWars* umlWars, bool good = true);

    /// Update function
    virtual void Update(double elapsed) override;

    /// Function to draw box
    void Draw(wxGraphicsContext* graphics);

    /**
    * The width of the item
    * @return width in pixels
    */
    double GetWidth() const { return mWidth; }

    /**
     * The height of the item
     * @return height in pixels
     */
    double GetHeight() const { return mHeight; }

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

#endif //UMLWARS_ITEMBOX_H
