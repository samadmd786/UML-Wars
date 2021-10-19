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
#include "LoadXML.h"
#include "ItemBox.h"

class Item;

class UMLWars {
private:

    // virtual pixel information
    double mScale;   ///< scale for virtual pixel conversion
    double mXOffset; ///< X offset for virtual pixel conversion
    double mYOffset; ///< Y offset for virtual pixel conversion

    // mouse location information
    double mMouseX = 0; ///< x coordinate of the mouse in virtual pixels
    double mMouseY = 0; ///< y coordinate of the mouse in virtual pixels

    /// xml data holder
    LoadXML mXML;

    /// Random number generator
    std::mt19937 mRandom;

    /// Harold Pointer
    std::shared_ptr<ItemHarold> mHarold;
    std::shared_ptr<ItemBox> mItemBox;

    /// Pointer for most recently added pen object
    std::shared_ptr<ItemPen> mPen;

    /// Vector of items
    std::vector<std::shared_ptr<Item>> mItems;

    /// Vector of items to be removed
    std::vector<std::shared_ptr<Item>> mToRemove;

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
     * Getter for Harold
     * @return a shared pointer to harold
     */
    std::shared_ptr<ItemHarold> GetHarold() { return mHarold; }

    /**
     * Setter for the most recent pen
     * @param pen a pointer to the pen
     */
    void SetPen(std::shared_ptr<ItemPen> pen) { mPen = pen; }

    /**
     * Getter for the most recent pen
     * @return a shared pointer to the pen
     */
    std::shared_ptr<ItemPen> GetPen() { return mPen; }

    void Add(std::shared_ptr<Item> item);

    void AddToRemove(std::shared_ptr<Item> item);

    void Remove(std::shared_ptr<Item> item);

    bool LaunchPen();

    void ResetPen();

    void OnDraw(wxGraphicsContext* graphics, int width, int height);

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

    void DeleteBox();


};

#endif //UMLWARS_UMLWARS_H
