#include <stdio.h>
#include <assert.h>


typedef enum
{
  LOW_Temp_BREACH ,
  LOW_Temp_WARNING,
  Temp_NORMAL,
  HIGH_Temp_WARNING,
  HIGH_Temp_BREACH
 }TempRange_e;

typedef enum
{
  LOW_SOC_BREACH ,
  LOW_SOC_WARNING,
  SOC_NORMAL,
  HIGH_SOC_WARNING,
  HIGH_SOC_BREACH
 }SOCRange_e;

typedef enum
{
  ChargeRate_BREACH ,
  ChargeRate_WARNING,
  ChargeRate_NORMAL
 }ChargeRateRange_e;
 


typedef struct
{
    TempRange_e TempRange ;
    SOCRange_e SOCRange ;
    ChargeRateRange_e ChargeRateRange ;
    int TempBreachAlerter;
    int SOCBreachAlerter;
    int ChargeRateBreachAlerter;
    int TempWarningAlerter;
    int SOCWarningAlerter;
    int ChargeRateWarningAlerter;
}BMS_s;

BMS_s BatteryCheck_s ={
    Temp_NORMAL,
    SOC_NORMAL,
    ChargeRate_NORMAL,
    0,
    0,
    0,
    0,
    0,
    0
};

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
   _Bool CheckTempInWarningRange(float temperature)
  {
      if((0<= temperature <=2.25) ||
            (42.75<= temperature <=45))
      {
          return 0;
      }
      else
      {
        return 1;  
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
 _Bool CheckSOCInWarningRange(float temperature)
  {
      if(((temperature <=2.25) && (temperature >=0)) ||
            ((temperature <=45) && (temperature >=42.75)))
      {
          return 0;
      }
      else
      {
        return 1;  
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
   _Bool CheckChargeRateInWarningRange(float temperature)
  {
      if(((temperature <=2.25) && (temperature >=0)) ||
            ((temperature <=45) && (temperature >=42.75)))
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
       printf("Temperature nearing out of range Warning!\n");
   }
  void TempAlerter(void)
  {
     BatteryCheck_s.TempBreachAlerter++;
     printf("Temperature out of range !\n");
  }
  void ChargeRateWarningAlerter(void)
   {
       BatteryCheck_s.TempWarningAlerter ++;
       printf("Temperature nearing out of range Warning!\n");
   }
  void SOCAlerter(void)
  {
     BatteryCheck_s.TempBreachAlerter++;
     printf("Temperature out of range !\n");
  }
  void SOCWarningAlerter(void)
   {
       BatteryCheck_s.TempWarningAlerter ++;
       printf("Temperature nearing out of range Warning!\n");
   }
  void ChargeRateAlerter(void)
  {
     BatteryCheck_s.TempBreachAlerter++;
     printf("Temperature out of range !\n");
  }
 
  _Bool BatteryTempIsOk(float temperature)
  {
      if(CheckTempInWarningRange(temperature) == 1)
     {
         SOCWarningAlerter();
         return 0;
     }
     else if(CheckTempInRange(temperature) == 0)
     {
       SOCAlerter();
       return 0;
     }
     else
     {
        return 1; 
     }
     
  }
  
  _Bool BatterySOCIsOk(float soc)
  {
     if(CheckSOCInWarningRange(soc) == 1)
     {
         SOCAlerter();
         return 0;
     }
     else if(CheckSOCInRange(soc) == 0)
     {
       SOCAlerter();
       return 0;
     }
     else
     {
        return 1; 
     }
  }
  
  _Bool BatteryChargeRateIsOk(float chargeRate)
  {
     if(CheckChargeRateInWarningRange(chargeRate) == 1)
     {
         ChargeRateWarningAlerter();
         return 0;
     }
     else if(CheckChargeRateInRange(chargeRate) == 0)
     {
       ChargeRateAlerter();
       return 0;
     }
     else
     {
        return 1; 
     }
  }


_Bool BatteryIsOk(float temperature, float soc, float chargeRate) 
{
    _Bool retVal;
    
    if( BatteryTempIsOk(temperature) == 0)
    {
        retVal = retVal|0;
    }
    if( BatterySOCIsOk(soc) == 0)
    {
        retVal = retVal|0;
    }
    if( BatteryChargeRateIsOk(chargeRate) == 0)
    {
        retVal = retVal|0;;
    }

}
 
 

int main() {
    BatteryIsOk(25, 70, 0.7);

    
    BatteryIsOk(50, 85, 0);

}
