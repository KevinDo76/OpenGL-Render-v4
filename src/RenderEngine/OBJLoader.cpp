#include "OBJLoader.h"
#include "Mesh.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <array>
#include <stdint.h>
#include <unordered_map>

void stringSplit(std::string& text, char delimeter, std::vector<std::string>& result)
{
    std::string currentBuff = "";
    result.clear();
    for (int i=0;i<text.size();i++)
    {
        if (text[i]==delimeter)
        {
            result.push_back(currentBuff);
            currentBuff = "";
            continue;
        }
        currentBuff+=text[i];
    }
    result.push_back(currentBuff);
}

namespace RenderEngine 
{
    bool loadOBJ(std::string path, mesh& meshObj)
    {
        std::vector<float> finalVBOArray;
        std::vector<uint32_t> finalIndicesArray;

        std::vector<std::array<float, 3>>verticesPos;
        std::vector<std::array<float, 3>>verticesNrm;
        std::vector<std::array<float, 2>>verticesTex;
        std::vector<std::string>faces;
        std::unordered_map<std::string, std::array<float, 8>>facesTranslate;

        std::ifstream file(path);
        std::string line;

        if (!file.is_open())
        {
            std::cout<<"Failed to read file \""<<path<<"\"\n";
            return false;
        }
        
        while (std::getline(file, line))
        {

            if (line[0] == '#')
                continue;

            if (line[0] == 'v' && line[1] == ' ')
            {
                std::vector<std::string>splitStrings;
                stringSplit(line, ' ', splitStrings);


                float v1 = (float)std::atof(splitStrings[1].c_str());
                float v2 = (float)std::atof(splitStrings[2].c_str());
                float v3 = (float)std::atof(splitStrings[3].c_str());

                verticesPos.push_back(std::array<float, 3>({v1, v2, v3}));
            }

            if (line[0] == 'v' && line[1] == 't')
            {
                std::vector<std::string>splitStrings;
                stringSplit(line, ' ', splitStrings);
                if (splitStrings.size() > 3)
                {
                    std::cout<<"Only 2D textures are supported\n";
                    return false;
                }

                float u = (float)std::atof(splitStrings[1].c_str());
                float v = (float)std::atof(splitStrings[2].c_str());

                verticesTex.push_back(std::array<float, 2>({u,v}));
            }

            if (line[0] == 'v' && line[1] == 'n')
            {
                std::vector<std::string>splitStrings;
                stringSplit(line, ' ', splitStrings);

                float n1 = (float)std::atof(splitStrings[1].c_str());
                float n2 = (float)std::atof(splitStrings[2].c_str());
                float n3 = (float)std::atof(splitStrings[3].c_str());

                verticesNrm.push_back(std::array<float, 3>({n1, n2, n3}));
            }

            if (line[0]== 'f')
            {
                std::vector<std::string>splitStrings;
                bool containSlashes =  line.find('/') != std::string::npos;
                stringSplit(line, ' ', splitStrings);
                if (splitStrings.size()>4)
                {
                    std::cout<<"Polygons are not supported\n";
                    return false;
                }
                
                for (int faceIndex = 1; faceIndex < splitStrings.size(); faceIndex++)
                {

                    if (!containSlashes)
                    {
                        //no slashes, only vert position
                        uint32_t index = (uint32_t)std::atoi(splitStrings[faceIndex].c_str())-1;
                        if (facesTranslate.find(splitStrings[faceIndex]) == facesTranslate.end()) // check if vertex entry already existed or not
                            facesTranslate[splitStrings[faceIndex]] = std::array<float, 8>({verticesPos[index][0],verticesPos[index][1],verticesPos[index][2],0,0,0,0,0});
                        
                        faces.push_back(splitStrings[faceIndex]);
                        continue;
                    }

                    std::vector<std::string>splitComponent;
                    stringSplit(splitStrings[faceIndex], '/', splitComponent);
                    
                    if (splitComponent.size() == 2)
                    {
                        uint32_t posIndex = (uint32_t)std::atoi(splitComponent[0].c_str())-1;
                        uint32_t texIndex = (uint32_t)std::atoi(splitComponent[1].c_str())-1;

                        if (facesTranslate.find(splitStrings[faceIndex]) == facesTranslate.end()) // check if vertex entry already existed or not
                            facesTranslate[splitStrings[faceIndex]] = std::array<float, 8>({verticesPos[posIndex][0],verticesPos[posIndex][1],verticesPos[posIndex][2],0,0,0,verticesTex[texIndex][0],verticesTex[texIndex][1]});
                        
                        faces.push_back(splitStrings[faceIndex]);
                        continue;
                    }

                    if (splitComponent[1].size()==0)
                    {
                        uint32_t posIndex = (uint32_t)std::atoi(splitComponent[0].c_str())-1;
                        uint32_t nrmIndex = (uint32_t)std::atoi(splitComponent[2].c_str())-1;

                        if (facesTranslate.find(splitStrings[faceIndex]) == facesTranslate.end()) // check if vertex entry already existed or not
                            facesTranslate[splitStrings[faceIndex]] = std::array<float, 8>({verticesPos[posIndex][0],verticesPos[posIndex][1],verticesPos[posIndex][2],verticesNrm[nrmIndex][0],verticesNrm[nrmIndex][1],verticesNrm[nrmIndex][2],0,0});
                        
                        faces.push_back(splitStrings[faceIndex]);
                        continue;
                    }

                    if (splitComponent.size() == 3)
                    {
                        uint32_t posIndex = (uint32_t)std::atoi(splitComponent[0].c_str())-1;
                        uint32_t nrmIndex = (uint32_t)std::atoi(splitComponent[2].c_str())-1;
                        uint32_t texIndex = (uint32_t)std::atoi(splitComponent[1].c_str())-1;

                        if (facesTranslate.find(splitStrings[faceIndex]) == facesTranslate.end()) // check if vertex entry already existed or not
                            facesTranslate[splitStrings[faceIndex]] = std::array<float, 8>({verticesPos[posIndex][0],verticesPos[posIndex][1],verticesPos[posIndex][2],verticesNrm[nrmIndex][0],verticesNrm[nrmIndex][1],verticesNrm[nrmIndex][2],verticesTex[texIndex][0],verticesTex[texIndex][1]});
                        
                        faces.push_back(splitStrings[faceIndex]);
                        continue;
                    }
                }
                
            }
        }

        uint32_t indicesCount = 0;
        std::unordered_map<std::string, uint32_t>indicesMap;

        for (int i=0;i<faces.size();i++)
        {
            if (indicesMap.find(faces[i]) == indicesMap.end())
            {
                std::array<float, 8>vertex = facesTranslate[faces[i]];
                for (int floatIndex = 0;floatIndex<8;floatIndex++)
                {
                    finalVBOArray.push_back(vertex[floatIndex]);
                }
                indicesMap[faces[i]] = indicesCount;
                indicesCount++;
            }
            finalIndicesArray.push_back(indicesMap[faces[i]]);
        }
        std::cout<<"Poly count: "<<finalIndicesArray.size()/3<<" vertices count: "<<finalIndicesArray.size()<<"\n";
        meshObj.updateDataBuffer(finalVBOArray, finalIndicesArray);

        file.close();

        return true;
    }
}