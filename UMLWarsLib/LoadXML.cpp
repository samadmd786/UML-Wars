/**
 * @file LoadXML.cpp
 * @author Aesha Ray
 */
#include "pch.h"
#include <random>
#include "LoadXML.h"

/**
 * Const for XML file
 * @return wxString of file
 */
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
                    const ElementHolderInheritance inheritedClassItem(child->GetAttribute("base"), child->GetAttribute("derived"), "");
                    mInherited.push_back(inheritedClassItem);
                }else{
                    const ElementHolderInheritance badInheritedClassItem(child->GetAttribute("base"), child->GetAttribute("derived"), child->GetAttribute("bad"));
                    mBadInherited.push_back(badInheritedClassItem);
                }
            }
        }
    }
}

/**
 * Get Class Name
 * @param good to true
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
 * @param good to true
 * @return element ElementHolder item with the good/bad attributes
*/
std::vector<ElementHolder> LoadXML::GetAttributes(bool good) {
    std::random_device rd;
    std::mt19937 rand(rd());

    std::shuffle(mAttributes.begin(), mAttributes.end(), rand);
    std::shuffle(mBadAttributes.begin(), mBadAttributes.end(), rand);
    std::vector<ElementHolder> attrs;

    if(good) {
        std::uniform_int_distribution<int> distribution(0,3);
        int limit = distribution(rand);
        for (size_t i = 0; i < limit; ++i)
        {
            attrs.push_back(mAttributes[i]);
        }
        return attrs;
    }

    std::uniform_int_distribution<int> distribution(0,2);
    int limit = distribution(rand);
    for (size_t i = 0; i < limit; ++i)
    {
        attrs.push_back(mAttributes[i]);
    }
    attrs.push_back(mBadAttributes[0]);
    std::shuffle(attrs.begin(), attrs.end(), rand);
    return attrs;
}

/**
 * Get Random Attributes
 * @param good to true
 * @return element ElementHolder item with the good/bad attributes
*/
std::vector<ElementHolder> LoadXML::GetOperations(bool good) {
    std::random_device rd;
    std::mt19937 rand(rd());

    std::shuffle(mOperations.begin(), mOperations.end(), rand);
    std::shuffle(mBadOperations.begin(), mBadOperations.end(), rand);
    std::vector<ElementHolder> operations;

    if(good) {
        std::uniform_int_distribution<int> distribution(0,3);
        int limit = distribution(rand);
        for (size_t i = 0; i < limit; ++i)
        {
            operations.push_back(mOperations[i]);
        }
        return operations;
    }

    std::uniform_int_distribution<int> distribution(0,2);
    int limit = distribution(rand);
    for (size_t i = 0; i < limit; ++i)
    {
        operations.push_back(mOperations[i]);
    }
    operations.push_back(mBadOperations[0]);
    std::shuffle(operations.begin(), operations.end(), rand);
    return operations;
}

/**
 * Get random inheritance
 */
ElementHolderInheritance LoadXML::GetInheritance(bool good){
    std::random_device rd;
    std::mt19937 rand(rd());

    std::shuffle(mInherited.begin(), mInherited.end(), rand);
    std::shuffle(mBadInherited.begin(), mBadInherited.end(), rand);

    return good ? mInherited[0] : mBadInherited[0];

}