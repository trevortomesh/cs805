/*
Assignment 2
CS 405/805-001: Computer Graphics
Instructor: Xue Dong Yang
Wednesday, October 12, 2016
Due Date: Friday, October 28, 2016
In this assignment, you are to implement a simple ray-tracing algorithm outlined
below:
*/

main ()
{
//Initialize the global data structures;
	for (i=0; i<ROWS; i++) //scan through each row
		for (j=0; j<COLS; j++) { //scan through each column

/*Construct the ray, V, started from the CenterOfProjection
and passing through the pixel (i, j);*/

/* if the ray intersects with an object save the returned
shading value into the image buffer */

if ((c = ray-tracing( V ) != nil) {
image[i][j] = c;
}


//Output the final image;

}
int ray-tracing( L )

{
P = ray-objects-intersection( L );
/* return the nearest
 intersection point if any */
if(P != nil){
	C = shading( P );
	return ( C );
	} else
	return( nil );
}



//The main computations are in the following three functions:

//Construction of ray V
//Input:
//pixel index (i, j) in the screen coordinates
//Output: V = (P0, V0) (for parametric ray equation P = P0 + V0*t)
//in the world coordinates.
/*Note: V is only a logical symbol for the ray in the algorithm. The
real representation of V is P0 and V0.void */

ray_construction(int i, int j, float P0[3], float V0[3]){

// Step 1:
//Map (j, i) in the screen coordinates to (xc, yc) in the camera coordinates.

// Step 2:
//Transform the origin (0.0, 0.0, 0.0) of the camera
//coordinates to P0 in the world coordinates using the
//transformation matrix Mcw. Note that the transformed result
//should be VRP.

// Step 3:
//Transform the point (xc, yc, f) on the impage plane in
//the camera coordinates to P1 in the world coordinates using
//the transformation matrix Mcw.
// V0 = P1 – P0;
// normalize V0 into unit length;
	return;
}

//Ray-Object Intersection

//Input:
//ray – P0, V0

//Output: the nearest intersection point P[3] if found, along with
//N[3], the surface normal at that point, and
//kd, the diffuse reflection coefficient of the surface.

/*Note: In a general system, the objects should be stored a list
structure. A loop will scan through each object in the list. The
nearest intersection point is found. In our case, we will have only
two hard-coded objects: a sphere and a polygon.
So, this part is “hard-coded” for now.*/

void ray_object_intersection(float P0[3], float V0[3])
{
	t1 = ray_sphere_intersection(float P0[3], float V0[3],
		struct sphere S, float N1[3], float kd1);

	t2 = ray_polygon_intersection(float P0[3], float V0[3],
		struct polygon PL, float N2[3], float kd2);

		if (t1 == nil and t2 == nil){
			return nil;

			else if (t2 == nil){
			return (t1, N1, kd1);
		}

			else if (t1 == nil){
			return(t2, N2, kd2);
		}

			else if (t1 < t2){
			return (t1, N1, kd1);
		}

			else{
			return (t2, n2, kd2);
		}

		}

// Shading:
// Input:
//P[3] – point position//
//
// Output:
//N[3] – surface normal at that point
//kd – diffuse reflection coefficient of the surface
//C – shading value

int shading(float P[3], float N[3], float kd){
L = LRP – P;

// LRP is the light position
//normalize L to unit length;
C = Ip * kd * (N * L); // where (N * L) is dot-product
}
