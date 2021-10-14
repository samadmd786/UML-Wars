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
    double mScale;
    double mXOffset;
    double mYOffset;
public:
    UMLWars();
    /// Size of the area we are going to draw on in pixels
    constexpr static double Size = 1000;

    std::vector<std::shared_ptr<Item>> mItems;

    void Add(std::shared_ptr<Item> item);
    void OnDraw(wxGraphicsContext* graphics, int width, int height);
};

#endif //UMLWARS_UMLWARS_H
