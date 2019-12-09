//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IHM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	carteAdr = 3 - (int(CheckBoxSK5->Checked) + int(CheckBoxSK6->Checked) * 2);

	cSuccess = velman.Connexion(carteAdr);
	if(cSuccess)
	{
		Label1->Caption = "Carte " + IntToStr(carteAdr) + " connect�e";
		CheckBoxSK5->Enabled = false;
		CheckBoxSK6->Enabled = false;
        Button1->Enabled = false;
		Timer1->Enabled = true;
	}
	else
	{
		Label1->Caption = "Connexion carte " + IntToStr(carteAdr) + " �chou�e";
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	tension = velman.Lecture(carteAdr);
    Label2->Caption = "Tension : " + FloatToStr(tension);
}
//---------------------------------------------------------------------------

