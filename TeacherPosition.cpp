#include "TeacherPosition.h"
#include <map>


string  positionToString(TeacherPosition techpos) 
{
	switch (techpos)
	{	
	case TeacherPosition::Assistant:
		return "��������";
 
	case TeacherPosition::Lecturer:
		return "��������";
 	case TeacherPosition::Director:
		return "��������";
 	default:
		return "��������";

	}
}
TeacherPosition positionToEnum(string techpos)
{
	map<string, TeacherPosition> position = {
		{"Assistant",TeacherPosition::Assistant},
		{"Lecturer",TeacherPosition::Lecturer},
		{"Director",TeacherPosition::Director} };
	auto pos = position.find(techpos);
	return (pos!=position.end()) ? pos->second : TeacherPosition::Lecturer;
}