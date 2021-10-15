/**
 * @file BoxClass.h
 * @author hemke
 *
 *
 */

#ifndef UMLWARS_BOXCLASS_H
#define UMLWARS_BOXCLASS_H

#include "Item.h"

class BoxClass : public Item{
private:
    double mXDir = 0;
    double mYDir = 0;
    double mDirection = 1;
    double mSpeed = 1;
public:

    /// Default constructor (disabled)
    BoxClass() = delete;

    /// Copy constructor (disabled)
    BoxClass(const BoxClass &) = delete;

    /// Assignment operator
    void operator=(const BoxClass &) = delete;

    BoxClass(UMLWars* umlWars);

    virtual void Update() override;

    void Draw(wxGraphicsContext* graphics);

    void SetSpeed(double speed) { mSpeed = speed; }
};

#endif //UMLWARS_BOXCLASS_H
