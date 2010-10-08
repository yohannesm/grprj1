/*
 * vrml.c
 * ------
 * Drawing subroutines for each vrml object.
 * Also contains the polygon data for each vrml object.
 *
 * Starter code for Project 1.
 *
 * Group Members: Yohannes Himawan
 * 		  David Lee
 */

#include "common.h"

#include <stdio.h>

#include "vrml.h"

/*
 * Note that in VRML, the face indices have a -1 to represent
 * the termination of a index sequence.
 */

/***********************************************************
 * Begin VRML Cube Data
 ***********************************************************/
GLfloat v_cube_vertices[] = {
	1.632990, 0.000000, 1.154700,
	0.000000, 1.632990, 1.154700,
	-1.632990, 0.000000, 1.154700,
	0.000000, -1.632990, 1.154700,
	0.000000, -1.632990, -1.154700,
	1.632990, 0.000000, -1.154700,
	0.000000, 1.632990, -1.154700,
	-1.632990, 0.000000, -1.154700,
};

GLint v_cube_indices[] = {
	0, 1, 2, 3, -1,
	4, 5, 0, 3, -1,
	5, 6, 1, 0, -1,
	6, 7, 2, 1, -1,
	3, 2, 7, 4, -1,
	7, 6, 5, 4, -1,
};


/***********************************************************
 * Begin VRML Dodecahedron Data
 ***********************************************************/
GLfloat v_dodeca_vertices[] = {
	1.214120, 0.000000, 1.589310,
	0.375185, 1.154700, 1.589310,
	-0.982247, 0.713644, 1.589310,
	-0.982247, -0.713644, 1.589310,
	0.375185, -1.154700, 1.589310,
	1.964490, 0.000000, 0.375185,
	1.589310, 1.154700, -0.375185,
	0.607062, 1.868350, 0.375185,
	-0.607062, 1.868350, -0.375185,
	-1.589310, 1.154700, 0.375185,
	-1.964490, 0.000000, -0.375185,
	-1.589310, -1.154700, 0.375185,
	-0.607062, -1.868350, -0.375185,
	0.607062, -1.868350, 0.375185,
	1.589310, -1.154700, -0.375185,
	0.982247, 0.713644, -1.589310,
	0.982247, -0.713644, -1.589310,
	-0.375185, 1.154700, -1.589310,
	-1.214120, 0.000000, -1.589310,
	-0.375185, -1.154700, -1.589310,
};

GLint v_dodeca_indices[] = {
	0, 1, 2, 3, 4, -1,
	0, 5, 6, 7, 1, -1,
	1, 7, 8, 9, 2, -1,
	2, 9, 10, 11, 3, -1,
	3, 11, 12, 13, 4, -1,
	4, 13, 14, 5, 0, -1,
	15, 6, 5, 14, 16, -1,
	17, 8, 7, 6, 15, -1,
	18, 10, 9, 8, 17, -1,
	19, 12, 11, 10, 18, -1,
	16, 14, 13, 12, 19, -1,
	16, 19, 18, 17, 15, -1,
};


/***********************************************************
 * Begin VRML Icosahedron Data
 ***********************************************************/
GLfloat v_icosa_vertices[] = {
	0.552786, 1.701300, 0.894427,
	0.000000, 0.000000, 2.000000,
	1.788850, 0.000000, 0.894427,
	-1.447210, 1.051460, 0.894427,
	-1.447210, -1.051460, 0.894427,
	0.552786, -1.701300, 0.894427,
	1.447210, 1.051460, -0.894427,
	-0.552786, 1.701300, -0.894427,
	-1.788850, 0.000000, -0.894427,
	-0.552786, -1.701300, -0.894427,
	1.447210, -1.051460, -0.894427,
	0.000000, 0.000000, -2.000000,
};

GLint v_icosa_indices[] = {
	0, 1, 2, -1,
	3, 1, 0, -1,
	4, 1, 3, -1,
	5, 1, 4, -1,
	2, 1, 5, -1,
	0, 2, 6, -1,
	7, 0, 6, -1,
	3, 0, 7, -1,
	8, 3, 7, -1,
	4, 3, 8, -1,
	9, 4, 8, -1,
	5, 4, 9, -1,
	10, 5, 9, -1,
	6, 2, 10, -1,
	2, 5, 10, -1,
	6, 11, 7, -1,
	7, 11, 8, -1,
	8, 11, 9, -1,
	9, 11, 10, -1,
	10, 11, 6, -1,
};


/***********************************************************
 * Begin VRML Pyramid Data
 ***********************************************************/
GLfloat v_pyramid_vertices[] = {
	0.997029, 0.000000, -0.997029,
	0.012175, 1.000000, -0.012175,
	-0.997029, 0.000000, -0.997029,
	-0.012175, 1.000000, -0.012175,
	-0.997029, 0.000000, 0.997029,
	-0.012175, 1.000000, 0.012175,
	0.997029, 0.000000, 0.997029,
	0.012175, 1.000000, 0.012175,
};

GLint v_pyramid_indices[] = {
	6, 0, 7, -1,
	7, 0, 1, -1,
	0, 2, 1, -1,
	1, 2, 3, -1,
	2, 4, 3, -1,
	3, 4, 5, -1,
	4, 6, 5, -1,
	5, 6, 7, -1,
	4, 0, 6, -1,
	4, 2, 0, -1,
	7, 1, 5, -1,
	1, 3, 5, -1,
};


/*
 * ADD YOUR FUNCTION DEFINITIONS HERE.
 * See vrml.h for a list of suggested functions.
 */

/* draws the object that is given to it, you must give it: 
 * the number of faces
 * the number indices per face
 * the total indices (size of v_indices)
 * we cannot calculate size of v_indices because the pyramid has a square base
*/
void draw_vrml_object(int num_of_faces, int indices_per_shape, int num_indices, GLfloat* v_vertices, GLint* v_indices)
{
	int i;
    int indices[indices_per_shape];

    //printf("num_indices: %i\n", num_indices);
    //printf("num_of_faces: %i\n", num_of_faces);
    //printf("indices per face: %i\n", indices_per_shape);

	/*
	 * loop over the vertex points
	 * 
	 */
	for (i = 0; i < num_indices; i += indices_per_shape + 1) 
    {
		/*
		 * Find the index into the vertex array.  The value
		 * in the cone_indices array refers to the index
		 * of the ordered triples, not the index for the
		 * actual GLfloats that comprise the cone_vertices array.
		 * Thus, we need to multiple by 3 to get the real index.
		 */
        int j = 0;
        
        // put one vertex into indicies, ignores the -1
        for (j = 0; j < indices_per_shape; ++j)
		    indices[j] = v_indices[i + j] * 3;

		glBegin(GL_LINE_LOOP);

        //printf("drawing verticies: ");
		/* All arguments here are pointers */
        for (j = 0; j < indices_per_shape; ++j)
        {
            //printf("%i, ", indices[j]);
        	glColor3f( (j%3 == 2 ? 1 : 0), (j%3 == 1 ? 1 : 0), (j%3 == 0 ? 1 : 0));
		    glVertex3fv( &( v_vertices[ indices[j] ] ) );
        }
        //printf("\n");
		glEnd();

	}
}

void draw_vrml_cube(void)
{
#if 1
    int size = sizeof(v_cube_indices) / sizeof(GLuint);
    draw_vrml_object(6, 4, size, v_cube_vertices, v_cube_indices);
#else
// old code
	int num_indices;
	int i;
    int num_of_faces = 6;

	num_indices = sizeof(v_cube_indices) / sizeof(GLuint);

    int num_in_vertices = num_indices / num_of_faces;    
    int indicies[num_in_vertices];

	/*
	 * Loop over all quads that need to be draen.
	 * Step i by 3 because there are 3 vertices per triangle.
	 */
	for (i = 0; i < num_indices; i += 5) 
    {
		/*
		 * Find the index into the vertex array.  The value
		 * in the cone_indices array refers to the index
		 * of the ordered triples, not the index for the
		 * actual GLfloats that comprise the cone_vertices array.
		 * Thus, we need to multiple by 3 to get the real index.
		 */
        int j = 0;
        for (j = 0; j < num_in_vertices; ++j)
		    indicies[j] = v_cube_indices[i + j] * 3;

		glBegin(GL_POLYGON);

		/* All arguments here are pointers */
        for (j = 0; j < num_in_vertices; ++j)
        {
            printf("%i, ", indicies[j]);
        	glColor3f( (j%3 == 2 ? 1 : 0), (j%3 == 1 ? 1 : 0), (j%3 == 0 ? 1 : 0));
		    glVertex3fv( &( v_cube_vertices[ indicies[j] ] ) );
        }
		glEnd();

	}
#endif
}

void draw_vrml_dodecahedron(void)
{
    int size = sizeof(v_dodeca_indices) / sizeof(GLuint);
    draw_vrml_object(12, 5, size, v_dodeca_vertices, v_dodeca_indices);
}

void draw_vrml_icosahedron(void)
{
    int size = sizeof(v_icosa_indices) / sizeof(GLuint);
    draw_vrml_object(20, 3, size, v_icosa_vertices, v_icosa_indices);
}

void draw_vrml_pyramid(void)
{
    int size = sizeof(v_pyramid_indices) / sizeof(GLuint);
    draw_vrml_object(4, 3, size, v_pyramid_vertices, v_pyramid_indices);
}

/* end of vrml.c */

