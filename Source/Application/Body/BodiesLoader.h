#ifndef NBODY_CPP_BODIESLOADER_H
#define NBODY_CPP_BODIESLOADER_H

#include <iostream>
#include <vector>
#include <sstream>

#include "Body.h"

/**
 * Class to load body from string content
 *
 * each body is contained in one line that follows the following format
 * body name;mass;radius;pos_x;pos_y;velocity_x;velocity_y;color
 */
class BodiesLoader
{
public:
    /**
     * Read bodies from given string content
     *
     * @param fileContent the file content
     * @return loaded bodies
     */
    static std::vector<Body> loadBodies(const std::string& fileContent);
};


#endif //NBODY_CPP_BODIESLOADER_H
