/******************************
file: orthoVects.cpp
author: Trevor M. Tomesh
date: October 7th 2016

This program simply takes two vectors and computes the
corresponding orthogonal unit vectors.
******************************/

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;


//This function returns the cross product of any two given 3-d vectors.
std::vector<float> cross(float vect1[], float vect2[]){
  std::vector<float> crossVect (3);
	crossVect[0] = -vect1[2]*vect2[1] + vect1[1]*vect2[2];
	crossVect[1] = vect1[2]*vect2[0] - vect1[0]*vect2[2];
	crossVect[2] = -vect1[1]*vect2[0] + vect1[0]*vect2[1];
	return crossVect;
}

//----------------------------------------------------
int main(){

	float v1[3], v2[3];
	float n[3], v[3], u[3];

//get values for base vectors v1 and v2 from user
	cout << "Enter V1_x: " << endl;
	cin >> v1[0];
	cout << "Enter V1_y: " << endl;
	cin >> v1[1];
	cout << "Enter V1_z: " << endl;
	cin >> v1[2];
	cout << "Enter V2_x: " << endl;
	cin >> v2[0];
	cout << "Enter V2_y: " << endl;
	cin >> v2[1];
	cout << "Enter V2_z: " << endl;
	cin >> v2[2];

	// Show the user the base vectors they entered
	cout << " " << endl;
	cout << "Base Vectors: " << endl;
	cout << "v1 = " << "[" << v1[0] <<"," << v1[1] << "," << v1[2] << "]" << endl;
	cout << "v2 = " << "[" << v2[0] <<"," << v2[1] << "," << v2[2] << "]" << endl;


//----- Compute n --------//
	// compute the absolute value of v1 to make life easier.
	float v1abs = sqrt(pow(v1[0],2)+pow(v1[1],2)+pow(v1[2],2));

	n[0] = v1[0]/v1abs;
	n[1] = v1[1]/v1abs;
	n[2] = v1[2]/v1abs;

//------ Compute u ---------//
float v2v1[3];
float v2v1abs;

 v2v1[0] = cross(v2,v1)[0];
 v2v1[1] = cross(v2,v1)[1];
 v2v1[2] = cross(v2,v1)[2];

 // calculate the absolute value of v2 cross v1
 v2v1abs = sqrt(pow(v2v1[0],2)+pow(v2v1[1],2)+pow(v2v1[2],2));

 u[0] = v2v1[0]/ v2v1abs;
 u[1] = v2v1[1]/v2v1abs;
 u[2] = v2v1[2]/v2v1abs;

 //------ Compute v --------//
	v[0] = cross(n,u)[0];
	v[1] = cross(n,u)[1];
	v[2] = cross(n,u)[2];

//----- Output resulting unit vector values --------- //
  cout << " " << endl;
	cout << "Orthogonal Unit Vectors: " << endl;
	cout << "n = " << "[" << n[0] << "," << n[1] << "," << n[2] << "]" << endl;
	cout << "u = " << "[" << u[0] << "," << u[1] << "," << u[2] << "]" << endl;
	cout << "v = " << "[" << v[0] << "," << v[1] << "," << v[2] << "]" << endl;

	return 0;
}
