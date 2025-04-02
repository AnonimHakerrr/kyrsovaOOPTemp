#include "File.h"
#include <regex>
#include "Iterator.h"
#include <unordered_set>



File::File(string path) : path(path) {}


vector<Student> File::readFile() {
	vector<Student> readStud;
	ifstream inFile(path);
	vector<vector<string>> lines;
	string line;
	while (getline(inFile, line)) {
		vector<string> x;
		string word;
		istringstream str2(line);
		while (getline(str2, word, ',')) {
			x.push_back(word);
		}
		lines.push_back(x);
	}
	for (auto l : lines) {
		Student stud(l[0], l[1], l[2]);
		for (size_t i = 3; i < l.size(); i += 8) {
			Teacher teach(positionToEnum(l[i + 4]), l[i + 5], l[i + 6]);
			Exam exam(teach, l[i], l[i + 1], stoi(l[i + 2]), stoi(l[i + 3]));
			stud.setRecordBookStudent(exam);
		}
		readStud.push_back(stud);
	}
	inFile.close();
	return readStud;
}
void File::writeFile(vector<Student> stud) {
	ofstream outFile(path);
	for (auto s : stud) {
		vector<string> st;
		st.push_back(s.getStudent());
		RecordBook rec = s.getRecordBookStudent();
		Iterator begin(rec.begin(), rec.end());
		Iterator end(rec.end(), rec.end());
		for (Iterator it = begin; it != end; ++it) {
			st.push_back((*it).getInfoExam());
		}
		string fullText;
		for (const string& line : st) {
			fullText += cleanText(line) + " ";
		}
		vector<string> parts = split(fullText, ' ');
		for (size_t i = 0; i < parts.size(); ++i) {
			outFile << parts[i];
			if (i != parts.size() - 1) outFile << ",";
		}
		outFile << "\n";
	}
	outFile.close();
}

string File::cleanText(const string& text) {
	string result = regex_replace(text, regex("\n"), " ");
	return result;
}

vector<string> File::split(const string& str, char delimiter) {
	vector<string> tokens;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter)) {
		if (!token.empty()) {
			tokens.push_back(token);
		}
	}
	unordered_set<string> stopWords = { ":", "Cтудент","Прізвище", "Групи", "Ім'я", "Назва", "предмету", "Кількість",
										 "годин", "на", "проведення", "Оцінка", "Посада", "Дата" };

	tokens.erase(remove_if(tokens.begin(), tokens.end(),
		[&](const string& s) { return stopWords.count(s) > 0; }),
		tokens.end());
	return tokens;
}






