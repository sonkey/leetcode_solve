class Solution {
public:
    bool isPalindrome(string s) {
        auto bit = s.begin();
        auto eit = s.end() - 1;
        while (bit < eit) {
        	if (!isdigit(*bit) && !isalpha(*bit)) {
        		++bit;
        		continue;
        	}
        	if (!isdigit(*eit) && !isalpha(*eit)) {
        		--eit;
        		continue;
        	}

        	if (isdigit(*bit) && isdigit(*eit)) {
        		if (*eit == *bit) {
        			bit++;
        			eit--;
                    continue;
        		}
        	}

        	if (isalpha(*bit) && isalpha(*eit)) {
        		if (equal(*bit, *eit)) {
        			bit++;
        			eit--;
        			continue;
        		}
        	}

        	return false;
        }
        return true;
    }

private:
	bool equal(char a, char b) {
		if (a == b) return true;
		if ((a^32) == b || a == (b^32)) return true;
		return false;
	}
};
