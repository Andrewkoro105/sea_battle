#include <iostream>
#include "fiend.h"

using namespace std;

int main()
{
    fiend meField(1, true);
    fiend unMeField(2, true);
    
    //meField.get();
    //meField.set();
	
    //unMeField.get();
    //unMeField.set();

    meField.get2Fiend(unMeField);
    meField.Shot(unMeField);
}

