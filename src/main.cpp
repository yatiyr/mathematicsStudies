#include <iostream>

#include <config/RootDir.h>
#include <fstream>
#include <array>

#include <Vector/vec.h>

#include <types.h>


int main()
{


    hyl::fvec2 vectornew(4.0, 3.0);
    hyl::fvec2 vectornew2 = hyl::normalized(vectornew);


    hyl::fvec2 vectorNormal(0.0, 1.0);
    hyl::fvec2 reflectVec(1.0, -1.0);

    hyl::fvec2 reflectionVec = hyl::projection(reflectVec, vectorNormal);

    std::cout << reflectionVec << std::endl;


}