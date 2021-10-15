/**
 * @file Item.h
 * @author Josh Erno
 *
 *  Base class for all items in the UML Wars game
 */

#ifndef UMLWARS_ITEM_H
#define UMLWARS_ITEM_H

#include <memory>

class UMLWars;

/**
 * Base class for any item in our UML War game
 */
class Item {
private:
    /// The UML War game this item is contained in
    UMLWars *mUMLWars;

    /// The underlying item image
    std::unique_ptr<wxImage> mItemImage;

    /// Bitmap for the item in question
    wxGraphicsBitmap mItemBitmap;

    // Item location in the UMLWars window
    double mX = 0;      ///< X location for the center of the item in virtual pixels
    double mY = 0;      ///< Y location for the center of the item in virtual pixels

    /// Rotation angle for the item
    double mRotation;

public:
    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    /// Assignment operator
    void operator=(const Item &) = delete;

    /**
    * The X location of the item
    * @return X location in pixels
    */
    double GetX() const { return mX; }

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    double GetY() const { return mY; }

    /**
     * Set the Y location of an item in pixels
     * @param newX the new x coordinate
     */
     void SetX(double newX) { mX = newX; }

    /**
     * Set the Y location of an item in pixels
     * @param newY the new y coordinate
     */
     void SetY(double newY) { mY = newY; }

    /**
     * Gets the current rotation
     * @return the rotation angle
     */
     double GetRotation() { return mRotation; }

    /**
     * Set the rotation of an image
     * @param newRotation the new rotation
     */
     void SetRotation(double newRotation) { mRotation = newRotation; }

    /**
    * Get the pointer to the UML War game object
    * @return Pointer to UML War game object
    */
    UMLWars* GetUMLWars() { return mUMLWars; }

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }

    virtual void Draw(wxGraphicsContext* graphics);

    //    virtual bool HitTest(int x, int y);

    /**
    * Handle updates for animation
    */
    virtual void Update() {}

    virtual ~Item();

protected:
    Item(UMLWars* umlWars, const std::wstring &filename);

};

#endif //UMLWARS_ITEM_H
