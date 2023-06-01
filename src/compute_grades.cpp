#include "compute_grades.hpp"
#include <numeric>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <cmath>



using namespace std;

//student class
void Student::validate() const
{
    for(const auto& Q : quiz)
    {
        if(Q < 0 || Q > 100)
            throw std::domain_error("Error: invalid percentage" + std::to_string(Q));
    }
    
    for(const auto& H : hw)
    {
        if(H < 0 || H > 100)
            throw std::domain_error("Error: invalid percentage" + std::to_string(H));
    }
    
    if(final_score < 0 || final_score > 100)
        throw std::domain_error("Error: invalid percentage" + std::to_string(final_score));
    
}
void Student::compute_grade()
{
    compute_course_score();
    if(course_score >= 97 && course_score <= 100)
        course_grade = "A+";
    else if(course_score >= 93 && course_score <= 96)
        course_grade = "A";
    else if(course_score >= 90 && course_score <= 92)
        course_grade = "A-";
    else if(course_score >= 87 && course_score <= 89)
        course_grade = "B+";
    else if(course_score >= 83 && course_score <= 86)
        course_grade = "B";
    else if(course_score >= 80 && course_score <= 82)
        course_grade = "B-";
    else if(course_score >= 77 && course_score <= 79)
        course_grade = "C+";
    else if(course_score >= 73 && course_score <= 76)
        course_grade = "C";
    else if(course_score >= 70 && course_score <= 72)
        course_grade = "C-";
    else if(course_score >= 67 && course_score <= 69)
        course_grade = "D+";
    else if(course_score >= 63 && course_score <= 66)
        course_grade = "D";
    else if(course_score >= 60 && course_score <= 62)
        course_grade = "D-";
    else
        course_grade = "F";
}

void Student::compute_grade()
{
    compute_course_score();
    if(course_score >= 97 && course_score <= 100)
        course_grade = "A+";
    else if(course_score >= 93 && course_score <= 96)
        course_grade = "A";
    else if(course_score >= 90 && course_score <= 92)
        course_grade = "A-";
    else if(course_score >= 87 && course_score <= 89)
        course_grade = "B+";
    else if(course_score >= 83 && course_score <= 86)
        course_grade = "B";
    else if(course_score >= 80 && course_score <= 82)
        course_grade = "B-";
    else if(course_score >= 77 && course_score <= 79)
        course_grade = "C+";
    else if(course_score >= 73 && course_score <= 76)
        course_grade = "C";
    else if(course_score >= 70 && course_score <= 72)
        course_grade = "C-";
    else if(course_score >= 67 && course_score <= 69)
        course_grade = "D+";
    else if(course_score >= 63 && course_score <= 66)
        course_grade = "D";
    else if(course_score >= 60 && course_score <= 62)
        course_grade = "D-";
    else
        course_grade = "F";
}

bool Student::operator ==(const Student& other) const
{
    return last_name == other.last_name && first_name == other.first_name;
}

std::istream& operator >> (std::istream& in, Student& s)
{
    std::string line;
    s.quiz.clear();
    s.hw.clear();
    while(std::getline(in, line) && !line.empty())
    {
        std::istringstream l(line);
        std::string keyword;
        l >> keyword;
        if(keyword == "Name")
        {
            std::string temp;
            l >> s.first_name >> s.last_name;
            while(l >> temp)
            {
                s.last_name = s.last_name + " " + temp;
            }
        }
        else if(keyword == "Quiz")
        {
            int qz;
            while(l >> qz)
            {
                s.quiz.push_back(qz);
            }
            if(s.quiz.size() == 0)
                s.quiz.push_back(0);
        }
        else if(keyword == "HW")
        {
            int h;
            while(l >> h)
            {
                s.hw.push_back(h);
            }
            if(s.hw.size() == 0)
                s.hw.push_back(0);
        }
        else if(keyword == "Final")
        {
            l >> s.final_score;
        }
    }
    return in;
}

std::ostream& operator << (std::ostream& out, const Student& s)
{
    out << std::setw(8) << std::left << "Name: " << s.first_name<< " " << s.last_name << "\n";
    out << std::setw(8) << std::left << "HW Ave: " << s.hw_avg << "\n";
    out << std::setw(8) << std::left << "QZ Ave: " << s.quiz_avg << "\n";
    out << std::setw(8) << std::left << "Final: " << s.final_score << "\n";
    out << std::setw(8) << std::left << "Total: " << s.course_score << "\n";
    out << std::setw(8) << std::left << "Grade: " << s.course_grade << "\n";
    
    return out;
    
}

void Student::compute_quiz_avg()
{
    if(quiz.size() == 1)
    {
        quiz_avg = double(quiz[0]);
    }
    else if(quiz.empty())
    {
        quiz_avg = 0.0;
    }
    else
    {
        int min = *std::min_element(quiz.begin(), quiz.end());
        double sum = std::accumulate(quiz.begin(), quiz.end(), 0.0);
        quiz_avg = (sum - min)/(quiz.size() -1);
    }
}

void Student::compute_hw_avg()
{
    if(hw.size() == 1)
    {
        hw_avg = double(hw[0]);
    }
    else if(hw.empty())
    {
        hw_avg = 0.0;
    }
    else
    {
        double sum = std::accumulate(hw.begin(), hw.end(), 0.0);
        hw_avg = sum / hw.size();
    }
}

void Student::compute_course_score()
{
    compute_quiz_avg();
    compute_hw_avg();
    double sum = quiz_avg * QUIZ_WEIGHT + hw_avg * HOMEWORK_WEIGHT + final_score * FINAL_WEIGHT;
    course_score = std::round(sum);
}



//Gradebook class
void Gradebook::compute_grades()
{
    for(Student& stu: students)
    {
        stu.compute_grade();
    }
}
void Gradebook::sort()
{
    std::sort(students.begin(), students.end());
}
void Gradebook::validate() const
{
    for(const auto& S: students)
        S.validate();
}

std::istream& operator >> (std::istream& in, Gradebook& b)
{
    b.students.clear();
    Student stu{};
    while(in >> stu)
    {
        b.students.push_back(stu);
    }
    return in;
}

std::ostream& operator << (std::ostream& out, const Gradebook& b)
{
    for(const auto& stu: b.students)
    {
        out << stu << "\n";
    }
    
    return out;
}
