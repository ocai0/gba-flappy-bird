#ifndef BOUNDINGBOX_H_
#define BOUNDINGBOX_H_

    typedef struct {
        int topLeft;
        int bottomLeft;
        int topRight;
        int bottomRight;
    } BoundingBox;

    typedef BoundingBox bBox;

#endif