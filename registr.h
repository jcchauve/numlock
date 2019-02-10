//---------------------------------------------------------------------------
#ifndef registrH
#define registrH
//---------------------------------------------------------------------------

int InitReg(AnsiString aReg);
int EndReg();
AnsiString  ReadReg(AnsiString aStr,AnsiString aCle="");
bool  ReadRegInt(int &aVal,AnsiString aStr,AnsiString aCle="");
int  ReadRegInt(AnsiString aStr,int aDef,AnsiString aCle="");

int WriteReg(AnsiString aCh,AnsiString aVal,AnsiString aCle="");
int WriteRegInt(AnsiString aCh,int aVal,AnsiString aCle="");

#define REGCLE_DEB    "software\\ClaudioSoft\\"

#endif
