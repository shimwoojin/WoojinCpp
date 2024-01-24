#include <stdio.h>
#include <iostream>

class exampleClass {
    int m_nID;
public:
    // initialize object with a read-only unique ID
    exampleClass(int nID) : m_nID(nID) {}
    int GetID(void) { return m_nID; }
};

class exampleClass2 {
    int m_nID;
public:
    // initialize object with a read-only unique ID
    exampleClass2(int nID) : m_nID(nID) {}
    int GetID(void) { return m_nID; }
};

int main()
{
    for (int i = 0; i < 10; i++)
    {
        __COUNTER__;
    }

    // __COUNTER__ is initially defined as 0
    exampleClass e1(__COUNTER__);

    // On the second reference, __COUNTER__ is now defined as 1
    exampleClass e2(__COUNTER__);

    // __COUNTER__ is now defined as 2
    exampleClass e3(__COUNTER__);

    exampleClass2 e4(__COUNTER__);
    exampleClass2 e5(__COUNTER__);
    exampleClass2 e6(__COUNTER__);

    printf("e1 ID: %i\n", e1.GetID());
    printf("e2 ID: %i\n", e2.GetID());
    printf("e3 ID: %i\n", e3.GetID());
    printf("e3 ID: %i\n", e4.GetID());
    printf("e3 ID: %i\n", e5.GetID());
    printf("e3 ID: %i\n", e6.GetID());

    // Output
    // ------------------------------
    // e1 ID: 0
    // e2 ID: 1
    // e3 ID: 2

    return 0;
}