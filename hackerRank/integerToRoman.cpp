class Solution {
public:
    string intToRoman(int num) {
        
        int proc = num;
        int ones = proc % 10;
        proc /= 10;
        int tens = proc % 10;
        proc /= 10;
        int hundreds  = proc % 10;
        proc /= 10;
        
        int thousands = proc % 10;
        
        string result = "";
        
        while(thousands) {
            result += 'M';
            thousands --;
        }
        
        
        if(hundreds == 9) {
            result.append("CM");
        } 
        else if(hundreds < 9 && hundreds >= 5) {
            result += 'D';
            hundreds -=5;
            while(hundreds) {
                result += 'C';
                hundreds--;
            }
        }
        else if(hundreds == 4) {
            result.append("CD");
        } else {
            while(hundreds) {
                result += 'C';
                hundreds--;  
            }
        }
        
        if(tens == 9) {
            result.append("XC");
        } else if(tens < 9 && tens >= 5) {
            result += 'L';
            tens -= 5;
            while(tens) {
                result += 'X';
                tens--;
            }
        } else if(tens == 4) {
            result.append("XL");
        } else {
            while(tens) {
                result+= 'X';
                tens--;
            }
        }
        
        if(ones == 9) {
            result.append("IX");
        } else if(ones < 9 && ones >= 5) {
            result += 'V';
            ones -= 5;
            while(ones) {
                result += 'I';
                ones--;
            }              

        } else if( ones == 4) {
            result.append("IV");
        } else {
            while(ones) {
                result += 'I';
                ones--;
            }            
        }
        return result;   
    }
};
