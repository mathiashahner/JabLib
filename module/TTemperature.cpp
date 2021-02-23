#include <modInclude.h>
#include <TTemperature.h>
#include <TCommonRoutines.h>

float CelciusToKelvin (float temperature)
{
float result;

   result = temperature + 273.15;

   return result;
}
