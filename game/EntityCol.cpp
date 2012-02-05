#include "Entity.h"

std::vector<EntityCol> EntityCol::EntityColList;

EntityCol::EntityCol()
{
    this->EntityA = NULL;
    this->EntityB = NULL;
}