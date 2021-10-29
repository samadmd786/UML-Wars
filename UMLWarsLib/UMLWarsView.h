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

    /// current speed variable
    double mCurrentSpeed = 1;

    /// Detect last box
    long long mLastBox = 0;

    /// OnPaint function
    void OnPaint(wxPaintEvent& event);

    /**
     * Detect on mouse move
     * @param event to find mouse coordinates
     */
    void OnMouseMove(wxMouseEvent &event);

    /**
     * Detect mouse click
     * @param event to find mouse click
     */
    void OnLeftDown(wxMouseEvent &event);

public:
    ///Constructor
    UMLWarsView();

    ///Initialize function
    void Initialize(wxFrame *parent);

    ///Timer function
    void OnTimer(wxTimerEvent& event);

    /**
     * Setter for custom
     * @param cus to detect if custom is selected
     */
    void SetCustom(bool cus) { mUMLWars.SetCustom(cus); }

    /**
     * Stop the timer so the window can close
     */
    void Stop() {mTimer.Stop();}
};

#endif //UMLWARS_UMLWARSVIEW_H
