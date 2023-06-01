#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <cmath>

#include "compute_grades.hpp"

using namespace std; 

constexpr double QUIZ_WEIGHT = 0.4;
constexpr double HOMEWORK_WEIGHT = 0.3;
constexpr double FINAL_WEIGHT = 0.3;

// ******************Gradebook*******************
istream& operator>>(istream& in, Gradebook& b)
{
    Student student;
    while(in >> student)
    {
        b.students.push_back(student);
    }
    return in;
}

void Gradebook::compute_grades()
{
    for(auto s : students)
        s.compute_grade();
}

void Gradebook::sort()
{
    ranges::sort(students);
}

void Gradebook::validate() const
{
    for(auto s : students)
        s.validate();
}

ostream& operator<<(ostream& out, const Gradebook& b)
{
    for(const auto& student : b.students)
        out << student << "\n";

    return out;
}



// ******************Student*******************
istream& operator>>(istream& in, Student& s)
{
    string line;
    s.quiz.clear();
    s.hw.clear();
    while(getline(in, line) && !line.empty())
    {
        istringstream stm(line);
        string word;
        stm >> word;
    
        if (word == "Name")
        {
            string temp;
            stm >> s.first_name;
            stm >> s.last_name;
            while(stm >> temp)
                s.last_name = s.last_name + " " + temp;
        }else if(word == "Quiz") {   
            int q;
            while(stm >> q)
                s.quiz.push_back(q);
        }else if(word == "HW") {
            int h;
            while(stm >> h)
                s.hw.push_back(h);
            if(!s.hw.size())
                s.hw.push_back(0);
        }else if(word == "Final") {
            stm >> s.final_score;
        }
    };

    return in;
}

void Student::validate() const
{
    auto valid = [](int n) 
    {    
        if (n<0 || n>100)
            throw domain_error(string("Error: invalid percentage "+to_string(n)));
    };
    ranges::for_each(quiz, valid);
    ranges::for_each(hw, valid);
    valid(final_score);
}

void Student::compute_grade()
{
    compute_course_score();
    if(course_score > 96)
        course_grade = "A+";
    else if(course_score > 92 && course_score <= 96)
        course_grade = "A";
    else if(course_score > 89 && course_score <= 92)
        course_grade = "A-";
    else if(course_score > 86 && course_score <= 89)
        course_grade = "B+";
    else if(course_score > 82 && course_score <= 86)
        course_grade = "B";
    else if(course_score > 79 && course_score <= 82)
        course_grade = "B-";
    else if(course_score > 76 && course_score <= 79)
        course_grade = "C+";
    else if(course_score > 72 && course_score <= 76)
        course_grade = "C";
    else if(course_score > 69 && course_score <= 72)
        course_grade = "C-";
    else if(course_score > 65 && course_score <= 69)
        course_grade = "D+";
    else if(course_score > 61 && course_score <= 66)
        course_grade = "D";
    else if(course_score >= 60 && course_score <= 62)
        course_grade = "D-";
    else
        course_grade = "F";
}

strong_ordering Student::operator <=> (const Student& other) const
{
    if(strong_ordering cmp = last_name <=> other.first_name; cmp!= 0)
        return cmp;
    else if(strong_ordering cmp = first_name <=> other.first_name; cmp!= 0)
        return cmp;
    else if (quiz_avg < other.quiz_avg)
        return strong_ordering::less;
    else if (quiz_avg > other.quiz_avg)
        return strong_ordering::greater;
    else if (hw_avg < other.hw_avg)
        return strong_ordering::less;
    else if (hw_avg > other.hw_avg)
        return strong_ordering::greater;
    else if (course_score < other.course_score)
        return strong_ordering::less;
    else if (course_score > other.course_score)
        return strong_ordering::greater;
    return strong_ordering::equal;
}

bool Student::operator==(const Student& other) const 
{ return other.last_name == last_name && other.first_name == first_name;  }

ostream& operator<< (std::ostream& out, const Student& s)
{
    out << setw(8) << left << "Name: " << s.first_name<< " " << s.last_name << "\n";
    out << setw(8) << left << "HW Ave: " << s.hw_avg << "\n";
    out << setw(8) << left << "QZ Ave: " << s.quiz_avg << "\n";
    out << setw(8) << left << "Final: " << s.final_score << "\n";
    out << setw(8) << left << "Total: " << s.course_score << "\n";
    out << setw(8) << left << "Grade: " << s.course_grade << "\n";
    
    return out;
    
}


void Student::compute_quiz_avg()
{
    if(quiz.size() < 2)
       quiz_avg = double(quiz[0]);
    else if (quiz.size() ==0)
        quiz_avg = 0.0;
    quiz_avg = accumulate(quiz.begin(), quiz.end(), 0.0)-ranges::min(quiz) / (quiz.size()-1);
}

void Student::compute_hw_avg()
{
    if (hw.size() < 2)
    {
        hw_avg = hw[0];
        return;
    }else{
        hw_avg = accumulate(hw.begin(), hw.end(), 0.0) / hw.size();
    }

}

void Student::compute_course_score()
{
    compute_quiz_avg();
    compute_hw_avg();
    course_score = std::round(quiz_avg * QUIZ_WEIGHT + hw_avg*HOMEWORK_WEIGHT + final_score*FINAL_WEIGHT);
}
