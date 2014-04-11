#ifndef KALAXTER_H
#define KALAXTER_H
#include <wx/wx.h>

class Kalaxter : public wxFrame
{
private:
    double memory;
    double result;
    int trigger;
    char operation;
    bool isOperatorsEnabled;
    bool isEqualEnabled;
    bool isDecimalEnabled;
    bool decimalPlaced;

    wxBoxSizer* bSizer;
    wxGridSizer* grid;

    wxButton* button1;
    wxButton* button2;
    wxButton* button3;
    wxButton* button4;
    wxButton* button5;
    wxButton* button6;
    wxButton* button7;
    wxButton* button8;
    wxButton* button9;
    wxButton* button0;
    wxButton* buttonP;
    wxButton* buttonM;
    wxButton* buttonMu;
    wxButton* buttonD;
    wxButton* buttonE;
    wxButton* buttonC;
    wxButton* buttonDec;
    wxButton* buttonBak;
    wxButton* buttonSqrt;

    wxTextCtrl* resultBox;

    void button1Clicked(wxCommandEvent &event);
    void button2Clicked(wxCommandEvent &event);
    void button3Clicked(wxCommandEvent &event);
    void button4Clicked(wxCommandEvent &event);
    void button5Clicked(wxCommandEvent &event);
    void button6Clicked(wxCommandEvent &event);
    void button7Clicked(wxCommandEvent &event);
    void button8Clicked(wxCommandEvent &event);
    void button9Clicked(wxCommandEvent &event);
    void button0Clicked(wxCommandEvent &event);
    void buttonPlusClicked(wxCommandEvent &event);
    void buttonMinusClicked(wxCommandEvent &event);
    void buttonMulClicked(wxCommandEvent &event);
    void buttonDivClicked(wxCommandEvent &event);
    void buttonEqClicked(wxCommandEvent &event);
    void buttonClsClicked(wxCommandEvent &event);
    void buttonDecimalClicked(wxCommandEvent &event);
    void buttonBackspaceClicked(wxCommandEvent &event);
    void buttonSqrtClicked(wxCommandEvent &event);

    enum Buttons{but1=10,but2,but3,but4,but5,but6,but7,but8,but9,but0,
    butP,butM,butMu,butD,butE,butC,butDec,butBak,butSqrt};

    DECLARE_EVENT_TABLE()
public:
    Kalaxter();
    ~Kalaxter();
};

#endif
