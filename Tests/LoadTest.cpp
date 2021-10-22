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


class LoadTest : public ::testing::Test {

};

TEST(LoadTest, Construct) {
    UMLWars umlwars;
}

TEST(LoadTest, GetClassName) {
    LoadXML loadXml;

    auto xmlFile = wxFileName::GetCwd() + "/../uml.xml";
    //umlwars.LoadXML(xmlfile);

    ASSERT_EQ(loadXml.GetClassName(true), true);
    ASSERT_EQ(loadXml.GetClassName(false), false);
}

TEST(LoadTest, GetAttributes) {
    LoadXML loadXml;

    auto xmlFile = wxFileName::GetCwd() + "/../uml.xml";
    //umlwars.LoadXML(xmlfile);

    ASSERT_EQ(loadXml.GetAttributes(true), true);
    ASSERT_EQ(loadXml.GetAttributes(false), false);

}