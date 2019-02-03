void routine()
{
  millisNow = (unsigned long)millis()/1000;
  if (etat_routines[0]) //If routine 1 is ON
  {
    if(currentMillisPump > R1interPump)
    {
      startingR1Pump = millisNow;
    }
    currentMillisPump = millisNow - startingR1Pump;
    nextPumpAct = (R1interPump - currentMillisPump);
    if ((currentMillisPump < R1activePump) && (statePumpR1 == 0)) 
    {
      statePumpR1 = 1;
      etat_actionneurs[3] = 1;
      update_actionneurs();
    }
    else if ((currentMillisPump > R1activePump) && (statePumpR1 == 1)) 
    {
      statePumpR1 = 0;
      etat_actionneurs[3] = 0;
      update_actionneurs();
    }

    if(currentMillisFan > R1interFan)
    {
      startingR1Fan = millisNow;
    }
    currentMillisFan = millisNow - startingR1Fan;
    nextFanAct = (R1interFan - currentMillisFan);
    if ((currentMillisFan < R1activeFan) && (stateFanR1 == 0)) 
    {
      stateFanR1 = 1;
      etat_actionneurs[2] = 1;
      update_actionneurs();
    }
    else if ((currentMillisFan > R1activeFan) && (stateFanR1 == 1)) 
    {
      stateFanR1 = 0;
      etat_actionneurs[2] = 0;
      update_actionneurs();
    }
    
  }
  else  //If routine 1 is OFF
  {
    startingR1Fan = millisNow;
    startingR1Pump = millisNow;
    statePumpR1 = 0;
    stateFanR1 = 0;
    //Serial.println("Routine OFF");
  }

  if (etat_routines[1])  //If routine 2 is ON
  {
  }
  else  //If routine 2 is OFF
  {

  }


}



