//#include "File.h"
//
//#include <fstream>
//#include <iostream>
//#include <sstream>
//#include <vector>
//
//#include "Exam.h"
//
//File::File(string path) : path(path) {}
//
//
//
//vector<vector<string>> File::ReadFile( )
//{
//    
//      ifstream inFile(path);
//         vector< vector<string>> lines;
//         string line;
//         while (std::getline(inFile, line)) {
//            vector<string > x;
//            string word;
//            istringstream str2(line);
//            while (getline(str2, word, ' '))
//            {
//                x.push_back(word);
//            }
//            lines.push_back(x);
//        }
//        inFile.close();
//        return lines;
//   
//}
//void File::WriteFile(Exam& e)
//{
//     istringstream str1(e.GetStudent());
//    istringstream str2(e.GetTeacher());
//    vector<string> words;
//    string word;
//    words.push_back(e.get(1));
//    words.push_back(e.get(2));
//    words.push_back(e.get(3));
//    words.push_back(e.get(4));
//    int x = 0;
//    while (getline(str1, word, ' '))
//    {
//        if (x != 0 && x != 2 && x != 3 && x != 5)
//            words.push_back(word);
//        x++;
//    }
//    x = 0;
//    while (getline(str2, word, ' '))
//    {
//        if (x != 0 && x != 2 && x != 3 && x != 5)
//            words.push_back(word);
//        x++;
//    }
//
//   ofstream outFile(path,ios::app);
//   for (const auto& word : words) {
//       outFile << word << " ";  
//   }
//   outFile << "\n";
//   outFile.close();
//
//
// 
//}
//
//
//
// 