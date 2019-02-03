

void show_menu()
{

  display.clearDisplay();
  /*display.setTextSize(2);//2 : 10 x 4 char
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("Germoir v1");*/
  display.setCursor(0, 0);
  display.setTextSize(1);//2 : 10 x 4 char

  ////////////////////
  if (id_menu == ID_PRINC)
  {
    for (int i = 1; i <= size_m_princ; i++)
    {
      if (select == i)
      {
        display.setTextColor(BLACK, WHITE);
      }
      display.println(m_princ[i - 1]);
      display.setTextColor(WHITE);

      if (i != size_m_manu)
      {
        if (i < 3)
        {
          display.setCursor(80, (i - 1) * 10);
          if (etat_routines[i - 1] == 1) // if ON
          {
            display.setTextColor(WHITE);
            display.print("OFF ");
            display.setTextColor(BLACK, WHITE);
            display.println("ON");
          }
          else // if OFF
          {
            display.setTextColor(BLACK, WHITE);
            display.print("OFF");
            display.setTextColor(WHITE);
            display.println(" ON");
          }
        }
        display.setTextColor(WHITE);
      }
    }
    if(etat_routines[0])
    {
      
      display.println("");
      String StrDostxt = "Pump in: ";
      display.print(StrDostxt);
      display.print((nextPumpAct/60)/60);
      display.print(":");
      display.print((nextPumpAct/60)%60);
      display.print(":");
      display.println(nextPumpAct%60);
      StrDostxt = "Fan in: ";
      display.print(StrDostxt);
      display.print((nextFanAct/60)/60);
      display.print(":");
      display.print((nextFanAct/60)%60);
      display.print(":");
      display.println(nextFanAct%60);
    }
  }
  ////////////////////////
  else if (id_menu == ID_MANU)
  {
    for (int i = 1; i <= size_m_manu; i++)
    {
      if (select == i)
      {
        display.setTextColor(BLACK, WHITE);
      }
      display.print(m_manu[i - 1]);
      display.setTextColor(WHITE);

      if (i != size_m_manu)
      {
        display.setCursor(80, (i - 1) * 10);
        if (etat_actionneurs[i - 1] == 1)
        {
          display.setTextColor(WHITE);
          display.print("OFF ");
          display.setTextColor(BLACK, WHITE);
          display.println("ON");
        }
        else
        {
          display.setTextColor(BLACK, WHITE);
          display.print("OFF");
          display.setTextColor(WHITE);
          display.println(" ON");
        }
      }
      display.setTextColor(WHITE);
    }
  }

  display.display();
}

void enter()
{
  switch (id_menu)
  {
    case ID_PRINC:
      switch (select)
      {
        case 1:
          etat_routines[select - 1] = !etat_routines[select - 1];
          break;

        case 2:
          etat_routines[select - 1] = !etat_routines[select - 1];
          break;

        case 3:
          id_menu = ID_MANU;
          select = 1;
          break;

        case size_m_princ:
          //exit
          setup();
          break;

      }
      break;


    case ID_MANU:
      if (select == size_m_manu)
      { //exit
        id_menu = ID_PRINC;
        select = 1;
      }
      else
      {
        etat_actionneurs[select - 1] = !etat_actionneurs[select - 1];
        update_actionneurs();
      }
      break;
  }


}

