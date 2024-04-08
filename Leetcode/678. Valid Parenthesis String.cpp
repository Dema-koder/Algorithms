/*
Два указателя 
1) Идем слева направо и все звезды заменяем на открывающие скобки
Если в какой то момент баланс меньше 0 то отве false
2) Идем справа налево и все звезды заменяет на закрывающие скобки
Если в какой то момент баланс меньше 0 то отве false
*/

class Solution {
public:
    bool checkValidString(string s) {
        int openCount = 0, closeCount = 0, left = 0, right = s.size() - 1;
        while (left < s.size()) {
            if (s[left] != ')')
                openCount++;
            else 
                openCount--;
            if (s[right] != '(')
                closeCount++;
            else 
                closeCount--;
            if (closeCount < 0 || openCount < 0)
                return false;
            left++, right--;
        }
        return true;
    }
};
