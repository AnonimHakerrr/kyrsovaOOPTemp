#include "TeacherPosition.h"
#include <map>

string  positionToString(TeacherPosition techpos){
	switch (techpos)
	{
	case TeacherPosition::Assistant:
		return "Асистент";
	case TeacherPosition::Lecturer:
		return "Викладач";
	case TeacherPosition::SeniorLecturer:
		return "Старший викладач";
	case TeacherPosition::Docent:
		return "Доцент";
	case TeacherPosition::Professor:
		return "Професор";
	default:
		return "Асистент";
	}
}

TeacherPosition positionToEnum(string techpos){
	map<string, TeacherPosition> position = {
		{"Асистент",TeacherPosition::Assistant},
		{"Викладач",TeacherPosition::Lecturer},
		{"Старший викладач",TeacherPosition::SeniorLecturer} ,
		{"Доцент", TeacherPosition::Docent},
		{"Професор",TeacherPosition::Professor},
	};
	auto pos = position.find(techpos);
	return (pos != position.end()) ? pos->second : TeacherPosition::Assistant;
}