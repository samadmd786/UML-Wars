project(UMLWarsLib)

set(SOURCE_FILES MainFrame.cpp MainFrame.h pch.h UMLWarsView.cpp UMLWarsView.h UMLWars.cpp UMLWars.h ids.h Item.h Item.cpp ItemHarold.cpp ItemHarold.h ItemBox.cpp ItemBox.h GraphicsItem.cpp GraphicsItem.h ItemPen.cpp ItemPen.h LoadXML.cpp LoadXML.h ElementHolder.cpp ElementHolder.h ScoreBoard.cpp ScoreBoard.h ItemBoxInheritance.cpp ItemBoxInheritance.h ElementHolderInheritance.cpp ElementHolderInheritance.h)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)