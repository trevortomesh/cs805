/******************************
file: main.cpp
author: Trevor M. Tomesh
date: October 7th 2016

- This program takes the vectors that define a camera and a light in
a world scene and computes the transformation vectors between the
camera, light and world coordinate systems.

- This program is an amalgamation of the functions written in
questions 2 and 3 of the homework assignment.

- It is kind of an ugly mess as the author is a python programmer and
should really have stuck to what he knows... but c'est la vie!

TO DO: Get rid of the ugly redundancies! They're ugly... and redundant!
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

	float lrp[3], lpn[3], lup[3]; //light
  float vrp[3], vpn[3], vup[3]; //view (camera)

	float nc[3], vc[3], uc[3]; // camera unit vectors
  float nl[3], vl[3], ul[3]; // light unit vectors

//get values for base vectors from user
  cout << "Please enter the light vectors: " << endl;
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

  cout << "Please enter the viewing vectors: " << endl;
  cout << "Enter VRP_x: " << endl;
  cin >> vrp[0];
  cout << "Enter VRP_y: " << endl;
  cin >> vrp[1];
  cout << "Enter VRP_z: " << endl;
  cin >> vrp[2];
  cout << "Enter VPN_x: " << endl;
  cin >> vpn[0];
  cout << "Enter VPN_y: " << endl;
  cin >> vpn[1];
  cout << "Enter VPN_z: " << endl;
  cin >> vpn[2];
  cout << "Enter VUP_x: " << endl;
  cin >> vup[0];
  cout << "Enter VUP_y: " << endl;
  cin >> vup[1];
  cout << "Enter VUP_z: " << endl;
  cin >> vup[2];

	// Show the user the base light vectors they entered
	cout << " " << endl;
	cout << "Light Vectors: " << endl;
	cout << "LRP = " << "[" << lrp[0] <<"," << lrp[1] << "," << lrp[2] << "]" << endl;
	cout << "LPN = " << "[" << lpn[0] <<"," << lpn[1] << "," << lpn[2] << "]" << endl;
  cout << "LUP = " << "[" << lup[0] <<"," << lup[1] << "," << lup[2] << "]" << endl;

// Show the user the base viewing vectors
  cout << " " << endl;
	cout << "Viewing Vectors: " << endl;
	cout << "VRP = " << "[" << vrp[0] <<"," << vrp[1] << "," << vrp[2] << "]" << endl;
	cout << "VPN = " << "[" << vpn[0] <<"," << vpn[1] << "," << vpn[2] << "]" << endl;
  cout << "VUP = " << "[" << vup[0] <<"," << vup[1] << "," << vup[2] << "]" << endl;


// ------------------------------ FOR LIGHT -------------------------------- //
//----- Compute n --------//
  float diffn[3];
  float absn;

  diffn[0] = lpn[0]-lrp[0];
  diffn[1] = lpn[1]-lrp[1];
  diffn[2] = lpn[2]-lrp[2];

  absn = sqrt(pow(diffn[0],2)+pow(diffn[1],2)+pow(diffn[2],2));


	nl[0] = diffn[0]/absn;
	nl[1] = diffn[1]/absn;
	nl[2] = diffn[2]/absn;

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

 ul[0] = diffcross[0]/ absu;
 ul[1] = diffcross[1]/absu;
 ul[2] = diffcross[2]/absu;

 //------ Compute v --------//
	vl[0] = cross(nl,ul)[0];
	vl[1] = cross(nl,ul)[1];
	vl[2] = cross(nl,ul)[2];

//----- Return M  (a.k.a R*T) -------//
  cout << " " << endl;
  cout <<  "Transforms: "<< endl;
  cout << "World to Light: ";
  cout << "{{" << ul[0] << "," << ul[1] << "," << ul[2] << "," << ul[0]*lrp[0]+ul[1]*lrp[1]+ul[2]*lrp[2] << "}" << ","
  << "{" << vl[0] << "," << vl[1] << "," << vl[2] << "," << vl[0]*lrp[0]+vl[1]*lrp[1]+vl[2]*lrp[2] << "}" << ","
  << "{" << nl[0] << "," << nl[1] << "," << nl[2] << "," << nl[0]*lrp[0]+nl[1]*lrp[1]+nl[2]*lrp[2] << "}" << ","
  << "{" << 0 << "," << 0 << "," << 0 << "," << 1 << "}}" << endl;

  cout << "Light to World: ";

  cout << "{{" << ul[0] << "," << vl[0] << "," << nl[0] << "," << lrp[0] << "}" << ","
  << "{" << ul[1] << "," << vl[1] << "," << nl[1] << "," << lrp[1] << "}" << ","
  << "{" << ul[2] << "," << vl[2] << "," << nl[2] << "," << lrp[2] << "}" << ","
  << "{" << 0 << "," << 0 << "," << 0 << "," << 1 << "}}" << endl;


//---------------------- FOR CAMERA ----------------------------------//

//----- Compute n --------//
	// compute the absolute value ... again.
  diffn[0] = vpn[0]-vrp[0];
  diffn[1] = vpn[1]-vrp[1];
  diffn[2] = vpn[2]-vrp[2];

  absn = sqrt(pow(diffn[0],2)+pow(diffn[1],2)+pow(diffn[2],2));


	nc[0] = diffn[0]/absn;
	nc[1] = diffn[1]/absn;
	nc[2] = diffn[2]/absn;

//------ Compute u  ---------//

 diffu[0] = vup[0] - vrp[0];
 diffu[1] = vup[1] - vrp[1];
 diffu[2] = vup[2] - vrp[2];


 diffcross[0] = cross(diffu,diffn)[0];
 diffcross[1] = cross(diffu,diffn)[1];
 diffcross[2] = cross(diffu,diffn)[2];

 // calculate the absolute value of v2 cross v1 ... again.
 absu = sqrt(pow(diffcross[0],2)+pow(diffcross[1],2)+pow(diffcross[2],2));

 uc[0] = diffcross[0]/ absu;
 uc[1] = diffcross[1]/absu;
 uc[2] = diffcross[2]/absu;

 //------ Compute v --------//
	vc[0] = cross(nc,uc)[0];
	vc[1] = cross(nc,uc)[1];
	vc[2] = cross(nc,uc)[2];

//----- Return R*T -------//
  cout << " " << endl;
  cout << "World to Camera: ";
  cout << "{{" << uc[0] << "," << uc[1] << "," << uc[2] << "," << uc[0]*vrp[0]+uc[1]*vrp[1]+uc[2]*vrp[2] << "}" << ","
  << "{" << vc[0] << "," << vc[1] << "," << vc[2] << "," << vc[0]*vrp[0]+vc[1]*vrp[1]+vc[2]*vrp[2] << "}" << ","
  << "{" << nc[0] << "," << nc[1] << "," << nc[2] << "," << nc[0]*vrp[0]+nc[1]*vrp[1]+nc[2]*vrp[2] << "}" << ","
  << "{" << 0 << "," << 0 << "," << 0 << "," << 1 << "}}" << endl;

  cout << "Camera to World: ";

  cout << "{{" << uc[0] << "," << vc[0] << "," << nc[0] << "," << vrp[0] << "}" << ","
       << "{" << uc[1] << "," << vc[1] << "," << nc[1] << "," << vrp[1] << "}" << ","
       << "{" << uc[2] << "," << vc[2] << "," << nc[2] << "," << vrp[2] << "}" << ","
       << "{" << 0 << "," << 0 << "," << 0 << "," << 1 << "}}" << endl;

cout << " " << endl;
cout << "Camera to Light: " << endl;

cout << "{{" << uc[0]*ul[0] << "," << ul[1]*vc[0] << "," << nc[0]*ul[2] << "," << vrp[0]*(lrp[0]*ul[0]+lrp[1]*ul[1]+lrp[2]*ul[2])<< "}" << ","
      << "{" << uc[1]*vl[0] << "," << vc[1]*vl[1] << "," << nc[1]*vl[2] << "," << vrp[1]*(lrp[0]*vl[0]+lrp[1]*vl[1]+lrp[2]*vl[2]) << "}" << ","
      << "{" << nl[0]*uc[2] << "," << nl[1]*vc[2] << "," << nc[2]*nl[2] << "," << vrp[2]*(lrp[0]*nl[0]+lrp[1]*nl[1]+lrp[2]*nl[2]) << "}" << ","
      << "{" << 0 << "," << 0 << "," << 0 << "," << 1 << "}}" << endl;

cout << "Light to Camera: " << endl;

cout << "{{" << uc[0]*ul[0] << "," << uc[1]*vl[0] << "," << nl[0]*uc[2] << "," << lrp[0]*(vrp[0]*uc[0]+vrp[1]*uc[1]+vrp[2]*uc[2])<< "}" << ","
      << "{" << ul[1]*vc[0] << "," << vc[1]*vl[1] << "," << nl[1]*vc[2] << "," << lrp[1]*(vrp[0]*vc[0]+vrp[1]*vc[1]+vrp[2]*vc[2]) << "}" << ","
      << "{" << nc[0]*ul[2] << "," << nc[1]*vl[2] << "," << nc[2]*nl[2] << "," << lrp[2]*(vrp[0]*nc[0]+vrp[1]*nc[1]+vrp[2]*nc[2]) << "}" << ","
      << "{" << 0 << "," << 0 << "," << 0 << "," << 1 << "}}" << endl;

	return 0;
}
