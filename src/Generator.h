#ifndef CC_MAP_GEN_H
#define CC_MAP_GEN_H
#include "String.h"
#include "ExtMath.h"
#include "Vectors.h"
/* Implements flatgrass map generator, and original classic vanilla map generation (with perlin noise)
   Based on: https://github.com/UnknownShadow200/ClassiCube/wiki/Minecraft-Classic-map-generation-algorithm
   Thanks to Jerralish for originally reverse engineering classic's algorithm, then preparing a high level overview of the algorithm.
   Copyright 2014-2019 ClassiCube | Licensed under BSD-3
*/

extern volatile float Gen_CurrentProgress;
extern volatile const char* Gen_CurrentState;
extern volatile cc_bool Gen_Done;
extern int Gen_Seed;
extern cc_bool Gen_Vanilla;
extern BlockRaw* Gen_Blocks;

void FlatgrassGen_Generate(void);
void NotchyGen_Generate(void);

extern BlockRaw* Tree_Blocks;
extern RNGState* Tree_Rnd;
/* Appropriate buffer size to hold positions and blocks generated by the tree generator. */
#define TREE_MAX_COUNT 96

/* Whether a tree can actually be generated at the given coordinates. */
cc_bool TreeGen_CanGrow(int treeX, int treeY, int treeZ, int treeHeight);
/* Generates the blocks (and their positions in the world) that actually make up a tree. */
/* Returns the number of blocks generated, which will be <= TREE_MAX_COUNT */
int  TreeGen_Grow(int treeX, int treeY, int treeZ, int height, IVec3* coords, BlockRaw* blocks);
#endif
