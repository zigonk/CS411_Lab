#include "utils.h"

const double Utils::translateL[3][3] = {{1, 0, 0},
                                        {0, 1, 0},
                                        {-1, 0, 1}};
const double Utils::translateR[3][3] = {{1, 0, 0},
                                        {0, 1, 0},
                                        {1, 0, 1}};
const double Utils::translateU[3][3] = {{1, 0, 0},
                                        {0, 1, 0},
                                        {0, 1, 1}};
const double Utils::translateD[3][3] = {{1, 0, 0},
                                        {0, 1, 0},
                                        {0, -1, 1}};
const double Utils::scaleUp[3][3] = {{1.1, 0, 0},
                                     {0, 1.1, 0},
                                     {0, 0, 1}};
const double Utils::scaleDown[3][3] = {{0.9, 0, 0},
                                       {0, 0.9, 0},
                                       {0, 0, 1}};
double angle1 = 1 * PI / 180.0;
const double Utils::rotateL[3][3] = {{cos(angle1), sin(angle1), 0},
                                     {-sin(angle1), cos(angle1), 0},
                                     {0, 0, 1}};
const double Utils::rotateR[3][3] = {{cos(angle1), -sin(angle1), 0},
                                     {sin(angle1), cos(angle1), 0},
                                     {0, 0, 1}};