# include <string>

using namespace std;

/*
Дана структура LectureTitle:
struct LectureTitle {
    string specialization;
    string course;
    string week;
};

Допишите конструктор и структуры Specialization, Course, Week так, чтобы объект LectureTitle можно было создать с помощью кода
LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
);

но нельзя было с помощью следующих фрагментов кода:
LectureTitle title("C++", "White belt", "4th");
LectureTitle title(string("C++"), string("White belt"), string("4th"));
LectureTitle title = {"C++", "White belt", "4th"};
LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
LectureTitle title(
    Course("White belt"),
    Specialization("C++"),
    Week("4th")
);
LectureTitle title(
    Specialization("C++"),
    Week("4th"),
    Course("White belt")
);
 */


struct Specialization {
    string value;

    explicit Specialization(const string& new_value) {
        value = new_value;
    }
};

struct Course {
    string value;

    explicit Course(const string& new_value) {
        value = new_value;
    }
};

struct Week {
    string value;

    explicit Week(const string& new_value) {
        value = new_value;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(const Specialization& new_specialization, const Course& new_course, const Week& new_week) {
        specialization = new_specialization.value;
        course = new_course.value;
        week = new_week.value;
    }
};


int main() {

    // Should work
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );

    // // Shouldn't work
//    LectureTitle title1("C++", "White belt", "4th");
//    LectureTitle title2(string("C++"), string("White belt"), string("4th"));
//    LectureTitle title3 = {"C++", "White belt", "4th"};
//    LectureTitle title4 = {{"C++"}, {"White belt"}, {"4th"}};
//    LectureTitle title5(
//            Course("White belt"),
//            Specialization("C++"),
//            Week("4th")
//    );
//    LectureTitle title6(
//            Specialization("C++"),
//            Week("4th"),
//            Course("White belt")
//    );

    return 0;
}