/**
 * @file LoadXML.cpp
 * @author Aesha Ray
 */
#include <random>
#include "LoadXML.h"

const wxString fileXML("data/uml.xml");

/**
 * Load XML file
 * @param fileXML file directory
 */
LoadXML::LoadXML()
{
    wxXmlDocument xmlDocument;
    xmlDocument.Load(fileXML);

    auto root = xmlDocument.GetRoot();
    auto classInherit = root->GetChildren();
    for(; classInherit; classInherit=classInherit->GetNext()) {
        auto name = classInherit->GetName();
        for (auto child = classInherit->GetChildren(); child; child = child->GetNext()) {
            auto nameNext = child->GetName();
            if (name == "class") {
                if (child->GetAttribute("bad") == wxEmptyString) {
                    const ElementHolder goodClassItem(child->GetNodeContent(), "");
                    if (nameNext == "name") {
                        mNames.push_back(goodClassItem);
                    }
                    else if (nameNext == "attribute") {
                        mAttributes.push_back(goodClassItem);
                    }
                    else if (nameNext == "operation") {
                        mOperations.push_back(goodClassItem);
                    }
                } else{
                    const ElementHolder badClassItem(child->GetNodeContent(), child->GetAttribute("bad"));
                    if (nameNext == "name") {
                        mBadNames.push_back(badClassItem);
                    }
                    else if (nameNext == "attribute") {
                        mBadAttributes.push_back(badClassItem);
                    }
                    else if (nameNext == "operation") {
                        mBadOperations.push_back(badClassItem);
                    }
                }
            } else if(name == "inheritance"){
                if (child->GetAttribute("bad") == wxEmptyString){
                    const ElementHolder inheritedClassItem(child->GetNodeContent(), "");
                    mInherited.push_back(inheritedClassItem);
                }else{
                    const ElementHolder badInheritedClassItem(child->GetNodeContent(), child->GetAttribute("bad"));
                    mBadInherited.push_back(badInheritedClassItem);
                }
            }
        }
    }
}

/**
 * Get Class Name
 * @param good, defaults to true
 * @return element ElementHolder item with the good/bad class
*/
ElementHolder LoadXML::GetClassName(bool good) {
    std::random_device rd;
    std::mt19937 rand(rd());

    std::shuffle(mNames.begin(), mNames.end(), rand);
    std::shuffle(mBadNames.begin(), mBadNames.end(), rand);
    return good ? mNames[0] : mBadNames[0];
}

/**
 * Get Random Attributes
 * @param good, defaults to true
 * @return element ElementHolder item with the good/bad class
*/
std::vector<ElementHolder> LoadXML::GetAttributes(bool good) {
    std::random_device rd;
    std::mt19937 rand(rd());

    std::shuffle(mAttributes.begin(), mAttributes.end(), rand);
    std::shuffle(mBadAttributes.begin(), mBadAttributes.end(), rand);
    return good ? mAttributes : mBadAttributes;
}