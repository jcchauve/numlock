//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USEFORM("fmain.cpp", FormXLock);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TFormXLock), &FormXLock);
                 if((_argc>1)&&!(stricmp(_argv[1],"-hide")))
                 {
                    Application->ShowMainForm = false;

                 }
     Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
