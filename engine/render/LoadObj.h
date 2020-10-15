#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <core/VectorMath.h>

class LoadObj
{

public:
	LoadObj(std::string fileName);
	~LoadObj();
};

LoadObj::LoadObj(std::string fileName)
{
    FILE* myfile = fopen(("textures/OBJs/" + fileName + ".obj").c_str(), "r");
    std::vector<VectorMath3> vC;
    std::vector<VectorMath3> vT;
    std::vector<VectorMath3> vN;
    char buf[256];
    std::cout << fileName << std::endl;
    if (myfile != NULL)
    {
        while (fscanf(myfile, "%256s", buf) > 0)
        {
            if (buf[0] == 'v' && buf[1] == '\0') {
                float x, y, z;
                if (fscanf(myfile, "%f %f %f", &x, &y, &z) == 3) {
                    vC.push_back(VectorMath3(x, y, z));
                }
                else { std::cout<<"Program broken. :("<<std::endl; }
           }

            else if (buf[0] == 'v' && buf[1] == 't' && buf[2] == '\0') {
                float x, y, z;
                if (fscanf(myfile, "%f %f", &x, &y) == 2) {
                    vT.push_back(VectorMath3(x, y, 0));
                }
                else { std::cout << "Program broken. :(" << std::endl; }
            }

            else if (buf[0] == 'v' && buf[1] == 'n' && buf[2] == '\0') {
                float x, y, z;
                if (fscanf(myfile, "%f %f %f", &x, &y, &z) == 3) {
                    vN.push_back(VectorMath3(x, y, z));
                }
                else { std::cout << "Program broken. :(" << std::endl; }
            }
        }
        fclose(myfile);
    }

    else { std::cout << "Unable to open file"; }
}

LoadObj::~LoadObj()
{ 
}