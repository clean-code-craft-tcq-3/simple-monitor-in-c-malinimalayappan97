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

 TempRange_e CheckTempRange(float temperature)
  {
      if(temperature < 0 )
      {
          BatteryCheck_s.TempRange = LOW_Temp_BREACH;
      }
      else if(temperature >= 0 && temperature < 2.25)
      {
          BatteryCheck_s.TempRange = LOW_Temp_WARNING;
      }
      else if(temperature >= 2.25 && temperature < 42.75)
      {
          BatteryCheck_s.TempRange = Temp_NORMAL;
      }
      else if(temperature >= 4.75 && temperature < 45)
      {
          BatteryCheck_s.TempRange = HIGH_Temp_WARNING;
      }
      else
      {
          BatteryCheck_s.TempRange = HIGH_Temp_BREACH;
      }
      return BatteryCheck_s.TempRange;
  }
  
  SOCRange_e CheckSocRange(float soc)
  {
      if(soc < 20 )
      {
          BatteryCheck_s.SOCRange = LOW_SOC_BREACH;
      }
      else if(soc >= 20 && soc < 24)
      {
          BatteryCheck_s.SOCRange = LOW_SOC_WARNING;
      }
      else if(soc >= 24 && soc < 76)
      {
          BatteryCheck_s.SOCRange = SOC_NORMAL;
      }
      else if(soc >= 76 && soc < 80)
      {
          BatteryCheck_s.SOCRange = HIGH_SOC_WARNING;
      }
      else
      {
          BatteryCheck_s.SOCRange = HIGH_SOC_BREACH;
      }
      return BatteryCheck_s.SOCRange;
  }

ChargeRateRange_e CheckChargeRateRange(float chargeRate)
  {
      if(chargeRate > 0.8 )
      {
          BatteryCheck_s.ChargeRateRange = ChargeRate_BREACH;
      }
      else if(chargeRate <=0.8 && chargeRate >= 0.76)
      {
          BatteryCheck_s.ChargeRateRange = ChargeRate_WARNING;
      }
      else
      {
          BatteryCheck_s.ChargeRateRange = ChargeRate_NORMAL;
      }
      return BatteryCheck_s.ChargeRateRange;
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
     if(CheckTempRange(temperature) != Temp_NORMAL)
     {
       TempAlerter();
     } 
  }
  
  void BatterySOCIsOk(float soc)
  {
     if(CheckSocRange(soc) != SOC_NORMAL)
     {
        SOCAlerter();
     } 
  }
  
  void BatteryChargeRateIsOk(float chargeRate)
  {
     if(CheckChargeRateRange(chargeRate) != ChargeRate_NORMAL)
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
