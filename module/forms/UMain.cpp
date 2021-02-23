#include <fmx.h>
#pragma hdrstop
#pragma package(smart_init)
#pragma resource "*.fmx"

#include "UMain.h"
#include "modInclude.h"
#include <TTemperature.h>

TFormMain *FormMain;

__fastcall TFormMain::TFormMain(TComponent* Owner)
   : TForm(Owner)
{
}

void __fastcall TFormMain::ConvertButtomClick(TObject *Sender)
{
int category;

   category = CategoryList->ItemIndex;

   switch (category)
   {
      case 0: // NULL Option
      {
         MessageBoxA( NULL, "Choose a Category to Continue!", "Invalid Option", 0 );
         break;
      }
      case 1: // Distance
      {
         break;
      }
      case 2: // Numbers
      {
         break;
      }
      case 3: // Temperature     //MessageBoxA( NULL, "Enter a Valid Entry!", "Invalid Input", 0 );
      {
         Input2->Text = CelciusToKelvin( StrToFloat(Input1->Text) );

         break;
      }
      default:
      {
         break;
      }
   }
}
