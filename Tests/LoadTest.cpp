/**
 * @file LaodTest.cpp
 * @author Aesha_Ray
 */

#include "gtest/gtest.h"
#include <pch.h>
#include <LoadXML.h>
#include <ElementHolder.h>
#include <UMLWars.h>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>

using namespace std;

TEST(LoadTest, GetClassName) {
    /// Load the xml object from UML Wars game
    UMLWars umlWars;
    LoadXML xml = umlWars.GetXML();

    /// Vector of all possible good classes
    std::vector<ElementHolder> goodClassVec = {
            ElementHolder("Employer", ""),
            ElementHolder("Timeline", ""),
            ElementHolder("Picture", ""),
            ElementHolder("Actor", "")
    };

    /// Vector of all possible bad classes
    std::vector<ElementHolder> badClassVec = {
            ElementHolder("employer", "Should be capitalized"),
            ElementHolder("", "Missing class name"),
            ElementHolder("movie", "Should be capitalized"),
            ElementHolder("Bank  Account", "No spaces in names"),
    };

    /// Get a random GOOD classname
    ElementHolder className = xml.GetClassName();

    bool exists = false;

    /// Check if the classname exists in the vector
    for (auto element : goodClassVec) {
        if (element.GetName() == className.GetName() && element.GetBad() == className.GetBad()) {
            exists = true;
        }
    }

    /// Should exist
    ASSERT_TRUE(exists);

    /// Get a random BAD classname
    className = xml.GetClassName(false);

    exists = false;

    /// Check if the classname exists in the vector
    for (auto element : badClassVec) {
        if (element.GetName() == className.GetName() && element.GetBad() == className.GetBad()) {
            exists = true;
        }
    }

    /// Should exist
    ASSERT_TRUE(exists);
}

TEST(LoadTest, GetAttributes) {
    /// Load the xml object from UML Wars game
    UMLWars umlWars;
    LoadXML xml = umlWars.GetXML();

    /// Vector of all possible good attrs
    std::vector<ElementHolder> goodAttrVec = {
            ElementHolder("age: int", ""),
            ElementHolder("location: string", ""),
            ElementHolder("description: string", ""),
            ElementHolder("time: double", ""),
            ElementHolder("frameRate: int", ""),
            ElementHolder("angle: double=0", "")
    };

    /// Vector of all possible bad attrs
    std::vector<ElementHolder> badAttrVec = {
            ElementHolder("mAge: int", "Language artifact"),
            ElementHolder("cofefe", "Missing type"),
            ElementHolder("is  empty: boolean", "No spaces in names"),
            ElementHolder("framerate: int", "Use camelCase"),
            ElementHolder("manager: Employee", "Should be association"),
            ElementHolder("v: vector&lt;double&gt;", "Language artifact"),
            ElementHolder("Age: double","Don't capitalize"),
            ElementHolder("numframes: int","Use camelCase"),
            ElementHolder("city: City", "Should be association"),
            ElementHolder("actor: Actor", "Should be association"),
    };

    /// Get all GOOD attributes
    std::vector<ElementHolder> goodAttrs = xml.GetAttributes();

    /// All attrs should be good
    for (auto element : goodAttrs) {
        bool exists = false;
        /// All attrs should be good
        for (auto attr : goodAttrVec) {
            if (element.GetName() == attr.GetName() && element.GetBad() == attr.GetBad()) {
                exists = true;
            }
        }
        /// Should exist
        ASSERT_TRUE(exists);
    }

    /// Get 0-2 GOOD attributes + 1 BAD attributes
    std::vector<ElementHolder> badAttrs = xml.GetAttributes(false);

    int numBad = 0;

    /// All attrs should be good
    for (auto element : badAttrs) {
        bool exists = false;
        /// Might be good
        for (auto attr : goodAttrVec) {
            if (element.GetName() == attr.GetName() && element.GetBad() == attr.GetBad()) {
                exists = true;
            }
        }
        if (exists == false) {
            /// should be bad
            for (auto attr : badAttrVec) {
                if (element.GetName() == attr.GetName() && element.GetBad() == attr.GetBad()) {
                    exists = true;
                    numBad++;
                }
            }
        }
        /// Should exist
        ASSERT_TRUE(exists);
    }

    /// There should only be 1 bad attribute
    ASSERT_EQ(numBad, 1);
}