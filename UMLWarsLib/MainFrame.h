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

    bool mStandard = true;


public:
    void Initialize();

    void OnVariantStandard(wxCommandEvent& event);

    void OnVariantCustom(wxCommandEvent& event);
};

#endif //UMLWARS_MAINFRAME_H