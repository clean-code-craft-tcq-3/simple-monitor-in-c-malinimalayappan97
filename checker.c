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
      if(temperature < 2.25 || temperature > 42.75)
      {
          return 0;
      }
      else
      {
        return 1;  
      }
  }
  
  _Bool CheckSocInRange(float soc)
  {
      if(soc < 24 || soc > 76)
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
      if(chargeRate > 0.76)
      {
          return 0;
      }
      else
      {
        return 1;  
      }
  }
  
  void TempAlerter(void)
  {
      if((BatteryCheck_s.TempRange == LOW_Temp_WARNING)  ||
         (BatteryCheck_s.TempRange == HIGH_Temp_WARNING) )
         {
             BatteryCheck_s.TempWarningAlerter ++;
             printf("Temperature nearing out of range Warning!\n");
         }
         else
         {
             BatteryCheck_s.TempBreachAlerter++;
             printf("Temperature out of range !\n");
         }
  }
  void SOCAlerter(void)
  {
    if((BatteryCheck_s.SOCRange == LOW_SOC_WARNING)  ||
         (BatteryCheck_s.SOCRange == HIGH_SOC_WARNING) )
         {
             BatteryCheck_s.SOCWarningAlerter ++;
             printf("SOC nearing out of range Warning!\n");
         }
         else
         {
             BatteryCheck_s.SOCBreachAlerter++;
             printf("SOC out of range !\n");
         }  
  }
   void ChargeRateAlerter(void)
  {
      if((BatteryCheck_s.ChargeRateRange == ChargeRate_WARNING))
         {
             BatteryCheck_s.ChargeRateWarningAlerter ++;
             printf("ChargeRate nearing out of range Warning!\n");
         }
         else
         {
             BatteryCheck_s.ChargeRateBreachAlerter++;
             printf("ChargeRate out of range !\n");
         }
  }
  void BatteryTempIsOk(float temperature)
  {
     if(CheckTempInRange(temperature) != 1)
     {
       TempAlerter();
     } 
  }
  
  void BatterySOCIsOk(float soc)
  {
     if(CheckSocInRange(soc) != 1)
     {
        SOCAlerter();
     } 
  }
  
  void BatteryChargeRateIsOk(float chargeRate)
  {
     if(CheckChargeRateInRange(chargeRate) != 1)
     {
        ChargeRateAlerter();
     }
  }


void BatteryIsOk(float temperature, float soc, float chargeRate) 
{
    void BatteryTempIsOk(float temperature);
    void BatterySOCIsOk(float soc);
    void BatteryChargeRateIsOk(float chargeRate);
}
 
 

int main() {
    BatteryIsOk(25, 70, 0.7);

    
    BatteryIsOk(50, 85, 0);

}
