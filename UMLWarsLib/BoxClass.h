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

public:

    /// Default constructor (disabled)
    BoxClass() = delete;

    /// Copy constructor (disabled)
    BoxClass(const BoxClass &) = delete;

    /// Assignment operator
    void operator=(const BoxClass &) = delete;

    BoxClass(UMLWars* umlWars);

    virtual void Update() override;
};

#endif //UMLWARS_BOXCLASS_H
