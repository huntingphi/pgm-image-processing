#ifndef DRIVER_HEADER
#define DRIVER_HEADER
#include <iostream>
#define STUB(method) void method(){std::cout<<"Todo: "<<#method<<"\n";}
STUB(invertImage);
STUB(add);
STUB(subtract);
STUB(mask);
STUB(threshold);

#endif