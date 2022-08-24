#include <Arduino.h>
#include "task2.h"
#include "events.h"

void task2()
{
    enum class TaskState
    {
        INIT,
        WAIT_PRESS,
        WAIT_STABLE,
        WAIT_RELEASE
    };
    static TaskState taskState = TaskState::INIT;
    static uint8_t lastButtonPressed;
    static uint32_t initStableTime;

    const uint8_t Boton1 = 13;
    const uint8_t Boton2 = 32;
    const uint32_t STABLE_TIME = 100;

    switch (taskState)
    {
    case TaskState::INIT:
    {
        pinMode(Boton1, INPUT_PULLUP);
        pinMode(Boton2, INPUT_PULLUP);

        taskState = TaskState::WAIT_PRESS; 
        break;
    }
    case TaskState::WAIT_PRESS:
    {
        if(digitalRead(Boton1) == LOW){
            lastButtonPressed = Boton1;
            initStableTime = millis();
            taskState = TaskState::WAIT_STABLE;
        }

        if(digitalRead(Boton2) == LOW){
            lastButtonPressed = Boton2;
            initStableTime = millis();
            taskState = TaskState::WAIT_STABLE;
        }
        break;
    }
    case TaskState::WAIT_STABLE:
    {
        if(digitalRead(lastButtonPressed) != LOW){
            taskState = TaskState::WAIT_PRESS;
        }
        else if ( (millis() - initStableTime) > STABLE_TIME){
            if(lastButtonPressed == Boton1) buttonEvt.whichButton = BUTTONS::Boton1;
            else if(lastButtonPressed == Boton2) buttonEvt.whichButton = BUTTONS::Boton2;
            buttonEvt.trigger = true;
            printf("Button pressed: %d\n", lastButtonPressed);
            taskState = TaskState::WAIT_RELEASE;
        }
        break;
    }
    case TaskState::WAIT_RELEASE:{
        if(digitalRead(lastButtonPressed) == HIGH){
            taskState = TaskState::WAIT_PRESS;
        }
        break;
    }

    default:
    {
    }
    }
}