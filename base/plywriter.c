// Copyright (c) 2023
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rply/rply.h"
#include "util.h"
#include "plywriter.h"

// Function to write a point cloud to a PLY file
int write_ply(double **points, int nr, int nc, const char *filename) {
    p_ply ply;
    int i, j;
    
    // Create PLY file
    ply = ply_create(filename, PLY_ASCII, NULL, 0, NULL);
    if (!ply) {
        printf("ERROR: Failed to create PLY file: %s\n", filename);
        return 0;
    }
    
    // Add vertex element
    ply_add_element(ply, "vertex", nr);
    ply_add_property(ply, "x", PLY_FLOAT, PLY_FLOAT, PLY_FLOAT);
    ply_add_property(ply, "y", PLY_FLOAT, PLY_FLOAT, PLY_FLOAT);
    ply_add_property(ply, "z", PLY_FLOAT, PLY_FLOAT, PLY_FLOAT);
    
    // Write header
    if (!ply_write_header(ply)) {
        printf("ERROR: Failed to write PLY header to file: %s\n", filename);
        ply_close(ply);
        return 0;
    }
    
    // Write vertex data
    for (i = 0; i < nr; i++) {
        for (j = 0; j < nc; j++) {
            ply_write(ply, points[i][j]);
        }
    }
    
    // Close PLY file
    if (!ply_close(ply)) {
        printf("ERROR: Failed to close PLY file: %s\n", filename);
        return 0;
    }
    
    return 1;
}