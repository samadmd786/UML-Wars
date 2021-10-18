/**
 * @file ElementHolder.h
 * @author hemke
 *
 *
 */

#ifndef UMLWARS_ELEMENTHOLDER_H
#define UMLWARS_ELEMENTHOLDER_H

class ElementHolder {
private:
    /// name of the element
    wxString mName;
    /// bad string holder
    wxString mBad;
public:
    ElementHolder(wxString name, wxString bad) {
        mName = name;
        mBad = bad;
    }
    wxString GetName() {
        return mName;
    }
    wxString GetBad() {
        return mBad;
    }
};

#endif //UMLWARS_ELEMENTHOLDER_H
