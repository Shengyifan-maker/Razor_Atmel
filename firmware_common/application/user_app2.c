/**********************************************************************************************************************
File: user_app2.c                                                                

Description:
This is a user_app2.c file template 

------------------------------------------------------------------------------------------------------------------------
API:

Public functions:


Protected System functions:
void UserApp2Initialize(void)
Runs required initialzation for the task.  Should only be called once in main init section.

void UserApp2RunActiveState(void)
Runs current task state.  Should only be called once in main loop.


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_UserApp2"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp2Flags;                       /* Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */
extern volatile u32 G_u32SystemTime1s;                 /* From board-specific source file */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp2_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp2_StateMachine;            /* The state machine function pointer */
//static u32 UserApp2_u32Timeout;                      /* Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------------------------*/
/* Protected functions                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Function: UserApp2Initialize

Description:
Initializes the State Machine and its variables.

Requires:
  -

Promises:
  - 
*/
void UserApp2Initialize(void)
{
  /* If good initialization, set state to Idle */
  if( 1 )
  {
    UserApp2_StateMachine = UserApp2SM_Idle;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp2_StateMachine = UserApp2SM_FailedInit;
  }

} /* end UserApp2Initialize() */

  
/*----------------------------------------------------------------------------------------------------------------------
Function UserApp2RunActiveState()

Description:
Selects and runs one iteration of the current state in the state machine.
All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
  - State machine function pointer points at current state

Promises:
  - Calls the function to pointed by the state machine function pointer
*/
void UserApp2RunActiveState(void)
{
  UserApp2_StateMachine();

} /* end UserApp2RunActiveState */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* Wait for ??? */
static void UserApp2SM_Idle(void)
{
   static u32 u32Counter = 0;
    static u32 u32Counter1 = 0;
    static u32 u32n = 0;

        if(WasButtonPressed(BUTTON3)) 
        { 
          ButtonAcknowledge(BUTTON3);
          u32n = 0;

          //u8 au8Message[] = ;
          LCDMessage(LINE1_START_ADDR,"CHOOSE THE SONG       ");
          
          
          //    ButtonAcknowledge(BUTTON0);
          //    ButtonAcknowledge(BUTTON1);
          //    ButtonAcknowledge(BUTTON2);
          
          
          
          PWMAudioOff(BUZZER1); 
          PWMAudioOff(BUZZER2);
          
          LedOff(WHITE);
          LedOff(PURPLE);
          LedOff(BLUE);
          LedOff(CYAN);
          LedOff(GREEN);
          LedOff(YELLOW);
          LedOff(ORANGE);
          LedOff(RED);
          
        }
        
        if( WasButtonPressed(BUTTON0) )
        { 
          ButtonAcknowledge(BUTTON0);
          u32n = 1;

      
          u8 au8Message[] = "FEN  SHUAI  JIANG!";
          LCDMessage(LINE1_START_ADDR, au8Message);
          LCDClearChars(LINE1_START_ADDR +20, 3);
          //LCDCommand(LCD_CLEAR_CMD);
          LedPWM(LCD_RED, LED_PWM_100);
          LedPWM(LCD_GREEN, LED_PWM_0);
          LedPWM(LCD_BLUE, LED_PWM_0);//LCD display;
        } 
       
          if(u32n == 1)
          {

           u32Counter1++;
           if(u32Counter1 == 100)
            { 
              LedOn(WHITE); 
            }
           if(u32Counter1 == 200)
            {
              LedOn(PURPLE); 
            }
           if(u32Counter1 == 300)
            {
              LedOn(BLUE);
     
            }
           if(u32Counter1 == 400)
            {
              LedOn(CYAN);
     
            }
           if(u32Counter1 == 500)
            {
              LedOn(GREEN);
            }
           if(u32Counter1 == 600)
            {
              LedOn(YELLOW);
            }
           if(u32Counter1 == 700)
            {
              LedOn(ORANGE);
            }
           if(u32Counter1 == 800)
           { 
              LedOn(RED);
           }  
           if(u32Counter1 == 900)
           { 
              LedOff(RED);  
              LedOff(WHITE);
              LedOff(PURPLE);
              LedOff(BLUE);
              LedOff(CYAN);
              LedOff(GREEN);
              LedOff(YELLOW);
              LedOff(ORANGE); 
              u32Counter1 = 0;   
           } 
         
           //led display; 
           
        static u16 au16NotesLeft[]    = {G4,E4,G4,E4, G4,E4,C4, D4,F4,E4,D4, G4,       G4,E4,G4,E4, G4,E4,C4,
                                        D4,F4,E4,D4, C4,       D4,D4,F4,F4, E4,C4,G4, D4,F4,E4,D4, G4,
                                        G4,E4,G4,E4, G4,E4,C4, D4,F4,E4,D4, C4,NO
                                        };
        
        
        static u16 au16DurationLeft[] = {EN,EN,EN,EN, EN,EN,QN, EN,EN,EN,EN, QN,       EN,EN,EN,EN, EN,EN,QN,
                                         EN,EN,EN,EN, QN,       EN,EN,EN,EN, EN,EN,QN, EN,EN,EN,EN, QN,
                                         EN,EN,EN,EN, EN,EN,QN, EN,EN,EN,EN, QN,QN
                                        };
        
        
        static u16 au16NoteTypeLeft[] = {RT,RT,RT,RT, RT,RT,HT, RT,RT,RT,RT, HT,       RT,RT,RT,RT, RT,RT,HT,
                                         RT,RT,RT,RT, HT,       RT,RT,RT,RT, RT,RT,RT, RT,RT,RT,RT, HT,
                                         RT,RT,RT,RT, RT,RT,HT, RT,RT,RT,RT, RT,RT
                                        };//Buzzer song;
        static u8 u8IndexLeft = 0;
        static u32 u32LeftTimer = 0;
        static u16 u16CurrentDurationLeft = 0;
        static u16 u16NoteSilentDurationLeft = 0;
        static bool bNoteActiveNextLeft = TRUE;
        u8 u8CurrentIndex;
        if(IsTimeUp(&u32LeftTimer, (u32)u16CurrentDurationLeft))
        {
          u32LeftTimer = G_u32SystemTime1ms;
          u8CurrentIndex = u8IndexLeft;
          
          if(bNoteActiveNextLeft)
          {
            if(au16NoteTypeLeft[u8CurrentIndex] == RT)
            {
              u16CurrentDurationLeft = au16DurationLeft[u8CurrentIndex] - REGULAR_NOTE_ADJUSTMENT;
              u16NoteSilentDurationLeft = REGULAR_NOTE_ADJUSTMENT;
              bNoteActiveNextLeft = FALSE;
            }
          
            else if(au16NoteTypeLeft[u8CurrentIndex] == ST)
            {
              u16CurrentDurationLeft = STACCATO_NOTE_TIME;
              u16NoteSilentDurationLeft = au16DurationLeft[u8CurrentIndex] - STACCATO_NOTE_TIME;
              bNoteActiveNextLeft = FALSE;
            }

            else if(au16NoteTypeLeft[u8CurrentIndex] == HT)
            {
              u16CurrentDurationLeft = au16DurationLeft[u8CurrentIndex];
              u16NoteSilentDurationLeft = 0;
              bNoteActiveNextLeft = TRUE;

              u8IndexLeft++;
              if(u8IndexLeft == sizeof(au16NotesLeft) / sizeof(u16) )
              {
                u8IndexLeft = 0;
              }
            }

            if(au16NotesLeft[u8CurrentIndex] != NO)
            {
              PWMAudioSetFrequency(BUZZER2, au16NotesLeft[u8CurrentIndex]);
              PWMAudioOn(BUZZER2);
            }
            else
            {                
              PWMAudioOff(BUZZER2);
            }
          }
          else
          {
              PWMAudioOff(BUZZER2);
              u32LeftTimer = G_u32SystemTime1ms;
              u16CurrentDurationLeft = u16NoteSilentDurationLeft;
              bNoteActiveNextLeft = TRUE;
              
              u8IndexLeft++;
              if(u8IndexLeft == sizeof(au16NotesLeft) / sizeof(u16) )
              {
                u8IndexLeft = 0;
              }
          } 
        }         
     }

   
   if(WasButtonPressed(BUTTON1))
   {
      ButtonAcknowledge(BUTTON1);
      u32n = 2;
      u32Counter = 0;
   
   
        u8 au8Message[] = "ODE    TO    JOY!  ";
        LCDMessage(LINE1_START_ADDR, au8Message);
        LCDClearChars(LINE1_START_ADDR +20, 3);
        //LCDCommand(LCD_CLEAR_CMD);
        LedPWM(LCD_RED, LED_PWM_0);
        LedPWM(LCD_GREEN, LED_PWM_0);
        LedPWM(LCD_BLUE, LED_PWM_100);
   }
   
   if(u32n == 2)
   {
     u32Counter++;
     if(u32Counter == 100)
     {
     LedOn(RED);
     }
   
     if(u32Counter == 200)
   {
     LedOff(RED);
     LedOn(YELLOW);
   }
     if(u32Counter == 300)
   {
     LedOff(YELLOW);
     LedOn(ORANGE);
   }
     if(u32Counter == 400)
   {
     LedOff(ORANGE);
     LedOn(GREEN);
   } 
   if(u32Counter == 500)
   {
     LedOff(GREEN);
     LedOn(BLUE);
     
   } 
    if(u32Counter == 600)
   {
     LedOff(BLUE);
     LedOn(CYAN);      
   } 
    if(u32Counter == 700)
   {
     LedOff(CYAN);
     LedOn(WHITE); 
     
   } 
    if(u32Counter == 800)
   {
     LedOff(WHITE);
     LedOn(PURPLE); 
     
   } 
    if(u32Counter == 850)
   { 
     LedOff(WHITE);
     LedOff(PURPLE);
     LedOff(BLUE);
     LedOff(CYAN);
     LedOff(GREEN);
     LedOff(YELLOW);
     LedOff(ORANGE); 
     LedOff(RED);
     u32Counter = 0; 
   }
      
   

    
     static u16 au16NotesLeft[]    = {E4,E4,F4,G4, G4,F4,E4,D4, C4,C4,D4,E4, E4,D4,D4,NO,
                                     E4,E4,F4,G4, G4,F4,E4,D4, C4,C4,D4,E4, D4,C4,C4,NO,
                                     D4,D4,E4,C4, D4,E4,F4,E4,C4, D4,E4,F4,E4,D4,
                                     C4,D4,G3,E4, E4,F4,G4, G4,F4,E4,F4,D4, C4,C4,D4,E4, D4,C4,C4,NO};
    
    
    static u16 au16DurationLeft[] = {QN,QN,QN,QN, QN,QN,QN,QN, QN,QN,QN,QN, HN,EN,QN,EN,
                                     QN,QN,QN,QN, QN,QN,QN,QN, QN,QN,QN,QN, HN,EN,QN,EN,
                                     QN,QN,QN,QN, QN,EN,EN,QN,QN, QN,EN,EN,QN,QN,
                                     QN,QN,QN,QN, QN,QN,QN, QN,QN,QN,EN,EN, QN,QN,QN,QN, HN,EN,QN,EN};
    
    
    static u16 au16NoteTypeLeft[] = {RT,RT,RT,RT, RT,RT,RT,RT, RT,RT,RT,RT, HT,RT,RT,RT,
                                     RT,RT,RT,RT, RT,RT,RT,RT, RT,RT,RT,RT, HT,RT,RT,RT,
                                     RT,RT,RT,RT, RT,RT,RT,RT,RT, RT,RT,RT,RT,RT,
                                     RT,RT,RT,HT, RT,RT,RT, RT,RT,RT,RT,RT, RT,RT,RT,RT, HT,RT,RT,RT};
   
    
    static u8  u8IndexLeft = 0;
    static u32 u32LeftTimer = 0;
    static u16 u16CurrentDurationLeft = 0;
    static u16 u16NoteSilentDurationLeft = 0;
    static bool bNoteActiveNextLeft = TRUE;
    u8 u8CurrentIndex;
    if(IsTimeUp(&u32LeftTimer, (u32)u16CurrentDurationLeft))
    {
      u32LeftTimer = G_u32SystemTime1ms;
      u8CurrentIndex = u8IndexLeft;
      
      /* Set up to play current note */
      if(bNoteActiveNextLeft)
      {
        if(au16NoteTypeLeft[u8CurrentIndex] == RT)
        {
          u16CurrentDurationLeft = au16DurationLeft[u8CurrentIndex] - REGULAR_NOTE_ADJUSTMENT;
          u16NoteSilentDurationLeft = REGULAR_NOTE_ADJUSTMENT;
          bNoteActiveNextLeft = FALSE;
        }
      
        else if(au16NoteTypeLeft[u8CurrentIndex] == ST)
        {
          u16CurrentDurationLeft = STACCATO_NOTE_TIME;
          u16NoteSilentDurationLeft = au16DurationLeft[u8CurrentIndex] - STACCATO_NOTE_TIME;
          bNoteActiveNextLeft = FALSE;
        }

        else if(au16NoteTypeLeft[u8CurrentIndex] == HT)
        {
          u16CurrentDurationLeft = au16DurationLeft[u8CurrentIndex];
          u16NoteSilentDurationLeft = 0;
          bNoteActiveNextLeft = TRUE;

          u8IndexLeft++;
          if(u8IndexLeft == sizeof(au16NotesLeft) / sizeof(u16) )
          {
            u8IndexLeft = 0;
          }
        }

        /* Set the buzzer frequency for the note (handle NO special case) */
        if(au16NotesLeft[u8CurrentIndex] != NO)
        {
          PWMAudioSetFrequency(BUZZER2, au16NotesLeft[u8CurrentIndex]);
          PWMAudioOn(BUZZER2);
        }
        else
        {                
          PWMAudioOff(BUZZER2);
        }
      }
        else
        {
          PWMAudioOff(BUZZER2);
          u32LeftTimer = G_u32SystemTime1ms;
          u16CurrentDurationLeft = u16NoteSilentDurationLeft;
          bNoteActiveNextLeft = TRUE;
          
          u8IndexLeft++;
          if(u8IndexLeft == sizeof(au16NotesLeft) / sizeof(u16) )
          {
            u8IndexLeft = 0;
          }
      } /* end else if(bNoteActiveNextLeft) */
    } /* end if(IsTimeUp(&u32LeftTimer, (u32)u16CurrentDurationLeft)) */
   //}
   } // END OF TASK2 CODE

} /* end UserApp2SM_Idle() */
   
#if 0
/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp2SM_Error(void)          
{
  
} /* end UserApp2SM_Error() */
#endif


/*-------------------------------------------------------------------------------------------------------------------*/
/* State to sit in if init failed */
static void UserApp2SM_FailedInit(void)
{
  
}
 /* end UserApp2SM_FailedInit() */


/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
