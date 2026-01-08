#include "../Config/Config.h"
#include "../Menu/Menu.h"

void ResetTimer()
{
    static bool resetExecuted = false;

    // ponteiros
    uintptr_t Ptr1 = *(uintptr_t*)(Client + 0x1279228);
    if (!Ptr1) return;

    uintptr_t Ptr2 = *(uintptr_t*)(Ptr1 + 0x20);
    if (!Ptr2) return;

    uintptr_t Ptr3 = *(uintptr_t*)(Ptr2 + 0x40);
    if (!Ptr3) return;

    float* ResetTimer_Value = (float*)(Ptr3 + 0x0);


    




    // --------------------------------------------------
    // RESET UMA VEZ (volta a subir)
    // --------------------------------------------------
    if (Config::ResetTimerOnce && !resetExecuted)
    {
        *ResetTimer_Value = 0.0f;
        resetExecuted = true;
    }

    if (!Config::ResetTimerOnce)
    {
        resetExecuted = false;
    }

    // --------------------------------------------------
    // FREEZE TIMER (fica travado em 0)
    // --------------------------------------------------
    if (Config::FreezeTimer)
    {
        *ResetTimer_Value = 0.0f;
    }
}
