/**
 * @file UMLWarsView.h
 * @author hemkesh
 *
 *
 */

#ifndef UMLWARS_UMLWARSVIEW_H
#define UMLWARS_UMLWARSVIEW_H
#include "UMLWars.h"

/**
 * View class for our UMLWARS
 */
class UMLWarsView : public wxWindow {
private:
    void OnPaint(wxPaintEvent& event);

    /// The timer that allows for animation
    wxTimer mTimer;

    UMLWars mUMLWars;
public:
    UMLWarsView();

    void Initialize(wxFrame *parent);

    /**
     * Stop the timer so the window can close
     */
    void Stop() {mTimer.Stop();}
};

#endif //UMLWARS_UMLWARSVIEW_H
