#include "kalaxter.h"
#include <string>
#include <cmath>

BEGIN_EVENT_TABLE(Kalaxter, wxFrame)
    EVT_BUTTON(but1, Kalaxter::button1Clicked)
    EVT_BUTTON(but2, Kalaxter::button2Clicked)
    EVT_BUTTON(but3, Kalaxter::button3Clicked)
    EVT_BUTTON(but4, Kalaxter::button4Clicked)
    EVT_BUTTON(but5, Kalaxter::button5Clicked)
    EVT_BUTTON(but6, Kalaxter::button6Clicked)
    EVT_BUTTON(but7, Kalaxter::button7Clicked)
    EVT_BUTTON(but8, Kalaxter::button8Clicked)
    EVT_BUTTON(but9, Kalaxter::button9Clicked)
    EVT_BUTTON(but0, Kalaxter::button0Clicked)
    EVT_BUTTON(butP, Kalaxter::buttonPlusClicked)
    EVT_BUTTON(butM, Kalaxter::buttonMinusClicked)
    EVT_BUTTON(butMu, Kalaxter::buttonMulClicked)
    EVT_BUTTON(butD, Kalaxter::buttonDivClicked)
    EVT_BUTTON(butE, Kalaxter::buttonEqClicked)
    EVT_BUTTON(butC, Kalaxter::buttonClsClicked)
    EVT_BUTTON(butDec, Kalaxter::buttonDecimalClicked)
    EVT_BUTTON(butBak, Kalaxter::buttonBackspaceClicked)
    EVT_BUTTON(butSqrt, Kalaxter::buttonSqrtClicked)
END_EVENT_TABLE()

Kalaxter::Kalaxter() : wxFrame(NULL, wxID_ANY, wxT("Kalaxter"), wxDefaultPosition, wxSize(220, 400))
{
    memory = 0;
    result = 0;
    trigger = 0;
    isOperatorsEnabled = false;
    isEqualEnabled = false;
    isDecimalEnabled = false;
    decimalPlaced = false;

    this->SetBackgroundColour(wxColour(*wxWHITE));

    this->bSizer = new wxBoxSizer(wxVERTICAL);
    this->grid = new wxGridSizer(3, 5, 5);

    this->resultBox = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize);
    this->resultBox->SetEditable(false);

    this->bSizer->Add(resultBox, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);

    wxSize buttonSize(50,50);

    this->button1 = new wxButton(this, but1, wxT("1"), wxDefaultPosition, buttonSize);
    this->button2 = new wxButton(this, but2, wxT("2"), wxDefaultPosition, buttonSize);
    this->button3 = new wxButton(this, but3, wxT("3"), wxDefaultPosition, buttonSize);
    this->button4 = new wxButton(this, but4, wxT("4"), wxDefaultPosition, buttonSize);
    this->button5 = new wxButton(this, but5, wxT("5"), wxDefaultPosition, buttonSize);
    this->button6 = new wxButton(this, but6, wxT("6"), wxDefaultPosition, buttonSize);
    this->button7 = new wxButton(this, but7, wxT("7"), wxDefaultPosition, buttonSize);
    this->button8 = new wxButton(this, but8, wxT("8"), wxDefaultPosition, buttonSize);
    this->button9 = new wxButton(this, but9, wxT("9"), wxDefaultPosition, buttonSize);
    this->button0 = new wxButton(this, but0, wxT("0"), wxDefaultPosition, buttonSize);
    this->buttonP = new wxButton(this, butP, wxT("+"), wxDefaultPosition, buttonSize);
    this->buttonM = new wxButton(this, butM, wxT("-"), wxDefaultPosition, buttonSize);
    this->buttonMu = new wxButton(this, butMu, wxT("X"), wxDefaultPosition, buttonSize);
    this->buttonD = new wxButton(this, butD, wxT("/"), wxDefaultPosition, buttonSize);
    this->buttonE = new wxButton(this, butE, wxT("="), wxDefaultPosition, buttonSize);
    this->buttonC = new wxButton(this, butC, wxT("AC"), wxDefaultPosition, buttonSize);
    this->buttonDec = new wxButton(this, butDec, wxT("."), wxDefaultPosition, buttonSize);
    this->buttonBak = new wxButton(this, butBak, wxT("<--"), wxDefaultPosition, buttonSize);
    this->buttonSqrt = new wxButton(this, butSqrt, wxT("Sqrt"), wxDefaultPosition, buttonSize);

    this->buttonP->Enable(false);
    this->buttonM->Enable(false);
    this->buttonMu->Enable(false);
    this->buttonD->Enable(false);
    this->buttonE->Enable(false);
    this->buttonDec->Enable(false);
    this->buttonSqrt->Enable(false);

    this->grid->Add(this->button1, 0, wxEXPAND);
    this->grid->Add(this->button2, 0, wxEXPAND);
    this->grid->Add(this->button3, 0, wxEXPAND);
    this->grid->Add(this->button4, 0, wxEXPAND);
    this->grid->Add(this->button5, 0, wxEXPAND);
    this->grid->Add(this->button6, 0, wxEXPAND);
    this->grid->Add(this->button7, 0, wxEXPAND);
    this->grid->Add(this->button8, 0, wxEXPAND);
    this->grid->Add(this->button9, 0, wxEXPAND);
    this->grid->Add(this->button0, 0, wxEXPAND);
    this->grid->Add(this->buttonDec, 0, wxEXPAND);
    this->grid->Add(this->buttonP, 0, wxEXPAND);
    this->grid->Add(this->buttonM, 0, wxEXPAND);
    this->grid->Add(this->buttonMu, 0, wxEXPAND);
    this->grid->Add(this->buttonD, 0, wxEXPAND);
    this->grid->Add(this->buttonE, 0, wxEXPAND);
    this->grid->Add(this->buttonC, 0, wxEXPAND);
    this->grid->Add(this->buttonBak, 0, wxEXPAND);
    this->grid->Add(this->buttonSqrt, 0, wxEXPAND);

    this->bSizer->Add(grid, 1, wxEXPAND);
    this->SetSizer(bSizer);
}

Kalaxter::~Kalaxter()
{
    this->Destroy();
}

void Kalaxter::button1Clicked(wxCommandEvent &event)
{
    this->resultBox->AppendText(wxT("1"));
    if(isOperatorsEnabled == false && trigger == 0)
    {
        isOperatorsEnabled = true;
        this->buttonP->Enable(true);
        this->buttonM->Enable(true);
        this->buttonMu->Enable(true);
        this->buttonD->Enable(true);
        this->buttonSqrt->Enable(true);
    }
    if(trigger == 1 && isEqualEnabled == false)
    {
        this->buttonE->Enable(true);
        isEqualEnabled = true;
    }
    if(isDecimalEnabled == false && decimalPlaced == false)
    {
        this->buttonDec->Enable(true);
        isDecimalEnabled = true;
    }
}

void Kalaxter::button2Clicked(wxCommandEvent &event)
{
    this->resultBox->AppendText(wxT("2"));
    if(isOperatorsEnabled == false && trigger == 0)
    {
        isOperatorsEnabled = true;
        this->buttonP->Enable(true);
        this->buttonM->Enable(true);
        this->buttonMu->Enable(true);
        this->buttonD->Enable(true);
        this->buttonSqrt->Enable(true);
    }
    if(trigger == 1 && isEqualEnabled == false)
    {
        this->buttonE->Enable(true);
        isEqualEnabled = true;
    }
    if(isDecimalEnabled == false && decimalPlaced == false)
    {
        this->buttonDec->Enable(true);
        isDecimalEnabled = true;
    }
}

void Kalaxter::button3Clicked(wxCommandEvent &event)
{
    this->resultBox->AppendText(wxT("3"));
    if(isOperatorsEnabled == false && trigger == 0)
    {
        isOperatorsEnabled = true;
        this->buttonP->Enable(true);
        this->buttonM->Enable(true);
        this->buttonMu->Enable(true);
        this->buttonD->Enable(true);
        this->buttonSqrt->Enable(true);
    }
    if(trigger == 1 && isEqualEnabled == false)
    {
        this->buttonE->Enable(true);
        isEqualEnabled = true;
    }
    if(isDecimalEnabled == false && decimalPlaced == false)
    {
        this->buttonDec->Enable(true);
        isDecimalEnabled = true;
    }
}

void Kalaxter::button4Clicked(wxCommandEvent &event)
{
    this->resultBox->AppendText(wxT("4"));
    if(isOperatorsEnabled == false && trigger == 0)
    {
        isOperatorsEnabled = true;
        this->buttonP->Enable(true);
        this->buttonM->Enable(true);
        this->buttonMu->Enable(true);
        this->buttonD->Enable(true);
        this->buttonSqrt->Enable(true);
    }
    if(trigger == 1 && isEqualEnabled == false)
    {
        this->buttonE->Enable(true);
        isEqualEnabled = true;
    }
    if(isDecimalEnabled == false && decimalPlaced == false)
    {
        this->buttonDec->Enable(true);
        isDecimalEnabled = true;
    }
}

void Kalaxter::button5Clicked(wxCommandEvent &event)
{
    this->resultBox->AppendText(wxT("5"));
    if(isOperatorsEnabled == false && trigger == 0)
    {
        isOperatorsEnabled = true;
        this->buttonP->Enable(true);
        this->buttonM->Enable(true);
        this->buttonMu->Enable(true);
        this->buttonD->Enable(true);
        this->buttonSqrt->Enable(true);
    }
    if(trigger == 1 && isEqualEnabled == false)
    {
        this->buttonE->Enable(true);
        isEqualEnabled = true;
    }
    if(isDecimalEnabled == false && decimalPlaced == false)
    {
        this->buttonDec->Enable(true);
        isDecimalEnabled = true;
    }
}

void Kalaxter::button6Clicked(wxCommandEvent &event)
{
    this->resultBox->AppendText(wxT("6"));
    if(isOperatorsEnabled == false && trigger == 0)
    {
        isOperatorsEnabled = true;
        this->buttonP->Enable(true);
        this->buttonM->Enable(true);
        this->buttonMu->Enable(true);
        this->buttonD->Enable(true);
        this->buttonSqrt->Enable(true);
    }
    if(trigger == 1 && isEqualEnabled == false)
    {
        this->buttonE->Enable(true);
        isEqualEnabled = true;
    }
    if(isDecimalEnabled == false && decimalPlaced == false)
    {
        this->buttonDec->Enable(true);
        isDecimalEnabled = true;
    }
}

void Kalaxter::button7Clicked(wxCommandEvent &event)
{
    this->resultBox->AppendText(wxT("7"));
    if(isOperatorsEnabled == false && trigger == 0)
    {
        isOperatorsEnabled = true;
        this->buttonP->Enable(true);
        this->buttonM->Enable(true);
        this->buttonMu->Enable(true);
        this->buttonD->Enable(true);
        this->buttonSqrt->Enable(true);
    }
    if(trigger == 1 && isEqualEnabled == false)
    {
        this->buttonE->Enable(true);
        isEqualEnabled = true;
    }
    if(isDecimalEnabled == false && decimalPlaced == false)
    {
        this->buttonDec->Enable(true);
        isDecimalEnabled = true;
    }
}

void Kalaxter::button8Clicked(wxCommandEvent &event)
{
    this->resultBox->AppendText(wxT("8"));
    if(isOperatorsEnabled == false && trigger == 0)
    {
        isOperatorsEnabled = true;
        this->buttonP->Enable(true);
        this->buttonM->Enable(true);
        this->buttonMu->Enable(true);
        this->buttonD->Enable(true);
        this->buttonSqrt->Enable(true);
    }
    if(trigger == 1 && isEqualEnabled == false)
    {
        this->buttonE->Enable(true);
        isEqualEnabled = true;
    }
    if(isDecimalEnabled == false && decimalPlaced == false)
    {
        this->buttonDec->Enable(true);
        isDecimalEnabled = true;
    }
}

void Kalaxter::button9Clicked(wxCommandEvent &event)
{
    this->resultBox->AppendText(wxT("9"));
    if(isOperatorsEnabled == false && trigger == 0)
    {
        isOperatorsEnabled = true;
        this->buttonP->Enable(true);
        this->buttonM->Enable(true);
        this->buttonMu->Enable(true);
        this->buttonD->Enable(true);
        this->buttonSqrt->Enable(true);
    }
    if(trigger == 1 && isEqualEnabled == false)
    {
        this->buttonE->Enable(true);
        isEqualEnabled = true;
    }
    if(isDecimalEnabled == false && decimalPlaced == false)
    {
        this->buttonDec->Enable(true);
        isDecimalEnabled = true;
    }
}

void Kalaxter::button0Clicked(wxCommandEvent &event)
{
    this->resultBox->AppendText(wxT("0"));
    if(isOperatorsEnabled == false && trigger == 0)
    {
        isOperatorsEnabled = true;
        this->buttonP->Enable(true);
        this->buttonM->Enable(true);
        this->buttonMu->Enable(true);
        this->buttonD->Enable(true);
        this->buttonSqrt->Enable(true);
    }
    if(trigger == 1 && isEqualEnabled == false)
    {
        this->buttonE->Enable(true);
        isEqualEnabled = true;
    }
    if(isDecimalEnabled == false && decimalPlaced == false)
    {
        this->buttonDec->Enable(true);
        isDecimalEnabled = true;
    }
}

void Kalaxter::buttonPlusClicked(wxCommandEvent &event)
{
    this->resultBox->GetValue().ToDouble(&memory);
    this->resultBox->Clear();
    operation = '+';
    if(trigger == 0)
    {
        trigger = 1;
    }
    isOperatorsEnabled = false;
    isDecimalEnabled = false;
    decimalPlaced = false;
    this->buttonP->Enable(false);
    this->buttonM->Enable(false);
    this->buttonMu->Enable(false);
    this->buttonD->Enable(false);
    this->buttonDec->Enable(false);
}

void Kalaxter::buttonMinusClicked(wxCommandEvent &event)
{
    this->resultBox->GetValue().ToDouble(&memory);
    this->resultBox->Clear();
    operation = '-';
    if(trigger == 0)
    {
        trigger = 1;
    }
    isOperatorsEnabled = false;
    isDecimalEnabled = false;
    decimalPlaced = false;
    this->buttonP->Enable(false);
    this->buttonM->Enable(false);
    this->buttonMu->Enable(false);
    this->buttonD->Enable(false);
    this->buttonDec->Enable(false);
}

void Kalaxter::buttonMulClicked(wxCommandEvent &event)
{
    this->resultBox->GetValue().ToDouble(&memory);
    this->resultBox->Clear();
    operation = '*';
    if(trigger == 0)
    {
        trigger = 1;
    }
    isOperatorsEnabled = false;
    isDecimalEnabled = false;
    decimalPlaced = false;
    this->buttonP->Enable(false);
    this->buttonM->Enable(false);
    this->buttonMu->Enable(false);
    this->buttonD->Enable(false);
    this->buttonDec->Enable(false);
}

void Kalaxter::buttonDivClicked(wxCommandEvent &event)
{
    this->resultBox->GetValue().ToDouble(&memory);
    this->resultBox->Clear();
    operation = '/';
    if(trigger == 0)
    {
        trigger = 1;
    }
    isOperatorsEnabled = false;
    isDecimalEnabled = false;
    decimalPlaced = false;
    this->buttonP->Enable(false);
    this->buttonM->Enable(false);
    this->buttonMu->Enable(false);
    this->buttonD->Enable(false);
    this->buttonDec->Enable(false);
}

void Kalaxter::buttonEqClicked(wxCommandEvent &event)
{
    double memory_b = memory;
    this->resultBox->GetValue().ToDouble(&memory);
    switch(operation)
    {
    case '+':
        result = memory_b+memory;
        break;
    case '-':
        result = memory_b-memory;
        break;
    case '*':
        result = memory_b*memory;
        break;
    case '/':
        if(memory == 0)
        {
            result = 0;
        }
        else
        {
            result = memory_b/memory;
        }
        break;
    }

    wxString resultStr = wxString::Format(wxT("%f"), result);
    this->resultBox->Clear();
    this->resultBox->AppendText(resultStr);

    isDecimalEnabled = false;
    decimalPlaced = true;
    this->buttonDec->Enable(false);

    isEqualEnabled = false;
    this->buttonE->Enable(false);
    trigger = 0;

    isOperatorsEnabled = true;
    this->buttonP->Enable(true);
    this->buttonM->Enable(true);
    this->buttonMu->Enable(true);
    this->buttonD->Enable(true);
}

void Kalaxter::buttonClsClicked(wxCommandEvent &event)
{
    memory = 0;
    result = 0;
    trigger = 0;
    operation = 'N';
    isOperatorsEnabled = false;
    isEqualEnabled = false;
    isDecimalEnabled = false;
    decimalPlaced = false;
    this->buttonP->Enable(false);
    this->buttonM->Enable(false);
    this->buttonMu->Enable(false);
    this->buttonD->Enable(false);
    this->buttonE->Enable(false);
    this->buttonDec->Enable(false);
    this->buttonSqrt->Enable(false);
    this->resultBox->Clear();
}

void Kalaxter::buttonDecimalClicked(wxCommandEvent &event)
{
    this->resultBox->AppendText(wxT("."));
    this->buttonDec->Enable(false);
    decimalPlaced = true;
}

void Kalaxter::buttonBackspaceClicked(wxCommandEvent &event)
{
    std::string text = std::string(this->resultBox->GetValue().ToStdString());
    int textLen = text.length();

    if(textLen > 1)
    {
        this->resultBox->Clear();
        text = text.substr(0, textLen-1);
        wxString resultStr(text);
        this->resultBox->AppendText(resultStr);
    }
    else if(textLen == 1)
    {
        this->resultBox->Clear();
        text = text.substr(0, textLen-1);
        wxString resultStr(text);
        this->resultBox->AppendText(resultStr);
        trigger = 0;
        isOperatorsEnabled = false;
        this->buttonP->Enable(false);
        this->buttonM->Enable(false);
        this->buttonMu->Enable(false);
        this->buttonD->Enable(false);
        this->buttonSqrt->Enable(false);
    }
}

void Kalaxter::buttonSqrtClicked(wxCommandEvent &event)
{
    this->resultBox->GetValue().ToDouble(&memory);
    double _sqrt_ = std::sqrt(memory);
    result = _sqrt_;

    this->resultBox->Clear();
    wxString resultStr = wxString::Format(wxT("%f"), result);
    this->resultBox->AppendText(resultStr);
}
