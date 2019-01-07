#ifndef NBODY_CPP_BODIESLOADER_H
#define NBODY_CPP_BODIESLOADER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Body.h"

/**
 * Class to load body from file
 *
 * each body is contained in one line that follows the following format
 * body name;mass;radius;pos_x;pos_y;velocity_x;velocity_y;color
 */
class BodiesLoader
{
public:
    /**
     * Instantiate bodies loader on specified file
     *
     * @param filePath the file path
     */
    explicit BodiesLoader(const std::string& filePath);

    /**
     * @return true if the file is open (and ready for reading)
     */
    bool isOpen();

    /**
     * @return loaded bodies
     */
    std::vector<Body> loadBodies();

private:
    std::ifstream m_file;
};


#endif //NBODY_CPP_BODIESLOADER_H
