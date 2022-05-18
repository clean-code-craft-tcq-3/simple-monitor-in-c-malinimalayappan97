#include <stdio.h>
#include <assert.h>

typedef struct
{
    int TempBreachAlerter;
    int SOCBreachAlerter;
    int ChargeRateBreachAlerter;
    int TempWarningAlerter;
    int SOCWarningAlerter;
    int ChargeRateWarningAlerter;
}BMS_s;

BMS_s BatteryCheck_s ={0, 0,0,0,0,0};
   _Bool CheckTempInWarningRange(float temperature)
  {
      if(((0<= temperature) &&(temperature <=2.25)) ||
            ((temperature >=42.75) &&( temperature <=45)))
      {
          return 1;
      }
      else
      {
        return 0;  
      }
  }
   _Bool CheckTempInRange(float temperature)
  {
      if(temperature < 0|| temperature > 45)
      {
          return 0;
      }
      else
      {
        return 1;  
      }
  }
  _Bool CheckHighSOCWarningRange(float soc)
  {
      if((10<= soc )&&(soc<=24))
      {
          return 1;
      }
      else
      {
          return 0;
      }
      
  }
  _Bool CheckLowSOCWarningRange(float soc)
  {
      if((76<= soc)&&(soc <=80))
          return 1;
      }
      else
      {
          return 0;
      }
      
  }

_Bool CheckSOCInWarningRange(float soc)
  {
if((checkHighSOCWarningRange(soc) == 1) ||(checkLowSOCWarningRange(soc==1))
      {
          return 1;
      }
      else
      {
        return 0;  
      }
  }
  
  _Bool CheckSOCInRange(float soc)
  {
      if(soc < 20 || soc > 80)
      {
          return 0;
      }
      else
      {
        return 1;  
      }
      
  }
    _Bool CheckChargeRateInWarningRange(float chargeRate)
  {
      if((0.76<=chargeRate)&&(chargeRate<= 0.8))
      {
          return 1;
      }
      else
      {
        return 0;  
      }
  }
_Bool CheckChargeRateInRange(float chargeRate)
  {
      if(chargeRate > 0.8)
      {
          return 0;
      }
      else
      {
        return 1;  
      }
  }

   void TempWarningAlerter(void)
   {
       BatteryCheck_s.TempWarningAlerter ++;
       printf("Warning :Temperature nearing out of range !\n");
   }
  void TempAlerter(void)
  {
     BatteryCheck_s.TempBreachAlerter++;
     printf("Error:Temperature out of range !\n");
  }
  void ChargeRateWarningAlerter(void)
   {
       BatteryCheck_s.ChargeRateWarningAlerter ++;
       printf("Warning :ChargeRate nearing out of range !\n");
   }
  void SOCAlerter(void)
  {
     BatteryCheck_s.SOCBreachAlerter++;
     printf("Error:SOC out of range !\n");
  }
  void SOCWarningAlerter(void)
   {
       BatteryCheck_s.SOCWarningAlerter ++;
       printf("Warning: SOC nearing out of range !\n");
   }
  void ChargeRateAlerter(void)
  {
     BatteryCheck_s.ChargeRateBreachAlerter++;
     printf("Error:ChargeRate out of range !\n");
  }
 
  void BatteryTempIsOk(float temperature)
  {
      if(CheckTempInWarningRange(temperature) == 1)
     {
         TempWarningAlerter();
     }
     else if(CheckTempInRange(temperature) == 0)
     {
       TempAlerter();
     }
     else{   }
  }
  
  void BatterySOCIsOk(float soc)
  {
     if(CheckSOCInWarningRange(soc) == 1)
     {
         SOCWarningAlerter();
     }
     else if(CheckSOCInRange(soc) == 0)
     {
       SOCAlerter();
     }
     else{   }
  }
  
 void BatteryChargeRateIsOk(float chargeRate)
  {
     if(CheckChargeRateInWarningRange(chargeRate) == 1)
     {
         ChargeRateWarningAlerter();
     }
     else if(CheckChargeRateInRange(chargeRate) == 0)
     {
       ChargeRateAlerter();
     }
     else
     {

     }
  }

void BatteryIsOk(float temperature, float soc, float chargeRate,) 
{
     BatteryTempIsOk(temperature);
     BatterySOCIsOk(soc);
     BatteryChargeRateIsOk(chargeRate);
}
 

int main() {
    BatteryIsOk(25, 70, 0.7);
    BatteryIsOk(46, 81, 1.0);
    BatteryIsOk(-1, 9, 0.9);
    BatteryIsOk(1, 22, 0.78);
    BatteryIsOk(44, 77, 0.79);
    
}
