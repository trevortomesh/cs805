/******************************
file: q3d.cpp
author: Trevor M. Tomesh
date: October 7th 2016

This program takes camera vectors from the user and
computes the corresponding transformation matricies.
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

	float lrp[3], lpn[3], lup[3];
	float n[3], v[3], u[3];

//get values for base vectors v1 and v2 from user
	cout << "Enter LRP_x: " << endl;
	cin >> lrp[0];
	cout << "Enter LRP_y: " << endl;
	cin >> lrp[1];
	cout << "Enter LRP_z: " << endl;
	cin >> lrp[2];
	cout << "Enter LPN_x: " << endl;
	cin >> lpn[0];
	cout << "Enter LPN_y: " << endl;
	cin >> lpn[1];
	cout << "Enter LPN_z: " << endl;
	cin >> lpn[2];
  cout << "Enter LUP_x: " << endl;
  cin >> lup[0];
  cout << "Enter LUP_y: " << endl;
  cin >> lup[1];
  cout << "Enter LUP_z: " << endl;
  cin >> lup[2];

	// Show the user the base vectors they entered
	cout << " " << endl;
	cout << "Light Vectors: " << endl;
	cout << "LRP = " << "[" << lrp[0] <<"," << lrp[1] << "," << lrp[2] << "]" << endl;
	cout << "LPN = " << "[" << lpn[0] <<"," << lpn[1] << "," << lpn[2] << "]" << endl;
  cout << "LUP = " << "[" << lup[0] <<"," << lup[1] << "," << lup[2] << "]" << endl;


//----- Compute n --------//
	// compute the absolute value of v1 to make life easier.
  float diffn[3];
  float absn;

  diffn[0] = lpn[0]-lrp[0];
  diffn[1] = lpn[1]-lrp[1];
  diffn[2] = lpn[2]-lrp[2];

  absn = sqrt(pow(diffn[0],2)+pow(diffn[1],2)+pow(diffn[2],2));


	n[0] = diffn[0]/absn;
	n[1] = diffn[1]/absn;
	n[2] = diffn[2]/absn;

//------ Compute u ---------//
float absu;
float diffu[3];
float diffcross[3];

 diffu[0] = lup[0] - lrp[0];
 diffu[1] = lup[1] - lrp[1];
 diffu[2] = lup[2] - lrp[2];


 diffcross[0] = cross(diffu,diffn)[0];
 diffcross[1] = cross(diffu,diffn)[1];
 diffcross[2] = cross(diffu,diffn)[2];

 // calculate the absolute value of v2 cross v1
 absu = sqrt(pow(diffcross[0],2)+pow(diffcross[1],2)+pow(diffcross[2],2));

 u[0] = diffcross[0]/ absu;
 u[1] = diffcross[1]/absu;
 u[2] = diffcross[2]/absu;

 //------ Compute v --------//
	v[0] = cross(n,u)[0];
	v[1] = cross(n,u)[1];
	v[2] = cross(n,u)[2];

//----- Output resulting unit vector values --------- //
/*
  cout << " " << endl;
	cout << "Orthogonal Unit Vectors: " << endl;
	cout << "n = " << "[" << n[0] << "," << n[1] << "," << n[2] << "]" << endl;
	cout << "u = " << "[" << u[0] << "," << u[1] << "," << u[2] << "]" << endl;
	cout << "v = " << "[" << v[0] << "," << v[1] << "," << v[2] << "]" << endl;
*/

//----- Return R*T -------//


  cout << " " << endl;
  cout <<  "Transforms: "<< endl;
  cout << "World to Light: ";
  cout << "{{" << u[0] << "," << u[1] << "," << u[2] << "," << u[0]*lrp[0]+u[1]*lrp[1]+u[2]*lrp[2] << "}" << ","
  << "{" << v[0] << "," << v[1] << "," << v[2] << "," << v[0]*lrp[0]+v[1]*lrp[1]+v[2]*lrp[2] << "}" << ","
  << "{" << n[0] << "," << n[1] << "," << n[2] << "," << n[0]*lrp[0]+n[1]*lrp[1]+n[2]*lrp[2] << "}" << ","
  << "{" << 0 << "," << 0 << "," << 0 << "," << 1 << "}}" << endl;

  cout << "Light to World: ";

  cout << "{{" << u[0] << "," << v[0] << "," << n[0] << "," << lrp[0] << "}" << ","
  << "{" << u[1] << "," << v[1] << "," << n[1] << "," << lrp[1] << "}" << ","
  << "{" << u[2] << "," << v[2] << "," << n[2] << "," << lrp[2] << "}" << ","
  << "{" << 0 << "," << 0 << "," << 0 << "," << 1 << "}}" << endl;


	return 0;
}
