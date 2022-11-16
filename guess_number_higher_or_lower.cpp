class Solution
{

    struct arr
    {
        long long l;
        long long h;
    };

public:
    long long guessNumber(long long n)
    {
        stack<arr> s;
        arr p;
        p.l = 0;
        p.h = n;
        s.push(p);
        arr x;
        while (s.empty() != true)
        {
            x = s.top();
            s.pop();
            if (guess((x.l + x.h) / 2) == 0)
            {
                return (x.l + x.h) / 2;
            }
            else if (guess((x.l + x.h) / 2) == 1)
            {
                x.l = (x.l + x.h) / 2 + 1;
                s.push(x);
            }
            else if (guess((x.l + x.h) / 2) == -1)
            {
                x.h = (x.l + x.h) / 2 - 1;
                s.push(x);
            }
        }
        return 0;
    }
};