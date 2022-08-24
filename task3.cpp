#include <Arduino.h>
#include "task3.h"
#include "events.h"

static bool compareKeys(BUTTONS *pSecret, BUTTONS *pKey)
{
    bool correct = true;
    for (uint8_t i = 0; i < 5; i++)
    {
        if (pSecret[i] != pKey[i]){
            correct = false;
            break;
        }
    }

    return correct;
}

void task3()
{

    enum class TaskStates
    {
        INIT,
        WAIT_CONFIG,
        APAGADO,
        ENCENDIDO,
        LENTO,
        MEDIO,
        RAPIDO,
    
    };
    static TaskStates taskState = TaskStates::INIT;
    const uint8_t led = 14;

    static const uint32_t ledSpeed = 0;

    static uint8_t ledState;
    static uint8_t keyCounter;

    switch (taskState)
    {
    case TaskStates::INIT:
    {
            if (buttonEvt.trigger == true)
            {
                buttonEvt.trigger = false;
                if (const uint32_t LentoINTERVAL = 500)
                {
                    if (buttonEvt.whichButton == BUTTONS::Boton1)
                    {
                        //Hacer que el led se apague                    
                        digitalWrite(led, LOW);
                    }

                    if (buttonEvt.whichButton == BUTTONS::Boton2)
                    {
                        //Hacer que el modo cambie a medio                
                        ledSpeed == 250;
                    }

                }

                if (const uint32_t MedioINTERVAL = 250)
                {
                    if (buttonEvt.whichButton == BUTTONS::Boton1)
                    {
                        //Hacer que el led se prenda                   
                        digitalWrite(led, HIGH);
                    }

                    if (buttonEvt.whichButton == BUTTONS::Boton2)
                    {
                        //Hacer que el modo cambie a lento              
                        ledSpeed == 500;
                    }

                }

                if (led == LOW)
                {
                    if (buttonEvt.whichButton == BUTTONS::Boton1)
                    {
                        //Hacer que el modo cambie a lento                     
                        ledSpeed == 500;
                    }

                    if (buttonEvt.whichButton == BUTTONS::Boton2)
                    {
                        //Hacer que el modo cambie a rapido              
                        ledSpeed == 125;
                    }

                }

                if (led == HIGH)
                {
                    if (buttonEvt.whichButton == BUTTONS::Boton1)
                    {
                        //Hacer que el modo cambie a medio                    
                        ledSpeed == 250;
                    }

                    if (buttonEvt.whichButton == BUTTONS::Boton2)
                    {
                        //Hacer que el modo cambie a rapido              
                        ledSpeed == 125;
                    }

                }

                if (const uint32_t RapidoINTERVAL = 125)
                {     
                    bool SecretCodigoRapido = false;

                    static BUTTONS SecretCodigoRapido[5] = {BUTTONS::Boton1, BUTTONS::Boton1,
                                                    BUTTONS::Boton2, BUTTONS::Boton2,
                                                    BUTTONS::Boton1};

                    static BUTTONS RapidoKey[5] = {BUTTONS::NONE};

                    if (SecretCodigoRapido = true){
                        digitalWrite(led, LOW);
                    }
                    else{
                       static TaskStates taskState = TaskStates::ENCENDIDO; 
                    }

                }


            break;
    }
    case TaskStates::LENTO:
    {
        const uint8_t led = 14;
        const uint32_t LentoINTERVAL = 500;

        break;
    }

    case TaskStates::MEDIO:
    {
        const uint8_t led = 14;
        const uint32_t MedioINTERVAL = 250;
        
        break;
    }

    case TaskStates::RAPIDO:
    {
        const uint8_t led = 14;
        const uint32_t RapidoINTERVAL = 125;
        
        break;
    }

    case TaskStates::APAGADO:
    {
        const uint8_t led = 14;
        digitalWrite(led, LOW);
        
        break;
    }

    case TaskStates::ENCENDIDO:
    {
        const uint8_t led = 14;
        digitalWrite(led, HIGH);
        
        break;
    }

    
    default:
    {
        break;
    }
    }
}