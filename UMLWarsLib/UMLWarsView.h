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
    /// The timer that allows for animation
    wxTimer mTimer;
    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;
    /// last stopwatch time
    long long mTime = 0;

    double mCurrentSpeed = 1;

    long long mLastBox = 0;

    // private functions
    void OnPaint(wxPaintEvent& event);
    void OnMouseMove(wxMouseEvent &event);
    void OnLeftDown(wxMouseEvent &event);

public:
    UMLWarsView();
    void Initialize(wxFrame *parent);

    void OnTimer(wxTimerEvent& event);
};

#endif //UMLWARS_UMLWARSVIEW_H
