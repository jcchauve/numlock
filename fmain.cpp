//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmain.h"
#include <assert.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormXLock *FormXLock;
//---------------------------------------------------------------------------
#define VERIFY(a) if(!a) return;

#define _ASSERT(a) assert(a)
#define VK_CAPSLOCK VK_CAPITAL

#include "registr.h"

#define REGCLE_NUMLOCK "software\\ClaudioSoft\\NumLock\\"
#define REGCLE_NUMLOCKA AnsiString(REGCLE_NUMLOCK)


// ==========================================================================
// Construction/Destruction
// ==========================================================================
CNumLock::CNumLock( int aVK ) :
  m_bIgnoreKeyInput( false )
  {
  // initialize required state
  mVK=aVK;
  m_iReqdXLockState = 0x0000;

  // initialize static info structure

  m_OSVersionInfo.dwOSVersionInfoSize = sizeof( OSVERSIONINFO );
  VERIFY( GetVersionEx( &m_OSVersionInfo ));
  }

CNumLock::~CNumLock()
  {
  }

  void CNumLock::ChangeState(bool bAlwaysOn)
  {
    if( bAlwaysOn )
    m_iReqdXLockState = 0x0001;
  else
    m_iReqdXLockState = 0x0000;

  }


// ==========================================================================
// Toggle NumLock - reverses the current NumLock status. The handling
// is different for Windows 9x and Windows NT.
// ==========================================================================
void CNumLock::ToggleXLock()
  {
  _ASSERT( m_bIgnoreKeyInput == false );
  m_bIgnoreKeyInput = true;

  if( m_OSVersionInfo.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS )
    {
    BYTE KeyboardState[ 256 ];
    VERIFY( GetKeyboardState( KeyboardState ));
    KeyboardState[ mVK ] = KeyboardState[ mVK ] ^ 1;
    VERIFY( SetKeyboardState( KeyboardState ));
    }
  else if( m_OSVersionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT )
    {
        keybd_event( mVK, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 );
        keybd_event( mVK, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0 );

    }
  else
    ; // OS not supported

  m_bIgnoreKeyInput = false;
  }
// ==========================================================================
// Check NumLock State - to be used in the main applications OnIdle handler:
// this checks whether the NumLock state is still as requested
// ==========================================================================
void CNumLock::CheckXLockState()
  {
  // if this is called while ignoring any keyboard input, the current state
  // of the numlock key is already being changed, hence:

  if( m_bIgnoreKeyInput )
    return;

  if( GetCurrXLockState() == m_iReqdXLockState )
    ; // nothing to do
  else
    ToggleXLock();
  }
// ==========================================================================
// Filter Message - filter VK_NUMLOCK messages: if NumLock is down, ignore all
// further WM_KEYDOWN messages until VK_NUMLOCK is up again. Return true if
// message was complete handled (processed or to be dropped), false if
// message should be processed further.
// ==========================================================================
bool CNumLock::FilterMessage( const MSG* pMsg )
  {
  if( pMsg->message == WM_KEYDOWN )
    {
    if( m_bIgnoreKeyInput )
      return true;

    else if( pMsg->wParam == VK_NUMLOCK )
      return m_bIgnoreKeyInput = true;
    else
      return false;
    }
  else if( pMsg->message == WM_KEYUP )
    {
    if( pMsg->wParam == VK_NUMLOCK )
      {
      m_bIgnoreKeyInput = false;
      CheckXLockState();
      return true;
      }
    else
      return m_bIgnoreKeyInput;
    }
  else
    return false;
  }


__fastcall TFormXLock::TFormXLock(TComponent* Owner)
        : TForm(Owner)
{
    InitReg(REGCLE_NUMLOCK);

        mNumLock= new CNumLock(VK_NUMLOCK);
        mCapsLock= new CNumLock(VK_CAPSLOCK);
        mInsert= new CNumLock(VK_INSERT);
        //fStates();
        ChkNumLock->Checked=ReadRegInt("NumLock",1);
        ChkCapsLock->Checked=ReadRegInt("CapsLock",0);
        ChkInsert->Checked=ReadRegInt("Insert",1);
   mInit=false;
  mHide=false;

}
//---------------------------------------------------------------------------
void __fastcall TFormXLock::FormDestroy(TObject *Sender)
{
        delete mNumLock;
        delete mCapsLock;
        delete mInsert;




}
//---------------------------------------------------------------------------
void __fastcall TFormXLock::Timer1Timer(TObject *Sender)
{
  if(!mInit)
  {
    //WindowState=wsMinimized;
    if(Application->ShowMainForm)
    {
      Application->Minimize();
    }
    mInit=true;
  }


    mNumLock->ChangeState(ChkNumLock->Checked);
    mCapsLock->ChangeState(ChkCapsLock->Checked);
    mInsert->ChangeState(ChkInsert->Checked);

        mNumLock->CheckXLockState();
        mCapsLock->CheckXLockState();
        mInsert->CheckXLockState();
}
//---------------------------------------------------------------------------



void __fastcall TFormXLock::FormClose(TObject *Sender, TCloseAction &Action)
{
          WriteRegInt("NumLock",ChkNumLock->Checked);
        WriteRegInt("CapsLock",ChkCapsLock->Checked);
        WriteRegInt("Insert",ChkInsert->Checked);

}
//---------------------------------------------------------------------------

