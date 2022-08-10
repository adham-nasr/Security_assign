#include<bits/stdc++.h>
using namespace std;
string x[8],z,ans[8];
int text[8][100],c[8][100] , memo[1000] , sp[8][100] , Msg[8][100];
int HTI(string y)
{
    int a=0,ind=0;
    while(ind<2)
    {
        a*=16;
        if(y[ind]<='9')
            a+=y[ind]-'0';
        else
            a+=y[ind]-55;
        ind++;
    }
    return a;
}
int main()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<100;j++)
            Msg[i][j]=-1;
    int sz;
    for(int i=0;i<8;i++)
        cin >> x[i] , sz = x[i].size();
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<sz;j+=2)
        {
            z=x[i][j];
            z+=x[i][j+1];
            text[i][j/2]=HTI(z);
            //cout << text[i][j/2] << " ";
            ans[i]+='-';
        }
        //cout << endl;
    }
    sz/=2;
    /// finding characters;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            for(int k=0;k<sz;k++)
                if(i!=j)
                    if( (text[i][k]^text[j][k])<64 && (text[i][k]^text[j][k])!=0)
                        c[i][k]=c[j][k]=1;
    }

    cout << endl << endl;
    /// using chars to find spaces;
    int spc=-1;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            for(int k=0;k<sz;k++)
                if(i!=j && c[i][k])
                    if((text[i][k]^text[j][k]) >= 64)
                        sp[j][k]=1;


    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            for(int k=0;k<sz;k++)
                if(i!=j)
                    if(sp[i][k] && (text[i][k]^text[j][k])!=0)
                        Msg[j][k] = (text[i][k]^text[j][k])+32;

    for(int i=0;i<8;i++)
        for(int j=0;j<sz;j++)
        {
            char a = Msg[i][j];
            if(sp[i][j])
                ans[i][j]=' ';
            else if(Msg[i][j]!=-1)
                ans[i][j]=a;
            else
                ans[i][j]='-';
        }
    for(int i=0;i<8;i++)
        cout << ans[i] << endl;

    /// guessing
    ans[4] = "address randomization could prevent malicious ca-l -t-----";

    for(int i=0;i<8;i++)
            for(int j=0;j<sz;j++)
            {
                if(i==4 || ans[4][j]=='-')
                    continue;
                int m = ans[4][j];
                ans[i][j] = char( (text[i][j]^text[4][j])^(m) );

            }
    cout << endl;
    for(int i=0;i<8;i++)
        cout << ans[i] << endl;

    /// second and last guess:
    ans[6] = "i shall never reuse the same password on multiple accounts";
    /// solve;
    for(int i=0;i<8;i++)
            for(int j=0;j<sz;j++)
            {
                if(i==6 || ans[6][j]=='-')
                    continue;
                int m = ans[6][j];
                ans[i][j] = char( (text[i][j]^text[6][j])^(m) );

            }
    cout << endl;
    for(int i=0;i<8;i++)
        cout << ans[i] << endl;
}
