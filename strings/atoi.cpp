int Solution::atoi(const string a) {

    int i=0,sign=1;
    int n = a.length();
    int res=0;
    long long int res1=0;
    if(a[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if(a[i] == '+')
    {
        sign = 1;
        i++;
    }

    for(;i<n;i++)
    {
        if(a[i] >= 48 && a[i] <=  57)
        {
            res = res*10 + a[i] - 48;
            res1 = res1*10 + a[i] - 48;

        }
        else
    {
    if(res!=res1)
    {
        if(sign == -1)
        return INT_MIN;
        else
        return INT_MAX;
    }
    else
    return sign*res;
    }
  //  else
//    return res;
    }
    return res*sign;
}

