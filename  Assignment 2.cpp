/*
* CS106L Assignment 2: Marriage Pact
* Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
*
* Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
* in this file. You do not need to modify any other files.
*
*/

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
std::string kYourName = "Daniel Troya"; // Don't forget to change this!
/**
* Takes in a file name and returns a set containing all of the applicant names as a set.
*
* @param filename The name of the file to read.
* Each line of the file will be a single applicant's name.
* @returns A set of all applicant names read from the file.
*/
std::set<std::string> get_applicants(std::string filename) {
std::set<std::string> applicants; // Save names
std::ifstream file(filename);
if (!file.is_open()) {
std::cout << "Error to open the file: " << filename << std::endl;
return applicants;
}
std::string name;
while (std::getline(file, name)) {
name.erase(0, name.find_first_not_of(' '));
name.erase(name.find_last_not_of(' ') + 1);
applicants.insert(name);
}
file.close();
return applicants; // Return the names of the .txt
}
/**
* Takes in a set of student names by reference and returns a queue of names
* that match the given student name.
*
* @param name The returned queue of names should have the same initials as this name.
* @param students The set of student names.
* @return A queue containing pointers to each matching name.
*/
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
std::queue<const std::string*> matches; // queu with pointers
char name_initial = '\0'; //Name
char last_name_initial = '\0'; //Last name
size_t space_pos = name.find(' '); //space
if (space_pos != std::string::npos) {
name_initial = name[0];
last_name_initial = name[space_pos + 1];
} else {
name_initial = name[0];
}
//List Students names
for (const auto& student : students) {
if (!student.empty()) {
size_t student_space_pos = student.find(' ');
if (student_space_pos != std::string::npos) {
// Comparar las iniciales del nombre y el apellido
if (student[0] == name_initial && student[student_space_pos + 1] == last_name_initial) {
matches.push(&student);
}
} else {
if (student[0] == name_initial) {
matches.push(&student);
}
}
}
}
return matches;
}
/**
* Takes in a queue of pointers to possible matches and determines the one true match!
*
* @param matches The queue of possible matches.
* @return Your magical one true love.
* Will return "NO MATCHES FOUND." if `matches` is empty.
*/
std::string get_match(std::queue<const std::string*>& matches) {
if (matches.empty()) {
return "NO MATCHES FOUND";
}
std::string match;

match = *matches.front();
matches.pop();
if (!matches.empty()) {
match = *matches.front();
}
return match; // Rertur match
}