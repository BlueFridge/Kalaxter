#include "kalaxter.h"
#include <wx/wx.h>

class Calc : public wxApp
{
public:
    virtual bool OnInit();
};

bool Calc::OnInit()
{
    Kalaxter* calc = new Kalaxter();
    calc->Show(true);
    return true;
}

IMPLEMENT_APP(Calc)
