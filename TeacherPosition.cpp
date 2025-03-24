#include "TeacherPosition.h"
#include <map>


string  positionToString(TeacherPosition techpos) 
{//Асистент  старший викладач доцент Професор
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
TeacherPosition positionToEnum(string techpos)
{
	map<string, TeacherPosition> position = {
		{"Assistant",TeacherPosition::Assistant},
		{"Lecturer",TeacherPosition::Lecturer},
		{"SeniorLecturer",TeacherPosition::SeniorLecturer} ,
		{"Docent", TeacherPosition::Docent},
		{"Professor",TeacherPosition::Professor},
	};
	auto pos = position.find(techpos);

return (pos!=position.end()) ? pos->second : TeacherPosition::Assistant;
}