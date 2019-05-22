
#include <AppControl.h>
#include <KinOS.h>

#include "debug.h"

enum{ FSM_1_CONNECTED , FSM_1_ADVERTISING , FSM_1_RESTART_ADV};

void AppControlHandler()
{
    bool update_done = false;
    
    //---------------------------------------------------------//
    //                                                         //
    //               CONNECTIVITY STATE MACHINE                //
    //                                                         //
    //                    +-------------+                      //
    //                    |             |                      //
    //                    |  Connected  |                      //
    //                    |             |                      //
    //                    +---^-----+---+                      //
    //                        |     |                          //
    //            Connected   |     |  !Is_Connected           //
    //           [No Output]  |     |   [No Output]            //
    //                        |     |                          //
    //                    +---+-----v---+                      //
    //            +------->             |                      //
    //            | START | Advertising |                      //
    //            +------->             |                      //
    //                    +---^-----+---+                      //
    //                        |     |                          //
    //              True      |     |   !Is_Advertising &      //
    //           [No Output]  |     |     !Is_Connected        //
    //                        |     |  [Start Advertising]     //
    //                        |     |                          //
    //                    +---+-----v---+                      //
    //                    |             |                      //
    //                    | Restart Adv |                      //
    //                    |             |                      //
    //                    +-------------+                      //
    //                                                         //
    //---------------------------------------------------------//
    
    static uint8 current_state = FSM_1_ADVERTISING;
    static uint8 next_state    = FSM_1_ADVERTISING;
        
    do  //-----------------------------------------------------//
    {   //-------------------State-Transitions-----------------//
        
        switch(current_state)
        {
            case FSM_1_CONNECTED:
            {
                if(!KinOS_IsConnected())
                {
                    next_state = FSM_1_ADVERTISING;
                    KinOS_ConfigureLight(BLUE,BYPASS,1,100);
                }
                
                break;
            }
            case FSM_1_ADVERTISING:
            {
                if(!KinOS_IsAdvertising() && !KinOS_IsConnected())
                {
                    next_state = FSM_1_RESTART_ADV;
                }
                else if(KinOS_IsConnected())
                {
                    next_state = FSM_1_CONNECTED;
                    KinOS_ConfigureLight(GREEN,BYPASS,1,100);
                }
                break;
            }
            case FSM_1_RESTART_ADV:
            {
                //KinOS_ConfigureLight(GREEN,ZIGZAG,25,100);
                next_state = FSM_1_ADVERTISING;
                break;
            }
        }
        //-----------------------------------------------------//
        //------------------Transition-Outputs-----------------//
        
        switch(current_state)
        {
            case FSM_1_CONNECTED:
            {
                break;
            }
            case FSM_1_ADVERTISING:
            {
                switch(next_state)
                {
                    case FSM_1_RESTART_ADV:
                    {
                        KinOS_Advertise(1,100);
                        break;
                    }
                }
                break;
            }
            case FSM_1_RESTART_ADV:
            {
                break;
            }
        }
        //-----------------------------------------------------//
        //-----------------------------------------------------//
        
        update_done = (current_state == next_state);
        current_state = next_state; // Update state
    }
    while(!update_done);
    NVIC_ClearPendingIRQ(AppControl_IRQ_cfg.intrSrc);
}
