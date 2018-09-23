class Solution {
public:
    int myAtoi(string str) {
    	int i = 0;
        for (; i < str.size(); ++i) {
        	if (str[i] != ' ') break;
        }

        string res = str.substr(i);
        if (res[0] != '-' && res[0] != '+' && !isdigit(res[0]))
        	return 0;

        bool negative = false;
        if (res[0] == '-') {
        	negative = true;
        	res = res.substr(1);
        } else if (res[0] == '+') {
        	negative = false;
        	res = res.substr(1);
        }

        for (i = 0; i < res.size(); ++i) {
        	if (!isdigit(res[i])) {
        		res = res.substr(0, i);
        		break;
        	}
        }

        int size = res.size();
        long long ret = 0;
     	for (i = 0; i < size; ++i) {
     		ret = ret * 10;
     		ret += (res[i] - '0');
     		if (negative && (0-ret) < INT_MIN) {
     			return INT_MIN;
     		}
     		if (!negative && ret > INT_MAX) {
     			return INT_MAX;
     		}
     	}
        
        if (negative) return -ret;
 		return ret;    	
    }
};
