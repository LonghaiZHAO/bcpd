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
#include <math.h>
#include "rply/rply.h"
#include "util.h"
#include "plyreader.h"

// Structure to hold vertex data during PLY parsing
typedef struct {
    double **vertices;  // Array to store vertex coordinates
    int vertex_count;   // Total number of vertices
    int current_vertex; // Current vertex being processed
    int dimension;      // Dimension of vertices (usually 3)
} ply_vertex_data;

// Callback function for vertex elements
static int vertex_cb(p_ply_argument argument) {
    long coord;
    ply_vertex_data *data;
    
    // Get user data and which coordinate (x, y, z) we're processing
    ply_get_argument_user_data(argument, (void **)&data, &coord);
    
    // Get the value of the coordinate
    double value = ply_get_argument_value(argument);
    
    // Store the value in our vertex array
    if (data->current_vertex < data->vertex_count && coord < data->dimension) {
        data->vertices[data->current_vertex][coord] = value;
        
        // If we've processed all coordinates for this vertex, move to the next
        if (coord == data->dimension - 1) {
            data->current_vertex++;
        }
    }
    
    return 1;
}

// Function to read PLY file and return vertices as a 2D array
double **read_ply(int *nr, int *nc, const char *file, const char *na) {
    p_ply ply;
    ply_vertex_data data;
    long nvertices;
    int i;
    
    // Open PLY file
    ply = ply_open(file, NULL, 0, NULL);
    if (!ply) {
        printf("ERROR: Failed to open PLY file: %s\n", file);
        exit(EXIT_FAILURE);
    }
    
    // Read PLY header
    if (!ply_read_header(ply)) {
        printf("ERROR: Failed to read PLY header from file: %s\n", file);
        ply_close(ply);
        exit(EXIT_FAILURE);
    }
    
    // Get number of vertices
    nvertices = ply_set_read_cb(ply, "vertex", "x", NULL, NULL, 0);
    if (nvertices <= 0) {
        printf("ERROR: No vertices found in PLY file: %s\n", file);
        ply_close(ply);
        exit(EXIT_FAILURE);
    }
    
    // Initialize vertex data
    data.vertex_count = nvertices;
    data.current_vertex = 0;
    data.dimension = 3; // Assume 3D points (x, y, z)
    data.vertices = calloc2d(nvertices, data.dimension);
    
    // Set callbacks for vertex coordinates
    ply_set_read_cb(ply, "vertex", "x", vertex_cb, &data, 0);
    ply_set_read_cb(ply, "vertex", "y", vertex_cb, &data, 1);
    ply_set_read_cb(ply, "vertex", "z", vertex_cb, &data, 2);
    
    // Read PLY data
    if (!ply_read(ply)) {
        printf("ERROR: Failed to read PLY data from file: %s\n", file);
        free2d(data.vertices, nvertices);
        ply_close(ply);
        exit(EXIT_FAILURE);
    }
    
    // Close PLY file
    ply_close(ply);
    
    // Set output parameters
    *nr = nvertices;
    *nc = data.dimension;
    
    return data.vertices;
}