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
    UMLWars* mUMLWars;

    // Item location in the UMLWars window
    double mX = 0;      ///< X location for the center of the item in virtual pixels
    double mY = 0;      ///< Y location for the center of the item in virtual pixels

    /// Rotation angle for the item
    double mRotation = 0;

    /// Speed for the item
    double mSpeed = 0;

    /// Unique ID
    long mID = 0;

public:
    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item&) = delete;

    /// Assignment operator
    void operator=(const Item&) = delete;

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
     * Getter for the speed of the item
     * @return Item speed
     */
    double GetSpeed() { return mSpeed; }

    /**
     * Sets the speed of the item
     * @param speed the new speed
     */
    void SetSpeed(double speed) { mSpeed = speed; }

    /**
     * Getter for the id of the item
     * @return Item id
     */
    long GetID() { return mID; }

    /**
     * Sets the ID of the item
     * @param id the new ID
     */
    void SetID(long id) { mID = id; }

    /**
    * Get the pointer to the UML War game object
    * @return Pointer to UML War game object
    */
    UMLWars* GetUMLWars() { return mUMLWars; }

    virtual void Draw(wxGraphicsContext* graphics);

    virtual bool HitTest(int x, int y);

    /**
    * Handle updates for animation
    */
    virtual void Update(double elapsed) { }

    bool IsOffScreen();

    virtual ~Item();

    /**
     * Handles launch of an item
     */
    virtual void Launch() {};

    /**
     * Handles launch of an item
     */
    virtual void Reset() {};

protected:
    Item(UMLWars* umlWars);

};

#endif //UMLWARS_ITEM_H
