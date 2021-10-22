/**
 * @file LoadXML.h
 * @author Aesha Ray
 */

#ifndef UMLWARS_LOADXML_H
#define UMLWARS_LOADXML_H

#include "ElementHolder.h"

/**
 * LoadXML class for loading the UML XML File
 */
class LoadXML{

private:
    /// List of good class names
    std::vector<ElementHolder> mNames;
    /// List of bad class names
    std::vector<ElementHolder> mBadNames;
    /// List of good attributes
    std::vector<ElementHolder> mAttributes;
    /// List of bad attributes
    std::vector<ElementHolder> mBadAttributes;
    /// List of good operations
    std::vector<ElementHolder> mOperations;
    /// List of bad oeprations
    std::vector<ElementHolder> mBadOperations;
    /// List of good inheritance
    std::vector<ElementHolder> mInherited;
    /// List of bad inheritance
    std::vector<ElementHolder> mBadInherited;

public:
    /// Constructor
    LoadXML();

    ElementHolder GetClassName(bool good = true);

    std::vector<ElementHolder> GetAttributes(bool good = true);

    std::vector<ElementHolder> GetOperations(bool good = true);
};


#endif //UMLWARS_LOADXML_H
