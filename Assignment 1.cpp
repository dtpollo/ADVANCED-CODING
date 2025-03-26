
 #include <algorithm>
 #include <fstream>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <vector>
 
 const std::string COURSES_OFFERED_PATH = "student_output/courses_offered.csv";
 const std::string COURSES_NOT_OFFERED_PATH = "student_output/courses_not_offered.csv";
 

 struct Course {
  std::string title;
  std::string number_of_units;
  std::string quarter;
};
 

 #include "utils.cpp"
 
 
 void parse_csv(std::string filename, std::vector<Course>& courses) {
  std::ifstream file(filename);
  std::string line;
  
  // Saltar el encabezafo
  std::getline(file, line);
  
  while (std::getline(file, line)) {
      std::vector<std::string> parts = split(line, ',');
      if (parts.size() >= 3) {
          Course course;
          course.title = parts[0];
          course.number_of_units = parts[1];
          course.quarter = parts[2];
          courses.push_back(course);
      }
  }
}
 

void write_courses_offered(std::vector<Course>& all_courses) {
  std::ofstream outfile(COURSES_OFFERED_PATH);
  outfile << "Title,Number of Units,Quarter\n";
  
  std::vector<Course> offered_courses;
  
  for (const Course& course : all_courses) {
      // ONlu not null curses
      if (course.quarter != "null") {
          outfile << course.title << "," 
                  << course.number_of_units << "," 
                  << course.quarter << "\n";
          offered_courses.push_back(course);
      }
  }
  
  // DElete courses
  for (const Course& course : offered_courses) {
      delete_elem_from_vector(all_courses, course);
  }
}

void write_courses_not_offered(const std::vector<Course>& unlisted_courses) {
  std::ofstream outfile(COURSES_NOT_OFFERED_PATH);
  outfile << "Title,Number of Units,Quarter\n";
  
  for (const Course& course : unlisted_courses) {
      outfile << course.title << "," 
              << course.number_of_units << "," 
              << course.quarter << "\n";
  }
}

 int main() {
   /* Makes sure you defined your Course struct correctly! */
   static_assert(is_valid_course<Course>, "Course struct is not correctly defined!");
 
   std::vector<Course> courses;
   parse_csv("courses.csv", courses);
 
   /* Uncomment for debugging... */
   // print_courses(courses);
 
   write_courses_offered(courses);
   write_courses_not_offered(courses);
 
   return run_autograder();
 }
