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
    /// An object that describes our UML Wars game
    UMLWars mUMLWars;

    void OnPaint(wxPaintEvent& event);
    void OnMouseMove(wxMouseEvent &event);

    /// The timer that allows for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

public:
    UMLWarsView();
    void Initialize(wxFrame *parent);

    void OnTimer(wxTimerEvent& event);
};

#endif //UMLWARS_UMLWARSVIEW_H
