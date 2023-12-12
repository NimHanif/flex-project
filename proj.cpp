#include <iostream>
#include <fstream>
#include <string>
#include<cstdio>
using namespace std;
#include "Header.h"
#include <sfml/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

char** filehandle::getcourses() {
	return courses;
}
void course::display_code() {
	cout << c_code << " ";
}
void student_attendance(student&s){

	course *temp=s.get_course();
	for (int i = 0;i < s.get_s_total_courses_ofastu();i++) {
		(temp[i]).display_code();
		cout<< endl;
		(temp[i].get_att()).mark_attendance();
	}


}
int student::get_s_total_courses_ofastu() {
	return s_total_courses_ofastu;
}
void concat_2_string(char* a, char* b, string& c) {
	int index = 0;
	for (int i=0;i < a[i]!='\0';i++) {
		c[index] = a[i];
		index++;
	}
	c[index] = ' ';
	index++;
	for (int i = 0;i < b[i] != '\0';i++) {
		c[index] = b[i];
		index++;
	}
	c[index] = '\0';

}
void student_marks(student&s){
	course* temp = s.get_course();
	
	for (int i = 0;i < s.get_s_total_courses_ofastu();i++) {
		temp[i].display_code();
		cout << endl;
		(temp[i].get_marks()).mark_marks();
	}
}

course* student::get_course() {
	return s_course;
}
void attendance::display_att() {
	cout << "P: " << present << endl;
	cout << "A: " << absent << endl;
	cout << "Percentage of attendance: " << a_percentage << endl;
}
void marks::display_marks() {
	cout<<"mid 1: "<<mid1<<endl;
	cout<<"mid 2: "<<mid2<<endl;
	cout<<"final: "<<final<<endl;
	cout<< "percatage of marks: " << m_percentage << endl;;

}
void attendance::mark_attendance() {
	cout << "1-present" << endl;
	cout << "2-absent" << endl;
	cout << endl << "Enter: ";
	total_classes++;
	int atten;
	cin >> atten;
	if (atten == 1) {
		present++;

	}
	if (atten == 2) {
		absent++;

	}
	a_percentage = (present/total_classes)*100;
}
attendance::attendance()
{
	present=0;
	absent=0;
	a_percentage=0;
	total_classes = 0;
}

attendance::~attendance()
{
}

void marks::mark_marks() {
	float m1, m2, fin;
	cout << endl << "Enter mid 1 marks out of 20: ";
	cin >> m1;
	cout << endl << "Enter mid 2 marks out of 20: ";
	cin >> m2;
	cout << endl << "Enter finals marks out of 60: ";
	cin >> fin;
	mid1 = m1;
	mid2 = m2;
	final = fin;
	m_percentage = ((m1+m2+fin)/ 100) * 100;

}
marks::marks()
{
	 mid1 = 0;
	 mid2 = 0;
	 final = 0;
	 m_percentage = 0;
}

marks::~marks()
{
}

void system_handle::press1() {
	cout << "1-Display already enrolled students" << endl;
	cout << "2-Add a student" << endl;
	cout << "3-Remove a student" << endl;
	cout << "4-Edit student detail" << endl;
	cout << "5-Back" << endl;
	int presssub;
	cout << endl;
	cout << "Enter: ";
	cin >> presssub;
	if (presssub == 1) {
		f.displaystu();
		cout << endl << endl;
		maindisplay();

	}
	if (presssub == 2) {
		string  roll_numm, con;
		string name3;
		int age;
		cout << "Enter name: ";
		getline(cin>>ws, name3);
		cout << "roll number: ";
		cin >> roll_numm;
		cout << "age: ";
		cin >> age;
		cout << "contact: ";
		cin >> con;
		student s11;
		s11.s_enroll(name3,roll_numm,age,con);
		f.write_expand_stu(name3, roll_numm, age, con);
		ifstream r;
		f.read_store_stu(r);
		cout << endl << endl;
		maindisplay();

	}
	if (presssub == 3) {
		string roll_num;
		
		cout << "roll number: ";
		cin>>roll_num;
		f.remove_compress_stu(roll_num);
		ifstream r;
		f.read_store_stu(r);
		cout << endl << endl;
		maindisplay();

	}
	if (presssub == 4) {
		string name, roll_num, con;
		int age;
		cout << "Enter name: ";
		getline(cin >> ws, name);
		cout << "roll number: ";
		cin >> roll_num;
		cout << "age: ";
		cin >> age;
		cout << "contact: ";
		cin >> con;
		f.edit_stu(name,roll_num,age,con);
		ifstream r;
		f.read_store_stu(r);
		cout << endl << endl;
		maindisplay();
	}
	if (presssub == 5) {
		maindisplay();

	}


}
void system_handle::press2() {
	cout << "1-Available courses" << endl;
	cout << "2-Register a course" << endl;
	cout << "3-Back" << endl;
	int presssub;
	cout << endl;
	cout << "Enter: ";
	cin >> presssub;
	if (presssub == 1) {
		f.displaycourse();
		cout << endl << endl;
		maindisplay();

	}
	if (presssub == 2) {
		string roll_num, code;
		cout << "roll number of the student who wants to register: ";
		cin >> roll_num;
		f.displaycourse_code();
		cout << endl;
		cout << endl;
		cout << "course code you want to register: ";
		cin >> code;
		int a = f.found_stu(roll_num);
		int b = f.found_course(code);
		if (a ==0) {
			cout << "invalid roll number" << endl;
		}
		if (b == 0) {
			cout << "course u want to register for is not available at the momment" << endl;
		}
		if(a==1 &&b==1){
			if (s1.getroll() == roll_num) {
				if (c1.getcode() == code) {
					s_reg_course(s1, c1);
				}
				if (c2.getcode() == code) {
					s_reg_course(s1, c2);
				}
				if (c3.getcode() == code) {
					s_reg_course(s1, c3);
				}
				if (c4.getcode() == code) {
					s_reg_course(s1, c4);
				}
				if (c5.getcode() == code) {
					s_reg_course(s1, c5);
				}
				if (c6.getcode() == code) {
					s_reg_course(s1, c6);
				}
				if (c7.getcode() == code) {
					s_reg_course(s1, c7);
				}
				



				if (s2.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_reg_course(s2, c1);
					}
					if (c2.getcode() == code) {
						s_reg_course(s2, c2);
					}
					if (c3.getcode() == code) {
						s_reg_course(s2, c3);
					}
					if (c4.getcode() == code) {
						s_reg_course(s2, c4);
					}
					if (c5.getcode() == code) {
						s_reg_course(s2, c5);
					}
					if (c6.getcode() == code) {
						s_reg_course(s2, c6);
					}
					if (c7.getcode() == code) {
						s_reg_course(s2, c7);
					}

				}



				if (s3.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_reg_course(s3, c1);
					}
					if (c2.getcode() == code) {
						s_reg_course(s3, c2);
					}
					if (c3.getcode() == code) {
						s_reg_course(s3, c3);
					}
					if (c4.getcode() == code) {
						s_reg_course(s3, c4);
					}
					if (c5.getcode() == code) {
						s_reg_course(s3, c5);
					}
					if (c6.getcode() == code) {
						s_reg_course(s3, c6);
					}
					if (c7.getcode() == code) {
						s_reg_course(s3, c7);
					}

				}




				if (s4.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_reg_course(s4, c1);
					}
					if (c2.getcode() == code) {
						s_reg_course(s4, c2);
					}
					if (c3.getcode() == code) {
						s_reg_course(s4, c3);
					}
					if (c4.getcode() == code) {
						s_reg_course(s4, c4);
					}
					if (c5.getcode() == code) {
						s_reg_course(s4, c5);
					}
					if (c6.getcode() == code) {
						s_reg_course(s4, c6);
					}
					if (c7.getcode() == code) {
						s_reg_course(s4, c7);
					}

				}




				if (s5.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_reg_course(s5, c1);
					}
					if (c2.getcode() == code) {
						s_reg_course(s5, c2);
					}
					if (c3.getcode() == code) {
						s_reg_course(s5, c3);
					}
					if (c4.getcode() == code) {
						s_reg_course(s5, c4);
					}
					if (c5.getcode() == code) {
						s_reg_course(s5, c5);
					}
					if (c6.getcode() == code) {
						s_reg_course(s5, c6);
					}
					if (c7.getcode() == code) {
						s_reg_course(s5, c7);
					}

				}




				if (s6.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_reg_course(s6, c1);
					}
					if (c2.getcode() == code) {
						s_reg_course(s6, c2);
					}
					if (c3.getcode() == code) {
						s_reg_course(s6, c3);
					}
					if (c4.getcode() == code) {
						s_reg_course(s6, c4);
					}
					if (c5.getcode() == code) {
						s_reg_course(s6, c5);
					}
					if (c6.getcode() == code) {
						s_reg_course(s6, c6);
					}
					if (c7.getcode() == code) {
						s_reg_course(s6, c7);
					}

				}




				if (s7.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_reg_course(s7, c1);
					}
					if (c2.getcode() == code) {
						s_reg_course(s7, c2);
					}
					if (c3.getcode() == code) {
						s_reg_course(s7, c3);
					}
					if (c4.getcode() == code) {
						s_reg_course(s7, c4);
					}
					if (c5.getcode() == code) {
						s_reg_course(s7, c5);
					}
					if (c6.getcode() == code) {
						s_reg_course(s7, c6);
					}
					if (c7.getcode() == code) {
						s_reg_course(s7, c7);
					}

				}




				if (s8.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_reg_course(s8, c1);
					}
					if (c2.getcode() == code) {
						s_reg_course(s8, c2);
					}
					if (c3.getcode() == code) {
						s_reg_course(s8, c3);
					}
					if (c4.getcode() == code) {
						s_reg_course(s8, c4);
					}
					if (c5.getcode() == code) {
						s_reg_course(s8, c5);
					}
					if (c6.getcode() == code) {
						s_reg_course(s8, c6);
					}
					if (c7.getcode() == code) {
						s_reg_course(s8, c7);
					}

				}



				if (s9.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_reg_course(s9, c1);
					}
					if (c2.getcode() == code) {
						s_reg_course(s9, c2);
					}
					if (c3.getcode() == code) {
						s_reg_course(s9, c3);
					}
					if (c4.getcode() == code) {
						s_reg_course(s9, c4);
					}
					if (c5.getcode() == code) {
						s_reg_course(s9, c5);
					}
					if (c6.getcode() == code) {
						s_reg_course(s9, c6);
					}
					if (c7.getcode() == code) {
						s_reg_course(s9, c7);
					}

				}




				if (s10.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_reg_course(s10, c1);
					}
					if (c2.getcode() == code) {
						s_reg_course(s10, c2);
					}
					if (c3.getcode() == code) {
						s_reg_course(s10, c3);
					}
					if (c4.getcode() == code) {
						s_reg_course(s10, c4);
					}
					if (c5.getcode() == code) {
						s_reg_course(s10, c5);
					}
					if (c6.getcode() == code) {
						s_reg_course(s10, c6);
					}
					if (c7.getcode() == code) {
						s_reg_course(s10, c7);
					}

				}




			}

			
		
		}

		cout << endl << endl;
		maindisplay();
		

	}

	if (presssub == 3) {
		maindisplay();

	}

}
void system_handle::press3() {
	cout << "1-Display Attendance" << endl;
	cout << "2-Mark Attendance" << endl;
	cout << "3-Back" << endl;
	int presssub;
	cout << endl;
	cout << "Enter: ";
	cin >> presssub;
	if (presssub == 1) {

		string roll_num;
		cout << "roll number of the student to display his/her attendance: ";
		cin >> roll_num;
		int a = f.found_stu(roll_num);
		if (a == 0) {
			cout << "invalid roll number" << endl;
		}
		if (a == 1) {
			if (s1.getroll() == roll_num) {
				s1.display_stu_with_courses_and_att();
			}
			if (s2.getroll() == roll_num) {
				s2.display_stu_with_courses_and_att();
			}
			if (s3.getroll() == roll_num) {
				s3.display_stu_with_courses_and_att();
			}
			if (s4.getroll() == roll_num) {
				s4.display_stu_with_courses_and_att();
			}
			if (s5.getroll() == roll_num) {
				s5.display_stu_with_courses_and_att();
			}
			if (s6.getroll() == roll_num) {
				s6.display_stu_with_courses_and_att();
			}
			if (s7.getroll() == roll_num) {
				s7.display_stu_with_courses_and_att();
			}
			if (s8.getroll() == roll_num) {
				s8.display_stu_with_courses_and_att();
			}

			if (s9.getroll() == roll_num) {
				s9.display_stu_with_courses_and_att();
			}
			if (s10.getroll() == roll_num) {
				s10.display_stu_with_courses_and_att();
			}


			cout << endl << endl;
			maindisplay();
		}
	}
		if (presssub == 2) {
			string roll_num;
			cout << "roll number of the student to mark his/her attendance: ";
			cin >> roll_num;
			int a = f.found_stu(roll_num);
			if (a == 0) {
				cout << "invalid roll number" << endl;
			}
			if (a == 1) {
				if (s1.getroll() == roll_num) {
					student_attendance(s1);
				}
				if (s2.getroll() == roll_num) {
					student_attendance(s2);
				}
				if (s3.getroll() == roll_num) {
					student_attendance(s3);
				}
				if (s4.getroll() == roll_num) {
					student_attendance(s4);
				}
				if (s5.getroll() == roll_num) {
					student_attendance(s5);
				}
				if (s6.getroll() == roll_num) {
					student_attendance(s6);
				}
				if (s7.getroll() == roll_num) {
					student_attendance(s7);
				}
				if (s8.getroll() == roll_num) {
					student_attendance(s8);
				}
				if (s9.getroll() == roll_num) {
					student_attendance(s9);
				}
				if (s10.getroll() == roll_num) {
					student_attendance(s10);
				}
			}
			cout << endl << endl;
			maindisplay();

		}
		if (presssub == 3) {
			cout << endl << endl;
			maindisplay();
		}

	
}
void system_handle::press4()
{
	cout << "1-Display Marks" << endl;
	cout << "2-Assign Marks" << endl;
	cout << "3-Back" << endl;
	int presssub;
	cout << endl;
	cout << "Enter: ";
	cin >> presssub;
	if (presssub == 1) {
		string roll_num;
		cout << "roll number of the student to display his/her marks: ";
		cin >> roll_num;
		int a = f.found_stu(roll_num);
		if (a == 0) {
			cout << "invalid roll number" << endl;
		}
		if (a == 1) {
			if (s1.getroll() == roll_num) {
				s1.display_stu_with_courses_and_marks();
			}
			if (s2.getroll() == roll_num) {
				s2.display_stu_with_courses_and_marks();
			}
			if (s3.getroll() == roll_num) {
				s3.display_stu_with_courses_and_marks();
			}
			if (s4.getroll() == roll_num) {
				s4.display_stu_with_courses_and_marks();
			}
			if (s5.getroll() == roll_num) {
				s5.display_stu_with_courses_and_marks();
			}
			if (s6.getroll() == roll_num) {
				s6.display_stu_with_courses_and_marks();
			}
			if (s7.getroll() == roll_num) {
				s7.display_stu_with_courses_and_marks();
			}
			if (s8.getroll() == roll_num) {
				s8.display_stu_with_courses_and_marks();
			}

			if (s9.getroll() == roll_num) {
				s9.display_stu_with_courses_and_marks();
			}
			if (s10.getroll() == roll_num) {
				s10.display_stu_with_courses_and_marks();
			}
			cout << endl << endl;
			maindisplay();
		}
	}
	if (presssub == 2) {
		string roll_num;
		cout << "roll number of the student to assign his/her marks: ";
		cin >> roll_num;
		int a = f.found_stu(roll_num);
		if (a == 0) {
			cout << "invalid roll number" << endl;
		}
		if (a == 1) {
			if (s1.getroll() == roll_num) {
				student_marks(s1);
			}
			if (s2.getroll() == roll_num) {
				student_marks(s2);
			}
			if (s3.getroll() == roll_num) {
				student_marks(s3);
			}
			if (s4.getroll() == roll_num) {
				student_marks(s4);
			}
			if (s5.getroll() == roll_num) {
				student_marks(s5);
			}
			if (s6.getroll() == roll_num) {
				student_marks(s6);
			}
			if (s7.getroll() == roll_num) {
				student_marks(s7);
			}
			if (s8.getroll() == roll_num) {
				student_marks(s8);
			}
			if (s9.getroll() == roll_num) {
				student_marks(s9);
			}
			if (s10.getroll() == roll_num) {
				student_marks(s10);
			}

			cout << endl << endl;
			maindisplay();

		}
	}
			if (presssub == 3) {
				cout << endl << endl;
				maindisplay();


			}
		
	}


void system_handle::press5() {
	cout << "1-Show the enrolled Courses of a student" << endl;
	cout << "2-Show students in a Course" << endl;
	cout << "3-Drop a course" << endl;
	cout << "4-Back" << endl;
	int presssub;
	cout << endl;
	cout << "Enter: ";
	cin >> presssub;
	if (presssub == 1) {
		string roll_num;
		cout << "enter roll number: ";
		cin >> roll_num;
		int a = f.found_stu(roll_num);
		if (a == 0) {
			cout << "invalid roll number" << endl;
		}
		if (a == 1) {
			if (s1.getroll() == roll_num) {
				s1.s_display_perstudent();
			}

			if (s2.getroll() == roll_num) {
				s2.s_display_perstudent();
			}

			if (s3.getroll() == roll_num) {
				s3.s_display_perstudent();
			}

			if (s4.getroll() == roll_num) {
				s4.s_display_perstudent();
			}

			if (s5.getroll() == roll_num) {
				s5.s_display_perstudent();
			}

			if (s6.getroll() == roll_num) {
				s6.s_display_perstudent();
			}

			if (s7.getroll() == roll_num) {
				s7.s_display_perstudent();
			}

			if (s8.getroll() == roll_num) {
				s8.s_display_perstudent();
			}

			if (s9.getroll() == roll_num) {
				s9.s_display_perstudent();
			}

			if (s10.getroll() == roll_num) {
				s10.s_display_perstudent();
			}

	
			cout << endl << endl;
			maindisplay();
		}
		cout << endl << endl;
		maindisplay();

	}
	if (presssub == 2) {
		f.displaycourse_code();
		cout << endl;
		cout << "enter the course code: ";
		string code;
		cin >> code;
		int a = f.found_course(code);
		if (a == 0) {
			cout << "invalid course: ";

		}
		if (a == 1) {
			if (c1.getcode()==code) {
				c1.c_display_percourseinfo();
			}


			if (c2.getcode() == code) {
				c2.c_display_percourseinfo();
			}

			if (c3.getcode() == code) {
				c3.c_display_percourseinfo();
			}

			if (c4.getcode() == code) {
				c4.c_display_percourseinfo();
			}

			if (c4.getcode() == code) {
				c5.c_display_percourseinfo();
			}

			if (c6.getcode() == code) {
				c6.c_display_percourseinfo();
			}

			if (c7.getcode() == code) {
				c7.c_display_percourseinfo();
			}
		}
		cout << endl << endl;
		maindisplay();

	}
	if (presssub == 3) {
		string roll_num, code;
		cout << "roll number of the student who wants to drop a course: ";
		cin >> roll_num;
		cout << "course code you want to drop: ";
		cin >> code;
		int a = f.found_stu(roll_num);
		int b = f.found_course(code);
		if (a == 0) {
			cout << "invalid roll number" << endl;
		}
		if (b == 0) {
			cout << "course u want to drop is not available at the moment" << endl;
		}
		if (a == 1 && b == 1) {
			if (s1.getroll() == roll_num) {
				if (c1.getcode() == code) {
					s_withdraw_course(s1, c1);
				}
				if (c2.getcode() == code) {
					s_withdraw_course(s1, c2);
				}
				if (c3.getcode() == code) {
					s_withdraw_course(s1, c3);
				}
				if (c4.getcode() == code) {
					s_withdraw_course(s1, c4);
				}
				if (c5.getcode() == code) {
					s_withdraw_course(s1, c5);
				}
				if (c6.getcode() == code) {
					s_withdraw_course(s1, c6);
				}
				if (c7.getcode() == code) {
					s_withdraw_course(s1, c7);
				}




				if (s2.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_withdraw_course(s2, c1);
					}
					if (c2.getcode() == code) {
						s_withdraw_course(s2, c2);
					}
					if (c3.getcode() == code) {
						s_withdraw_course(s2, c3);
					}
					if (c4.getcode() == code) {
						s_withdraw_course(s2, c4);
					}
					if (c5.getcode() == code) {
						s_withdraw_course(s2, c5);
					}
					if (c6.getcode() == code) {
						s_withdraw_course(s2, c6);
					}
					if (c7.getcode() == code) {
						s_withdraw_course(s2, c7);
					}

				}



				if (s3.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_withdraw_course(s3, c1);
					}
					if (c2.getcode() == code) {
						s_withdraw_course(s3, c2);
					}
					if (c3.getcode() == code) {
						s_withdraw_course(s3, c3);
					}
					if (c4.getcode() == code) {
						s_withdraw_course(s3, c4);
					}
					if (c5.getcode() == code) {
						s_withdraw_course(s3, c5);
					}
					if (c6.getcode() == code) {
						s_withdraw_course(s3, c6);
					}
					if (c7.getcode() == code) {
						s_withdraw_course(s3, c7);
					}

				}




				if (s4.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_withdraw_course(s4, c1);
					}
					if (c2.getcode() == code) {
						s_withdraw_course(s4, c2);
					}
					if (c3.getcode() == code) {
						s_withdraw_course(s4, c3);
					}
					if (c4.getcode() == code) {
						s_withdraw_course(s4, c4);
					}
					if (c5.getcode() == code) {
						s_withdraw_course(s4, c5);
					}
					if (c6.getcode() == code) {
						s_withdraw_course(s4, c6);
					}
					if (c7.getcode() == code) {
						s_withdraw_course(s4, c7);
					}

				}




				if (s5.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_withdraw_course(s5, c1);
					}
					if (c2.getcode() == code) {
						s_withdraw_course(s5, c2);
					}
					if (c3.getcode() == code) {
						s_withdraw_course(s5, c3);
					}
					if (c4.getcode() == code) {
						s_withdraw_course(s5, c4);
					}
					if (c5.getcode() == code) {
						s_withdraw_course(s5, c5);
					}
					if (c6.getcode() == code) {
						s_withdraw_course(s5, c6);
					}
					if (c7.getcode() == code) {
						s_withdraw_course(s5, c7);
					}

				}




				if (s6.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_withdraw_course(s6, c1);
					}
					if (c2.getcode() == code) {
						s_withdraw_course(s6, c2);
					}
					if (c3.getcode() == code) {
						s_withdraw_course(s6, c3);
					}
					if (c4.getcode() == code) {
						s_withdraw_course(s6, c4);
					}
					if (c5.getcode() == code) {
						s_withdraw_course(s6, c5);
					}
					if (c6.getcode() == code) {
						s_withdraw_course(s6, c6);
					}
					if (c7.getcode() == code) {
						s_withdraw_course(s6, c7);
					}

				}




				if (s7.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_withdraw_course(s7, c1);
					}
					if (c2.getcode() == code) {
						s_withdraw_course(s7, c2);
					}
					if (c3.getcode() == code) {
						s_withdraw_course(s7, c3);
					}
					if (c4.getcode() == code) {
						s_withdraw_course(s7, c4);
					}
					if (c5.getcode() == code) {
						s_withdraw_course(s7, c5);
					}
					if (c6.getcode() == code) {
						s_withdraw_course(s7, c6);
					}
					if (c7.getcode() == code) {
						s_withdraw_course(s7, c7);
					}

				}




				if (s8.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_withdraw_course(s8, c1);
					}
					if (c2.getcode() == code) {
						s_withdraw_course(s8, c2);
					}
					if (c3.getcode() == code) {
						s_withdraw_course(s8, c3);
					}
					if (c4.getcode() == code) {
						s_withdraw_course(s8, c4);
					}
					if (c5.getcode() == code) {
						s_withdraw_course(s8, c5);
					}
					if (c6.getcode() == code) {
						s_withdraw_course(s8, c6);
					}
					if (c7.getcode() == code) {
						s_withdraw_course(s8, c7);
					}

				}



				if (s9.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_withdraw_course(s9, c1);
					}
					if (c2.getcode() == code) {
						s_withdraw_course(s9, c2);
					}
					if (c3.getcode() == code) {
						s_withdraw_course(s9, c3);
					}
					if (c4.getcode() == code) {
						s_withdraw_course(s9, c4);
					}
					if (c5.getcode() == code) {
						s_withdraw_course(s9, c5);
					}
					if (c6.getcode() == code) {
						s_withdraw_course(s9, c6);
					}
					if (c7.getcode() == code) {
						s_withdraw_course(s9, c7);
					}

				}




				if (s10.getroll() == roll_num) {
					if (c1.getcode() == code) {
						s_withdraw_course(s10, c1);
					}
					if (c2.getcode() == code) {
						s_withdraw_course(s10, c2);
					}
					if (c3.getcode() == code) {
						s_withdraw_course(s10, c3);
					}
					if (c4.getcode() == code) {
						s_withdraw_course(s10, c4);
					}
					if (c5.getcode() == code) {
						s_withdraw_course(s10, c5);
					}
					if (c6.getcode() == code) {
						s_withdraw_course(s10, c6);
					}
					if (c7.getcode() == code) {
						s_withdraw_course(s10, c7);
					}

				}




			}



		}
		cout << endl << endl;
		maindisplay();

	}
	if (presssub == 4) {
		maindisplay();
	}
}
void system_handle::press6() {
	maindisplay();
}
void system_handle::maindisplay1() {

	string roll;
	cout << "Roll No.: ";
	cin >> roll;
	cout << endl;



	if (f.found_stu(roll))
	{
		cout << endl;
		cout << endl;
		cout << "1- Enroll a student" << endl;
		cout << "      -Display already enrolled students" << endl;
		cout << "      -Add a student" << endl;
		cout << "      -Remove a student" << endl;
		cout << "      -Edit student detail" << endl;
		cout << "      -Back" << endl;
		cout << endl;
		cout << "2 - Course Registration" << endl;
		cout << "      -Available courses" << endl;
		cout << "      -Register a course" << endl;
		cout << "      -Back" << endl;
		cout << endl;
		cout << "3 - Attendance" << endl;
		cout << "      -Display Attendance" << endl;
		cout << "      -Mark Attendance" << endl;
		cout << "      -Back" << endl;
		cout << endl;
		cout << "4 - Marks" << endl;
		cout << "      -Display Marks" << endl;
		cout << "      -Assign Marks" << endl;
		cout << "      -Back" << endl;
		cout << endl;
		cout << "5 - Course Withdraw" << endl;
		cout << "       -Show the enrolled Courses of a student" << endl;
		cout << "       -Show students in a Course" << endl;
		cout << "       -Drop a course" << endl;
		cout << "       -Back" << endl;
		cout << endl;
		cout << "6 - Exit" << endl;
		int press;
		cout << endl;
		cout << "Enter: ";
		cin >> press;
		cout << endl;
		if (press == 1) {
			press1();
		}
		if (press == 2) {
			press2();

		}
		if (press == 3) {
			press3();

		}
		if (press == 4) {
			press4();

		}
		if (press == 5) {
			press5();

		}
		if (press == 6) {
			

		}




	}
	if(!f.found_stu(roll))
	{
		cout << "Not Found" << endl;
		cout << endl << endl;
		maindisplay1();
	}

}
void system_handle::maindisplay() {

		cout << endl;
		cout << endl;
		cout << "1- Enroll a student" << endl;
		cout << "      -Display already enrolled students" << endl;
		cout << "      -Add a student" << endl;
		cout << "      -Remove a student" << endl;
		cout << "      -Edit student detail" << endl;
		cout << "      -Back" << endl;
		cout << endl;
		cout << "2 - Course Registration" << endl;
		cout << "      -Available courses" << endl;
		cout << "      -Register a course" << endl;
		cout << "      -Back" << endl;
		cout << endl;
		cout << "3 - Attendance" << endl;
		cout << "      -Display Attendance" << endl;
		cout << "      -Mark Attendance" << endl;
		cout << "      -Back" << endl;
		cout << endl;
		cout << "4 - Marks" << endl;
		cout << "      -Display Marks" << endl;
		cout << "      -Assign Marks" << endl;
		cout << "      -Back" << endl;
		cout << endl;
		cout << "5 - Course Withdraw" << endl;
		cout << "       -Show the enrolled Courses of a student" << endl;
		cout << "       -Show students in a Course" << endl;
		cout << "       -Drop a course" << endl;
		cout << "       -Back" << endl;
		cout << endl;
		cout << "6 - Exit" << endl;
		int press;
		cout << endl;
		cout << "Enter: ";
		cin >> press;
		cout << endl;
		if (press == 1) {
			press1();
		}
		if (press == 2) {
			press2();

		}
		if (press == 3) {
			press3();

		}
		if (press == 4) {
			press4();

		}
		if (press == 5) {
			press5();

		}
		if (press == 6) {


		}




	}
	






void system_handle::write_in_file_and_storing_7course_and_10stu() {

	ifstream r;

	s1.s_enroll("Nimra Hanif", "22L-6705", 21, "+923216779948");
	f.write_expand_stu("Nimra Hanif", "22L-6705", 21, "+923216779948");
	f.read_store_stu(r);
	
	s2.s_enroll("Eva Rodriguez", "17Y-5542", 17, "+922198765432");
	f.write_expand_stu("Eva Rodriguez", "17Y-5542", 17, "+922198765432");
	f.read_store_stu(r);
	
	s3.s_enroll("Oliver Smith", "29M-9876", 29, "+924112345678");
	f.write_expand_stu("Oliver Smith", "29M-9876", 29, "+924112345678");
	f.read_store_stu(r);

	s4.s_enroll("Sophie Patel", "41N-2233", 41, "+925198765432");
	f.write_expand_stu("Sophie Patel", "41N-2233", 41, "+925198765432");
	f.read_store_stu(r);
	
	s5.s_enroll("Mason Chen", "26J-6677", 26, "+923478965432");
	f.write_expand_stu("Mason Chen", "26J-6677", 26, "+923478965432");
	f.read_store_stu(r);
	
	s6.s_enroll("Ava Kumar", "19P-1122", 19, "+920112233445");
	f.write_expand_stu("Ava Kumar", "19P-1122", 19, "+920112233445");
	f.read_store_stu(r);

	s7.s_enroll("Lucas Gupta", "33R-8899", 33, "+926778899001");
	f.write_expand_stu("Lucas Gupta", "33R-8899", 33, "+926778899001");
	f.read_store_stu(r);
	
	s8.s_enroll("Isabella Khan", "28Q-5566", 28, "+927112233445");
	f.write_expand_stu("Isabella Khan", "28Q-5566", 28, "+927112233445");
	f.read_store_stu(r);
	
	s9.s_enroll("Jackson Lee", "25K-3344", 25, "+928998877665");
	f.write_expand_stu("Jackson Lee", "25K-3344", 25, "+928998877665");
	f.read_store_stu(r);
	
	s10.s_enroll("Emma Ali", "35V-6677", 35, "+924556677889");
	f.write_expand_stu("Emma Ali", "35V-6677", 35, "+924556677889");
	f.read_store_stu(r);



	
	c1.c_add("ENG201", "English_Literature", "Dr._Johnson", 4, 25);
	f.write_expand_course("ENG201", "English_Literature", "Dr._Johnson", 4, 25);
	f.read_store_course(r);
	
	c2.c_add("MATH301", "Advanced_Calculus", "Prof._Brown", 4, 20);
	f.write_expand_course("MATH301", "Advanced_Calculus", "Prof._Brown", 4, 20);
	f.read_store_course(r);
	
	c3.c_add("MUSIC110", "Music_Appreciation", "Prof._Robinson", 2, 40);
	f.write_expand_course("MUSIC110", "Music_Appreciation", "Prof._Robinson", 2, 40);
	f.read_store_course(r);
	
	c4.c_add("PHYS101", "Physics_for_Beginners", "Prof._Davis", 4, 30);
	f.write_expand_course("PHYS101", "Physics_for_Beginners", "Prof._Davis", 4, 30);
	f.read_store_course(r);
	
	c5.c_add("HIST202", "World_History", "Dr._White", 3, 35);
	f.write_expand_course("HIST202", "World_History", "Dr._White", 3, 35);
	f.read_store_course(r);
	
	c6.c_add("ART150", "Introduction_to_Art", "Prof._Turner", 3, 25);
	f.write_expand_course("ART150", "Introduction_to_Art", "Prof._Turner", 3, 25);
	f.read_store_course(r);
	
	c7.c_add("BUS305", "Business_Ethics", "Dr._Miller", 3, 25);
	f.write_expand_course("BUS305", "Business_Ethics", "Dr._Miller", 3, 25);
	f.read_store_course(r);
}
void system_handle::system_handle::display_main() {

	maindisplay1();
}


system_handle::system_handle()
{
	
}

system_handle::~system_handle()
{
}

void course::c_display_percourseinfo_simple() {
	cout << c_code <<" ";
	cout  << c_name << endl;
	
}
void course::add_student_ina_course(string n , string r , int a, string c) {
	c_stu = new student[1];
	c_students_in_a_course++;
	if (c_students_in_a_course == 1) {
		c_stu[0] = student(n, r, a, c);
	}
	if (c_students_in_a_course > 1 && c_students_in_a_course < c_capacity) {
		int index = 0;
		student* temp = new student[c_students_in_a_course];
		for (int i = 0;i < c_students_in_a_course-1;i++) {
			
				temp[index]=c_stu[i];
				index++;
			
		}
		temp[index]= student(n, r, a, c);
		c_stu = temp;

	}
	if(c_students_in_a_course >c_capacity) {
		cout << "seats full in this course" << endl;
	}
		
	
}
attendance& course::get_att() {
	return a;
}
marks& course::get_marks() {
	return m;
}
void course::remove_student_ina_course(string r){
	int index = 0;
	student* temp = new student[c_students_in_a_course - 1];
	for (int i = 0;i < c_students_in_a_course;i++) {
		if (c_stu[i].getroll() != r) {
			temp[index] = c_stu[i];
			index++;
		}
	}
	c_stu = temp;
	c_students_in_a_course--;
}
void course::c_display_percourseinfo() {
	cout << "Course code: " << c_code << endl;
	cout << "name: " << c_name << endl;
	cout << "instructor: " << c_instructor << endl;
	cout << "credit: " << c_credits << endl;
	cout << "capacity: " << c_capacity << endl;
	cout << "Total students: " << c_students_in_a_course << endl;

	if(c_students_in_a_course != 0) {
		cout << "students enrolled in this course: " << endl;
		for (int i = 0;i < c_students_in_a_course;i++) {
			c_stu[i].s_display_perstudent_simple();
			cout << endl;
		}
		cout << endl;
	}
}
void course::c_add(string c , string n , string i , int ch , int cap) {
	c_code = c;
	c_name = n;
	c_instructor = i;
	c_credits = ch;
	c_capacity = cap;
	c_students_in_a_course = 0;
}
void course::c_remove(string c ){
	filehandle f1;
	f1.remove_compress_course(c);
}
void course::c_display_total(){
	filehandle f1;
	f1.displaycourse();

}
string course::getcode() {
	return c_code;
}
string course::getname() {
	return c_name;
}
string course::getins() {
	return c_instructor;
}
int course::getcap() {
	return c_capacity;
}
int course::getcred() {
	return c_credits;
}
course::course(string c , string n ,string i,int ch,int cap)
{
	c_code = c;
	c_name = n;
	c_instructor = i;
	c_credits = ch;
	c_capacity = cap;
	

	


}
course::course()
{
	c_code = "\0";
	c_name = "\0";
	c_instructor = "\0";
	c_credits = 0;
	c_capacity = 0;
	c_students_in_a_course = 0;



}
student::student(string n, string r, int a, string c)
{
	s_name = n;
	s_roll = r;
	s_age = a;
	s_contact = c;
	




}
student::student() {
	s_total_courses_ofastu = 0;
		s_name = "\0";
		s_roll = "\0";
		s_age = 0;
		s_contact = "\0";
		
		

}
course::~course()
{

}
void course::display_courses_with_att() {
	c_display_percourseinfo_simple();
	a.display_att();

}
void course::display_courses_with_marks() {
	c_display_percourseinfo_simple();
	m.display_marks();

}
void student::s_add_acourse(string c, string n, string i, int ch, int cap){
	s_total_courses_ofastu++;
	if (s_total_courses_ofastu == 1) {
		s_course[0] = course(c,n,i,ch,cap);
	}
	if (s_total_courses_ofastu > 1) {
		int index = 0;
		course* temp = new course[s_total_courses_ofastu];
		for (int i = 0;i < s_total_courses_ofastu - 1;i++) {

			temp[index] = s_course[i];
			index++;

		}
		temp[index] = course(c,n,i,ch,cap);
		s_course= temp;

	}

	
}
void student::display_stu_with_courses_and_att() {
	course* temp = get_course();
	for (int i = 0;i < get_s_total_courses_ofastu();i++) {
		(temp[i].display_courses_with_att());
	}
}
void student::display_stu_with_courses_and_marks() {
	course* temp = get_course();
	for (int i = 0;i < get_s_total_courses_ofastu();i++) {
		(temp[i].display_courses_with_marks());
	}
}
void student::s_remove_acourse(string code){
	int index = 0;
	course* temp = new course[s_total_courses_ofastu - 1];
	for (int i = 0;i < s_total_courses_ofastu;i++) {
		if (s_course[i].getcode() != code) {
			temp[index]= s_course[i];
			index++;
		}
	}
	s_course = temp;
	s_total_courses_ofastu--;

}



student::~student()
{
}
string student::getroll() {
	return s_roll;
}
string student::getstuname() {
	return s_name;
}
string student::getcon() {
	return s_contact;
}
int student::getage() {
	return s_age;
}
void student::s_display_total(){
	filehandle f1;
	f1.displaystu();
}
void student::s_display_perstudent(){
	cout << "Name:" << s_name << endl;
	cout << "Roll_num: " << s_roll << endl;
	cout << "age: " << s_age << endl;
	cout << "contact: " << s_contact << endl;
	cout << "total courses enrolled by this student: " << s_total_courses_ofastu << endl;
	for (int i = 0;i < s_total_courses_ofastu;i++) {
		s_course[i].c_display_percourseinfo_simple();
	}
	cout << endl;

}
void student::s_display_perstudent_simple() {
	cout << s_roll << " ";
	cout  << s_name <<endl;

	cout << endl;
}
void student::s_remove(string roll) {
	filehandle f1;
	f1.remove_compress_stu(roll);
}
void student::s_enroll(string n="\0", string r="\0", int a=0, string c="\0") {
	s_name = n;
	s_roll = r;
	s_age = a;
	s_contact = c;
	s_course = new course[1];
	


}
void student::s_attendance(){}
void student::s_mark() {}
void s_reg_course(student&s1,course&c1){
	s1.s_add_acourse(c1.getcode(), c1.getname(), c1.getins(), c1.getcred(), c1.getcap());
	c1.add_student_ina_course(s1.getstuname(), s1.getroll(), s1.getage(), s1.getcon());

}
void s_withdraw_course(student& s1, course& c1){
	s1.s_remove_acourse(c1.getcode());
	c1.remove_student_ina_course(s1.getroll());
}

void stringcpy(char* a, string b) {
	int i = 0;
	for (i;i < b.length();i++) {
		a[i] = b[i];
	}
	a[i] = '\0';
}
void stringcpy2(char* a, char*b) {
	int i = 0;
	for (i; b[i]='\0';i++) {
		a[i] = b[i];
	}
	a[i] = '\0';
}
void stringcpy3(string a, char* b) {
	int i = 0;
	for (i;i < b[i]!='\0';i++) {
		a[i] = b[i];
	}
	a[i] = '\0';
}
void filehandle::write_expand_course(string c, string n, string ins, int ch, int cap){

	if (course_size == 1) {
		ofstream r1;
		r1.open("courses.txt");
		r1 << c << " " << n << " " << ins << " " << ch << " " << cap << " ";
		r1.close();
		course_size++;
	}
	else {
		string line;

		char** courses2 = new char* [course_size];
		for (int i = 0;i < course_size;i++) {
			courses2[i] = new char[100];
		}

		ofstream r1;
		r1.open("courses.txt");

		for (int i = 0;i < course_size - 1;i++) {
			r1 << courses[i];
			r1 << endl;
		}

		r1 << c << " " << n << " " << ins << " " << ch << " " << cap << " ";
		courses = courses2;
		course_size++;
	}

}
void filehandle::write_expand_stu(string n,string r,int a,string c){
	if(stu_size==1){
		ofstream r1;
		r1.open("students.txt");
		r1 << n << " " << r << " " << a << " " << c;cout<< endl;
		r1.close();
		stu_size++;
	}
	else {
		string line;
		char** students2 = new char* [stu_size];
		for (int i = 0;i < stu_size;i++) {
			students2[i] = new char[100];
		}

		ofstream r1;
		r1.open("students.txt");

		for (int i = 0;i < stu_size - 1;i++) {
			r1 << students[i];
			r1 << endl;
		}

		r1 << n << " " << r << " " << a << " " << c;
		students = students2;
		stu_size++;
	}

}
void filehandle::read_store_course(ifstream&r){

	int index = 0;
	string line;
	r.open("courses.txt");
	while (getline(r, line)) {

		stringcpy(courses[index], line);
		index++;

	}

	r.close();
}
void filehandle::remove_compress_stu(string roll){
	if (found_stu(roll)) {
		string line;
		stu_size--;
		stu_size--;
		char** students2 = new char* [stu_size];
		for (int i = 0;i < stu_size;i++) {
			students2[i] = new char[100];
		}

		ofstream r1;
		r1.open("students.txt");

		for (int i = 0;i < stu_size+1;i++) {
			if (!found_stu_perline(roll,students[i])) {
				r1 << students[i];
				r1 << endl;
			}
		}


		students = students2;
	}
	else {
		cout << endl << endl << "STUDENT YOU WANT TO REMOVE NOT FOUND" << endl << endl;
	}

}
void filehandle::edit_stu(string name, string roll, int age, string contact) {
	char* edit_line = new char[100];
	int index = 0;
	for (int i=0;i < name.length();i++) {
		edit_line[index] = name[i];
		index++;
	}
	edit_line[index] = ' ';
	index++;
	for (int i = 0;i < roll.length();i++) {
		edit_line[index] = roll[i];
		index++;
	}
	edit_line[index] = ' ';
	index++;
	string age_string= to_string(age);
	edit_line[index] =age_string[0];
	index++;
	edit_line[index] = age_string[1];
	index++;
	edit_line[index] = ' ';
	index++;
	for (int i = 0;i < contact.length();i++) {
		edit_line[index] = contact[i];
		index++;
	}
	edit_line[index] = '\0';

	if (found_stu(roll)) {
		for (int i = 0;i < stu_size-1;i++) {
			if (found_stu_perline(roll, students[i])) {
				students[i] = edit_line;
				break;
				

			}
		}
		ofstream r1;
		r1.open("students.txt");

		for (int i = 0;i < stu_size-1;i++) {
			r1 << students[i];
			r1 << endl;
		}
	}
	else {
		cout << endl << endl << "STUDENT YOU WANT TO EDIT NOT FOUND" << endl << endl;
	}
}
void filehandle::remove_compress_course(string code){
	if (found_course(code)) {
		string line;
		course_size--;
		course_size--;
		char** courses2 = new char* [course_size];
		for (int i = 0;i < course_size;i++) {
			courses2[i] = new char[100];
		}


		ofstream r1;
		r1.open("courses.txt");

		for (int i = 0;i < course_size+1;i++) {
			if (!found_course_perline(code,courses[i])) {
				r1 << courses[i];
				r1 << endl;
			}
		}
		

		courses = courses2;
	}
	else {
		cout << endl<<endl<<"THE COURSE YOU ARE TRYING TO REMOVE IS NOT AVAILABLE" << endl << endl;
	}

}
void filehandle::displaycourse() {
	cout <<endl<<endl<< "--COURSES OFFERED--" << endl << endl;
	for (int i = 0;i < course_size-1;i++) {
		cout << courses[i] << endl;
	}
}
void filehandle::displaycourse_code() {
	cout << endl << endl << "--COURSES OFFERED--" << endl << endl;
	int j = 0;
	for (int i = 0;i < course_size - 1;i++) {
		for (j;courses[i][j]!= ' ';j++) {
			cout << courses[i][j];
		}

		cout << "  ";
		j = 0;
	}
}
filehandle::filehandle()

{
	int index2 = 1;
	ifstream r2;
	string line2;
	r2.open("students.txt");
	while (getline(r2, line2)) {
		
		index2++;

	}

	r2.close();
	stu_size = index2;
	students = new char* [index2];
	for (int i = 0;i < index2;i++) {
		students[i] = new char[100];
	}
	for (int i = 0;i <index2;i++) {
		stringcpy(students[i], " ");
	}

	ifstream r;
	int index = 1;
	string line;
	r.open("courses.txt");
	while (getline(r, line)) {

		index++;

	}
	r.close();
	course_size = index;
	courses = new char* [index];
	for (int i = 0;i < index;i++) {
		courses[i] = new char[100];
	}
	for (int i = 0;i < index;i++) {
		stringcpy(courses[i], " ");
	}
}

filehandle::~filehandle()
{
}

void filehandle::read_store_stu(ifstream& r) {
	int index = 0;
	string line;
	r.open("students.txt");
	while (getline(r, line)) {

		stringcpy(students[index], line);
		index++;

	}

	r.close();
}

void filehandle::displaystu() {
	cout << "--ENROLLED STUDENTS--" << endl << endl;
	for (int i = 0;i < stu_size-1;i++) {
		cout << students[i] << endl;
	}
}
bool filehandle::found_course(string code){
	ifstream r;
	int found = 0;
	string line;
	r.open("courses.txt");
	while (getline(r,line)) {
		char* line2 = new char[100];
		stringcpy(line2, line);

		if (found_course_perline( code,line2)) {
			found = 1;
			break;
		}


	}
	r.close();
	if (found == 1) {
		return 1;

	}
	else {
		return 0;
	}
}
bool filehandle::found_stu(string rol) {
	ifstream r;
	int found = 0;
	string line;
	r.open("students.txt");
	while (getline(r, line)) {
		char* line2 = new char[100];
		stringcpy(line2, line);

		if (found_stu_perline(rol, line2)) {
			found = 1;
			break;
		}


	}
	r.close();
	if (found == 1) {
		return 1;

	}
	else {
		return 0;
	}


}
bool filehandle::found_stu_perline(string roll,char*a){
	int i = 0, index = 0,found=1;
	for (i;a[i] != ' ';i++) {

	}
	i++;
	for (i;a[i] != ' ';i++) {

	}
	i++;
	for (i;a[i]!= ' ';i++) {
		if (roll[index] != a[i]) {
			found = 0;
			break;
		}
		index++;

	}
	if (found == 0) {
		return 0;
	}
	else {
		return 1;
	}


}
bool filehandle::found_course_perline(string code,char*a){
	int i = 0, index = 0, found = 1;
	for (i;a[i] != ' ';i++) {
		if (code[index] != a[i]) {
			found = 0;
			break;
		}
		index++;

	}
	if (found == 0) {
		return 0;
	}
	else {
		return 1;
	}
}
void filehandle::clear_stu() {
	ofstream r;
	r.open("students.txt");
	r.close();


}
void filehandle::clear_course() {
	ofstream r;
	r.open("courses.txt");
	r.close();


}

int main() {

	RectangleShape rectangle(Vector2f(1200, 700)); 
	Color customColor(215, 205, 204); 
	rectangle.setFillColor(customColor);
    RectangleShape rectangle1(Vector2f(400, 205)); 
	Color customColor1(212,210,213);
	rectangle1.setFillColor(customColor1);
	rectangle1.setOutlineThickness(5.f);
	rectangle1.setOutlineColor(Color(110, 106, 111));
	float x1, y1;
	x1 =770;
	y1 = 10;
	RectangleShape rectanglef(Vector2f(502, 197));
	rectanglef.setFillColor(Color(212, 210, 213));
	rectanglef.setOutlineThickness(5.f);
	rectanglef.setOutlineColor(Color(212, 210, 213));
	float x3, y3;
	x3 = 10;
	y3 = 250;
	RectangleShape rectangle2(Vector2f(280, 100));
	rectangle2.setFillColor(Color(212, 210, 213));
	rectangle2.setOutlineThickness(5.f);
	rectangle2.setOutlineColor(Color(110, 106, 111));
	float x2, y2;
	x2 = 550;
	y2 = 550;
	RenderWindow window(VideoMode(1200, 700), "nimra");
	Font font;
	font.loadFromFile("font.otf");
	Text text, text1, text2, text3, text4, text5, text6, text7;
	text.setFont(font);
	text.setCharacterSize(96);
	text.setFillColor(Color(108,105,141));
	text.setPosition(800, 10);
	text.setString("FLEX\n");
	text1.setFont(font);
	text1.setCharacterSize(40);
	text1.setFillColor(Color(108, 105, 141));
	text1.setPosition(800, 100);
	text1.setString("------------\nAcademic Portal\n");
	text2.setFont(font);
	text2.setCharacterSize(40);
	text2.setFillColor(Color::Black);
	text2.setPosition(10, 500);
	text2.setString("");
	text3.setFont(font);
	text3.setCharacterSize(20);
	text3.setFillColor(Color::Black);
	text3.setPosition(10, 650);
	text3.setString("");

	text4.setFont(font);
	text4.setCharacterSize(50);
	text4.setFillColor(Color::Black);
	text4.setPosition(650, 20);
	text4.setString("");
	text5.setFont(font);
	text5.setCharacterSize(35);
	text5.setFillColor(Color::Black);
	text5.setPosition(500, 500);
	text5.setString("Press Enter to continue\n\n");
	
	text6.setFont(font);
	text6.setCharacterSize(30);
	text6.setFillColor(Color::Black);
	text6.setPosition(600, 450);
	text6.setString("");
	text7.setFont(font);
	text7.setCharacterSize(50);
	text7.setFillColor(Color(107,45,82));
	text7.setPosition(750, 300);
	text7.setString(" Name:Nimra Hanif\n Roll no:22L-6705");
	Text inputText1;
	inputText1.setFont(font);
	inputText1.setCharacterSize(80);
	inputText1.setFillColor(Color(67,124,144));
	inputText1.setPosition(550, 540);
	inputText1.setString(" ENTER");
	Sprite sprite;
	Texture spriteTexture;
	if (spriteTexture.loadFromFile("study.jpg"))
	{
		sprite.setTexture(spriteTexture);
		
		sprite.setPosition(10.f, 10.f);
		sprite.setScale(1.0f, 1.0f); 
	}
	else
	{
		cout << "not opened";
	}
	Sprite sprite1;
	/*Texture spriteTexture1;
	if (spriteTexture1.loadFromFile("fast.jpg"))
	{
		sprite1.setTexture(spriteTexture1);
		
		sprite1.setPosition(10.f, 250.f);
		sprite1.setScale(0.5, 0.5); 
	}*/
	/*else
	{
		cout << "not opened";
	}*/
	Sprite sprite2;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
			{
				window.close();
			}
			else if (Mouse::getPosition(window).x > rectangle2.getGlobalBounds().left
				&& Mouse::getPosition(window).x < rectangle2.getGlobalBounds().left +
				rectangle2.getGlobalBounds().width && Mouse::getPosition(window).y>
				rectangle2.getGlobalBounds().top && Mouse::getPosition(window).y <
				(rectangle2.getGlobalBounds().top + rectangle2.getGlobalBounds().height) &&
				Mouse::isButtonPressed(Mouse::Left))
			{
				window.close();
			}
		}
		window.clear();
		window.draw(rectangle);
		window.draw(rectangle1);
		window.draw(rectangle2);
		window.draw(rectanglef);
		window.draw(sprite);
		window.draw(sprite1);
		window.draw(text);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(sprite2);
		window.draw(inputText1);
		window.display();
		rectangle1.setPosition(Vector2f(x1, y1));
		rectangle2.setPosition(Vector2f(x2, y2));
		rectanglef.setPosition(Vector2f(x3, y3));
	}
	ofstream r1;
	r1.open("students.txt");
	r1.close();
	ofstream r;
	r.open("courses.txt");
	r.close();

	cout << "--FLEX FAST--" << endl << endl;
	system_handle *s=new system_handle;
	s->write_in_file_and_storing_7course_and_10stu();
	s->display_main();
	delete s;

	return 0;
}