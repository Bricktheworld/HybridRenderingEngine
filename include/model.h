#ifndef MODEL_H
#define MODEL_H

// ===============================
// AUTHOR       : Angel Ortiz (angelo12 AT vt DOT edu)
// CREATE DATE  : 2018-09-10
// PURPOSE      : TODO
// ===============================
// SPECIAL NOTES: TODO update comments
// ===============================

//Includes
#include "shader.h"
#include "texture.h"
#include "mesh.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <vector>
#include <unordered_map>
#include <string>

struct TransformParameters{
    TransformParameters(): scaling(glm::vec3(1.0f)) {};
    glm::vec3 translation;
    float angle;
    glm::vec3 rotationAxis;
    glm::vec3 scaling;
};

class Model {
    public:
        Model(const std::string meshPath, const bool PBR, const TransformParameters initParameters){
            if(PBR){
               pbrMaterial = true; 
               numTextures = 4;
            }
            loadModel(meshPath);
            modelParameters = initParameters;
        }

        void draw(const Shader &shader, const bool textured);
        void update( const unsigned int deltaT);

        glm::mat4 getModelMatrix();

        unsigned int numTextures = 3;
        bool pbrMaterial = false;
    private:
        TransformParameters modelParameters;
        glm::mat4 modelMatrix;

        std::vector<Mesh> meshes;        
        std::unordered_map<std::string, Texture> textureAtlas; 

        std::string directory, fileExtension;

        void loadModel(std::string path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<unsigned int> processTextures(const aiMaterial *material);
};

#endif 