/**
 * @file UMLWars.h
 * @author hemkesh
 *
 *
 */

#ifndef UMLWARS_UMLWARS_H
#define UMLWARS_UMLWARS_H

#include <random>
#include <memory>
#include "Item.h"
#include "GraphicsItem.h"
#include "ItemHarold.h"
#include "ItemPen.h"
#include "ScoreBoard.h"
#include "LoadXML.h"
#include "ItemBox.h"

/**
 * Item class
 */
class Item;
/**
 * Class for UMLWars game
 */
class UMLWars {
private:

    // virtual pixel information
    double mScale;   ///< scale for virtual pixel conversion
    double mXOffset; ///< X offset for virtual pixel conversion
    double mYOffset; ///< Y offset for virtual pixel conversion
    long mLastID = 0; ///< Last ID of the item

    // mouse location information
    double mMouseX = 0; ///< x coordinate of the mouse in virtual pixels
    double mMouseY = 0; ///< y coordinate of the mouse in virtual pixels

    /// rotation speed for boxes
    double mRotationSpeed = 1;

    /// xml data holder
    LoadXML mXML;

    /// Random number generator
    std::mt19937 mRandom;

    /// Harold Pointer
    std::shared_ptr<ItemHarold> mHarold;

    /// Vector of items
    std::vector<std::shared_ptr<Item>> mItems;

    /// Pen Pointer
    std::shared_ptr<ItemPen> mPen;

    /// Item to be removed
    long mItemToRemove = -1;

    /// Custom
    bool mCustom;

    /// mBackground
    std::shared_ptr<wxImage> mBackground;

    /// Bitmap for the item in question
    wxGraphicsBitmap mBackgroundBitmap;

public:
    UMLWars();

    /// Size of the area we are going to draw on in pixels
    constexpr static double Size = 1000;

    /**
     * Getter for the mouse x position
     * @return mouse x coordinate
     */
    double GetMouseX() const { return mMouseX; }

    /**
     * Getter for the mouse y coordinate
     * @return mouse y coordinate
     */
    double GetMouseY() const { return mMouseY; }

    /**
     * Setter for the mouse x coordinate
     * @param oX the x coordinate
     */
    void SetMouseX(double oX) { mMouseX = (oX-mXOffset)/mScale; }

    /**
     * Setter for the mouse y coordinate
     * @param oY the y coordinate
     */
    void SetMouseY(double oY) { mMouseY = (oY-mYOffset)/mScale; }

    /**
     * Setter for Harold
     * @param harold a pointer to harold
     */
    void SetHarold(std::shared_ptr<ItemHarold> harold) { mHarold = harold; }

    /**
     * Setter for custom background
     * @param cus a pointer to harold
     */
    void SetCustom(bool cus) { mCustom = cus; }

    /**
     * Getter for Harold
     * @return a shared pointer to harold
     */
    std::shared_ptr<ItemHarold> GetHarold() { return mHarold; }

    /**
     * Getter for the pen
     * @return a shared pointer to the pen
     */
    std::shared_ptr<ItemPen> GetPen() { return mPen; }

    /**
     * Setter for the pen pointer
     */
    void SetPen(std::shared_ptr<ItemPen> pen) {mPen = pen;}

    /**
     * Getter for the scoreboard
     * @param board a pointer to the scoreboard
     * @return shared_ptr<Item>
     */
     std::shared_ptr<Item> GetScoreBoard() { return mItems[2]; }

     /// Add function
    void Add(std::shared_ptr<Item> item);

    /**
    * Remove add function
    */
    void AddToRemove(long id);

    /**
    * Remove function
    * @param item to remove
    */
    void Remove(std::shared_ptr<Item> item);

    /**
    * Remove function
    * @return void
    */
    void LaunchPen();

    /// Function to reset pen
    void ResetPen();

    ///Function to draw window
    void OnDraw(wxGraphicsContext* graphics, int width, int height);

    ///Update function
    void Update(double elapsed);

    /**
     * Get the random number generator
     * @return Pointer to the random number generator
     */
    std::mt19937& GetRandom() { return mRandom; }

    /**
     * Get the XML
     * @return get the xml loaded
     */
    LoadXML GetXML() { return mXML; }

    /// Delete box function
    void DeleteBox();

    /// Setter for rotation speed
    void SetRotationSpeed(double speed) {mRotationSpeed = speed;}

    /// Getter for Rotation Speed
    double GetRotationSpeed() {return mRotationSpeed; }


};

#endif //UMLWARS_UMLWARS_H
