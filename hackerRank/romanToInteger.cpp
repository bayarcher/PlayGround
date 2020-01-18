class Solution {
public:
    int romanToInt(string s) {
        string::reverse_iterator inputChars = s.rbegin();
        int value = 0;
        char curChar = 0;
        char prevChar = 0;
        
        while(inputChars != s.rend()) {
            prevChar = curChar;
            curChar = (*inputChars);
            
            switch(curChar){
                case 'I':
                    if(prevChar == 'V' || prevChar == 'X') {
                        value -= 1;
                    } else value += 1;
                   break; 
                case 'V':
                    value += 5;
                    break;
                case 'X':
                    if(prevChar == 'L' || prevChar == 'C') {
                        value -= 10;
                    } else value += 10;
                    break;
                case 'L':
                    value += 50;
                    break;
                case 'C':
                    if(prevChar == 'D' || prevChar == 'M') {
                        value -= 100;
                    } else value += 100;
                    break;
                case 'D':
                    value += 500;
                    break;
                case 'M':
                    value += 1000;
                    break;
                default:
                    break;
                    
            }
            ++inputChars;
            
        }
        return value;
    }
};

