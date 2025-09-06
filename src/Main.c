#include "/home/codeleaded/System/Static/Library/GarbageCollector.h"

int main() {

    GarbageCollector gc = GarbageCollector_New();
    GarbageCollector_Start(&gc);

    void* owner1 = NULL;
    GarbageCollector_Alloc(&gc,&owner1,10);
    
    
    void* owner2 = NULL;
    GarbageCollector_Alloc(&gc,&owner2,10);
    

    {
        void* owner3 = NULL;
        GarbageCollector_Share(&gc,&owner2,&owner3);
        

        Thread_Sleep_M(1000);
    }

    {
        void* owner4 = NULL;
        GarbageCollector_Share(&gc,&owner2,&owner4);
        owner4 = NULL;

        Thread_Sleep_M(1000);
    }
    owner1 = NULL;
    owner2 = NULL;


    Thread_Sleep_M(2000);

    GarbageCollector_Free(&gc);    

    return 0;
}
