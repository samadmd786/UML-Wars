/**
 * @file ElementHolderInheritance.h
 * @author Andrew Haas
 *
 * class to hold Elements (inheritance) in XML file
 */

#ifndef UMLWARS_ELEMENTHOLDERINHERITANCE_H
#define UMLWARS_ELEMENTHOLDERINHERITANCE_H

#include "ElementHolder.h"

/**
 * class to hold Elements (inheritance) in XML file
 */
class ElementHolderInheritance : public ElementHolder{
private:
    /// the name of the derived class in the relationship
    wxString mDerivedName;

public:


    /**
     * Function setting name of class and if class is bad
     * @param base name the of the base class
     * @param derived name of the derived class
     * @param bad reason whether relationship is bad
     * @return void
     */
    ElementHolderInheritance(wxString base, wxString derived, wxString bad) : ElementHolder(base, bad) {
        mDerivedName = derived;
    }

    /**
     * Getter for the derived class name
     * @return wxString mDerivedName
     */
    wxString GetDerivedName(){
        return mDerivedName;
    }


};

#endif //UMLWARS_ELEMENTHOLDERINHERITANCE_H
