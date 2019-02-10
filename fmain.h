//---------------------------------------------------------------------------

#ifndef fmainH
#define fmainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

class CNumLock
  {
  private:

	OSVERSIONINFO m_OSVersionInfo; // needed to distinguish Windows 9x/NT

  int  m_iReqdXLockState; // state of NumLock key required for this app
  bool m_bIgnoreKeyInput;   // true while NumLock key is down

  int  GetCurrXLockState()const{ return GetKeyState( mVK ) & 0x0001; };
  void ToggleXLock();
  int mVK;

  public:

  void CheckXLockState();               // include in OnIdle
  bool FilterMessage( const MSG* pMsg );  // include in PreTranslateMessage

  CNumLock( int aVK  );
	virtual ~CNumLock();
  void ChangeState(bool bAlwaysOn);

  };


//---------------------------------------------------------------------------
class TFormXLock : public TForm
{
__published:	// IDE-managed Components
        TTimer *Timer1;
  TCheckBox *ChkNumLock;
  TCheckBox *ChkCapsLock;
  TCheckBox *ChkInsert;
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TFormXLock(TComponent* Owner);
        CNumLock *mNumLock;
        CNumLock *mCapsLock;
        CNumLock *mInsert;
      bool mInit;
      bool mHide;
       //  fStates();
        };
//---------------------------------------------------------------------------
extern PACKAGE TFormXLock *FormXLock;
//---------------------------------------------------------------------------
#endif
