#include <string>
#include <iostream>

#define NO_OF_CHARS 256  

void badCharHeuristic(std::string str, int size, int badchar[NO_OF_CHARS]){
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

bool search(std::string txt, std::string pat){
    int m = pat.size();
    int n = txt.size();
	
    int badchar[NO_OF_CHARS];

    badCharHeuristic(pat, m, badchar);

    int s = 0; 
    while (s <= (n - m)){
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0){
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
			return true;
        }
        else{
            int bc = badchar[txt[s + j]];
            s += std::max(1, j - bc);
        }
    }
	return false;
}