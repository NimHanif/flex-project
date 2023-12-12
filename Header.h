class marks;
class attendance;
class system_handle;
class course;
class students;
class filehandle;



class attendance
{
public:
	attendance();
	~attendance();
	void mark_attendance();
	void display_att();


private:
	float present;
	float absent;
	float a_percentage;
	float total_classes;
};
class marks
{
public:
	marks();
	~marks();
	void mark_marks();
	void display_marks();

private:
	float mid1;
	float mid2;
	float final;
	float m_percentage;
};
class filehandle
{
public:
	filehandle();
	~filehandle();
	void read_store_stu(ifstream&);
	void read_store_course(ifstream&);
	void displaystu();
	void displaycourse();
	bool found_stu(string);
	bool found_course(string);
	void write_expand_course(string, string, string, int, int);
	void write_expand_stu(string, string, int, string);
	void remove_compress_stu(string);
	void remove_compress_course(string);
	bool found_stu_perline(string, char*);
	bool found_course_perline(string, char*);
	void edit_stu(string, string, int, string);
	void clear_stu();
	void clear_course();
	int stu_size;
	int course_size;
	char** getcourses();
	void displaycourse_code();
	

private:
	char** students;

	char** courses;
};
class student
{
public:
	student();
	student(string, string, int, string);
	~student();
	void s_enroll(string, string, int, string);
	void s_attendance();
	friend void s_reg_course(student&, course&);
	void s_mark();
	friend  void s_withdraw_course(student&, course&);
	void s_remove(string);
	void s_display_total();
	void s_display_perstudent();
	void s_display_perstudent_simple();
	string getroll();
	string getstuname();
	string getcon();
	int getage();
	void s_add_acourse(string, string, string, int, int);
	void s_remove_acourse(string);
	friend  void student_attendance(student&);
	friend  void student_marks(student&);
	course* get_course();
	int get_s_total_courses_ofastu();
	void display_stu_with_courses_and_att();
	void display_stu_with_courses_and_marks();




private:

	string s_name;
	string s_roll;
	int s_age;
	string s_contact;
	int s_total_courses_ofastu;
	course* s_course;


};
class course
{
public:
	course(string, string, string, int, int);
	course();
	~course();
	void c_add(string, string, string, int, int);
	void c_remove(string);
	void c_display_total();
	void c_display_percourseinfo();
	void c_display_percourseinfo_simple();
	void add_student_ina_course(string, string, int, string);
	void remove_student_ina_course(string);
	string getcode();
	string getname();
	string getins();
	int getcap();
	int getcred();
	attendance& get_att();
	marks& get_marks();
	void display_courses_with_att();
	void display_courses_with_marks();
	void display_code();


private:
	string c_code;
	string c_name;
	string c_instructor;
	int c_credits;
	int c_capacity;
	student* c_stu;
	int c_students_in_a_course;
	attendance a;
	marks m;

};

class system_handle
{
private:

public:

	filehandle f;
	student s1;
	student s2;
	student s3;
	student s4;
	student s5;
	student s6;
	student s7;
	student s8;
	student s9;
	student s10;
	student s11;
	course c1;
	course c2;
	course c3;
	course c4;
	course c5;
	course c6;
	course c7;
	system_handle();
	~system_handle();
	void display_main();
	void write_in_file_and_storing_7course_and_10stu();
	void maindisplay();
	void maindisplay1();
	void press1();
	void press2();
	void press3();
	void press4();
	void press5();
	void press6();
	

};

void stringcpy(char* a, string b);
void stringcpy2(char* a, char* b);
void stringcpy3(string a, char* b);
void concat_2_string(char* a, char* b, string &c);



