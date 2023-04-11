//---------------------------------------------------------------------------

#ifndef GreenPower_uH
#define GreenPower_uH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TfrmGreenP : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TListBox *lstConsump;
	TLabel *Label3;
	TPanel *Panel1;
	TStatusBar *stsInfo;
	TBitBtn *bttSurprise;
	TPanel *pnlSurprise;
	TButton *btnLoad;
	TButton *btnClacSav;
	TButton *btnSort;
	TImage *imgGreen;
	TTimer *tmrGreen;
	TImage *imgSolar;
	void __fastcall btnLoadClick(TObject *Sender);
	void __fastcall bttSurpriseClick(TObject *Sender);
	void __fastcall btnClacSavClick(TObject *Sender);
	void __fastcall btnSortClick(TObject *Sender);
	void __fastcall tmrGreenTimer(TObject *Sender);

private:	// User declarations
	TStringList *xList;     // should be under private!    ****
public:		// User declarations
	__fastcall TfrmGreenP(TComponent* Owner);
	//AnsiString ExtractFieldFromLine(AnsiString snglLine, int fieldNr, char delim);

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGreenP *frmGreenP;
//---------------------------------------------------------------------------
#endif
