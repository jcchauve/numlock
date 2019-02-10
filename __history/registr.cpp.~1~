//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
#include <vcl/registry.hpp>
#include "registr.h"

//---------------------------------------------------------------------------



TRegistry *gpRegistry = 0;
AnsiString gCle="";

int InitReg(AnsiString aReg)
{
	gCle = aReg;
}

int EndReg()
{

  delete gpRegistry;
  gpRegistry=0;
}

AnsiString  ReadReg(AnsiString aStr,AnsiString aCle)
{
  AnsiString lCle = (aCle=="") ? gCle : aCle;
  if (lCle=="")
  {
		return("");
  }
  if (!gpRegistry)
  {
  	gpRegistry = new TRegistry;
    //gpRegistry->OpenKey(lCle,True);
  }
  if (lCle!="")
  {
  		AnsiString lRet;
  		gpRegistry->OpenKey(lCle,True);
    	lRet=gpRegistry->ReadString(aStr );
		gpRegistry->CloseKey();
		return(lRet);
  }
}
int WriteReg(AnsiString aCh,AnsiString aVal,AnsiString aCle)
{
  AnsiString lCle = (aCle=="") ? gCle : aCle;
  if (lCle!="")
  {
  		bool lOk=gpRegistry->OpenKey(lCle,True);
      if (lOk)
      {
      	gpRegistry->WriteString(aCh,aVal );
    		gpRegistry->CloseKey();
      }
  }
  return(1);
}
bool  ReadRegInt(int &aVal,AnsiString aStr,AnsiString aCle)
{
  AnsiString lStr = ReadReg(aStr,aCle);
  if (lStr=="")
    return false;
  bool lRet=true;
  try
  {
    aVal = lStr.ToInt();
  }
  catch (Exception &Ex)
  {
    return false;
  }
  return lRet;
}

int WriteRegInt(AnsiString aCh,int aVal,AnsiString aCle)
{
  return WriteReg(aCh,AnsiString(aVal),aCle);
}

int  ReadRegInt(AnsiString aStr,int aDef,AnsiString aCle)
{
  int lRet=aDef;
  ReadRegInt(lRet,aStr,aCle);
  return lRet;
}

