/**
 * @file UMLWars.h
 * @author hemkesh
 *
 *
 */

#ifndef UMLWARS_UMLWARS_H
#define UMLWARS_UMLWARS_H

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


public:
    UMLWars();
    /// Size of the area we are going to draw on in pixels
    constexpr static double Size = 1000;

    std::vector<std::shared_ptr<Item>> mItems;

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
    void SetMouseX(double oX) { mMouseX = (oX - mXOffset)/mScale; }

    /**
     * Setter for the mouse y coordinate
     * @param oY the y coordinate
     */
    void SetMouseY(double oY) { mMouseY = (oY - mYOffset)/mScale; }

    void Add(std::shared_ptr<Item> item);
    void OnDraw(wxGraphicsContext* graphics, int width, int height);
};

#endif //UMLWARS_UMLWARS_H
