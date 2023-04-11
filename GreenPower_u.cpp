//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GreenPower_u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmGreenP *frmGreenP;

//- Q1 -----------------------------------------------------------------------
__fastcall TfrmGreenP::TfrmGreenP(TComponent* Owner): TForm(Owner)
{
//
	stsInfo->Panels->Items[0]->Text = "Started : "
	+FormatDateTime("dd mmmm yyyy ' at 'hh:nn", Now());

}
//= Q2a ====================================================================
AnsiString ExtractFieldFromLine(AnsiString snglLine, int fieldNr, char delim)
// Add self-defined method: ExtractFieldFromLine()    (loacal function!)
{
	int pos;
	AnsiString field;
	snglLine +=  delim;
	for (int i = 1; i < fieldNr; i++)
	{
		pos = snglLine.Pos(delim);
		field = snglLine.SubString(1,pos-1);
		snglLine.Delete(1,pos);
	}
    return field;
}

//- Q2b ----------------------------------------------------------------------
void __fastcall TfrmGreenP::tmrGreenTimer(TObject *Sender)
{
//
   imgGreen->Left = Random(frmGreenP->ClientWidth - imgGreen->Width);
}
//- Q3 ----------------------------------------------------------------------
void __fastcall TfrmGreenP::btnLoadClick(TObject *Sender)
{
//
	xList = new TStringList;
	xList->LoadFromFile("..\\..\\Solar data\\HOwners.csv");
	AnsiString ln;

	for (int i = 0; i < xList->Count; i++)
	{
		ln = xList->Strings[i];
		while (ln.Pos("|") > 0)
			ln[ln.Pos("|")] = '\t';
		lstConsump->Items->Add(ln);
	}
   lstConsump->Items->Delete(0);
}
//- Q4 -----------------------------------------------------------------------
void __fastcall TfrmGreenP::btnClacSavClick(TObject *Sender)
{
	// Calculate savings[%]
	// Solar support systems ...
	// S	Solar System		saving 75-100%    (all inclusive!)
	// -	no support system   no saving
	// B	Back-up solar		saving 20-40%
	// W	Water solar geyser	saving 30-60%
	  AnsiString ln, supp, firstP, secP ;
	  int savng;
	  int x;
	  for (x = 0; x < lstConsump->Items->Count; x++)
	  {
		ln =lstConsump->Items->Strings[x];
		supp = ExtractFieldFromLine(ln,5,'\t');

		if (supp =='S')
		{
			savng == Random(26)+ 75;
        }
		else if (supp =='-')
		{
			savng = 0;
		}
		else if (supp =='B')
		{
			savng = Random(21)+ 20;
		}
		else if (supp =='W')
		{
            savng = Random(31)+ 30;
		}

		firstP = ln.SubString(1, AnsiPos("\t\t",ln));
		secP = ln.SubString(AnsiPos("\t\t",ln)+1,200);
		lstConsump->Items->Strings[x] = firstP + IntToStr(savng)+ "% " + secP;
	  }
}
//- Q5 -----------------------------------------------------------------------
void __fastcall TfrmGreenP::btnSortClick(TObject *Sender)
{
//
   bool swopp = true;
   int iEnd = lstConsump->Count-1;
   tmrGreen->Enabled = true;

   while (swopp)
   {
	   swopp = false;
	   int x;
	   for (x = 0; x < iEnd; x++)
	   {
			AnsiString str1 = ExtractFieldFromLine(lstConsump->Items->Strings[x],4,'\t')
			+ ExtractFieldFromLine(lstConsump->Items->Strings[x+1],3,'\t');

			AnsiString str2 = ExtractFieldFromLine(lstConsump->Items->Strings[x+1],4,'\t')
			+ ExtractFieldFromLine(lstConsump->Items->Strings[x+1],3,'\t');

			if (str1.Length()<5) str1.Insert("0",2);
			if (str2.Length()<5) str2.Insert("0",2);

			if (str1<str2)
			{
				String temp = lstConsump->Items->Strings[x];
				lstConsump->Items->Strings[x] = lstConsump->Items->Strings[x+1];
				lstConsump->Items->Strings[x] = temp;
                swopp = true;
			}
            Application->ProcessMessages();
	   }
       iEnd--;
   }
	tmrGreen->Enabled = false;
    imgGreen->Left = 300;
	bttSurprise->Enabled = true;
}
//- Q6 -----------------------------------------------------------------------
void __fastcall TfrmGreenP::bttSurpriseClick(TObject *Sender)
{
	//------ Dynamically instatiate an image on panel! -------

	TImage *imgNum;
	imgNum = new TImage(this);
	imgNum->Parent = pnlSurprise;
	imgNum->Left = 2;
	imgNum->Top = 2;
	imgNum->Stretch = true;
	imgNum->Height = 67;
    imgNum->Width = 60;
	int x;
	for (x = 9; x >=0; x--)
	{
		imgNum->Picture->LoadFromFile("..\\..\\Solar data\\Num"+IntToStr(x)+".bmp");
		Application->ProcessMessages();
        Sleep(200);
		
	}
	int rnd = Random(lstConsump->Count-1);
	lstConsump->ItemIndex = rnd;
	pnlSurprise->Color = clNavy;
	AnsiString bDate = ExtractFieldFromLine(lstConsump->Items->Strings[rnd],1,'\t');
	bDate = "19" + bDate.SubString(1,2)+"/"+ bDate.SubString(3,2)+"/"+bDate.SubString(5,2);
	TDate theBday = StrToDate(bDate);

	AnsiString surprise  = "Congradulations to : "
	+ ExtractFieldFromLine(lstConsump->Items->Strings[rnd],5,'\t').SubString(1,1)
	+ ". "+ExtractFieldFromLine(lstConsump->Items->Strings[rnd],6,'\t')
	+ " born on a " + FormatDateTime("dddd", theBday);
	stsInfo->Panels->Items[1]->Text = surprise;

}
//---------------------------------------------------------------------------


