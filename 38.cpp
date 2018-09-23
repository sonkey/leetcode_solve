class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "";
        if (n == 1) return string("1");

        string pre;
        if (mem[n-1] != "") 
            pre = mem[n-1];
        else 
            pre = countAndSay(n - 1);

        int cur, next = 0;
        string res;
        while (next < pre.size()) {
            int count = 0;
            while (pre[next] == pre[cur]) {
                next++;
                count++;
            }
            res += to_string(count);
            res.push_back(pre[cur]);
            cur = next;
        }

        return mem[n] = res;
    }

private:
    string mem[100];
};
