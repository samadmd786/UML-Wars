/**
 * @file MainFrame.h
 * @author hemkesh
 *
 * The top-level (main) frame of the application
 */

#ifndef UMLWARS_MAINFRAME_H
#define UMLWARS_MAINFRAME_H
#include "UMLWarsView.h"

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame {
private:
    /// View class for our Demo
    UMLWarsView *mUMLWarsView;
    void OnAbout(wxCommandEvent &);
    void OnExit(wxCommandEvent &event);

public:
    void Initialize();
};

#endif //UMLWARS_MAINFRAME_H