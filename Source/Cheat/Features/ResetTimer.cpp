#include "../Config/Config.h"
#include "../Menu/Menu.h"

void ResetTimer()
{
    uintptr_t Ptr1 = *(uintptr_t*)(Client + 0x1279228);
    if (!Ptr1) return;
    uintptr_t Ptr2 = *(uintptr_t*)(Ptr1 + 0x20);
    if (!Ptr2) return;
    uintptr_t Ptr3 = *(uintptr_t*)(Ptr2 + 0x40);
    if (!Ptr3) return;

    double* ResetTimer_Value = (double*)(Ptr3 + 0x0);

    static bool resetExecuted = false;
    if (Config::ResetTimerOnce && !resetExecuted)
    {
        *ResetTimer_Value = 0.0;
        resetExecuted = true;
    }

    if (!Config::ResetTimerOnce)
    {
        resetExecuted = false;
    }
}
