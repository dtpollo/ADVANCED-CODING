#include <iostream>
#include <string>
#include <tuple>

//Declarations Part 1
int x = (1); //Direct Initialization
double y = {12}; //Uniform Initialization
std::tuple<std::string, int, float> PatientInfo(){
std::string Pat_name = "Jose Montero";
int Pat_age = 24;
float Pat_weight = 65.4;
return {Pat_name, Pat_age, Pat_weight};
}

//Declarations Part 2
int a = 1;
int& reference_to_a = a;

//Declarations Part 3
std::tuple<float, float, float> Point(){
float p_x = 3.0;
float p_y = 12.3;
float p_z = 23.5;
return {p_x, p_y, p_z};
}



int main(void){
//Part 1: Variable Initialization
std::cout << "-----> PART 1 <-----" << std::endl;
std::cout << "Direct Ini: " << x << std::endl;
std::cout << "Uniform Ini: " << y << std::endl;
auto [Pat_name, Pat_age, Pat_weight] = PatientInfo();
std::cout << "Structured Ini --> ";
std::cout << "Patient's name: " << Pat_name << " , Age: " << Pat_age << " , Weight: " << Pat_weight <<std::endl;


//Part 2: References
std::cout << "-----> PART 2 <-----" << std::endl;
std::cout << "Original Value of 'a' : " << a << std::endl;
reference_to_a = 2000;
std::cout << "Value of 'a', after the reference: " << a << std::endl;


//Part 3: Structured Binding
std::cout << "-----> PART 3 <-----" << std::endl;
std::cout << "Structured Binding" << std::endl;
auto POINT_IN_PLANE = Point();
float Coordinate_X = std::get<0>(POINT_IN_PLANE);
float Coordinate_Y = std::get<1>(POINT_IN_PLANE);
float Coordinate_Z = std::get<2>(POINT_IN_PLANE);
std::cout << "Point(" << Coordinate_X << "," << Coordinate_Y << "," << Coordinate_Z << ")" <<std::endl;



return 0;
}