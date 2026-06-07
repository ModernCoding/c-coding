#if !defined (COORD_H)
#define COORD_H


struct Coordinate {
  int x;
  int y;
  int z;
};

struct Coordinate new_coord (int x, int y, int z);


#endif