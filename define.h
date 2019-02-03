
//////////////////////////////////
// menu display Declaration //
//////////////////////////////////
byte id_menu = 1;
byte select = 1;

byte R1start = 0;
byte R2start = 0;

#define ID_PRINC 1
#define ID_MANU 2

#define size_m_princ 4 //+1 for exit
String m_princ[] = {"Routine 1", "Routine 2", "manu", "exit"};
byte etat_routines[] = {0, 0};

#define size_m_manu 5 //+1 for exit
String m_manu[] = {"Vidange 1:", "Vidange 2:", "Air:", "Pompe:", "exit "};

#define nb_actionneurs 4
byte etat_actionneurs[] = {0, 0, 0, 0};

//////////////////////////////////
// mosfet pin Declaration //
//////////////////////////////////
#define pinValve1  3 //down plug
#define pinPump  5 // midle plug
#define pinFan  6 // up plug
#define pinValve2 4 //Direct

//////////////////////////////////
// Timer Declaration //
//////////////////////////////////
unsigned long millisNow = 0;
unsigned long currentMillisFan = 0;
unsigned long currentMillisPump = 0;
unsigned long startingR1Fan = 0;
unsigned long startingR1Pump = 0;
unsigned long startingR2;

int statePumpR1;
int stateFanR1;
unsigned long nextFanAct = 0;
unsigned long nextPumpAct = 0;

#define R1interPump 43200 // interval between pump activation in sec
#define R1interFan 43200 // interval between fan activation in sec
#define R1activePump 1 // Time in sec of Pump activation
#define R1activeFan 300 // Time in sec of Pump activation


//////////////////////////
// MicroOLED Definition //
//////////////////////////
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

//////////////////////////////////
// buttons Declaration //
//////////////////////////////////

#define DEBOUNCE 10  // button debouncer, how many ms to debounce, 5+ ms is usually plenty

// here is where we define the buttons that we'll use. button "1" is the first, button "6" is the 6th, etc
byte buttons[] = {14, 15, 16}; // the analog 0-5 pins are also known as 14-19
// This handy macro lets us determine how big the array up above is, by checking the size
#define NUMBUTTONS sizeof(buttons)
// we will track if a button is just pressed, just released, or 'currently pressed'
byte pressed[NUMBUTTONS], justpressed[NUMBUTTONS], justreleased[NUMBUTTONS];
