//
// Created by Aesha Ray on 10/18/21.
//

#ifndef UMLWARS_LOADXML_H
#define UMLWARS_LOADXML_H


#include "UMLWars.h"
class UMLWars;

class LoadXML : public UMLWars {

private:
    /// List of good class names
    std::vector<wxString> mNames;
    /// List of bad class names
    std::vector<wxString> mBadNames;
    /// List of good attributes
    std::vector<wxString> mAttributes;
    /// List of bad attributes
    std::vector<wxString> mBadAttributes;
    /// List of good operations
    std::vector<wxString> mOperations;
    /// List of bad oeprations
    std::vector<wxString> mBadOperations;
    /// List of good inheritance
    std::vector<wxString> mInherited;
    /// List of bad inheritance
    std::vector<wxString> mBadInherited;

public:
    void LoadUML(wxString fileXML);

};


#endif //UMLWARS_LOADXML_H
