/**
 * @file ElementHolder.h
 * @author hemke
 *
 *
 */

#ifndef UMLWARS_ELEMENTHOLDER_H
#define UMLWARS_ELEMENTHOLDER_H

/**
 * class to hold Elements in XML file
 */
class ElementHolder {
private:
    /// name of the element
    wxString mName;
    /// bad string holder
    wxString mBad;
public:
    /**
     * Function setting name of class and if class is bad
     * @param name, bad name of element and if bad
     * @return void
     */
    ElementHolder(wxString name, wxString bad) {
        mName = name;
        mBad = bad;
    }

    /**
      * Getter for name of element
      * @return class name
      */
    wxString GetName() {
        return mName;
    }

    /**
     * Getter indicating if element is bad
     * @return mbad
     */
    wxString GetBad() {
        return mBad;
    }
};

#endif //UMLWARS_ELEMENTHOLDER_H
