#include "proj1.hpp"
#include <map>
#include <set>
#include <string>
#include <vector>
#include "iostream"




bool verifySolution(std::string s1, std::string s2, std::string s3, const std::map<char, unsigned> & mapping)
{


    int loop = s3.length();
    int reminder = 0;
    std::string Strnum;
    for (int i = 0 ; i < loop ; i++){


        if ( s1.length() > 0 && s2.length() > 0){
            Strnum = std::to_string(mapping.at(s1.back()) + mapping.at(s2.back()) + reminder);
            reminder = 0;

            if (Strnum.length() > 1 ) {
                char r = Strnum[0];
                reminder = atoi(&r);}
            if (atoi(&Strnum.back()) != mapping.at(s3.back())) {
                return false;
            }

            s1.pop_back();
            s2.pop_back();
            s3.pop_back();
        }
        else if(s1.length() == 0 && s2.length() == 0){
            if (reminder != mapping.at(s3.back())) {
                return false;
            }

            s1.pop_back();
            s2.pop_back();
            s3.pop_back();
        }
        else if(s2.length() == 0){
            Strnum = std::to_string(mapping.at(s1.back()) + reminder);
            reminder = 0;
            if (Strnum.length() > 1 ) {
                char r = Strnum[0];
                reminder = atoi(&r);
            }
            if (atoi(&Strnum.back()) != mapping.at(s3.back())) {
                return false;
            }
            s1.pop_back();
            s2.pop_back();
            s3.pop_back();

        }

        else if(s1.length() == 0){
            Strnum = std::to_string(mapping.at(s2.back()) + reminder);
            reminder = 0;
            if (Strnum.length() > 1 ) {
                char r = Strnum[0];
                reminder = atoi(&r);
            }
            if (atoi(&Strnum.back()) != mapping.at(s3.back())) {
                return false;
            }
            s1.pop_back();
            s2.pop_back();
            s3.pop_back();

        }

    }
    return true;

}



// bool p1 = puzzleSolver("POT", "PAN", "BIB", puzzle);
std::vector<char> UniqueLetter(std::string s1, std::string s2, std::string s3){

    std::set<char> unique;
    for (int i = 0; i < s1.length(); i++)
        unique.insert(s1[i]);

    for (int i = 0; i < s2.length(); i++)
        unique.insert(s2[i]);

    for (int i = 0; i < s3.length(); i++)
        unique.insert(s3[i]);

    std::vector<char>length(unique.begin(), unique.end());

    return length;
}


/*    if (mapping.size() == LetterSet.size()) {
        if (verifySolution(s1, s2, s3, mapping) == true) {
            return true;
        }


        mapping.erase(LetterSet[Length]);

        return false;
        }

    for (int i = 0; i < 10; i++) {
        if (num[i] == false) {

            if (mapping.count(LetterSet[Length])){
                mapping.erase(LetterSet[Length]);
            }
            mapping.insert({LetterSet[Length], i});
            num[i] = true;


            if (hepler(s1, s2, s3, mapping,LetterSet, Length +1, num ))
                return true;

            num[i] = false;

        }

    }
    return false;
}

*/





bool hepler(std::string s1, std::string s2, std::string s3, std::map<char, unsigned> & mapping, std::vector<char> LetterSet, int Length, bool* num) {


    if (mapping.size() == LetterSet.size()) {
        if (verifySolution(s1, s2, s3, mapping) == true) {
            return true;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (num[i] == false) {

            mapping.insert(L)


        }

    }
    return false;
}


bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::map<char, unsigned> & mapping){
    std::vector<char> LetterSet = UniqueLetter(s1,s2,s3);

    int Length =LetterSet.size();
    if (Length > 10){
        return false;
    }

    bool num[10] = {false};

    if (hepler(s1,s2,s3,mapping,LetterSet,0, num) == true && verifySolution(s1,s2,s3,mapping)){
        for( std::map<char ,unsigned >::iterator iter=mapping.begin(); iter!=mapping.end(); ++iter)
        {
            std:: cout << (*iter).first << ": " << (*iter).second << std::endl;
        }
        return true;
    }
    return false;


}


