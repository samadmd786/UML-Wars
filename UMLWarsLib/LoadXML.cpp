/**
 * @file LoadXML.cpp
 * @author Aesha Ray
 */
#include "LoadXML.h"


/**
 * Load XML file
 * @param fileXML file directory
 */
void LoadXML::LoadUML(wxString fileXML)
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
                    const wxString goodClassItem = child->GetNodeContent();
                    if (nameNext == "name") {
                        mNames.push_back(goodClassItem);
                    }
                    else if (nameNext == "attribute") {
                        mAttributes.push_back(goodClassItem);
                    }
                    else if (nameNext == "operation") {
                        mOperations.push_back(goodClassItem);
                    }
                }else{
                    const wxString badClassItem = child->GetNodeContent();
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
            }else if(name == "inheritance"){
                if (child->GetAttribute("bad") == wxEmptyString){
                    const wxString inheritedClassItem = child->GetNodeContent();
                    mInherited.push_back(inheritedClassItem);
                }else{
                    const wxString badInheritedClassItem = child->GetNodeContent();
                    mBadInherited.push_back(badInheritedClassItem);
                }
            }
        }
    }
}