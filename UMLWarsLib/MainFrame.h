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

    /// About menu option
    void OnAbout(wxCommandEvent &);

    /// Exit menu option
    void OnExit(wxCommandEvent &event);

public:

    /// Initialize function
    void Initialize();

    /// Standard menu option
    void OnVariantStandard(wxCommandEvent& event);

    /// Custom menu option
    void OnVariantCustom(wxCommandEvent& event);

    /// Close windown option
    void OnClose(wxCloseEvent& event);
};

#endif //UMLWARS_MAINFRAME_H