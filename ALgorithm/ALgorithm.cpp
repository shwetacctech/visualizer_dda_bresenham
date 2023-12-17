// ALgorithm.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "ALgorithm.h"


// This is an example of an exported variable
ALGORITHM_API int nALgorithm=0;

// This is an example of an exported function.
ALGORITHM_API int fnALgorithm(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
ALgorithm::ALgorithm()
{
    return;
}
