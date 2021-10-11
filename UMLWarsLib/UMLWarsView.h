/**
 * @file UMLWarsView.h
 * @author hemkesh
 *
 *
 */

#ifndef UMLWARS_UMLWARSVIEW_H
#define UMLWARS_UMLWARSVIEW_H

/**
 * View class for our UMLWARS
 */
class UMLWarsView : public wxWindow {
private:
    void OnPaint(wxPaintEvent& event);
public:
    void Initialize(wxFrame *);
};

#endif //UMLWARS_UMLWARSVIEW_H
