 int fun(char a)
 {
     if(a == 'I')
     return 1;
     else if(a == 'V')
     return 5;
     else if(a == 'X')
     return 10;
     else if(a == 'L')
     return 50;
     else if(a == 'C')
     return 100;
     else if(a == 'D')
     return 500;
     else if(a == 'M')
     return 1000;
     else return 0;
 }
int romanToInt(char* a) {
    int i,num=0,n = strlen(a);
    for(i=0;i<n;)
    {
        if(fun(a[i]) >= fun(a[i+1]))
        {
          num = num + fun(a[i]);
          i++;
        }
        else
        {
            num = num + (fun(a[i+1])-(a[i]));
            i+=2;
        }
    }
    return num;
}

