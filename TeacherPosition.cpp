#include "TeacherPosition.h"
#include <map>

string  positionToString(TeacherPosition techpos){
	switch (techpos)
	{
	case TeacherPosition::Assistant:
		return "��������";
	case TeacherPosition::Lecturer:
		return "��������";
	case TeacherPosition::SeniorLecturer:
		return "������� ��������";
	case TeacherPosition::Docent:
		return "������";
	case TeacherPosition::Professor:
		return "��������";
	default:
		return "��������";
	}
}

TeacherPosition positionToEnum(string techpos){
	map<string, TeacherPosition> position = {
		{"��������",TeacherPosition::Assistant},
		{"��������",TeacherPosition::Lecturer},
		{"������� ��������",TeacherPosition::SeniorLecturer} ,
		{"������", TeacherPosition::Docent},
		{"��������",TeacherPosition::Professor},
	};
	auto pos = position.find(techpos);
	return (pos != position.end()) ? pos->second : TeacherPosition::Assistant;
}