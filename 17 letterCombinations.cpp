class Solution {
void getLetters(vector<string>& rst, string curRst, const string& digits, int pos){
    if(pos == digits.size()){
        rst.push_back(curRst);
        return;
    }

    vector<char> letter(4, 'a');
    int cnt = 0;
    switch(digits[pos]){
        case '2':{
            cnt = 3;
            letter[0] = 'a';
            letter[1] = 'b';
            letter[2] = 'c';
            break;
        }
        case '3':{
            cnt = 3;
            letter[0] = 'd';
            letter[1] = 'e';
            letter[2] = 'f';
            break;
        }
        case '4':{
            cnt = 3;
            letter[0] = 'g';
            letter[1] = 'h';
            letter[2] = 'i';
            break;
        }
        case '5':{
            cnt = 3;
            letter[0] = 'j';
            letter[1] = 'k';
            letter[2] = 'l';
            break;
        }
        case '6':{
            cnt = 3;
            letter[0] = 'm';
            letter[1] = 'n';
            letter[2] = 'o';
            break;
        }
        case '7':{
            cnt = 4;
            letter[0] = 'p';
            letter[1] = 'q';
            letter[2] = 'r';
            letter[3] = 's';
            break;
        }
        case '8':{
            cnt = 3;
            letter[0] = 't';
            letter[1] = 'u';
            letter[2] = 'v';
            break;
        }
        case '9':{
            cnt = 4;
            letter[0] = 'w';
            letter[1] = 'x';
            letter[2] = 'y';
            letter[3] = 'z';
            break;
        }
        default: break;
    }

    for(int i = 0; i < cnt; i++){
        getLetters(rst, curRst+letter[i], digits, pos+1);
    }
}

public:
    // 递归回溯
    vector<string> letterCombinations(string digits) {
        vector<string> rst;
        if(digits.empty()) return rst;
        getLetters(rst, "", digits, 0);
        return rst;
    }
};