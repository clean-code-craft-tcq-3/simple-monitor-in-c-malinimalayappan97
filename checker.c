#include <stdio.h>
#include <assert.h>
int TempAlerter = 0;
int SOCAlerter = 0;
int ChargeRateAlerter = 0;
bool TempInRange = FALSE;
bool SOCInRange = FALSE;
bool ChargeRateInRange = FALSE;

 bool isTempValueInRange(float temperature)
  {
      if(temperature < 0 || temperature > 45)
      {
          printf("%fTemperature out of range!\n",temperature);
          TempAlerter = TempAlerter+1;
      }
  }
 
  bool isSOCValueInRange(float soc)
  {
      if(soc < 20 || soc > 80)
      {
          printf("%fState of Charge out of range!\n",soc);
          SOCAlerter = SOCAlerter+1;
      }
  }
  
   bool isChargeRateValueInRange(float chargeRate)
  {
      if(chargeRate > 0.8)
      {
          printf("%fCharge Rate out of range!\n",chargeRate);
          ChargeRateAlerter = ChargeRateAlerter+1;
      }
  }

void batteryIsOk(float temperature, float soc, float chargeRate) 
{
    TempInRange = isTempValueInRange(temperature);
    SOCInRange =isSOCValueInRange(soc);
    ChargeRateInRange =isChargeRateValueInRange(chargeRate);
}
 
 

int main() {
    batteryIsOk(25, 70, 0.7);
    assert(TempAlerter == 0);
    assert(SOCAlerter == 0);
    assert(ChargeRateAlerter == 0);
    
    batteryIsOk(50, 85, 0);
    assert(TempAlerter == 1);
    assert(SOCAlerter == 1);
    assert(ChargeRateAlerter == 0);
}
